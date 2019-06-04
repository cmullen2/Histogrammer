#include <stdlib.h>


void PlotComparisonThesisResultsCosth() {
		
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr252019/OnePlotResultsNPi0WithProtonCorrectedFittedUnbinVTheoryOnlyMay29.root","recreate");
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr252019/OnePlotResultsNPi0WithProtonCorrectedFittedUnbinVTheoryOnlyMay29REMOVEDFITFAILEDFirstAndLastBinsVersion2Between2and-2WithIgorNewResultsCosthBins.root","recreate");
 
  TCanvas *Canvas1 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",0,0,1600,2000);
Canvas1->SetGrid();
  Canvas1->SetCanvasSize(1600,2000);
  Canvas1->SetWindowSize(1600,2000);
//  Canvas1->Divide(3,4,0,0,0);
  Canvas1->Divide(5,4,0,0,0); //For doing 410To710

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


//SAID with more bins
  vector<Double_t> VecAllChrisSigmaSAIDMBIgor;
  vector<Double_t> VecAllChrisEgSAIDMBIgor;
  vector<Double_t> VecAllChrisCosthSAIDMBIgor;
  vector<TString> VecAllChrisTypeSAIDMBIgor;
  vector<Double_t> VecAllChrisSigmaErrSAIDMBIgor;
  vector<Double_t> VecAllChrisEgErrSAIDMBIgor;
  vector<Double_t> VecAllChrisCosthErrSAIDMBIgor;


// Unbinned fit results 
  vector<Double_t> VecAllChrisSigmaUnBin;
  vector<Double_t> VecAllChrisEgUnBin;
  vector<Double_t> VecAllChrisCosthUnBin;
//  vector<TString> VecAllChrisTypeUnBin;
  vector<Double_t> VecAllChrisSigmaErrUnBin;
  vector<Double_t> VecAllChrisEgErrUnBin;
  vector<Double_t> VecAllChrisCosthErrUnBin;

	//StrictCuts DariaPhi 
  vector<Double_t> VecAllChrisSigmaStrictDar;
  vector<Double_t> VecAllChrisEgStrictDar;
  vector<Double_t> VecAllChrisCosthStrictDar;
  vector<TString> VecAllChrisTypeStrictDar;
  vector<Double_t> VecAllChrisSigmaErrStrictDar;
  vector<Double_t> VecAllChrisEgErrStrictDar;
  vector<Double_t> VecAllChrisCosthErrStrictDar;

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

//SAID More bins
  Double_t AllChrisSigmaSAIDMBIgor;
  Double_t AllChrisEgSAIDMBIgor;
  Double_t AllChrisCosthSAIDMBIgor;
  TString AllChrisTypeSAIDMBIgor;
  Double_t AllChrisSigmaErrSAIDMBIgor;
  Double_t AllChrisEgErrSAIDMBIgor;
  Double_t AllChrisCosthErrSAIDMBIgor;

	//My UnBinned Results
  Double_t AllChrisSigmaUnBin;
  Double_t AllChrisEgUnBin;
  Double_t AllChrisCosthUnBin;
//  TString AllChrisTypeUnBin;
  Double_t AllChrisSigmaErrUnBin;
  Double_t AllChrisEgErrUnBin;
  Double_t AllChrisCosthErrUnBin;


	//StrictCutsDariaPhiAnalysis
  Double_t AllChrisSigmaStrictDar;
  Double_t AllChrisEgStrictDar;
  Double_t AllChrisCosthStrictDar;
  TString AllChrisTypeStrictDar;
  Double_t AllChrisSigmaErrStrictDar;
  Double_t AllChrisEgErrStrictDar;
  Double_t AllChrisCosthErrStrictDar;

	
  //read in my results from text file
//  std::ifstream inputFile("Data/CutResultsNew.txt");
  std::ifstream inputFile("Data/MyResultsNewCoplanFitsApr11.txt");
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



//  std::ifstream inputFileSAIDMB("NeutronTheoryCurves/SAIDMoreBinsNeutronResults.txt");
  std::ifstream inputFileSAIDMB("NeutronTheoryCurves/SAIDMoreBinsNeutronResultsREMOVED3Bins.txt");
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


  std::ifstream inputFileSAIDMBIgor("SAIDIGOR2019.txt");
  std::string lineSAIDMBIgor;
  if (inputFileSAIDMBIgor.is_open()){
    while(getline(inputFileSAIDMBIgor, lineSAIDMBIgor) ){
      stringstream(lineSAIDMBIgor)>>AllChrisSigmaSAIDMBIgor >>AllChrisSigmaErrSAIDMBIgor>>AllChrisEgSAIDMBIgor>>AllChrisEgErrSAIDMBIgor >> AllChrisCosthSAIDMBIgor>>AllChrisCosthErrSAIDMBIgor>> AllChrisTypeSAIDMBIgor;
      VecAllChrisSigmaSAIDMBIgor.push_back(AllChrisSigmaSAIDMBIgor);
      VecAllChrisEgSAIDMBIgor.push_back(AllChrisEgSAIDMBIgor);
      VecAllChrisCosthSAIDMBIgor.push_back(AllChrisCosthSAIDMBIgor);
      VecAllChrisTypeSAIDMBIgor.push_back(AllChrisTypeSAIDMBIgor);
      VecAllChrisSigmaErrSAIDMBIgor.push_back(AllChrisSigmaErrSAIDMBIgor);
      VecAllChrisEgErrSAIDMBIgor.push_back(AllChrisEgErrSAIDMBIgor);
      VecAllChrisCosthErrSAIDMBIgor.push_back(AllChrisCosthErrSAIDMBIgor);
    }
  }



  //read in my unbinned results from text file
//  std::ifstream inputFileUnBin("Data/CutResultsUnBinnedProtonSigma.txt");
//  std::ifstream inputFileUnBin("Data/Results410To710UnBinnedProtonSigmaMay17th.txt");
//  std::ifstream inputFileUnBin("Data/ProtonCorrectedUnBinResults410To710UnBinnedProtonSigmaMay22nd.txt");
//  std::ifstream inputFileUnBin("Data/ProtonCorrectedByFittingUnBinResults410To710UnBinnedProtonSigmaMay22nd.txt");
//  std::ifstream inputFileUnBin("Data/UnBinApr11CorrectedbyFittingResults.txt");
//  std::ifstream inputFileUnBin("Data/UnBinMay23CorrectedbyFittingResults.txt");
//  std::ifstream inputFileUnBin("Data/UnBinMay29CorrectedbyFittingResults.txt");
//  std::ifstream inputFileUnBin("NeutronSigmaResultsMay23rd2019.txt");
  std::ifstream inputFileUnBin("NeutronSigmaResultsMay29th2019.txt");
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


  //read in StrictCutsDariaPhi results from text file
//  std::ifstream inputFileStrictDar("Data/CutResultsNewStrictDariaPhi.txt");
  std::ifstream inputFileStrictDar("Data/MyResultsBGSUBBEDNPi0April25RunFixedSubRatio.txt");
  std::string lineStrictDar;
  if (inputFileStrictDar.is_open()){
    while(getline(inputFileStrictDar, lineStrictDar) ){
      stringstream(lineStrictDar)>>AllChrisSigmaStrictDar >>AllChrisSigmaErrStrictDar>>AllChrisEgStrictDar>>AllChrisEgErrStrictDar >> AllChrisCosthStrictDar>>AllChrisCosthErrStrictDar>> AllChrisTypeStrictDar;
      VecAllChrisSigmaStrictDar.push_back(AllChrisSigmaStrictDar);
      VecAllChrisEgStrictDar.push_back(AllChrisEgStrictDar);
      VecAllChrisCosthStrictDar.push_back(AllChrisCosthStrictDar);
      VecAllChrisTypeStrictDar.push_back(AllChrisTypeStrictDar);
      VecAllChrisSigmaErrStrictDar.push_back(AllChrisSigmaErrStrictDar);
      VecAllChrisEgErrStrictDar.push_back(AllChrisEgErrStrictDar);
      VecAllChrisCosthErrStrictDar.push_back(AllChrisCosthErrStrictDar);
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
Double_t ArrSigmaSAIDMBIgor[41];
Double_t ArrCosthSAIDMBIgor[41];
Double_t ArrEgSAIDMBIgor[41];
Double_t ArrSigmaErrSAIDMBIgor[41];
Double_t ArrCosthErrSAIDMBIgor[41];
Double_t ArrEgErrSAIDMBIgor[41];


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


//StrictCuts DariaPhi
Double_t ArrSigmaStrictDar[20];
Double_t ArrCosthStrictDar[20];
Double_t ArrEgStrictDar[20];
Double_t ArrSigmaErrStrictDar[20];
Double_t ArrCosthErrStrictDar[20];
Double_t ArrEgErrStrictDar[20];


//for(Int_t i=0;i<24;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
//for(Int_t i=0;i<18;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
	for(Int_t i=0;i<20;i++){
		for(Int_t j=0;j<18;j++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3



	//MyResults
	ArrSigma[j] = VecAllChrisSigma[j*20+i];
	ArrCosth[j] = VecAllChrisCosth[j*20+i];
	ArrEg[j] = VecAllChrisEg[j*20+i];
	ArrSigmaErr[j] = VecAllChrisSigmaErr[j*20+i];
	ArrCosthErr[j] = VecAllChrisCosthErr[j*20+i];
	ArrEgErr[j] = VecAllChrisEgErr[j*20+i];

	//MyUnBinnedResults
	ArrSigmaUnBin[j] = VecAllChrisSigmaUnBin[j*20+i];
	ArrCosthUnBin[j] = VecAllChrisCosthUnBin[j*20+i];
	ArrEgUnBin[j] = VecAllChrisEgUnBin[j*20+i];
	ArrSigmaErrUnBin[j] = VecAllChrisSigmaErrUnBin[j*20+i];
	ArrCosthErrUnBin[j] = VecAllChrisCosthErrUnBin[j*20+i];
	ArrEgErrUnBin[j] = VecAllChrisEgErrUnBin[j*20+i];


	//Strict CutsDariaPhi
	ArrSigmaStrictDar[j] = VecAllChrisSigmaStrictDar[j*20+i];
	ArrCosthStrictDar[j] = VecAllChrisCosthStrictDar[j*20+i];
	ArrEgStrictDar[j] = VecAllChrisEgStrictDar[j*20+i];
	ArrSigmaErrStrictDar[j] = VecAllChrisSigmaErrStrictDar[j*20+i];
	ArrCosthErrStrictDar[j] = VecAllChrisCosthErrStrictDar[j*20+i];
	ArrEgErrStrictDar[j] = VecAllChrisEgErrStrictDar[j*20+i];




}

// 		(j*41 + i)+1 = 1,42,83 so fine for i=0. i=1 gives 2,43,84, i=20 gives 21,62,103 instead want 40,80,100 want 3,44,85 for i=1
//		so want 1,3,5,7,9 etc. for j=0  so j*41 + i*2 +1
//			i=0	1	tick			1
//			i=1	2	cross need 3 i*2	3
//1			i=2	3	i*2			5
//			i=3	4				7

//for(Int_t j=0;j<41;j++){     0*41 +0 41, 41+0, 82+0, etc. all 0.95, 2,42,83 etc. want to access 1,42,83 so j*41 gives 0,41,82 for j=0, 
for(Int_t j=0;j<18;j++){
	//SAIDMBs
	ArrSigmaSAIDMB[j] = VecAllChrisSigmaSAIDMB[j*41+i*2 +1];
	ArrCosthSAIDMB[j] = VecAllChrisCosthSAIDMB[j*41+i*2 +1];
	ArrEgSAIDMB[j] = VecAllChrisEgSAIDMB[j*41+i*2 +1];
	ArrSigmaErrSAIDMB[j] = VecAllChrisSigmaErrSAIDMB[j*41+i*2 +1];
	ArrCosthErrSAIDMB[j] = VecAllChrisCosthErrSAIDMB[j*41+i*2 +1];
	ArrEgErrSAIDMB[j] = VecAllChrisEgErrSAIDMB[j*41+i*2 +1];


	//SAIDMBs
	ArrSigmaSAIDMBIgor[j] = VecAllChrisSigmaSAIDMBIgor[j*41+i*2 +1];
	ArrCosthSAIDMBIgor[j] = VecAllChrisCosthSAIDMBIgor[j*41+i*2 +1];
	ArrEgSAIDMBIgor[j] = VecAllChrisEgSAIDMBIgor[j*41+i*2 +1];
	ArrSigmaErrSAIDMBIgor[j] = VecAllChrisSigmaErrSAIDMBIgor[j*41+i*2 +1];
	ArrCosthErrSAIDMBIgor[j] = VecAllChrisCosthErrSAIDMBIgor[j*41+i*2 +1];
	ArrEgErrSAIDMBIgor[j] = VecAllChrisEgErrSAIDMBIgor[j*41+i*2 +1];


}






//Canvas1->SetGridY();
    Canvas1->cd(i+1);
Canvas1->SetGrid();

TString PosTitle =Form("%f",ArrCosthUnBin[0]) ;
TString PosName = Form("%f",ArrCosthUnBin[0]) ;

/*
	TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
	TGraph* SigmaPlotSAIDMB=new TGraphErrors(40,ArrCosthSAIDMB,ArrSigmaSAIDMB,ArrCosthErrSAIDMB,ArrSigmaErrSAIDMB);
	TGraph* SigmaPlotSAIDMBIgor=new TGraphErrors(40,ArrCosthSAIDMBIgor,ArrSigmaSAIDMBIgor,ArrCosthErrSAIDMBIgor,ArrSigmaErrSAIDMBIgor);
	TGraph* SigmaPlotUnBin=new TGraphErrors(20,ArrCosthUnBin,ArrSigmaUnBin,ArrCosthErrUnBin,ArrSigmaErrUnBin);
	TGraph* SigmaPlotStrictDar=new TGraphErrors(20,ArrCosthStrictDar,ArrSigmaStrictDar,ArrCosthErrStrictDar,ArrSigmaErrStrictDar);
*/

	TGraph* SigmaPlot=new TGraphErrors(18,ArrEg,ArrSigma,ArrEgErr,ArrSigmaErr);
	TGraph* SigmaPlotSAIDMB=new TGraphErrors(18,ArrEgSAIDMB,ArrSigmaSAIDMB,ArrEgErrSAIDMB,ArrSigmaErrSAIDMBIgor);
	TGraph* SigmaPlotSAIDMBIgor=new TGraphErrors(18,ArrEgSAIDMBIgor,ArrSigmaSAIDMBIgor,ArrCosthErrSAIDMBIgor,ArrSigmaErrSAIDMBIgor);
	TGraph* SigmaPlotUnBin=new TGraphErrors(18,ArrEgUnBin,ArrSigmaUnBin,ArrEgErrUnBin,ArrSigmaErrUnBin);
	TGraph* SigmaPlotStrictDar=new TGraphErrors(18,ArrEgStrictDar,ArrSigmaStrictDar,ArrEgErrStrictDar,ArrSigmaErrStrictDar);


SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotSAIDMB->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotSAIDMBIgor->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotUnBin->SetMarkerStyle(29);//Filled triangle(black(default)
SigmaPlotStrictDar->SetMarkerStyle(22);//triangle(blue)



//1=black 2=red 3 = green 4=blue 5 =yellow 6 = pink 7=cyan
//used black red cyan pink new
SigmaPlotSAIDMB->SetMarkerColor(2);//(red)
SigmaPlotSAIDMBIgor->SetMarkerColor(1);//(red)
SigmaPlotUnBin->SetMarkerColor(4);//(blue)
SigmaPlotStrictDar->SetMarkerColor(6);// pink


SigmaPlotSAIDMB->SetFillStyle(0);
SigmaPlotSAIDMB->SetFillColor(0);
SigmaPlotSAIDMBIgor->SetFillStyle(0);
SigmaPlotSAIDMBIgor->SetFillColor(0);
SigmaPlotUnBin->SetFillStyle(0);
SigmaPlotUnBin->SetFillColor(0);
SigmaPlotStrictDar->SetFillStyle(0);// pink
SigmaPlotStrictDar->SetFillColor(0);// pink
SigmaPlot->SetFillStyle(0);//pink
SigmaPlot->SetFillColor(0);//pink


//SigmaPlotUnBin->SetTitle("UnBinnedFit");
SigmaPlotSAIDMB->SetTitle("SAIDMB");
SigmaPlotSAIDMBIgor->SetTitle("SAIDMBIgor");
//SigmaPlotUnBin->SetTitle("UnBinnedFitMay17th");
SigmaPlotUnBin->SetTitle("UnBinnedFitCorrectedByFittingMay29th");
//SigmaPlotStrictDar->SetTitle("StrictDar");// pink
//SigmaPlotStrictDar->SetTitle("StrictCuts");// pink
SigmaPlotStrictDar->SetTitle("CutsN10To10");// pink
SigmaPlot->SetTitle("CoplanFitsApr2019");//pink



TMultiGraph* mg = new TMultiGraph();
mg->SetMaximum(1);
mg->SetMinimum(-0.1);
//mg->Add(SigmaPlot);
mg->Add(SigmaPlotSAIDMB);
mg->Add(SigmaPlotSAIDMBIgor);
mg->Add(SigmaPlotUnBin);
//mg->Add(SigmaPlotStrictDar);






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
//c3->Write();

}
Canvas1->Write();
outfile->Close();
} //closing main function
	

