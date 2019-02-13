#include <stdlib.h>


void PlotComparisonCosth() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ChrisResultsNPi0ErrsCosth.root","recreate");
  
//  vector<Double_t> VecChrisSigma;
//  vector<TString> VecChrisType;
//  vector<Double_t> VecChrisCosth;
//  vector<Double_t> VecChrisEg;
  vector<Double_t> VecAllChrisSigma;
  vector<Double_t> VecAllChrisEg;
  vector<Double_t> VecAllChrisCosth;
  vector<TString> VecAllChrisType;

  vector<Double_t> VecAllChrisSigmaErr;
  vector<Double_t> VecAllChrisEgErr;
  vector<Double_t> VecAllChrisCosthErr;



  Double_t AllChrisSigma;
  Double_t AllChrisEg;
  Double_t AllChrisCosth;
  TString AllChrisType;
  Double_t AllChrisSigmaErr;
  Double_t AllChrisEgErr;
  Double_t AllChrisCosthErr;
	
  //read in simons results from text file
  std::ifstream inputFile("MyResultsNew.txt");
  std::string line;


  if (inputFile.is_open()){
    while(getline(inputFile, line) ){
      stringstream(line)>>AllChrisSigma>>AllChrisSigmaErr >>AllChrisEg>>AllChrisEgErr >> AllChrisCosth>>AllChrisCosthErr>> AllChrisType;
      VecAllChrisSigma.push_back(AllChrisSigma);
      VecAllChrisEg.push_back(AllChrisEg);
      VecAllChrisCosth.push_back(AllChrisCosth);
      VecAllChrisType.push_back(AllChrisType);

      VecAllChrisSigmaErr.push_back(AllChrisSigmaErr);
      VecAllChrisEgErr.push_back(AllChrisEgErr);
      VecAllChrisCosthErr.push_back(AllChrisCosthErr);
    }
  }

Double_t ArrSigma[41];
Double_t ArrCosth[41];
Double_t ArrEg[41];

Double_t ArrSigmaErr[41];
Double_t ArrCosthErr[41];
Double_t ArrEgErr[41];






for(Int_t i=0;i<20;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
	for(Int_t j=0;j<41;j++){

	//MyResults
	ArrSigma[j] = VecAllChrisSigma[j*20+i];
	ArrCosth[j] = VecAllChrisCosth[j*20+i];
	ArrEg[j] = VecAllChrisEg[j*20+i];

	ArrSigmaErr[j] = VecAllChrisSigmaErr[j*20+i];
	ArrCosthErr[j] = VecAllChrisCosthErr[j*20+i];
	ArrEgErr[j] = VecAllChrisEgErr[j*20+i];


}
	
auto c3 = new TCanvas("c3","c3");

TString PosTitle =Form("%f",ArrCosth[0]) ;
TString PosName = Form("%f",ArrCosth[0]) ;

	TGraph* SigmaPlot=new TGraphErrors(41,ArrEg,ArrSigma,ArrEgErr,ArrSigmaErr);



SigmaPlot->SetMarkerStyle(22);


TMultiGraph* mg = new TMultiGraph();
mg->Add(SigmaPlot);


TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;



//  SigmaPlot->Draw("AP*");
  SigmaPlot->SetTitle(hTitle);
  SigmaPlot->SetName(hName);
  SigmaPlot->GetYaxis()->SetTitle("#Sigma");
  SigmaPlot->GetXaxis()->SetTitle("Egamma ");
  SigmaPlot->GetXaxis()->CenterTitle();
//  SigmaPlot->Write();

mg->SetName(hName);
//mg->SetTitle("SomeTitle ; #Sigma; Cos#theta_{CM}");
mg->SetTitle(hTitle+";Egamma;#Sigma");
//mg->GetYaxis()->SetTitle("#Sigma");
//mg->GetXaxis()->SetTitle("Cos#theta_{CM} ");
//mg->GetXaxis()->CenterTitle();
mg->Draw("AP");
TLegend* leg = c3->BuildLegend();


mg->Write();
leg->Write();//Sort the writing of the legend later


}
outfile->Close();
} //closing main function
	

