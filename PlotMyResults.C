#include <stdlib.h>


void PlotMyResults() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ChrisResultsTemp.root","recreate");
  
  vector<Double_t> VecSimonSigma;
  vector<TString> VecChrisType;
  vector<Double_t> VecSimonCosth;
  vector<Double_t> VecSimonEg;
  vector<Double_t> VecAllSimonSigma;
  vector<Double_t> VecAllSimonEg;
  vector<Double_t> VecAllSimonCosth;
  vector<TString> VecAllChrisType;
  Double_t AllSimonSigma;
  Double_t AllSimonEg;
  Double_t AllSimonCosth;
  TString AllChrisType;


	
  //read in simons results from text file
  std::ifstream inputFile("MyResults.txt");
  std::string line;


  if (inputFile.is_open()){
    while(getline(inputFile, line) ){
      stringstream(line)>>AllSimonSigma >>AllSimonEg >> AllSimonCosth>> AllChrisType;
      VecAllSimonSigma.push_back(AllSimonSigma);
      VecAllSimonEg.push_back(AllSimonEg);
      VecAllSimonCosth.push_back(AllSimonCosth);
      VecAllChrisType.push_back(AllChrisType);
    }
  }


Double_t ArrSigma[20];
Double_t ArrCosth[20];
Double_t ArrEg[20];
TString ArrType[20];



for(Int_t i=0;i<123;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
	VecSimonSigma.clear();
	VecSimonCosth.clear();
	VecChrisType.clear();
	VecSimonEg.clear();
	for(Int_t j=0;j<20;j++){
	VecSimonSigma.push_back(VecAllSimonSigma[j+i*20]);
	VecSimonCosth.push_back(VecAllSimonCosth[j+i*20]);
	VecChrisType.push_back(VecAllChrisType[j+i*20]);
	VecSimonEg.push_back(VecAllSimonEg[j+i*20]);


	ArrSigma[j] = VecAllSimonSigma[j+i*20];
	ArrCosth[j] = VecAllSimonCosth[j+i*20];
	ArrEg[j] = VecAllSimonEg[j+i*20];
	ArrType[j] = VecAllChrisType[j+i*20];

//	cout << VecAllSimonSigma[j+i*20] << "  " << VecAllSimonCosth[j+i*20] <<"  " << VecAllChrisType[j+i*20] <<"    " << VecAllSimonEg[j+i*20]<<endl;
}
	
//	cout << "YODA= " << VecSimonEg[0]<< endl;

TString PosTitle =Form("%f",ArrEg[0]) ;
TString PosName = Form("%f",ArrEg[0]) ;


//	TGraph* SigmaPlot=new TGraph(20,VecSimonCosth,VecSimonSigma);
	TGraph* SigmaPlot=new TGraph(20,ArrCosth,ArrSigma);
TString hTitle ="Sigma"+ArrType[0]+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+ArrType[0]+PosName; // +VecChrisType[i*20] + (TString)i ;


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
	

