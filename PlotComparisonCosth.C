#include <stdlib.h>


void PlotComparisonCosth() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ChrisResultsTempComparisonCosthFixedNewResultsErrs.root","recreate");
  
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


  vector<Double_t> VecAllSimonSigma;
  vector<Double_t> VecAllSimonEg;
  vector<Double_t> VecAllSimonCosth;

  vector<Double_t> VecAllSimonSigmaErr;
  vector<Double_t> VecAllSimonEgErr;
  vector<Double_t> VecAllSimonCosthErr;


  Double_t AllChrisSigma;
  Double_t AllChrisEg;
  Double_t AllChrisCosth;
  TString AllChrisType;
  Double_t AllChrisSigmaErr;
  Double_t AllChrisEgErr;
  Double_t AllChrisCosthErr;
 
  Double_t AllSimonSigma;
  Double_t AllSimonEg;
  Double_t AllSimonCosth;

  Double_t AllSimonSigmaErr;
  Double_t AllSimonEgErr;
  Double_t AllSimonCosthErr;
	
  //read in simons results from text file
  std::ifstream inputFile("CutResultsNew.txt");
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

  std::ifstream inputFile2("NewSimonsResultsMyBins.txt");
  std::string line2;


  if (inputFile2.is_open()){
    while(getline(inputFile2, line2) ){
      stringstream(line2)>>AllSimonSigma>>AllSimonSigmaErr >>AllSimonEg>>AllSimonEgErr >> AllSimonCosth>>AllSimonCosthErr;
      VecAllSimonSigma.push_back(AllSimonSigma);
      VecAllSimonEg.push_back(AllSimonEg);
      VecAllSimonCosth.push_back(AllSimonCosth);
      VecAllSimonSigmaErr.push_back(AllSimonSigmaErr);
      VecAllSimonEgErr.push_back(AllSimonEgErr);
      VecAllSimonCosthErr.push_back(AllSimonCosthErr);
    }
  }

Double_t ArrSigma[11];
Double_t ArrCosth[11];
Double_t ArrEg[11];

Double_t ArrSigmaErr[11];
Double_t ArrCosthErr[11];
Double_t ArrEgErr[11];


Double_t ArrSigmaSimon[11];
Double_t ArrSigmaDiv[11];
Double_t ArrCosthSimon[11];
Double_t ArrEgSimon[11];

Double_t ArrSigmaSimonErr[11];
//Double_t ArrSigmaDiv[11];
Double_t ArrCosthSimonErr[11];
Double_t ArrEgSimonErr[11];




for(Int_t i=0;i<20;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
	for(Int_t j=0;j<11;j++){

	//MyResults
	ArrSigma[j] = VecAllChrisSigma[j*20+i];
	ArrCosth[j] = VecAllChrisCosth[j*20+i];
	ArrEg[j] = VecAllChrisEg[j*20+i];

	ArrSigmaErr[j] = VecAllChrisSigmaErr[j*20+i];
	ArrCosthErr[j] = VecAllChrisCosthErr[j*20+i];
	ArrEgErr[j] = VecAllChrisEgErr[j*20+i];


	//Simons Results
	ArrSigmaSimon[j] = VecAllSimonSigma[j*20+i];
	ArrCosthSimon[j] = VecAllSimonCosth[j*20+i];
	ArrEgSimon[j] = VecAllSimonEg[j*20+i];

	ArrSigmaSimonErr[j] = VecAllSimonSigmaErr[j*20+i];
	ArrCosthSimonErr[j] = VecAllSimonCosthErr[j*20+i];
	ArrEgSimonErr[j] = VecAllSimonEgErr[j*20+i];

	if(VecAllSimonSigma[j*20+i]!=0){
	ArrSigmaDiv[j] = VecAllChrisSigma[j*20+i]/VecAllSimonSigma[j*20+i]; 

}
	else{

	ArrSigmaDiv[j]=0;

}


}
	
auto c3 = new TCanvas("c3","c3");

TString PosTitle =Form("%f",ArrCosth[0]) ;
TString PosName = Form("%f",ArrCosth[0]) ;


//	TGraph* SigmaPlot=new TGraph(20,VecSimonCosth,VecSimonSigma);
//	TGraph* SigmaPlot=new TGraph(12,ArrCosth,ArrSigma);
//	TGraph* SigmaPlotSimon=new TGraph(12,ArrCosthSimon,ArrSigmaSimon);
//	TGraph* DivisionPlotSimon=new TGraph(12,ArrCosthSimon,ArrSigmaDiv);

//	TGraph* SigmaPlot=new TGraph(11,ArrEg,ArrSigma);
//	TGraph* SigmaPlotSimon=new TGraph(11,ArrEgSimon,ArrSigmaSimon);
//	TGraph* DivisionPlotSimon=new TGraph(11,ArrEgSimon,ArrSigmaDiv);

	TGraph* SigmaPlot=new TGraphErrors(11,ArrEg,ArrSigma,ArrEgErr,ArrSigmaErr);
	TGraph* SigmaPlotSimon=new TGraphErrors(11,ArrEgSimon,ArrSigmaSimon,ArrEgSimonErr,ArrSigmaSimonErr);
	TGraph* DivisionPlotSimon=new TGraph(11,ArrEgSimon,ArrSigmaDiv);


SigmaPlotSimon->SetMarkerStyle(21);
SigmaPlotSimon->SetMarkerColor(2);

DivisionPlotSimon->SetMarkerStyle(23);
DivisionPlotSimon->SetMarkerColor(4);

SigmaPlot->SetMarkerStyle(22);


TMultiGraph* mg = new TMultiGraph();
mg->Add(SigmaPlot);
mg->Add(SigmaPlotSimon);
//mg->Add(DivisionPlotSimon);


TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;


  SigmaPlotSimon->SetTitle(hTitle+"Simon");
  SigmaPlotSimon->SetName(hName+"Simon");

  DivisionPlotSimon->SetTitle(hTitle+"Divi");
  DivisionPlotSimon->SetName(hName+"Divi");

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
DivisionPlotSimon->Write();


}
outfile->Close();
} //closing main function
	

