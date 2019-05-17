#include <stdlib.h>

//Read in data from 
void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName );


void PlotComparisonCoplanBinSystematics() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/SigmaPPi0CutsAnalysisCoplanBinsAllVsEachOther.root","recreate");

  vector<Double_t> VecAllChrisSigmaCuts;
  vector<Double_t> VecAllChrisEgCuts;
  vector<Double_t> VecAllChrisCosthCuts;
  vector<TString> VecAllChrisTypeCuts;
  vector<Double_t> VecAllChrisSigmaErrCuts;
  vector<Double_t> VecAllChrisEgErrCuts;
  vector<Double_t> VecAllChrisCosthErrCuts;
  Double_t AllChrisSigmaCuts;
  Double_t AllChrisEgCuts;
  Double_t AllChrisCosthCuts;
  TString AllChrisTypeCuts;
  Double_t AllChrisSigmaErrCuts;
  Double_t AllChrisEgErrCuts;
  Double_t AllChrisCosthErrCuts;
 
  vector<Double_t> VecAllChrisSigmaCutsN10To10;
  vector<Double_t> VecAllChrisEgCutsN10To10;
  vector<Double_t> VecAllChrisCosthCutsN10To10;
  vector<TString> VecAllChrisTypeCutsN10To10;
  vector<Double_t> VecAllChrisSigmaErrCutsN10To10;
  vector<Double_t> VecAllChrisEgErrCutsN10To10;
  vector<Double_t> VecAllChrisCosthErrCutsN10To10;
  Double_t AllChrisSigmaCutsN10To10;
  Double_t AllChrisEgCutsN10To10;
  Double_t AllChrisCosthCutsN10To10;
  TString AllChrisTypeCutsN10To10;
  Double_t AllChrisSigmaErrCutsN10To10;
  Double_t AllChrisEgErrCutsN10To10;
  Double_t AllChrisCosthErrCutsN10To10;

  vector<Double_t> VecAllChrisSigmaCutsN30ToN10;
  vector<Double_t> VecAllChrisEgCutsN30ToN10;
  vector<Double_t> VecAllChrisCosthCutsN30ToN10;
  vector<TString> VecAllChrisTypeCutsN30ToN10;
  vector<Double_t> VecAllChrisSigmaErrCutsN30ToN10;
  vector<Double_t> VecAllChrisEgErrCutsN30ToN10;
  vector<Double_t> VecAllChrisCosthErrCutsN30ToN10;
  Double_t AllChrisSigmaCutsN30ToN10;
  Double_t AllChrisEgCutsN30ToN10;
  Double_t AllChrisCosthCutsN30ToN10;
  TString AllChrisTypeCutsN30ToN10;
  Double_t AllChrisSigmaErrCutsN30ToN10;
  Double_t AllChrisEgErrCutsN30ToN10;
  Double_t AllChrisCosthErrCutsN30ToN10;

  vector<Double_t> VecAllChrisSigmaCuts10To30;
  vector<Double_t> VecAllChrisEgCuts10To30;
  vector<Double_t> VecAllChrisCosthCuts10To30;
  vector<TString> VecAllChrisTypeCuts10To30;
  vector<Double_t> VecAllChrisSigmaErrCuts10To30;
  vector<Double_t> VecAllChrisEgErrCuts10To30;
  vector<Double_t> VecAllChrisCosthErrCuts10To30;
  Double_t AllChrisSigmaCuts10To30;
  Double_t AllChrisEgCuts10To30;
  Double_t AllChrisCosthCuts10To30;
  TString AllChrisTypeCuts10To30;
  Double_t AllChrisSigmaErrCuts10To30;
  Double_t AllChrisEgErrCuts10To30;
  Double_t AllChrisCosthErrCuts10To30;


  vector<Double_t> VecAllChrisSigmaCutsN30ToN10And10To30;
  vector<Double_t> VecAllChrisEgCutsN30ToN10And10To30;
  vector<Double_t> VecAllChrisCosthCutsN30ToN10And10To30;
  vector<TString> VecAllChrisTypeCutsN30ToN10And10To30;
  vector<Double_t> VecAllChrisSigmaErrCutsN30ToN10And10To30;
  vector<Double_t> VecAllChrisEgErrCutsN30ToN10And10To30;
  vector<Double_t> VecAllChrisCosthErrCutsN30ToN10And10To30;
  Double_t AllChrisSigmaCutsN30ToN10And10To30;
  Double_t AllChrisEgCutsN30ToN10And10To30;
  Double_t AllChrisCosthCutsN30ToN10And10To30;
  TString AllChrisTypeCutsN30ToN10And10To30;
  Double_t AllChrisSigmaErrCutsN30ToN10And10To30;
  Double_t AllChrisEgErrCutsN30ToN10And10To30;
  Double_t AllChrisCosthErrCutsN30ToN10And10To30;


  TString InFileCuts = "Data/CutResultsNewBGSUBBEDApril25Run.txt";
  GetSigmaFromFile( VecAllChrisSigmaCuts, VecAllChrisSigmaErrCuts, VecAllChrisEgCuts, VecAllChrisEgErrCuts, VecAllChrisCosthCuts,  VecAllChrisCosthErrCuts,  InFileCuts );

  TString InFileCutsN10To10 = "Data/CutResultsNewBGSUBBEDMay10RunCoplanN10To10.txt";
  GetSigmaFromFile( VecAllChrisSigmaCutsN10To10, VecAllChrisSigmaErrCutsN10To10, VecAllChrisEgCutsN10To10, VecAllChrisEgErrCutsN10To10, VecAllChrisCosthCutsN10To10,  VecAllChrisCosthErrCutsN10To10,  InFileCutsN10To10 );

  TString InFileCutsN30ToN10 = "Data/CutResultsNewBGSUBBEDMay10RunCoplanN30ToN10.txt";
  GetSigmaFromFile( VecAllChrisSigmaCutsN30ToN10, VecAllChrisSigmaErrCutsN30ToN10, VecAllChrisEgCutsN30ToN10, VecAllChrisEgErrCutsN30ToN10, VecAllChrisCosthCutsN30ToN10,  VecAllChrisCosthErrCutsN30ToN10,  InFileCutsN30ToN10 );

  TString InFileCuts10To30 = "Data/CutResultsNewBGSUBBEDMay10RunCoplan10To30.txt";
  GetSigmaFromFile( VecAllChrisSigmaCuts10To30, VecAllChrisSigmaErrCuts10To30, VecAllChrisEgCuts10To30, VecAllChrisEgErrCuts10To30, VecAllChrisCosthCuts10To30,  VecAllChrisCosthErrCuts10To30,  InFileCuts10To30 );

  TString InFileCutsN30ToN10And10To30 = "Data/CutResultsNewBGSUBBEDMay10RunCoplanN30ToN10And10To30.txt";
  GetSigmaFromFile( VecAllChrisSigmaCutsN30ToN10And10To30, VecAllChrisSigmaErrCutsN30ToN10And10To30, VecAllChrisEgCutsN30ToN10And10To30, VecAllChrisEgErrCutsN30ToN10And10To30, VecAllChrisCosthCutsN30ToN10And10To30,  VecAllChrisCosthErrCutsN30ToN10And10To30,  InFileCutsN30ToN10And10To30 );



Double_t ArrSigmaCuts[20];
Double_t ArrCosthCuts[20];
Double_t ArrEgCuts[20];
Double_t ArrSigmaErrCuts[20];
Double_t ArrCosthErrCuts[20];
Double_t ArrEgErrCuts[20];

Double_t ArrSigmaCutsN10To10[20];
Double_t ArrCosthCutsN10To10[20];
Double_t ArrEgCutsN10To10[20];
Double_t ArrSigmaErrCutsN10To10[20];
Double_t ArrCosthErrCutsN10To10[20];
Double_t ArrEgErrCutsN10To10[20];

Double_t ArrSigmaCutsN30ToN10[20];
Double_t ArrCosthCutsN30ToN10[20];
Double_t ArrEgCutsN30ToN10[20];
Double_t ArrSigmaErrCutsN30ToN10[20];
Double_t ArrCosthErrCutsN30ToN10[20];
Double_t ArrEgErrCutsN30ToN10[20];

Double_t ArrSigmaCuts10To30[20];
Double_t ArrCosthCuts10To30[20];
Double_t ArrEgCuts10To30[20];
Double_t ArrSigmaErrCuts10To30[20];
Double_t ArrCosthErrCuts10To30[20];
Double_t ArrEgErrCuts10To30[20];

Double_t ArrSigmaCutsN30ToN10And10To30[20];
Double_t ArrCosthCutsN30ToN10And10To30[20];
Double_t ArrEgCutsN30ToN10And10To30[20];
Double_t ArrSigmaErrCutsN30ToN10And10To30[20];
Double_t ArrCosthErrCutsN30ToN10And10To30[20];
Double_t ArrEgErrCutsN30ToN10And10To30[20];


for(Int_t i=0;i<11;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
	for(Int_t j=0;j<20;j++){

	//MyResults
	ArrSigmaCutsN30ToN10[j] = VecAllChrisSigmaCutsN30ToN10[j+20*i];
	ArrCosthCutsN30ToN10[j] = VecAllChrisCosthCutsN30ToN10[j+20*i];
	ArrEgCutsN30ToN10[j] = VecAllChrisEgCutsN30ToN10[j+20*i];
	ArrSigmaErrCutsN30ToN10[j] = VecAllChrisSigmaErrCutsN30ToN10[j+20*i];
	ArrCosthErrCutsN30ToN10[j] = VecAllChrisCosthErrCutsN30ToN10[j+20*i];
	ArrEgErrCutsN30ToN10[j] = VecAllChrisEgErrCutsN30ToN10[j+20*i];

	//MyResults
	ArrSigmaCutsN10To10[j] = VecAllChrisSigmaCutsN10To10[j+20*i];
	ArrCosthCutsN10To10[j] = VecAllChrisCosthCutsN10To10[j+20*i];
	ArrEgCutsN10To10[j] = VecAllChrisEgCutsN10To10[j+20*i];
	ArrSigmaErrCutsN10To10[j] = VecAllChrisSigmaErrCutsN10To10[j+20*i];
	ArrCosthErrCutsN10To10[j] = VecAllChrisCosthErrCutsN10To10[j+20*i];
	ArrEgErrCutsN10To10[j] = VecAllChrisEgErrCutsN10To10[j+20*i];

	//MyResults
	ArrSigmaCuts[j] = VecAllChrisSigmaCuts[j+20*i];
	ArrCosthCuts[j] = VecAllChrisCosthCuts[j+20*i];
	ArrEgCuts[j] = VecAllChrisEgCuts[j+20*i];
	ArrSigmaErrCuts[j] = VecAllChrisSigmaErrCuts[j+20*i];
	ArrCosthErrCuts[j] = VecAllChrisCosthErrCuts[j+20*i];
	ArrEgErrCuts[j] = VecAllChrisEgErrCuts[j+20*i];


	//MyResults
	ArrSigmaCuts10To30[j] = VecAllChrisSigmaCuts10To30[j+20*i];
	ArrCosthCuts10To30[j] = VecAllChrisCosthCuts10To30[j+20*i];
	ArrEgCuts10To30[j] = VecAllChrisEgCuts10To30[j+20*i];
	ArrSigmaErrCuts10To30[j] = VecAllChrisSigmaErrCuts10To30[j+20*i];
	ArrCosthErrCuts10To30[j] = VecAllChrisCosthErrCuts10To30[j+20*i];
	ArrEgErrCuts10To30[j] = VecAllChrisEgErrCuts10To30[j+20*i];

	//MyResults
	ArrSigmaCutsN30ToN10And10To30[j] = VecAllChrisSigmaCutsN30ToN10And10To30[j+20*i];
	ArrCosthCutsN30ToN10And10To30[j] = VecAllChrisCosthCutsN30ToN10And10To30[j+20*i];
	ArrEgCutsN30ToN10And10To30[j] = VecAllChrisEgCutsN30ToN10And10To30[j+20*i];
	ArrSigmaErrCutsN30ToN10And10To30[j] = VecAllChrisSigmaErrCutsN30ToN10And10To30[j+20*i];
	ArrCosthErrCutsN30ToN10And10To30[j] = VecAllChrisCosthErrCutsN30ToN10And10To30[j+20*i];
	ArrEgErrCutsN30ToN10And10To30[j] = VecAllChrisEgErrCutsN30ToN10And10To30[j+20*i];







}
	
auto c3 = new TCanvas("c3","c3");

TString PosTitle =Form("%f",ArrEgCuts[0]) ;
TString PosName = Form("%f",ArrEgCuts[0]) ;

	TGraph* SigmaPlotCuts=new TGraphErrors(20,ArrCosthCuts,ArrSigmaCuts,ArrCosthErrCuts,ArrSigmaErrCuts);
	TGraph* SigmaPlotCutsN10To10=new TGraphErrors(20,ArrCosthCutsN10To10,ArrSigmaCutsN10To10,ArrCosthErrCutsN10To10,ArrSigmaErrCutsN10To10);
	TGraph* SigmaPlotCutsN30ToN10=new TGraphErrors(20,ArrCosthCutsN30ToN10,ArrSigmaCutsN30ToN10,ArrCosthErrCutsN30ToN10,ArrSigmaErrCutsN30ToN10);
	TGraph* SigmaPlotCuts10To30=new TGraphErrors(20,ArrCosthCuts10To30,ArrSigmaCuts10To30,ArrCosthErrCuts10To30,ArrSigmaErrCuts10To30);
	TGraph* SigmaPlotCutsN30ToN10And10To30=new TGraphErrors(20,ArrCosthCutsN30ToN10And10To30,ArrSigmaCutsN30ToN10And10To30,ArrCosthErrCutsN30ToN10And10To30,ArrSigmaErrCutsN30ToN10And10To30);


    SigmaPlotCuts->SetMarkerStyle(21);  //filled square()
    SigmaPlotCuts->SetMarkerColor(2);  //red
    SigmaPlotCuts->SetFillStyle(0);
    SigmaPlotCuts->SetFillColor(0);
    SigmaPlotCuts->SetTitle("Cuts Analysis Apr25");


    SigmaPlotCutsN10To10->SetMarkerStyle(21);  //filled square()
    SigmaPlotCutsN10To10->SetMarkerColor(3);  //green
    SigmaPlotCutsN10To10->SetFillStyle(0);
    SigmaPlotCutsN10To10->SetFillColor(0);
    SigmaPlotCutsN10To10->SetTitle("Cuts Analysis N10To10");


    SigmaPlotCutsN30ToN10->SetMarkerStyle(21);  //filled square()
    SigmaPlotCutsN30ToN10->SetMarkerColor(4);  //blue
    SigmaPlotCutsN30ToN10->SetFillStyle(0);
    SigmaPlotCutsN30ToN10->SetFillColor(0);
    SigmaPlotCutsN30ToN10->SetTitle("Cuts Analysis N30ToN10");

    SigmaPlotCuts10To30->SetMarkerStyle(21);  //filled square()
    SigmaPlotCuts10To30->SetMarkerColor(7);  //cyan
    SigmaPlotCuts10To30->SetFillStyle(0);
    SigmaPlotCuts10To30->SetFillColor(0);
    SigmaPlotCuts10To30->SetTitle("Cuts Analysis 10To30");

    SigmaPlotCutsN30ToN10And10To30->SetMarkerStyle(21);  //filled square()
    SigmaPlotCutsN30ToN10And10To30->SetMarkerColor(6);  //pink
    SigmaPlotCutsN30ToN10And10To30->SetFillStyle(0);
    SigmaPlotCutsN30ToN10And10To30->SetFillColor(0);
    SigmaPlotCutsN30ToN10And10To30->SetTitle("Cuts Analysis N30ToN10And10To30");


TMultiGraph* mg = new TMultiGraph();
mg->Add(SigmaPlotCuts);
mg->Add(SigmaPlotCutsN10To10);
mg->Add(SigmaPlotCutsN30ToN10);
mg->Add(SigmaPlotCuts10To30);
mg->Add(SigmaPlotCutsN30ToN10And10To30);


TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;

//  SigmaPlot->Draw("AP*");
//  SigmaPlot->SetTitle(hTitle);
//  SigmaPlot->SetName(hName);
  SigmaPlotCuts->GetYaxis()->SetTitle("#Sigma");
  SigmaPlotCuts->GetXaxis()->SetTitle("Egamma ");
  SigmaPlotCuts->GetXaxis()->CenterTitle();
//  SigmaPlot->Write();

mg->SetName(hName);
//mg->SetTitle("SomeTitle ; #Sigma; Cos#theta_{CM}");
mg->SetTitle(hTitle+";Egamma;#Sigma");
//mg->GetYaxis()->SetTitle("#Sigma");
//mg->GetXaxis()->SetTitle("Cos#theta_{CM} ");
//mg->GetXaxis()->CenterTitle();
mg->Draw("AP");
TLegend* leg = c3->BuildLegend();
   leg->SetFillStyle(0);


mg->Write();
leg->Write();//Sort the writing of the legend later
c3->Write();

}
outfile->Close();
} //closing main function
	

void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName ){

  Double_t Sigma;
  Double_t SigmaErr;
  Double_t Eg;
  Double_t EgErr;
  Double_t Costh;
  Double_t CosthErr;

  std::ifstream inputFileSpec(InFileName);
  std::string lineSpec;
  if (inputFileSpec.is_open()){
    while(getline(inputFileSpec, lineSpec) ){
      stringstream(lineSpec)>>Sigma >>SigmaErr>>Eg>>EgErr >> Costh>>CosthErr;
      VecSigma.push_back(Sigma);
      VecEg.push_back(Eg);
      VecCosth.push_back(Costh);
      VecSigmaErr.push_back(SigmaErr);
      VecEgErr.push_back(EgErr);
      VecCosthErr.push_back(CosthErr);

    }
  }
  inputFileSpec.close();


}








