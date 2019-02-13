#include <stdlib.h>


  TFile* infileParaPerp = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0LinPolNonStrictCuts.root");	
  TFile* infileMoeller = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0MoellerLinPolNonStrictCuts.root");	



void LinPolEnhancementForming() { 
  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/EnhancementsBGSUBBEDPPi0LinPolNonStrictCuts.root","recreate");	



 TString histMoellerName ="/SignalTiming/PolStateD0.00_/BeamEnergy_SignalTiming_PolStateD0.00_";
 TString histParaName ="/SignalTiming/PolStateD-0.50_/BeamEnergy_SignalTiming_PolStateD-0.50_";
 TString histPerpName ="/SignalTiming/PolStateD0.50_/BeamEnergy_SignalTiming_PolStateD0.50_"  ;


 TH1F* histMoeller = (TH1F*)infileMoeller->Get(histMoellerName); 
 TH1F* histPara = (TH1F*)infileParaPerp->Get(histParaName); 
 TH1F* histPerp = (TH1F*)infileParaPerp->Get(histPerpName); 

histPara->Divide(histMoeller);
histPerp->Divide(histMoeller);


 histPara->Write();
 histPerp->Write();
 histMoeller->Write();
/*
  string dirs[5] = {"Random","TimeCoinc", "Cut1","SignalTiming","BackgroundTiming"};
				
  TDirectory *weightsDir = infile->GetDirectory(dirs[3].c_str());	//WeightsDir is top lev folder
  TIter	nextPolbinDir(weightsDir->GetListOfKeys());
  TKey 	*polbinKey;
  TDirectory *outWeightsDir = ofile->mkdir(dirs[3].c_str());

      while ((polbinKey=(TKey*)nextPolbinDir())){   //Looping round my polarisation states - +
	TDirectory *polbinDir = weightsDir->GetDirectory(polbinKey->GetName());
	TIter	nextHist(polbinDir->GetListOfKeys());
	TKey	*histKey;
	TDirectory *outPolBinKey = outWeightsDir->mkdir(polbinKey->GetName());
	outPolBinKey->cd();			

	while ((histKey=(TKey*)nextHist())) {
	  //Getting  Signal and bg histo
	  TH1F* hist = (TH1F*) histKey->ReadObj();
	  TString histBgName ="/" + dirs[4] + "/"  + (TString)polbinDir->GetName() + "/" + (TString)histKey->GetName() ;
   	  TH1F* histBg = (TH1F*)infile->Get(histBgName); 
	  //Adding signal and bg histo based on ratio of two windows
	  hist->Add(histBg,-1.0);
//	cout<< histKey->GetName() << " =signal  " <<endl; 
//	cout<< histBgName << " =background  " <<endl; 
	  hist->Write();  //Sort out file name and set up directory structure in outfile

	}  //Closing while hist key		
      }   //Closing while nextPolbin

*/

  ofile->Close();
} //closing main function
	

