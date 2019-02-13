#include <stdlib.h>

  TFile* infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/EnhancementsBGSUBBEDPPi0LinPolNonStrictCuts.root");	

void LinPolDataExtraction() { 
//  TFile* ofile = new TFile("/home/chris/Docs/haspy/LatestFitting/Jan8th2017/Histogrammer/EnhancementsData.txt","recreate");	




 TString histMoellerName ="BeamEnergy_SignalTiming_PolStateD0.00_";
 TString histParaName ="BeamEnergy_SignalTiming_PolStateD-0.50_";
 TString histPerpName ="BeamEnergy_SignalTiming_PolStateD0.50_"  ;


 TH1F* histMoeller = (TH1F*)infile->Get(histMoellerName); 
 TH1F* histPara = (TH1F*)infile->Get(histParaName); 
 TH1F* histPerp = (TH1F*)infile->Get(histPerpName); 

std::ofstream textfile;
textfile.open("EnhancementsDataPara.txt",std::ios_base::app);
//textfile.open("EnhancementsDataPerp.txt",std::ios_base::app);



cout <<"BinNumber  " << "XbinCentre  " << "YBinCentre" <<"  BinContent" <<endl;
textfile <<"#BinNumber  " << "#XbinCentre   "  <<"   #BinContent" <<endl;
for(Int_t i=0; i<300; i++){


Double_t binCentreX = histPara->GetXaxis()->GetBinCenter(i);
//Double_t binCentreY = histPara->GetYaxis()->GetBinCenter(i);
Double_t binContent = histPara->GetBinContent(i);

/*
Double_t binCentreX = histPerp->GetXaxis()->GetBinCenter(i);
//Double_t binCentreY = histPara->GetYaxis()->GetBinCenter(i);
Double_t binContent = histPerp->GetBinContent(i);
*/

cout <<i << "          "<< binCentreX << "          "<<binContent<< endl;
textfile<<i << "          "<< binCentreX << "          "<<binContent<<endl ;



}

 // ofile->Close();
} //closing main function
	

