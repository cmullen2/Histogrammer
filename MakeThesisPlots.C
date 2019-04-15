#include <stdlib.h>
#include <TString.h>

//Read in data from 
void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName );

Double_t ConvertToCME(Double_t taggE);


void MakeThesisPlots() {
 
/* //Simons crap
  Int_t Start=60;
  Int_t X=4;
  Int_t Y=3;
  Int_t number=4;


  gStyle->SetOptFit(0);
  gStyle->SetOptTitle(1);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFont(132,"K");
  gStyle->SetTitleX(0.16);
  gStyle->SetTitleFontSize(0.1);
  gStyle->SetTitleFillColor(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(0);

  gStyle->SetCanvasColor(0);
  gStyle->SetFrameFillColor(0);

  gStyle->SetTitleOffset(1.2, "X");
  gStyle->SetTitleOffset(1.2, "Y");
  gStyle->SetTitleFont(132,"X");
  gStyle->SetTitleFont(132,"Y");
  gStyle->SetTitleSize(0.1,"X");
  gStyle->SetTitleSize(0.1,"Y");

  gStyle->SetLabelOffset(0.01, "X");
  gStyle->SetLabelOffset(0.01, "Y");
  gStyle->SetLabelOffset(0.01, "Z");
  gStyle->SetLabelFont(132,"X");
  gStyle->SetLabelFont(132,"Y");
  gStyle->SetLabelFont(132,"Z");
  gStyle->SetLabelSize(0.1,"X");
  gStyle->SetLabelSize(0.1,"Y");
  gStyle->SetLabelSize(0.035,"Z");

  gStyle->SetNdivisions(506,"X");
  gStyle->SetNdivisions(506,"Y");
  gStyle->SetNdivisions(506,"Z");

  gStyle->SetStripDecimals(kFALSE);
*/
  
/*
  Int_t xPlots = X;
  Int_t yPlots = Y;
  Int_t totalPlots = xPlots*yPlots;

  Double_t marginX = 0.06;
  Double_t marginY = 0.06;
  TPad *Pad1;
  TPad *Pad2;

  TCanvas *Canvas_1_n2 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",0,0,1600,2000);
  Canvas_1_n2->SetCanvasSize(1600,2000);
  Canvas_1_n2->SetWindowSize(1600,2000);
  Canvas_1_n2->Divide(xPlots,yPlots,0,0,0);  

  gStyle->SetOptTitle(0);
  Canvas_1_n2->Range(423.75,-5810.569,1486.25,52295.12);
  Canvas_1_n2->SetFillColor(0);
  Canvas_1_n2->SetBorderMode(0);
  Canvas_1_n2->SetBorderSize(0);
  Canvas_1_n2->SetFrameBorderMode(0);
  Canvas_1_n2->SetFrameBorderMode(0);



  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ThesisPlotFirstAttempt/PPi0AllPlotted.root","recreate");



  Canvas_1_n2->cd(xPlots);

  Double_t scaleX = 1-marginX;
  Double_t scaleY = 1-marginY;

  gPad->TPad::SetPad(marginX+scaleX*gPad->TPad::GetAbsXlowNDC(),
                     marginY+scaleY*gPad->TPad::GetAbsYlowNDC(),
                     scaleX*(gPad->TPad::GetAbsXlowNDC()+gPad->TPad::GetAbsWNDC()+marginX),
                     scaleY*(gPad->TPad::GetAbsYlowNDC()+gPad->TPad::GetAbsHNDC()+marginY));

  gPad->SetLeftMargin(0*scaleX*marginX/gPad->TPad::GetAbsWNDC());
  gPad->SetTopMargin(0*scaleY*marginY/gPad->TPad::GetAbsHNDC());
  gPad->SetRightMargin(0*scaleX*marginX/gPad->TPad::GetAbsWNDC());
  gPad->SetBottomMargin(0*scaleY*marginY/gPad->TPad::GetAbsHNDC());

  gPad->SetFillColor(0);
  gPad->SetFrameFillStyle(4000);
  TLegend* legend = new TLegend(0.02,0,1,1);

  Canvas_1_n2->cd();

*/

//Can add a legend to empty plot space, Add other data and theory easily etc.


  TCanvas *Canvas1 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",0,0,1600,2000);
  Canvas1->SetCanvasSize(1600,2000);
  Canvas1->SetWindowSize(1600,2000);
  Canvas1->Divide(4,3,0,0,0);  
 

  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ThesisPlotsFirstAttempt/PPi0AllPlotted.root","recreate");


  vector<Double_t> VecAllChrisSigma;
  vector<Double_t> VecAllChrisEg;
  vector<Double_t> VecAllChrisCosth;
  vector<TString> VecAllChrisType;
  vector<Double_t> VecAllChrisSigmaErr;
  vector<Double_t> VecAllChrisEgErr;
  vector<Double_t> VecAllChrisCosthErr;
  //My Results
  Double_t AllChrisSigma;
  Double_t AllChrisEg;
  Double_t AllChrisCosth;
  TString AllChrisType;
  Double_t AllChrisSigmaErr;
  Double_t AllChrisEgErr;
  Double_t AllChrisCosthErr;
  TString InFile = "Data/CutResultsNew.txt";
  GetSigmaFromFile( VecAllChrisSigma, VecAllChrisSigmaErr, VecAllChrisEg, VecAllChrisEgErr, VecAllChrisCosth,  VecAllChrisCosthErr,  InFile );
  //My Results
  Double_t ArrSigma[20];
  Double_t ArrCosth[20];
  Double_t ArrEg[20];
  Double_t ArrSigmaErr[20];
  Double_t ArrCosthErr[20];
  Double_t ArrEgErr[20];
  for(Int_t i=0;i<11;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
    for(Int_t j=0;j<20;j++){

      //MyResults
      ArrSigma[j] = VecAllChrisSigma[j+i*20];
      ArrCosth[j] = VecAllChrisCosth[j+i*20];
      ArrEg[j] = VecAllChrisEg[j+i*20];
      ArrSigmaErr[j] = VecAllChrisSigmaErr[j+i*20];
      ArrCosthErr[j] = VecAllChrisCosthErr[j+i*20];
      ArrEgErr[j] = VecAllChrisEgErr[j+i*20];

    }

    Canvas1->cd(i+1);
//    auto c3 = new TCanvas("c3","c3");

    TString PosTitle =Form("%f",ArrEg[0]) ;
    TString PosName = Form("%f",ArrEg[0]) ;
    TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
    SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)

    SigmaPlot->SetFillStyle(0);//pink
    SigmaPlot->SetFillColor(0);//pink

    SigmaPlot->SetTitle("CoplanFitsOrig");//pink


    TMultiGraph* mg = new TMultiGraph();
    mg->SetMaximum(1);
    mg->SetMinimum(0);

    mg->Add(SigmaPlot);

    TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
    TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;

    SigmaPlot->GetYaxis()->SetTitle("#Sigma");
    SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
    SigmaPlot->GetXaxis()->CenterTitle();


    mg->SetName(hName);
    mg->SetTitle(hTitle+";Cos#theta_{CM};#Sigma");
    mg->Draw("AP");
//    TLegend* leg = c3->BuildLegend();
    TLegend* leg = gPad->BuildLegend();
    leg->SetFillStyle(0);
//    mg->Write();
    leg->Write();//Sort the writing of the legend later
//    c3->Write();


  }
  Canvas1->Write();
  outfile->Close();
} //closing main function
	

//////////////////////////////////////////////////////////////////////////////MainFuncClosed/////



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




Double_t ConvertToCME(Double_t taggE){

  return TMath::Sqrt((938.27+taggE)*(938.27+taggE)-taggE*taggE);

}



