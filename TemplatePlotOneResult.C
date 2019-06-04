#include <stdlib.h>


void TemplatePlotOneResult() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/PPi0PlotOnlyOneResultMay23rd.root","recreate");
 /*
  TCanvas *Canvas1 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",0,0,1600,2000);
  Canvas1->SetCanvasSize(1600,2000);
  Canvas1->SetWindowSize(1600,2000);
//  Canvas1->Divide(3,4,0,0,0);
  Canvas1->Divide(6,4,0,0,0); //For doing 410To710
*/
  vector<Double_t> VecAllChrisSigma;
  vector<Double_t> VecAllChrisEg;
  vector<Double_t> VecAllChrisCosth;
  vector<TString> VecAllChrisType;
  vector<Double_t> VecAllChrisSigmaErr;
  vector<Double_t> VecAllChrisEgErr;
  vector<Double_t> VecAllChrisCosthErr;

//SAID with more bins
  vector<Double_t> VecAllChrisSigmaSAIDMB;
  vector<Double_t> VecAllChrisEgSAIDMB;
  vector<Double_t> VecAllChrisCosthSAIDMB;
  vector<TString> VecAllChrisTypeSAIDMB;
  vector<Double_t> VecAllChrisSigmaErrSAIDMB;
  vector<Double_t> VecAllChrisEgErrSAIDMB;
  vector<Double_t> VecAllChrisCosthErrSAIDMB;

// Unbinned fit results 
  vector<Double_t> VecAllChrisSigmaUnBin;
  vector<Double_t> VecAllChrisEgUnBin;
  vector<Double_t> VecAllChrisCosthUnBin;
//  vector<TString> VecAllChrisTypeUnBin;
  vector<Double_t> VecAllChrisSigmaErrUnBin;
  vector<Double_t> VecAllChrisEgErrUnBin;
  vector<Double_t> VecAllChrisCosthErrUnBin;


	//My Results
  Double_t AllChrisSigma;
  Double_t AllChrisEg;
  Double_t AllChrisCosth;
  TString AllChrisType;
  Double_t AllChrisSigmaErr;
  Double_t AllChrisEgErr;
  Double_t AllChrisCosthErr;

//SAID More bins
  Double_t AllChrisSigmaSAIDMB;
  Double_t AllChrisEgSAIDMB;
  Double_t AllChrisCosthSAIDMB;
  TString AllChrisTypeSAIDMB;
  Double_t AllChrisSigmaErrSAIDMB;
  Double_t AllChrisEgErrSAIDMB;
  Double_t AllChrisCosthErrSAIDMB;

	//My UnBinned Results
  Double_t AllChrisSigmaUnBin;
  Double_t AllChrisEgUnBin;
  Double_t AllChrisCosthUnBin;
//  TString AllChrisTypeUnBin;
  Double_t AllChrisSigmaErrUnBin;
  Double_t AllChrisEgErrUnBin;
  Double_t AllChrisCosthErrUnBin;
	
  //read in my results from text file
//  std::ifstream inputFile("Data/CutResultsNew.txt");
  std::ifstream inputFile("Data/Results410To710NewCoplanFitsApr2019.txt");
  std::string line;
  if (inputFile.is_open()){
    while(getline(inputFile, line) ){
      stringstream(line)>>AllChrisSigma >>AllChrisSigmaErr>>AllChrisEg>>AllChrisEgErr >> AllChrisCosth>>AllChrisCosthErr>> AllChrisType;
      VecAllChrisSigma.push_back(AllChrisSigma);
      VecAllChrisEg.push_back(AllChrisEg);
      VecAllChrisCosth.push_back(AllChrisCosth);
      VecAllChrisType.push_back(AllChrisType);
      VecAllChrisSigmaErr.push_back(AllChrisSigmaErr);
      VecAllChrisEgErr.push_back(AllChrisEgErr);
      VecAllChrisCosthErr.push_back(AllChrisCosthErr);
    }
  }
  std::ifstream inputFileSAIDMB("ProtonTheoryCurves/SAIDMoreBinsProtonResults.txt");
  std::string lineSAIDMB;
  if (inputFileSAIDMB.is_open()){
    while(getline(inputFileSAIDMB, lineSAIDMB) ){
      stringstream(lineSAIDMB)>>AllChrisSigmaSAIDMB >>AllChrisSigmaErrSAIDMB>>AllChrisEgSAIDMB>>AllChrisEgErrSAIDMB >> AllChrisCosthSAIDMB>>AllChrisCosthErrSAIDMB>> AllChrisTypeSAIDMB;
      VecAllChrisSigmaSAIDMB.push_back(AllChrisSigmaSAIDMB);
      VecAllChrisEgSAIDMB.push_back(AllChrisEgSAIDMB);
      VecAllChrisCosthSAIDMB.push_back(AllChrisCosthSAIDMB);
      VecAllChrisTypeSAIDMB.push_back(AllChrisTypeSAIDMB);
      VecAllChrisSigmaErrSAIDMB.push_back(AllChrisSigmaErrSAIDMB);
      VecAllChrisEgErrSAIDMB.push_back(AllChrisEgErrSAIDMB);
      VecAllChrisCosthErrSAIDMB.push_back(AllChrisCosthErrSAIDMB);
    }
  }
  //read in my unbinned results from text file
//  std::ifstream inputFileUnBin("Data/CutResultsUnBinnedProtonSigma.txt");
//  std::ifstream inputFileUnBin("Data/Results410To710UnBinnedProtonSigmaMay17th.txt");
//  std::ifstream inputFileUnBin("Data/ProtonCorrectedUnBinResults410To710UnBinnedProtonSigmaMay22nd.txt");
//  std::ifstream inputFileUnBin("Data/ProtonCorrectedByFittingUnBinResults410To710UnBinnedProtonSigmaMay22nd.txt");
//  std::ifstream inputFileUnBin("Data/UnBinApr11CorrectedbyFittingResults.txt");
  std::ifstream inputFileUnBin("Data/ProtonCorrectedByFittingUnBinResults410To710UnBinnedProtonSigmaMay22nd.txt");
  std::string lineUnBin;
  if (inputFileUnBin.is_open()){
    while(getline(inputFileUnBin, lineUnBin) ){
      stringstream(lineUnBin)>>AllChrisSigmaUnBin >>AllChrisSigmaErrUnBin>>AllChrisEgUnBin>>AllChrisEgErrUnBin >> AllChrisCosthUnBin>>AllChrisCosthErrUnBin; //>> AllChrisTypeUnBin;
      VecAllChrisSigmaUnBin.push_back(AllChrisSigmaUnBin);
      VecAllChrisEgUnBin.push_back(AllChrisEgUnBin);
      VecAllChrisCosthUnBin.push_back(AllChrisCosthUnBin);
//      VecAllChrisTypeUnBin.push_back(AllChrisTypeUnBin);
      VecAllChrisSigmaErrUnBin.push_back(AllChrisSigmaErrUnBin);
      VecAllChrisEgErrUnBin.push_back(AllChrisEgErrUnBin);
      VecAllChrisCosthErrUnBin.push_back(AllChrisCosthErrUnBin);
    }
  }

	//My Results
Double_t ArrSigma[20];
Double_t ArrCosth[20];
Double_t ArrEg[20];
Double_t ArrSigmaErr[20];
Double_t ArrCosthErr[20];
Double_t ArrEgErr[20];

//SAIDMBs
Double_t ArrSigmaSAIDMB[41];
Double_t ArrCosthSAIDMB[41];
Double_t ArrEgSAIDMB[41];
Double_t ArrSigmaErrSAIDMB[41];
Double_t ArrCosthErrSAIDMB[41];
Double_t ArrEgErrSAIDMB[41];

	//My UnBinned Results
Double_t ArrSigmaUnBin[20];
Double_t ArrCosthUnBin[20];
Double_t ArrEgUnBin[20];
Double_t ArrSigmaErrUnBin[20];
Double_t ArrCosthErrUnBin[20];
Double_t ArrEgErrUnBin[20];

for(Int_t i=0;i<16;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
	for(Int_t j=0;j<20;j++){
	//MyResults
	ArrSigma[j] = VecAllChrisSigma[j+i*20];
	ArrCosth[j] = VecAllChrisCosth[j+i*20];
	ArrEg[j] = VecAllChrisEg[j+i*20];
	ArrSigmaErr[j] = VecAllChrisSigmaErr[j+i*20];
	ArrCosthErr[j] = VecAllChrisCosthErr[j+i*20];
	ArrEgErr[j] = VecAllChrisEgErr[j+i*20];

	//MyUnBinnedResults
	ArrSigmaUnBin[j] = VecAllChrisSigmaUnBin[j+i*20];
	ArrCosthUnBin[j] = VecAllChrisCosthUnBin[j+i*20];
	ArrEgUnBin[j] = VecAllChrisEgUnBin[j+i*20];
	ArrSigmaErrUnBin[j] = VecAllChrisSigmaErrUnBin[j+i*20];
	ArrCosthErrUnBin[j] = VecAllChrisCosthErrUnBin[j+i*20];
	ArrEgErrUnBin[j] = VecAllChrisEgErrUnBin[j+i*20];
}

for(Int_t j=0;j<41;j++){
	//SAIDMBs
	ArrSigmaSAIDMB[j] = VecAllChrisSigmaSAIDMB[j+i*41];
	ArrCosthSAIDMB[j] = VecAllChrisCosthSAIDMB[j+i*41];
	ArrEgSAIDMB[j] = VecAllChrisEgSAIDMB[j+i*41];
	ArrSigmaErrSAIDMB[j] = VecAllChrisSigmaErrSAIDMB[j+i*41];
	ArrCosthErrSAIDMB[j] = VecAllChrisCosthErrSAIDMB[j+i*41];
	ArrEgErrSAIDMB[j] = VecAllChrisEgErrSAIDMB[j+i*41];

}

    auto c3 = new TCanvas("c3","c3");
  //  Canvas1->cd(i+1);

TString PosTitle =Form("%f",ArrEg[0]) ;
TString PosName = Form("%f",ArrEg[0]) ;
	TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
	TGraph* SigmaPlotSAIDMB=new TGraphErrors(40,ArrCosthSAIDMB,ArrSigmaSAIDMB,ArrCosthErrSAIDMB,ArrSigmaErrSAIDMB);
	TGraph* SigmaPlotUnBin=new TGraphErrors(20,ArrCosthUnBin,ArrSigmaUnBin,ArrCosthErrUnBin,ArrSigmaErrUnBin);
SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotSAIDMB->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotUnBin->SetMarkerStyle(29);//Filled triangle(black(default)

//1=black 2=red 3 = green 4=blue 5 =yellow 6 = pink 7=cyan
//used black red cyan pink new
SigmaPlotSAIDMB->SetMarkerColor(2);//(red)
SigmaPlotUnBin->SetMarkerColor(4);//(blue)

SigmaPlotSAIDMB->SetFillStyle(0);
SigmaPlotSAIDMB->SetFillColor(0);
SigmaPlotUnBin->SetFillStyle(0);
SigmaPlotUnBin->SetFillColor(0);
SigmaPlot->SetFillStyle(0);//pink
SigmaPlot->SetFillColor(0);//pink


//SigmaPlotUnBin->SetTitle("UnBinnedFit");
SigmaPlotSAIDMB->SetTitle("SAIDMB");
//SigmaPlotUnBin->SetTitle("UnBinnedFitMay17th");
SigmaPlotUnBin->SetTitle("UnBinnedFitCorrectedByFittingMay22nd");
SigmaPlot->SetTitle("CoplanFitsApr2019");//pink

TMultiGraph* mg = new TMultiGraph();
//mg->SetMaximum(1);
//mg->SetMinimum(0);
//mg->Add(SigmaPlot);
mg->Add(SigmaPlotSAIDMB);
mg->Add(SigmaPlotUnBin);

TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;
  SigmaPlot->GetYaxis()->SetTitle("#Sigma");
  SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
  SigmaPlot->GetXaxis()->CenterTitle();
mg->SetName(hName);
mg->SetTitle(hTitle+";Cos#theta_{CM};#Sigma");
mg->Draw("AP");
TLegend* leg = gPad->BuildLegend();
leg->SetFillStyle(0);

leg->Write();//Sort the writing of the legend later
c3->Write();

}
//Canvas1->Write();
outfile->Close();
} //closing main function
	

