#include <stdlib.h>




void MakeSigmaGraph(vector<Double_t> sigma, vector<Double_t> error, vector<Double_t> plotVar, vector<Double_t> plotVarError, Int_t numBins, TString hTitle, TString hName);
void MakeSigmaGraph(vector<Double_t> sigma, vector<Double_t> error, vector<Double_t> plotVar, vector<Double_t> plotVarError, Int_t numBins, TString hTitle, TString hName, vector<Double_t> prevResultsSigma );

void PlotSimon() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/SimonsResults.root","recreate");
  
  vector<Double_t> VecSimonSigma;
  vector<Double_t> VecSimonCosth;
  vector<Double_t> VecSimonEg;
  vector<Double_t> VecAllSimonSigma;
  vector<Double_t> VecAllSimonEg;
  vector<Double_t> VecAllSimonCosth;
  Double_t AllSimonSigma;
  Double_t AllSimonEg;
  Double_t AllSimonCosth;


	
  //read in simons results from text file
  std::ifstream inputFile("SimonsResultsMyBins.txt");
  std::string line;


  if (inputFile.is_open()){
    while(getline(inputFile, line) ){
      stringstream(line)>>AllSimonSigma >>AllSimonEg >> AllSimonCosth;
      VecAllSimonSigma.push_back(AllSimonSigma);
      VecAllSimonEg.push_back(AllSimonEg);
      VecAllSimonCosth.push_back(AllSimonCosth);
    }
  }



for(Int_t i=0;i<11;i++){
	VecSimonSigma.clear();
	VecSimonCosth.clear();
	for(Int_t j=0;j<20;j++){
	VecSimonSigma.push_back(VecAllSimonSigma[j+i*20]);
	VecSimonCosth.push_back(VecAllSimonCosth[j+i*20]);
	cout << VecAllSimonSigma[j+i*20] << "  " << VecAllSimonCosth[j+i*20] << endl;
}
	
	TGraph* SigmaPlot=new TGraph(20,&VecSimonCosth[0],&VecSimonSigma[0]);

TString hTitle ="Sigma" +(TString) i ;
TString hName="Sigma" + (TString)i ;


  SigmaPlot->Draw("AP*");
  SigmaPlot->SetTitle(hTitle);
  SigmaPlot->SetName(hName);
  SigmaPlot->GetYaxis()->SetTitle("#Sigma");
  SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
  SigmaPlot->GetXaxis()->CenterTitle();
  SigmaPlot->Write();
}
outfile->Close();
} //closing main function
	

void MakeSigmaGraph(vector<Double_t> sigma, vector<Double_t> error, vector<Double_t> plotVar, vector<Double_t> plotVarError, Int_t numBins, TString hTitle,TString hName, vector<Double_t> prevResultsSigma){

  TGraph* SigmaPlot = new TGraphErrors(numBins,&(plotVar[0]),&(sigma[0]),&(plotVarError[0]),&(error[0])); 
  TGraph* SigmaSimonPlot = new TGraphErrors(numBins,&(plotVar[0]),&(prevResultsSigma[0]),&(plotVarError[0]),&(error[0])); 

  TCanvas *c2 = new TCanvas("c2","YADASDASDSADASDAS", 700,500);


  for(Int_t ccc=0; ccc<20;ccc++){
    cout << "SIMONS SIGMAS   " << prevResultsSigma[ccc]<< endl;
  }



  SigmaPlot->Draw("AP");
  SigmaPlot->SetTitle(hTitle);
  SigmaPlot->SetName(hName);
  SigmaPlot->GetYaxis()->SetTitle("#Sigma");
  SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
  SigmaPlot->GetXaxis()->CenterTitle();


  TString hTitle2 = hTitle + Form("Simon");
  TString hName2 = hName + Form("Simon");

  SigmaSimonPlot->Draw("same");
  SigmaSimonPlot->SetTitle(hTitle2);
  SigmaSimonPlot->SetName(hName2);
  SigmaSimonPlot->GetYaxis()->SetTitle("#Sigma");
  SigmaSimonPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
  SigmaSimonPlot->GetXaxis()->CenterTitle();

  c2->Modified();
  c2->Update();

  SigmaPlot->Write();
  SigmaSimonPlot->Write();
}


void MakeSigmaGraph(vector<Double_t> sigma, vector<Double_t> error, vector<Double_t> plotVar, vector<Double_t> plotVarError, Int_t numBins, TString hTitle,TString hName){

  TGraph* SigmaPlot = new TGraphErrors(numBins,&(plotVar[0]),&(sigma[0]),&(plotVarError[0]),&(error[0])); 
  SigmaPlot->Draw("AP");
  SigmaPlot->SetTitle(hTitle);
  SigmaPlot->SetName(hName);
  SigmaPlot->GetYaxis()->SetTitle("#Sigma");
  SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
  SigmaPlot->GetXaxis()->CenterTitle();

  SigmaPlot->Write();
}

