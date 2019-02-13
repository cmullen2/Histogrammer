#include <stdlib.h>
#include <TString.h>

void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName, Double_t IsTheory );

void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);
//void DecodePi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);

void TestOpenFile() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/DELETETest2.root","recreate");
	
Double_t Eg1 =580 ;
Double_t NThetaBins = 20 ;
Double_t ThetaHigh =180 ;
Double_t ThetaLow =0 ;
Double_t NotTheory =0;

GetPi0SAID( Eg1, NThetaBins, ThetaHigh, ThetaLow);





for(Int_t i=0;i<11;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
	for(Int_t j=0;j<20;j++){


	TheoryEgamma= VecAllChrisEg[j+i*20];

}
vector<Double_t> VecSigmaSAID;
vector<Double_t> VecSigmaErrSAID;
vector<Double_t> VecEgSAID;
vector<Double_t> VecEgErrSAID;
vector<Double_t> VecCosthSAID;
vector<Double_t> VecCosthErrSAID;
Double_t IsTheorySAID = 1;
TString InFileNameSAID = "tmp/pageSAID.txt";

	GetPi0SAID( TheoryEgamma,  TheoryThetaBins, TheoryThetaHigh, TheoryThetaLow);
//	DecodePi0SAID();
	GetSigmaFromFile(VecSigmaSAID, VecSigmaErrSAID, VecEgSAID ,VecEgErrSAID , VecCosthSAID , VecCosthErrSAID, InFileNameSAID, IsTheorySAID);

auto c3 = new TCanvas("c3","c3");

TString PosTitle =Form("%f",ArrEg[0]) ;
TString PosName = Form("%f",ArrEg[0]) ;

	TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
	TGraph* SigmaPlotSimon=new TGraphErrors(20,ArrCosthSimon,ArrSigmaSimon,ArrCosthSimonErr,ArrSigmaSimonErr);
	TGraph* DivisionPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaDiv);

		//SpecMom Binned cuts Analysis
	TGraph* SigmaPlotSpec=new TGraphErrors(20,ArrCosthSpec,ArrSigmaSpec,ArrCosthErrSpec,ArrSigmaErrSpec);


SigmaPlotSimon->SetMarkerStyle(21);  //filled square(red)
SigmaPlotSimon->SetMarkerColor(2);  //red

DivisionPlotSimon->SetMarkerStyle(23);//filled upside down triangle(blue)
DivisionPlotSimon->SetMarkerColor(4);//blue

SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)


	//SpecMom binned markers
SigmaPlotSpec->SetMarkerStyle(22);//Filled triangle(black(default)

	//SpecMom binned marker colors
SigmaPlotSpec->SetMarkerColor(2);  //red

//SPec Mom for legend
SigmaPlotSpec->SetFillStyle(0);
SigmaPlotSpec->SetFillColor(0);

//SpecMom Titles
SigmaPlotSpec->SetTitle("SpecMom0-50Mev");



SigmaPlot->SetFillStyle(0);//pink
SigmaPlot->SetFillColor(0);//pink
SigmaPlotSimon->SetFillStyle(0);//pink
SigmaPlotSimon->SetFillColor(0);//pink
DivisionPlotSimon->SetFillStyle(0);//pink
DivisionPlotSimon->SetFillColor(0);//pink


SigmaPlot->SetTitle("CoplanFitsOrig");//pink
SigmaPlotSimon->SetTitle("Simon");//pink
DivisionPlotSimon->SetTitle("Division");//pink



TMultiGraph* mg = new TMultiGraph();
mg->Add(SigmaPlot);
mg->Add(SigmaPlotSimon);
mg->Add(DivisionPlotSimon);

//SpecMom add to multigraph
mg->Add(SigmaPlotSpec);


TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;

//  SigmaPlot->Draw("AP*");
//  SigmaPlot->SetTitle(hTitle);
//  SigmaPlot->SetName(hName);
  SigmaPlot->GetYaxis()->SetTitle("#Sigma");
  SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
  SigmaPlot->GetXaxis()->CenterTitle();
//  SigmaPlot->Write();

mg->SetName(hName);
//mg->SetTitle("SomeTitle ; #Sigma; Cos#theta_{CM}");
mg->SetTitle(hTitle+";Cos#theta_{CM};#Sigma");
//mg->GetYaxis()->SetTitle("#Sigma");
//mg->GetXaxis()->SetTitle("Cos#theta_{CM} ");
//mg->GetXaxis()->CenterTitle();


mg->Draw("AP");
TLegend* leg = c3->BuildLegend();
leg->SetFillStyle(0);

mg->Write();
leg->Write();//Sort the writing of the legend later
DivisionPlotSimon->Write();
c3->Write();

}
outfile->Close();
} //closing main function
	



void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName, Double_t IsTheory ){


  Double_t Sigma;
  Double_t SigmaErr;
  Double_t Eg;
  Double_t EgErr;
  Double_t Costh;
  Double_t CosthErr;
  TString HeaderLines;
cout << "ENTERED FUNCTUION"<< endl;


  std::ifstream inputFileSpec(InFileName);
  std::string lineSpec;
  if (inputFileSpec.is_open()){
    while(getline(inputFileSpec, lineSpec) ){
	if(IsTheory){
		stringstream(lineSpec)>>HeaderLines;
		cout << HeaderLines << endl;

	}
      stringstream(lineSpec)>>Sigma >>SigmaErr>>Eg>>EgErr >> Costh>>CosthErr;
      VecSigma.push_back(Sigma);
      VecEg.push_back(Eg);
      VecCosth.push_back(Costh);
      VecSigmaErr.push_back(SigmaErr);
      VecEgErr.push_back(EgErr);
      VecCosthErr.push_back(CosthErr);
	
    }
  }



}

void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){


 TString  Header;
 TString  Ranges;
 TString  Total ;
 TString  Line  ;
 TString  Reaction = "1";
 TString  obs = "S";
// TString  fixVar = "W";
 TString  fixVar = "ELab";
 TString  runVar = "cosA";

/*  Char_t Header[256];
  Char_t Ranges[256];
  Char_t Total [256];
  Char_t Line  [256];
  Char_t *Reaction = "1";
  Char_t *obs = "S";
  Char_t *fixVar = "W";
  Char_t *runVar = "A";*/
  Double_t thetaStep = (ThHigh-ThLow)/(NThetaBins);

Header ="http://gwdac.phys.gwu.edu/cgi-bin/go3pr2?sl=CM12&rt=" + Reaction+ "&ot="+obs;
Ranges = "&iv="+runVar+ Form("&il=%f&ii=%f&iu=%f",ThLow,thetaStep,ThHigh)+ "&fv="+fixVar+Form("&fn=%f",Egamma);
Total =Header +  Ranges ;
cout << Total << endl;
Line = "wget '"+Total+"' -O tmp/PageSAID.txt";

cout << Line << endl;
/*
  sprintf(Header, "http://gwdac.phys.gwu.edu/cgi-bin/go3pr2?sl=CM12&rt=%d&ot=%s", Reaction, obs);
  sprintf(Ranges, "&iv=%s&il=%f&ii=%f&iu=%f&fv=%s&fn=%f", runVar, ThLow, thetaStep, ThHigh, fixVar, W);
  sprintf(Total, "%s%s", Header, Ranges);
  sprintf(Line, "wget %c%s%c -O tmp/PageSAID.txt", 34, Total, 34); //PRINT CHR$(34) gives "
*/
  gSystem->Exec(Line);


};







