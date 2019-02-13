#include <stdlib.h>
#include <TString.h>

void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName );
void GetCorrectionFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecEg ,vector<Double_t> &VecCosth , TString InFileName );
void GetSigmaTheoryFromFile(Double_t  ArrSigma2[], Double_t ArrCosth2[],  TString InFileName2,  Double_t NThetaBins2, Double_t IsTheoryMAID );
Double_t ConvertToCME(Double_t taggE);
void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);  
void GetPi0MAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);


void PlotResults() {
		
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ResultsNPi0TheoryDataComparisonNPi0Theory.root","recreate");
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/TestDelSoon.root","recreate");
  

  Double_t NDataEgBins = 24 ; //Number of bins in data for looping
  Double_t TheoryThetaBins = 20;
  Double_t TheoryThetaLowSAID = -1;
  Double_t TheoryThetaLowMAID = 0;
  Double_t TheoryThetaHighSAID =1 ;
  Double_t TheoryThetaHighMAID =180 ;
  Double_t TheoryEgamma;

	//NonStrict CutsBasedAnalysis No SpecMomCut
  vector<Double_t> VecAllChrisSigmaNonCut;
  vector<Double_t> VecAllChrisEgNonCut;
  vector<Double_t> VecAllChrisCosthNonCut;
  vector<TString> VecAllChrisTypeNonCut;
  vector<Double_t> VecAllChrisSigmaErrNonCut;
  vector<Double_t> VecAllChrisEgErrNonCut;
  vector<Double_t> VecAllChrisCosthErrNonCut;

	//NonStrict CutsBasedAnalysis With SpecMomCut
  vector<Double_t> VecAllChrisSigmaNon;
  vector<Double_t> VecAllChrisEgNon;
  vector<Double_t> VecAllChrisCosthNon;
  vector<TString> VecAllChrisTypeNon;
  vector<Double_t> VecAllChrisSigmaErrNon;
  vector<Double_t> VecAllChrisEgErrNon;
  vector<Double_t> VecAllChrisCosthErrNon;
	
	//Strict CutsBasedAnalysis With SpecMomCut
  vector<Double_t> VecAllChrisSigmaStrict;
  vector<Double_t> VecAllChrisEgStrict;
  vector<Double_t> VecAllChrisCosthStrict;
  vector<TString> VecAllChrisTypeStrict;
  vector<Double_t> VecAllChrisSigmaErrStrict;
  vector<Double_t> VecAllChrisEgErrStrict;
  vector<Double_t> VecAllChrisCosthErrStrict;

	//Proton SAID Correction Factor
  vector<Double_t> VecAllChrisSigmaPSCF;
  vector<Double_t> VecAllChrisEgPSCF;
  vector<Double_t> VecAllChrisCosthPSCF;


	//Results From triple fit
/*  vector<Double_t> VecAllChrisSigma;
  vector<Double_t> VecAllChrisEg;
  vector<Double_t> VecAllChrisCosth;
  vector<TString> VecAllChrisType;
  vector<Double_t> VecAllChrisSigmaErr;
  vector<Double_t> VecAllChrisEgErr;
  vector<Double_t> VecAllChrisCosthErr;

  //Binned Spectator momentum will need 8 of these, means need to adjust other scripts, Need a spearate script to read in the 8 spectator ones and separate them. Then load in 8 here.
  //0-50Mev
  vector<Double_t> VecAllChrisSigmaSpec;
  vector<Double_t> VecAllChrisEgSpec;
  vector<Double_t> VecAllChrisCosthSpec;
  vector<TString> VecAllChrisTypeSpec;
  vector<Double_t> VecAllChrisSigmaErrSpec;
  vector<Double_t> VecAllChrisEgErrSpec;
  vector<Double_t> VecAllChrisCosthErrSpec;


  //My Results
  Double_t AllChrisSigma;
  Double_t AllChrisEg;
  Double_t AllChrisCosth;
  TString AllChrisType;
  Double_t AllChrisSigmaErr;
  Double_t AllChrisEgErr;
  Double_t AllChrisCosthErr;

  //Binned SpecMom
  Double_t AllChrisSigmaSpec;
  Double_t AllChrisEgSpec;
  Double_t AllChrisCosthSpec;
  TString AllChrisTypeSpec;
  Double_t AllChrisSigmaErrSpec;
  Double_t AllChrisEgErrSpec;
  Double_t AllChrisCosthErrSpec;
*/
//	NonStrictCuts No SpecMomCut
  Double_t AllChrisSigmaNonCut;
  Double_t AllChrisEgNonCut;
  Double_t AllChrisCosthNonCut;
  TString AllChrisTypeNonCut;
  Double_t AllChrisSigmaErrNonCut;
  Double_t AllChrisEgErrNonCut;
  Double_t AllChrisCosthErrNonCut;
	//NonStrictCuts
  Double_t AllChrisSigmaNon;
  Double_t AllChrisEgNon;
  Double_t AllChrisCosthNon;
  TString AllChrisTypeNon;
  Double_t AllChrisSigmaErrNon;
  Double_t AllChrisEgErrNon;
  Double_t AllChrisCosthErrNon;
	//StrictCuts
  Double_t AllChrisSigmaStrict;
  Double_t AllChrisEgStrict;
  Double_t AllChrisCosthStrict;
  TString AllChrisTypeStrict;
  Double_t AllChrisSigmaErrStrict;
  Double_t AllChrisEgErrStrict;
  Double_t AllChrisCosthErrStrict;



  TString InFileNonCut = "Data/MyResultsBGSUBBEDNPi0NonStrictCutsAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaNonCut, VecAllChrisSigmaErrNonCut, VecAllChrisEgNonCut, VecAllChrisEgErrNonCut, VecAllChrisCosthNonCut,  VecAllChrisCosthErrNonCut,  InFileNonCut );


  TString InFileNon = "Data/MyResultsBGSUBBEDNPi0NonStrictCutsSpecMomCutAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaNon, VecAllChrisSigmaErrNon, VecAllChrisEgNon, VecAllChrisEgErrNon, VecAllChrisCosthNon,  VecAllChrisCosthErrNon,  InFileNon );


  TString InFileStrict = "Data/MyResultsBGSUBBEDNPi0StrictCutsSpecMomCutAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaStrict, VecAllChrisSigmaErrStrict, VecAllChrisEgStrict, VecAllChrisEgErrStrict, VecAllChrisCosthStrict,  VecAllChrisCosthErrStrict,  InFileStrict );


	//PSCF Proton SAID Correction Factor
  TString InFilePSCF = "../SAIDProtonCorrectionFactor.txt";
  GetCorrectionFromFile( VecAllChrisSigmaPSCF, VecAllChrisEgPSCF, VecAllChrisCosthPSCF, InFilePSCF );


/*
  TString InFile = "Data/CutResultsNew.txt";
  GetSigmaFromFile( VecAllChrisSigma, VecAllChrisSigmaErr, VecAllChrisEg, VecAllChrisEgErr, VecAllChrisCosth,  VecAllChrisCosthErr,  InFile );


  TString InFileSpec = "Data/CutResultsNewNonStrictSpecMomBins0to50Mev.txt";
  GetSigmaFromFile( VecAllChrisSigmaSpec, VecAllChrisSigmaErrSpec, VecAllChrisEgSpec, VecAllChrisEgErrSpec, VecAllChrisCosthSpec,  VecAllChrisCosthErrSpec,  InFileSpec);

*/
/*
  //My Results
  Double_t ArrSigma[20];
  Double_t ArrCosth[20];
  Double_t ArrEg[20];
  Double_t ArrSigmaErr[20];
  Double_t ArrCosthErr[20];
  Double_t ArrEgErr[20];

  //My Results Spec Binned Cuts Analysis
  Double_t ArrSigmaSpec[20];
  Double_t ArrCosthSpec[20];
  Double_t ArrEgSpec[20];
  Double_t ArrSigmaErrSpec[20];
  Double_t ArrCosthErrSpec[20];
  Double_t ArrEgErrSpec[20];

*/
  Double_t ArrSigmaPSCF[20];

  Double_t ArrSigmaNonCut[20];
  Double_t ArrCosthNonCut[20];
  Double_t ArrEgNonCut[20];
  Double_t ArrSigmaErrNonCut[20];
  Double_t ArrCosthErrNonCut[20];
  Double_t ArrEgErrNonCut[20];

  Double_t ArrSigmaNon[20];
  Double_t ArrCosthNon[20];
  Double_t ArrEgNon[20];
  Double_t ArrSigmaErrNon[20];
  Double_t ArrCosthErrNon[20];
  Double_t ArrEgErrNon[20];

  Double_t ArrSigmaStrict[20];
  Double_t ArrCosthStrict[20];
  Double_t ArrEgStrict[20];
  Double_t ArrSigmaErrStrict[20];
  Double_t ArrCosthErrStrict[20];
  Double_t ArrEgErrStrict[20];

  for(Int_t i=0;i<NDataEgBins;i++){//Number of eg bins//Deprecated*Number of folders(rand,sig,cut1) 41*3
    for(Int_t j=0;j<20;j++){ //Number of Costh Bins

      ArrSigmaNonCut[j] = VecAllChrisSigmaNonCut[j+i*20];
      ArrCosthNonCut[j] = VecAllChrisCosthNonCut[j+i*20];
      ArrEgNonCut[j] = VecAllChrisEgNonCut[j+i*20];
      ArrSigmaErrNonCut[j] = VecAllChrisSigmaErrNonCut[j+i*20];
      ArrCosthErrNonCut[j] = VecAllChrisCosthErrNonCut[j+i*20];
      ArrEgErrNonCut[j] = VecAllChrisEgErrNonCut[j+i*20];

      ArrSigmaNon[j] = VecAllChrisSigmaNon[j+i*20];
      ArrCosthNon[j] = VecAllChrisCosthNon[j+i*20];
      ArrEgNon[j] = VecAllChrisEgNon[j+i*20];
      ArrSigmaErrNon[j] = VecAllChrisSigmaErrNon[j+i*20];
      ArrCosthErrNon[j] = VecAllChrisCosthErrNon[j+i*20];
      ArrEgErrNon[j] = VecAllChrisEgErrNon[j+i*20];

      ArrSigmaStrict[j] = VecAllChrisSigmaStrict[j+i*20];
      ArrCosthStrict[j] = VecAllChrisCosthStrict[j+i*20];
      ArrEgStrict[j] = VecAllChrisEgStrict[j+i*20];
      ArrSigmaErrStrict[j] = VecAllChrisSigmaErrStrict[j+i*20];
      ArrCosthErrStrict[j] = VecAllChrisCosthErrStrict[j+i*20];
      ArrEgErrStrict[j] = VecAllChrisEgErrStrict[j+i*20];

/*      //MyResults
      ArrSigma[j] = VecAllChrisSigma[j+i*20];
      ArrCosth[j] = VecAllChrisCosth[j+i*20];
      ArrEg[j] = VecAllChrisEg[j+i*20];
      ArrSigmaErr[j] = VecAllChrisSigmaErr[j+i*20];
      ArrCosthErr[j] = VecAllChrisCosthErr[j+i*20];
      ArrEgErr[j] = VecAllChrisEgErr[j+i*20];

      //MyResults SPecMom bins cuts analysis
      ArrSigmaSpec[j] = VecAllChrisSigmaSpec[j+i*20];
      ArrCosthSpec[j] = VecAllChrisCosthSpec[j+i*20];
      ArrEgSpec[j] = VecAllChrisEgSpec[j+i*20];
      ArrSigmaErrSpec[j] = VecAllChrisSigmaErrSpec[j+i*20];
      ArrCosthErrSpec[j] = VecAllChrisCosthErrSpec[j+i*20];
      ArrEgErrSpec[j] = VecAllChrisEgErrSpec[j+i*20];

*/
     // TheoryEgamma= VecAllChrisEg[j+i*20];
      TheoryEgamma= VecAllChrisEgNonCut[j+i*20];

	if(TheoryEgamma>420 && TheoryEgamma<640){
	if(VecAllChrisSigmaPSCF[10+i*20]==0){
      ArrSigmaPSCF[j]=  VecAllChrisSigmaNon[j+i*20]*VecAllChrisSigmaPSCF[10+i*20];//Different NEgammaBins for Proton vs neutron
}
else{
ArrSigmaPSCF[j]=0;
}

}
else{
	ArrSigmaPSCF[j]=0;
}


    }


    //    vector<Double_t> VecSigmaSAID;
    //    vector<Double_t> VecSigmaErrSAID;
    //    vector<Double_t> VecEgSAID;
    //    vector<Double_t> VecEgErrSAID;
    //    vector<Double_t> VecCosthSAID;
    //    vector<Double_t> VecCosthErrSAID;
    Double_t ArrSigmaSAID[20];
    Double_t ArrSigmaSAIDDiv[20];
    Double_t ArrCosthSAID[20];
    TString InFileNameSAID = "tmp/PageSAID.txt";

    Double_t ArrSigmaMAID[20];
    Double_t ArrSigmaMAIDNew[20];
    Double_t ArrSigmaMAIDDiv[20];
    Double_t ArrCosthMAID[20];
    Double_t ArrCosthMAIDNew[20];
    TString InFileNameMAID = "tmp/PageMAID.txt";
    Double_t IsMAID=0;

/*
    Double_t ArrSigmaMineCorrectedMAID[20];
    Double_t ArrSigmaMineCorrectedSAID[20];
*/


    //GetSAID Predictions
        GetPi0SAID( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighSAID, TheoryThetaLowSAID);
        GetSigmaTheoryFromFile(ArrSigmaSAID, ArrCosthSAID ,  InFileNameSAID,  TheoryThetaBins,IsMAID);

    //GetMAID predictions //MAID File gives me 21 for some reason, fix later,removed last(180) point for now
    GetPi0MAID( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighMAID, TheoryThetaLowMAID);
    IsMAID=1;
    GetSigmaTheoryFromFile(ArrSigmaMAID, ArrCosthMAID ,  InFileNameMAID,  TheoryThetaBins,IsMAID);

    for(Int_t j=0;j<20;j++){
//      if(ArrSigmaSAID[j]!=0){
//	ArrSigmaSAIDDiv[j] = VecAllChrisSigma[j+i*20]/ArrSigmaSAID[j]; 
//      }
//      else{
//	ArrSigmaSAIDDiv[j]=0;
//      }

	
//Convert ArrCosthMAID to Costh from theta and reverse the ordering in both arrays
	ArrCosthMAIDNew[j] = TMath::Cos( TMath::DegToRad()*  (ArrCosthMAID[19-j] ) );
	ArrSigmaMAIDNew[j] = ArrSigmaMAID[19-j];

//      if(ArrSigmaMAIDNew[j]!=0){
//	ArrSigmaMAIDDiv[j] = VecAllChrisSigma[j+i*20]/ArrSigmaMAIDNew[j]; 
//      }
//      else{
//	ArrSigmaMAIDDiv[j]=0;
//      }

    }



//    for(Int_t j=0;j<20;j++){
//ArrSigmaMineCorrectedMAID[j]=VecAllChrisSigma[j+i*20]/ArrSigmaMAIDDiv[10];
//ArrSigmaMineCorrectedSAID[j]=VecAllChrisSigma[j+i*20]/ArrSigmaSAIDDiv[10] ;
//}


    auto c3 = new TCanvas("c3","c3");
    TString PosTitle =Form("%f",ArrEgNonCut[0]) ;
    TString PosName = Form("%f",ArrEgNonCut[0]) ;
	//Declare Graphs
 //   TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotNonCut=new TGraphErrors(20,ArrCosthNonCut,ArrSigmaNonCut,ArrCosthErrNonCut,ArrSigmaErrNonCut);
    TGraph* SigmaPlotNon=new TGraphErrors(20,ArrCosthNon,ArrSigmaNon,ArrCosthErrNon,ArrSigmaErrNon);
    TGraph* SigmaPlotStrict=new TGraphErrors(20,ArrCosthStrict,ArrSigmaStrict,ArrCosthErrStrict,ArrSigmaErrStrict);
//    TGraph* DivisionPlotSAID=new TGraph(20,ArrCosthSAID,ArrSigmaSAIDDiv);
    TGraph* SigmaPlotSAID=new TGraphErrors(20,ArrCosthSAID,ArrSigmaSAID,ArrCosthErrNonCut,ArrSigmaErrNonCut);
//    TGraph* DivisionPlotMAID=new TGraph(20,ArrCosthMAIDNew,ArrSigmaMAIDDiv);
    TGraph* SigmaPlotMAID=new TGraphErrors(20,ArrCosthMAIDNew,ArrSigmaMAIDNew,ArrCosthErrNonCut,ArrSigmaErrNonCut);
//    TGraph* SigmaPlotCorrectedMAID=new TGraphErrors(20,ArrCosthMAIDNew,ArrSigmaMineCorrectedMAID,ArrCosthErr,ArrSigmaErr);
//    TGraph* SigmaPlotCorrectedSAID=new TGraphErrors(20,ArrCosthSAID,ArrSigmaMineCorrectedSAID,ArrCosthErr,ArrSigmaErr);
    //SpecMom Binned cuts Analysis
//    TGraph* SigmaPlotSpec=new TGraphErrors(20,ArrCosthSpec,ArrSigmaSpec,ArrCosthErrSpec,ArrSigmaErrSpec);
    TGraph* SigmaPlotPSCF=new TGraphErrors(20,ArrCosthNon,ArrSigmaPSCF,ArrCosthErrNon,ArrSigmaErrNon);

	//Set Marker Style/Color
//    DivisionPlotSAID->SetMarkerStyle(31);
//    DivisionPlotSAID->SetMarkerColor(6);
//    DivisionPlotMAID->SetMarkerStyle(32);
//    DivisionPlotMAID->SetMarkerColor(8);
//    SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)
    SigmaPlotNonCut->SetMarkerStyle(22);//
    SigmaPlotNonCut->SetMarkerColor(1);  //black
    SigmaPlotNon->SetMarkerStyle(22);//
    SigmaPlotNon->SetMarkerColor(2);  //red
    SigmaPlotStrict->SetMarkerStyle(22);//
    SigmaPlotStrict->SetMarkerColor(3);  //lime
    SigmaPlotSAID->SetMarkerStyle(25);//
    SigmaPlotSAID->SetMarkerColor(5);  //yellow
    SigmaPlotMAID->SetMarkerStyle(26);//
    SigmaPlotMAID->SetMarkerColor(4);//blue 
    SigmaPlotPSCF->SetMarkerStyle(22);//
    SigmaPlotPSCF->SetMarkerColor(9);//purple  
//    SigmaPlotSpec->SetMarkerStyle(22);//
//    SigmaPlotSpec->SetMarkerColor(2);  //red
//    SigmaPlotCorrectedSAID->SetMarkerStyle(29);//Filled triangle(black(default)
//    SigmaPlotCorrectedSAID->SetMarkerColor(9); //purple
//    SigmaPlotCorrectedMAID->SetMarkerStyle(30);//Filled triangle(black(default)
//    SigmaPlotCorrectedMAID->SetMarkerColor(8); //green(not lime)

	//Set Fill Style/Color
    SigmaPlotSAID->SetFillStyle(0);
    SigmaPlotSAID->SetFillColor(0);
    SigmaPlotMAID->SetFillStyle(0);
    SigmaPlotMAID->SetFillColor(0);
    SigmaPlotNonCut->SetFillStyle(0);
    SigmaPlotNonCut->SetFillColor(0);
    SigmaPlotNon->SetFillStyle(0);
    SigmaPlotNon->SetFillColor(0);
    SigmaPlotStrict->SetFillStyle(0);
    SigmaPlotStrict->SetFillColor(0);
    SigmaPlotPSCF->SetFillStyle(0);
    SigmaPlotPSCF->SetFillColor(0);
//    SigmaPlotCorrectedSAID->SetFillStyle(0);
//    SigmaPlotCorrectedSAID->SetFillColor(0);
//    SigmaPlotCorrectedMAID->SetFillStyle(0);
//    SigmaPlotCorrectedMAID->SetFillColor(0);
//    SigmaPlotSpec->SetFillStyle(0);
//    SigmaPlotSpec->SetFillColor(0);
//    SigmaPlot->SetFillStyle(0);
//    SigmaPlot->SetFillColor(0);
//    DivisionPlotSAID->SetFillStyle(0);
//    DivisionPlotSAID->SetFillColor(0);
//    DivisionPlotMAID->SetFillStyle(0);
//    DivisionPlotMAID->SetFillColor(0);



	//Set Title
    SigmaPlotSAID->SetTitle("SAID");
    SigmaPlotMAID->SetTitle("MAID");
    SigmaPlotNonCut->SetTitle("NonCut");
    SigmaPlotNon->SetTitle("Non");
    SigmaPlotStrict->SetTitle("Strict");
    SigmaPlotPSCF->SetTitle("ProtonSAIDCorrection");
//    SigmaPlotCorrectedSAID->SetTitle("CorrectedWithSAID");
//    SigmaPlotCorrectedMAID->SetTitle("CorrectedWithMAID");
//    SigmaPlotSpec->SetTitle("SpecMom0-50Mev");
//    SigmaPlot->SetTitle("CoplanFitsOrig");//pink
//    DivisionPlotSAID->SetTitle("SAIDDivision");//pink
//    DivisionPlotMAID->SetTitle("MAIDDivision");//pink


	//Create Multigraph and add plots to it 
    TMultiGraph* mg = new TMultiGraph();
//    mg->Add(SigmaPlot);
//    mg->Add(DivisionPlotSAID);
//    mg->Add(DivisionPlotMAID);
//    mg->Add(SigmaPlotSpec);
    mg->Add(SigmaPlotSAID);
    mg->Add(SigmaPlotMAID);
    mg->Add(SigmaPlotNonCut);
    mg->Add(SigmaPlotNon);
    mg->Add(SigmaPlotPSCF);
    mg->Add(SigmaPlotStrict);
//    mg->Add(SigmaPlotCorrectedSAID);
//    mg->Add(SigmaPlotCorrectedMAID);

    TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
    TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;

    //  SigmaPlot->Draw("AP*");
    //  SigmaPlot->SetTitle(hTitle);
    //  SigmaPlot->SetName(hName);
//    SigmaPlot->GetYaxis()->SetTitle("#Sigma");
//    SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
//    SigmaPlot->GetXaxis()->CenterTitle();
    //  SigmaPlot->Write();
    SigmaPlotNonCut->GetYaxis()->SetTitle("#Sigma");
    SigmaPlotNonCut->GetXaxis()->SetTitle("Cos#theta_{CM} ");
    SigmaPlotNonCut->GetXaxis()->CenterTitle();


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
 //   leg->Write();//Sort the writing of the legend later
 //   DivisionPlotSAID->Write();
 //   DivisionPlotMAID->Write();
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

}

void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){


  TString  Header;
  TString  Ranges;
  TString  Total ;
  TString  Line  ;
  TString  Reaction = "4"; //Choosing first reaction from (http://gwdac.phys.gwu.edu/analysis/pr_analysis.html) 1 is Pi0P can check in the saved webpage
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

void GetPi0MAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){

  //MAID has a lot more flexibility
  //Model Parameters see ( https://maid.kph.uni-mainz.de/maid2007/polariz.html)
  TString  Born = "1";
  TString  Rho = "1";
  TString  Omega = "1";
  TString  P33_1232 = "1";
  TString  P11_1440 = "1";
  TString  D13_1520 = "1";
  TString  S11_1535 = "1";
  TString  S31_1620 = "1";
  TString  S11_1650 = "1";
  TString  F15_1680 = "1";
  TString  D33_1700 = "1";
  TString  P13_1720 = "1";
  TString  P31_1910 = "1";
  TString  D15_1675 = "1";
  TString  F35_1905 = "1";
  TString  F37_1950 = "1";
  //  Double_t M_p = 938.2720;
  //  Double_t Beam;
  //
  // Change of S-wave low-energy corrections and type of pi-N coupling 
  TString E0plus = "1.0";
  TString S0plus = "1.0";
  TString PSPV = "1.0";

  //Resonance coupling values relative to default, default =1
  TString P33_1232_M1p = "1.0";
  TString P33_1232_E1p = "1.0";
  TString P33_1232_S1p = "1.0";

  TString S31_1620_A12 = "1.0";
  TString S31_1620_S12 = "1.0";

  TString D33_1700_A32 = "1.0";
  TString D33_1700_A12 = "1.0";
  TString D33_1700_S12 = "1.0";

  TString F35_1905_A32 = "1.0";
  TString F35_1905_A12 = "1.0";
  TString F35_1905_S12 = "1.0";

  TString P31_1910_A12 = "1.0";
  TString P31_1910_S12 = "1.0";

  TString F37_1950_A32 = "1.0";
  TString F37_1950_A12 = "1.0";
  TString F37_1950_S12 = "1.0";

  TString P11_1440_A12 = "1.0";
  TString P11_1440_S12 = "1.0";

  TString D13_1520_A32 = "1.0";
  TString D13_1520_A12 = "1.0";
  TString D13_1520_S12 = "1.0";

  TString S11_1535_A12 = "1.0";
  TString S11_1535_S12 = "1.0";

  TString S11_1650_A12 = "1.0";
  TString S11_1650_S12 = "1.0";

  TString D15_1675_A32 = "1.0";
  TString D15_1675_A12 = "1.0";
  TString D15_1675_S12 = "1.0";

  TString F15_1680_A32 = "1.0";
  TString F15_1680_A12 = "1.0";
  TString F15_1680_S12 = "1.0";

  TString P13_1720_A32 = "1.0";
  TString P13_1720_A12 = "1.0";
  TString P13_1720_S12 = "1.0";



  TString  Header;
  TString  Ranges;
  TString  Mechan;
  TString  Corr;
  TString  Coupling;
  TString  Total;
  TString  Line;
  TString  Reaction = "2"; //Choosing first reaction from (https://maid.kph.uni-mainz.de/maid2007/polariz.html) 1 is Pi0P can check in the saved webpage
  //  TString  obs = "S"; //Observable is not needed since we are grabbing a table with all of them.
  // TString  fixVar = "ELab";
  // TString  runVar = "cosA";
  TString  runVar = "3";//choose independent variable 1=Q^2, 2=W, 3=Theta
  Double_t thetaStep = (ThHigh-ThLow)/(NThetaBins);
  Double_t W = ConvertToCME(Egamma);


  //Param3 is DSG, T, P, S, E, F, G, H, Param 4 is Cx', Cz', Ox', Oz', Tx', Tz', Lx' 
  //Header ="http://wwwkph.kph.uni-mainz.de/cgi-bin/maid1?switch=215&param2="+ Reaction + "&param3=1&param4=1";//+obs;
  Header ="https://maid.kph.uni-mainz.de/cgi-bin/maid1?switch=215&param2="+ Reaction + "&param3=1&param4=1";//+obs;

  if(runVar=="3"){ //Egamma needs to be done in W
    Ranges = "&param50="+ runVar + "&value35=0.0&value36" +Form("=%f",W)+ "&value37" +Form("=%f",ThLow)+ "&value41" +Form("=%f",thetaStep)+ "&value42" +Form("=%f",ThHigh)+ "&param99=0";
  }

  if(runVar=="2"){ //Egamma needs to be done in W
    Ranges ="&param50=" +runVar+ "&value35=0.0&value36" +Form("=%f",ThLow)+ "&value37" +Form("=%f",W)+ "&value41" +Form("=%f",thetaStep)+ "&value42" +Form("=%f",ThHigh)+ "&param99=0";
  }


  Mechan = "&param11=" +Born+ "&param12=" +Rho+ "&param13=" +Omega+ "&param14=" +P33_1232+ "&param15=" +P11_1440+ "&param16=" +D13_1520+ "&param17=" +S11_1535+ "&param18=" +S31_1620+ "&param19=" +S11_1650+ "&param20=" +D15_1675+ "&param21=" +F15_1680+ "&param22=" +D33_1700+ "&param23=" +P13_1720+ "&param24=" +F35_1905+ "&param25=" +P31_1910+ "&param26=" +F37_1950;


  Corr = "&value11=" +E0plus+ "&value12=" +S0plus+ "&value13=" +PSPV;
  Coupling = "&value51=" +P33_1232_M1p+ "&value52=" +P33_1232_E1p+ "&value53=" +P33_1232_S1p+ "&value54=" +S31_1620_A12+ "&value55=" +S31_1620_S12+ "&value56=" +D33_1700_A32+ "&value57=" +D33_1700_A12 + "&value58=" +D33_1700_S12+ "&value59=" +F35_1905_A32+ "&value60=" +F35_1905_A12+ "&value61=" +F35_1905_S12+ "&value62=" +P31_1910_A12+ "&value63=" +P31_1910_S12+ "&value64=" +F37_1950_A32+ "&value65=" +F37_1950_A12+ "&value66=" +F37_1950_S12+ "&value67=" +P11_1440_A12+ "&value68=" +P11_1440_S12+ "&value69=" +D13_1520_A32+ "&value70=" +D13_1520_A12+ "&value71=" +D13_1520_S12+ "&value72=" +S11_1535_A12+ "&value73=" +S11_1535_S12+ "&value74=" +S11_1650_A12+ "&value75=" +S11_1650_S12+ "&value76=" +D15_1675_A32+ "&value77=" +D15_1675_A12+ "&value78=" +D15_1675_S12+ "&value79=" +F15_1680_A32+ "&value80=" +F15_1680_A12+ "&value81=" +F15_1680_S12+ "&value82=" +P13_1720_A32+ "&value83=" +P13_1720_A12+ "&value84=" +P13_1720_S12;


  Total =Header +  Ranges + Mechan + Corr + Coupling ;
  cout << Total << endl;
  Line = "wget '"+Total+"' -O tmp/PageMAID.txt";

  cout << Line << endl;
  gSystem->Exec(Line);


};




/*
  void GetSigmaTheoryFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecCosth , TString InFileName,Double_t NThetaBins ){

  Double_t Sigma;
  Double_t Costh;
  //  TString HeaderLines;
  Double_t lineCount=0;

  std::ifstream inputFileSpec(InFileName);
  std::string lineSpec;
  if (inputFileSpec.is_open()){
  while(getline(inputFileSpec, lineSpec) ){
  if(lineCount<7 || lineCount>(7+NThetaBins)  ){
  //		stringstream(lineSpec)>>HeaderLines;
  //		cout << HeaderLines << endl;
  lineCount=lineCount+1;
  }	
  else{
  //                stringstream(lineSpec)>>HeaderLines;
  //		cout << "The Line is now = " << HeaderLines<< endl;
  stringstream(lineSpec)>>Costh>>Sigma ;
  lineCount=lineCount+1;
	
  VecSigma.push_back(Sigma);
  VecCosth.push_back(Costh);
  }
  }
  }



  }
*/




void GetSigmaTheoryFromFile(Double_t  ArrSigma[], Double_t ArrCosth[] , TString InFileName,Double_t NThetaBins, Double_t IsTheoryMAID ){

  Double_t Sigma;
  Double_t Eg;
  Double_t XSec;
  Double_t P;
  Double_t T;
  Double_t Costh;
  TString HeaderLines;
  Double_t lineCount=0;
  vector<Double_t> VecSigma;
  vector<Double_t> VecCosth;


  std::ifstream inputFileSpec(InFileName);
  std::string lineSpec;
  if (inputFileSpec.is_open()){
    while(getline(inputFileSpec, lineSpec) ){
      if(IsTheoryMAID){
	if(lineCount<26 || lineCount>(26+NThetaBins)  ){
	  //stringstream(lineSpec)>>HeaderLines;
	 // cout << HeaderLines << endl;
	  lineCount=lineCount+1;
	}
	else{
//	  stringstream(lineSpec)>>HeaderLines;
	//  cout << "The Line is now = " << HeaderLines<< endl;
	  stringstream(lineSpec)>>Costh>>Eg>>XSec >>T>>P >>Sigma ;
	  lineCount=lineCount+1;
	//  cout << Sigma << endl;
	  VecSigma.push_back(Sigma);
	  VecCosth.push_back(Costh);
	}
      }
      else{ 
	if(lineCount<7 || lineCount>(7+NThetaBins)  ){
	  //		stringstream(lineSpec)>>HeaderLines;
	  //		cout << HeaderLines << endl;
	  lineCount=lineCount+1;
	}	
	else{
	  //                stringstream(lineSpec)>>HeaderLines;
	  //		cout << "The Line is now = " << HeaderLines<< endl;
	  stringstream(lineSpec)>>Costh>>Sigma ;
	  lineCount=lineCount+1;
	
	  VecSigma.push_back(Sigma);
	  VecCosth.push_back(Costh);
	}
      }
    }
  }


  for(Int_t j=0;j<VecSigma.size()-1;j++){

    ArrSigma[j]=VecSigma[j];
    ArrCosth[j]=VecCosth[j];
  }


}


Double_t ConvertToCME(Double_t taggE){

  return TMath::Sqrt((938.27+taggE)*(938.27+taggE)-taggE*taggE);

}



void GetCorrectionFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecEg ,vector<Double_t> &VecCosth , TString InFileName ){

  Double_t Sigma;
  Double_t Eg;
  Double_t Costh;

  std::ifstream inputFileSpec(InFileName);
  std::string lineSpec;
  if (inputFileSpec.is_open()){
    while(getline(inputFileSpec, lineSpec) ){
      stringstream(lineSpec)>>Sigma >>Eg >> Costh;
      VecSigma.push_back(Sigma);
      VecEg.push_back(Eg);
      VecCosth.push_back(Costh);
	
    }
  }

}












///cgi-bin/maid1?switch=215&param2=1&param4=1&param50=3&value35=0&value36=1232&value37=30&value41=10&value42=180&param99=0&param11=1&param12=1&param13=1&param14=1&param15=1&param16=1&param17=1&param18=1&param19=1&param20=1&param21=1&param22=1&param23=1&param24=1&param25=1&param26=1&value11=1.0&value12=1.0&value13=1.0&value51=1.0&value52=1.0&value53=1.0&value54=1.0&value55=1.0&value56=1.0&value57=1.0&value58=1.0&value59=1.0&value60=1.0&value61=1.0&value62=1.0&value63=1.0&value64=1.0&value65=1.0&value66=1.0&value67=1.0&value68=1.0&value69=1.0&value70=1.0&value71=1.0&value72=1.0&value73=1.0&value74=1.0&value75=1.0&value76=1.0&value77=1.0&value78=1.0&value79=1.0&value80=1.0&value81=1.0&value82=1.0&value83=1.0&value84=1.0



