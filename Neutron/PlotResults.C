#include <stdlib.h>
#include <TString.h>

void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName );
void GetCorrectionFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecEg ,vector<Double_t> &VecCosth , TString InFileName );
void GetSigmaTheoryFromFile(Double_t  ArrSigma2[], Double_t ArrCosth2[],  TString InFileName2,  Double_t NThetaBins2, Double_t IsTheoryMAID );
Double_t ConvertToCME(Double_t taggE);
void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);  
void GetPi0MAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);





//TheoryDataFromBnGa
void GetPi0BnGa(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);
void GetBnGaSigmaFromFile(vector<Double_t>  &VecSigmaBnGa, vector<Double_t> &VecSigmaErrBnGa, vector<Double_t> &VecEgBnGa ,vector<Double_t> &VecEgErrBnGa ,vector<Double_t> &VecCosthBnGa ,vector<Double_t> &VecCosthErrBnGa, Double_t NThetaBins ,TString BnGaFileName );

//Theory Data From SAID to use for comparison on plots
void GetPi0SAIDMoreBins(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);  
void GetSAIDSigmaFromFile(vector<Double_t>  &VecSigmaSAIDMB, vector<Double_t> &VecSigmaErrSAIDMB, vector<Double_t> &VecEgSAIDMB ,vector<Double_t> &VecEgErrSAIDMB ,vector<Double_t> &VecCosthSAIDMB ,vector<Double_t> &VecCosthErrSAIDMB, Double_t NThetaBins ,TString SAIDMBFileName );



void PlotResults() {
		
  //  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ResultsNPi0TheoryDataComparisonNPi0Theory.root","recreate");
  //  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/TestDelSoon.root","recreate");
  //  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/DevCodeNPi0.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/MeetingFeb28/NPi0AllPlotted.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr112019/NPi0CoplanFitsAndUnBinnedVersusNewVersionOfBoth.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr112019/NPi0CoplanFitsOldVsNewApr.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr112019/NPi0UnBinnedOldVersusNewApr.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr252019/NPi0SigmaCutsAnalysisVsUnBinnedVsCoplanFitsWithTheoryFixedSubRatio.root","recreate");
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr252019/NPi0SigmaCutsAnalysisVsCutsCorrectedVsUnBinnedVsCoplanFitsWithTheoryFixedSubRatio.root","recreate");

  Double_t NDataEgBins = 24 ; //Number of bins in data for looping
  Double_t TheoryThetaBinsDouble = 40;
  Double_t TheoryThetaBins = 20;
  Double_t TheoryThetaLowSAID = -1;
  Double_t TheoryThetaLowMAID = 0;
  Double_t TheoryThetaHighSAID =1 ;
  Double_t TheoryThetaHighMAID =180 ;
  Double_t TheoryEgamma;



  // CutsBasedAnalysis Apr252019
  vector<Double_t> VecAllChrisSigmaCut;
  vector<Double_t> VecAllChrisEgCut;
  vector<Double_t> VecAllChrisCosthCut;
  vector<TString> VecAllChrisTypeCut;
  vector<Double_t> VecAllChrisSigmaErrCut;
  vector<Double_t> VecAllChrisEgErrCut;
  vector<Double_t> VecAllChrisCosthErrCut;


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

  //Proton SAID Correction Factor From Cuts analysis to SAID
  vector<Double_t> VecAllChrisSigmaPSCFCut;
  vector<Double_t> VecAllChrisEgPSCFCut;
  vector<Double_t> VecAllChrisCosthPSCFCut;

  //Results From triple fit
  vector<Double_t> VecAllChrisSigma;
  vector<Double_t> VecAllChrisEg;
  vector<Double_t> VecAllChrisCosth;
  vector<TString> VecAllChrisType;
  vector<Double_t> VecAllChrisSigmaErr;
  vector<Double_t> VecAllChrisEgErr;
  vector<Double_t> VecAllChrisCosthErr;

  //Results From triple fit + unbin
  vector<Double_t> VecAllChrisSigmaUnBin;
  vector<Double_t> VecAllChrisEgUnBin;
  vector<Double_t> VecAllChrisCosthUnBin;
  vector<TString> VecAllChrisTypeUnBin;
  vector<Double_t> VecAllChrisSigmaErrUnBin;
  vector<Double_t> VecAllChrisEgErrUnBin;
  vector<Double_t> VecAllChrisCosthErrUnBin;

  //Results From triple fit V2 Apr2019
  vector<Double_t> VecAllChrisSigmaApr;
  vector<Double_t> VecAllChrisEgApr;
  vector<Double_t> VecAllChrisCosthApr;
  vector<TString> VecAllChrisTypeApr;
  vector<Double_t> VecAllChrisSigmaErrApr;
  vector<Double_t> VecAllChrisEgErrApr;
  vector<Double_t> VecAllChrisCosthErrApr;

  //Results From triple fit + unbin V2 Apr 2019
  vector<Double_t> VecAllChrisSigmaUnBinApr;
  vector<Double_t> VecAllChrisEgUnBinApr;
  vector<Double_t> VecAllChrisCosthUnBinApr;
  vector<TString> VecAllChrisTypeUnBinApr;
  vector<Double_t> VecAllChrisSigmaErrUnBinApr;
  vector<Double_t> VecAllChrisEgErrUnBinApr;
  vector<Double_t> VecAllChrisCosthErrUnBinApr;
//////////////////////////////////////////////////////////////////////////////////////////////////

  //My Results
  Double_t AllChrisSigma;
  Double_t AllChrisEg;
  Double_t AllChrisCosth;
  TString AllChrisType;
  Double_t AllChrisSigmaErr;
  Double_t AllChrisEgErr;
  Double_t AllChrisCosthErr;

  //My ResultsUnBin
  Double_t AllChrisSigmaUnBin;
  Double_t AllChrisEgUnBin;
  Double_t AllChrisCosthUnBin;
  TString AllChrisTypeUnBin;
  Double_t AllChrisSigmaErrUnBin;
  Double_t AllChrisEgErrUnBin;
  Double_t AllChrisCosthErrUnBin;


  //My ResultsV2
  Double_t AllChrisSigmaApr;
  Double_t AllChrisEgApr;
  Double_t AllChrisCosthApr;
  TString AllChrisTypeApr;
  Double_t AllChrisSigmaErrApr;
  Double_t AllChrisEgErrApr;
  Double_t AllChrisCosthErrApr;

  //My ResultsUnBinV2
  Double_t AllChrisSigmaUnBinApr;
  Double_t AllChrisEgUnBinApr;
  Double_t AllChrisCosthUnBinApr;
  TString AllChrisTypeUnBinApr;
  Double_t AllChrisSigmaErrUnBinApr;
  Double_t AllChrisEgErrUnBinApr;
  Double_t AllChrisCosthErrUnBinApr;


  //	CutsApr252019
  Double_t AllChrisSigmaCut;
  Double_t AllChrisEgCut;
  Double_t AllChrisCosthCut;
  TString AllChrisTypeCut;
  Double_t AllChrisSigmaErrCut;
  Double_t AllChrisEgErrCut;
  Double_t AllChrisCosthErrCut;

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

////////////////////////////////////////////////////////////////////////////////////////////////

  TString InFileNonCut = "Data/MyResultsBGSUBBEDNPi0NonStrictCutsAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaNonCut, VecAllChrisSigmaErrNonCut, VecAllChrisEgNonCut, VecAllChrisEgErrNonCut, VecAllChrisCosthNonCut,  VecAllChrisCosthErrNonCut,  InFileNonCut );

  TString InFileCut = "Data/MyResultsBGSUBBEDNPi0April25RunFixedSubRatio.txt";
  GetSigmaFromFile( VecAllChrisSigmaCut, VecAllChrisSigmaErrCut, VecAllChrisEgCut, VecAllChrisEgErrCut, VecAllChrisCosthCut,  VecAllChrisCosthErrCut,  InFileCut );


  TString InFileNon = "Data/MyResultsBGSUBBEDNPi0NonStrictCutsSpecMomCutAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaNon, VecAllChrisSigmaErrNon, VecAllChrisEgNon, VecAllChrisEgErrNon, VecAllChrisCosthNon,  VecAllChrisCosthErrNon,  InFileNon );


  TString InFileStrict = "Data/MyResultsBGSUBBEDNPi0StrictCutsSpecMomCutAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaStrict, VecAllChrisSigmaErrStrict, VecAllChrisEgStrict, VecAllChrisEgErrStrict, VecAllChrisCosthStrict,  VecAllChrisCosthErrStrict,  InFileStrict );


  //PSCF Proton SAID Correction Factor
  TString InFilePSCF = "../SAIDProtonCorrectionFactor.txt";
  GetCorrectionFromFile( VecAllChrisSigmaPSCF, VecAllChrisEgPSCF, VecAllChrisCosthPSCF, InFilePSCF );

  //PSCF Proton SAID Correction Factor From the cuts based analysis
  TString InFilePSCFCut = "../SAIDProtonCorrectionFactorCuts.txt";
  GetCorrectionFromFile( VecAllChrisSigmaPSCFCut, VecAllChrisEgPSCFCut, VecAllChrisCosthPSCFCut, InFilePSCFCut );


  TString InFile = "Data/MyResultsNewCoplanFitsNoSpecMomCut.txt";
  GetSigmaFromFile( VecAllChrisSigma, VecAllChrisSigmaErr, VecAllChrisEg, VecAllChrisEgErr, VecAllChrisCosth,  VecAllChrisCosthErr,  InFile );


  TString InFileUnBin = "Data/MyResultsUnBinnedNeutronSigma.txt";
  GetSigmaFromFile( VecAllChrisSigmaUnBin, VecAllChrisSigmaErrUnBin, VecAllChrisEgUnBin, VecAllChrisEgErrUnBin, VecAllChrisCosthUnBin,  VecAllChrisCosthErrUnBin,  InFileUnBin );


  TString InFileApr = "Data/MyResultsNewCoplanFitsApr11.txt";
  GetSigmaFromFile( VecAllChrisSigmaApr, VecAllChrisSigmaErrApr, VecAllChrisEgApr, VecAllChrisEgErrApr, VecAllChrisCosthApr,  VecAllChrisCosthErrApr,  InFileApr );


  TString InFileUnBinApr = "Data/MyResultsUnBinnedNeutronSigmaApr11.txt";
  GetSigmaFromFile( VecAllChrisSigmaUnBinApr, VecAllChrisSigmaErrUnBinApr, VecAllChrisEgUnBinApr, VecAllChrisEgErrUnBinApr, VecAllChrisCosthUnBinApr,  VecAllChrisCosthErrUnBinApr,  InFileUnBinApr );


//////////////////////////////////////////////////////////////////////////////////////////////////

  //My Results
  Double_t ArrSigma[20];
  Double_t ArrCosth[20];
  Double_t ArrEg[20];
  Double_t ArrSigmaErr[20];
  Double_t ArrCosthErr[20];
  Double_t ArrEgErr[20];

  //My Results UnBin
  Double_t ArrSigmaUnBin[20];
  Double_t ArrCosthUnBin[20];
  Double_t ArrEgUnBin[20];
  Double_t ArrSigmaErrUnBin[20];
  Double_t ArrCosthErrUnBin[20];
  Double_t ArrEgErrUnBin[20];

  //My ResultsV2
  Double_t ArrSigmaApr[20];
  Double_t ArrCosthApr[20];
  Double_t ArrEgApr[20];
  Double_t ArrSigmaErrApr[20];
  Double_t ArrCosthErrApr[20];
  Double_t ArrEgErrApr[20];

  //My Results UnBinV2
  Double_t ArrSigmaUnBinApr[20];
  Double_t ArrCosthUnBinApr[20];
  Double_t ArrEgUnBinApr[20];
  Double_t ArrSigmaErrUnBinApr[20];
  Double_t ArrCosthErrUnBinApr[20];
  Double_t ArrEgErrUnBinApr[20];


  Double_t ArrSigmaPSCF[20];
  Double_t ArrSigmaPSCFCut[20];


  Double_t ArrSigmaCut[20];
  Double_t ArrCosthCut[20];
  Double_t ArrEgCut[20];
  Double_t ArrSigmaErrCut[20];
  Double_t ArrCosthErrCut[20];
  Double_t ArrEgErrCut[20];


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

///////////////////////////////////////////////////////////////////////////////////////////////////



  for(Int_t i=0;i<NDataEgBins;i++){//Number of eg bins//Deprecated*Number of folders(rand,sig,cut1) 41*3
    for(Int_t j=0;j<20;j++){ //Number of Costh Bins

      ArrSigmaNonCut[j] = VecAllChrisSigmaNonCut[j+i*20];
      ArrCosthNonCut[j] = VecAllChrisCosthNonCut[j+i*20];
      ArrEgNonCut[j] = VecAllChrisEgNonCut[j+i*20];
      ArrSigmaErrNonCut[j] = VecAllChrisSigmaErrNonCut[j+i*20];
      ArrCosthErrNonCut[j] = VecAllChrisCosthErrNonCut[j+i*20];
      ArrEgErrNonCut[j] = VecAllChrisEgErrNonCut[j+i*20];


      ArrSigmaCut[j] = VecAllChrisSigmaCut[j+i*20];
      ArrCosthCut[j] = VecAllChrisCosthCut[j+i*20];
      ArrEgCut[j] = VecAllChrisEgCut[j+i*20];
      ArrSigmaErrCut[j] = VecAllChrisSigmaErrCut[j+i*20];
      ArrCosthErrCut[j] = VecAllChrisCosthErrCut[j+i*20];
      ArrEgErrCut[j] = VecAllChrisEgErrCut[j+i*20];


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

      //MyResults
      ArrSigma[j] = VecAllChrisSigma[j+i*20];
      ArrCosth[j] = VecAllChrisCosth[j+i*20];
      ArrEg[j] = VecAllChrisEg[j+i*20];
      ArrSigmaErr[j] = VecAllChrisSigmaErr[j+i*20];
      ArrCosthErr[j] = VecAllChrisCosthErr[j+i*20];
      ArrEgErr[j] = VecAllChrisEgErr[j+i*20];

      //MyResults
      ArrSigmaUnBin[j] = VecAllChrisSigmaUnBin[j+i*20];
      ArrCosthUnBin[j] = VecAllChrisCosthUnBin[j+i*20];
      ArrEgUnBin[j] = VecAllChrisEgUnBin[j+i*20];
      ArrSigmaErrUnBin[j] = VecAllChrisSigmaErrUnBin[j+i*20];
      ArrCosthErrUnBin[j] = VecAllChrisCosthErrUnBin[j+i*20];
      ArrEgErrUnBin[j] = VecAllChrisEgErrUnBin[j+i*20];

      //MyResultsV2
      ArrSigmaApr[j] = VecAllChrisSigmaApr[j+i*20];
      ArrCosthApr[j] = VecAllChrisCosthApr[j+i*20];
      ArrEgApr[j] = VecAllChrisEgApr[j+i*20];
      ArrSigmaErrApr[j] = VecAllChrisSigmaErrApr[j+i*20];
      ArrCosthErrApr[j] = VecAllChrisCosthErrApr[j+i*20];
      ArrEgErrApr[j] = VecAllChrisEgErrApr[j+i*20];

      //MyResults Unbin V2
      ArrSigmaUnBinApr[j] = VecAllChrisSigmaUnBinApr[j+i*20];
      ArrCosthUnBinApr[j] = VecAllChrisCosthUnBinApr[j+i*20];
      ArrEgUnBinApr[j] = VecAllChrisEgUnBinApr[j+i*20];
      ArrSigmaErrUnBinApr[j] = VecAllChrisSigmaErrUnBinApr[j+i*20];
      ArrCosthErrUnBinApr[j] = VecAllChrisCosthErrUnBinApr[j+i*20];
      ArrEgErrUnBinApr[j] = VecAllChrisEgErrUnBinApr[j+i*20];





      TheoryEgamma= VecAllChrisEg[j+i*20];
      //  TheoryEgamma= VecAllChrisEgNonCut[j+i*20];



      //for(Int_t ff=0; ff<VecAllChrisSigmaPSCF.size(); ff++){

      //	cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  " << VecAllChrisSigmaPSCF[5+(i-9)*20] <<endl;
      //}
      //0,1,->10 i.e 11 in PSCF, i goes 0->23 i.e 24 : 430=9=i, 630 =19 so map is 9=0 and 19 = 11

      //cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG " << i <<"  " << TheoryEgamma <<endl;


      //FIX THIS ISSUE
      if(TheoryEgamma>420 && TheoryEgamma<640){
	//	if(   VecAllChrisSigmaPSCF[5+i*20]!=0 && VecAllChrisSigmaPSCF[6+i*20]!=0 ){ //i is wrong here since only have protoncorrection from 430>
	// ArrSigmaPSCF[j]=  VecAllChrisSigmaNon[j+i*20]*VecAllChrisSigmaPSCF[10+i*20];//Different NEgammaBins for Proton vs neutron
	//	  ArrSigmaPSCF[j]=  VecAllChrisSigma[j+(i-9)*20]/((VecAllChrisSigmaPSCF[5+(i-9)*20]+VecAllChrisSigmaPSCF[6+(i-9)*20]+VecAllChrisSigmaPSCF[7+(i-9)*20] + VecAllChrisSigmaPSCF[8+(i-9)*20] +VecAllChrisSigmaPSCF[9+(i-9)*20])/5);//Different NEgammaBins for Proton vs neutron
	//	  ArrSigmaPSCF[j]=  VecAllChrisSigma[j+(i-9)*20]*((VecAllChrisSigmaPSCF[5+(i-9)*20]+VecAllChrisSigmaPSCF[6+(i-9)*20]+VecAllChrisSigmaPSCF[7+(i-9)*20] + VecAllChrisSigmaPSCF[8+(i-9)*20] +VecAllChrisSigmaPSCF[9+(i-9)*20])/5);//Different NEgammaBins for Proton vs neutron
	ArrSigmaPSCF[j]=  VecAllChrisSigma[j+i*20]*((VecAllChrisSigmaPSCF[5+(i-9)*20]+VecAllChrisSigmaPSCF[6+(i-9)*20]+VecAllChrisSigmaPSCF[7+(i-9)*20] + VecAllChrisSigmaPSCF[8+(i-9)*20] +VecAllChrisSigmaPSCF[9+(i-9)*20])/5);//Different NEgammaBins for Proton vs neutron
//	cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX00000" << VecAllChrisSigmaPSCF[5+(i-9)*20]<< "  " << VecAllChrisSigmaPSCF[6+(i-9)*20] <<"  " <<  VecAllChrisSigmaPSCF[7+(i-9)*20] <<"  " <<  VecAllChrisSigmaPSCF[8+(i-9)*20] <<"   " <<  VecAllChrisSigmaPSCF[9+(i-9)*20] <<endl;

//	ArrSigmaPSCFCut[j]=  VecAllChrisSigmaCut[j+i*20]*((VecAllChrisSigmaPSCF[5+(i-9)*20]+VecAllChrisSigmaPSCF[6+(i-9)*20]+VecAllChrisSigmaPSCF[7+(i-9)*20] + VecAllChrisSigmaPSCF[8+(i-9)*20] +VecAllChrisSigmaPSCF[9+(i-9)*20])/5);//Different NEgammaBins for Proton vs neutron
	ArrSigmaPSCFCut[j]=  VecAllChrisSigmaCut[j+i*20]*((VecAllChrisSigmaPSCFCut[5+(i-9)*20]+VecAllChrisSigmaPSCFCut[6+(i-9)*20]+VecAllChrisSigmaPSCFCut[7+(i-9)*20] + VecAllChrisSigmaPSCFCut[8+(i-9)*20] +VecAllChrisSigmaPSCFCut[9+(i-9)*20])/5);//Different NEgammaBins for Proton vs neutron


	//	}
	//	else{
	//	  ArrSigmaPSCF[j]=0;
	//	}

      }
      else{
	ArrSigmaPSCF[j]=0;
	ArrSigmaPSCFCut[j]=0;
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

    TString InFileNameSAIDMB = "tmp/PageSAIDMoreBins.txt";
    vector<Double_t> VecSigmaSAIDMB;
    vector<Double_t> VecSigmaErrSAIDMB;
    vector<Double_t> VecEgSAIDMB;
    vector<Double_t> VecEgErrSAIDMB;
    vector<Double_t> VecCosthSAIDMB;
    vector<Double_t> VecCosthErrSAIDMB;


    TString InFileNameBnGa = "tmp/PageBnGa.txt";
    vector<Double_t> VecSigmaBnGa;
    vector<Double_t> VecSigmaErrBnGa;
    vector<Double_t> VecEgBnGa;
    vector<Double_t> VecEgErrBnGa;
    vector<Double_t> VecCosthBnGa;
    vector<Double_t> VecCosthErrBnGa;




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



    //GetBonnGatchina Predictions
    GetPi0BnGa( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighSAID, TheoryThetaLowSAID);
    GetBnGaSigmaFromFile( VecSigmaBnGa, VecSigmaErrBnGa,VecEgBnGa ,VecEgErrBnGa ,VecCosthBnGa ,VecCosthErrBnGa, TheoryThetaBins, InFileNameBnGa );

    //Get SAID More Bins Prediction
    GetPi0SAIDMoreBins( TheoryEgamma,  TheoryThetaBinsDouble, TheoryThetaHighSAID, TheoryThetaLowSAID);
    GetSAIDSigmaFromFile( VecSigmaSAIDMB, VecSigmaErrSAIDMB,VecEgSAIDMB, VecEgErrSAIDMB ,VecCosthSAIDMB ,VecCosthErrSAIDMB, TheoryThetaBinsDouble, InFileNameSAIDMB );

    //Fill arrays for bnga
    Int_t NumBnGaPts = VecSigmaBnGa.size();
    Double_t ArrSigmaBnGa[NumBnGaPts];
    Double_t ArrSigmaErrBnGa[NumBnGaPts];
    Double_t ArrEgBnGa[NumBnGaPts];
    Double_t ArrEgErrBnGa[NumBnGaPts];
    Double_t ArrCosthBnGa[NumBnGaPts];
    Double_t ArrCosthErrBnGa[NumBnGaPts];

    for(Int_t vv=0; vv<VecSigmaBnGa.size();vv++){
      ArrSigmaBnGa[vv] = VecSigmaBnGa[vv];
      ArrSigmaErrBnGa[vv] = VecSigmaErrBnGa[vv];
      ArrEgBnGa[vv] = VecEgBnGa[vv];
      ArrEgErrBnGa[vv] = VecEgErrBnGa[vv];
      ArrCosthBnGa[vv] = VecCosthBnGa[vv];
      ArrCosthErrBnGa[vv] = VecCosthErrBnGa[vv];
    }

    //Fill arrays for said more bins
    Int_t NumSAIDMBPts = VecSigmaSAIDMB.size();
    Double_t ArrSigmaSAIDMB[NumSAIDMBPts];
    Double_t ArrSigmaErrSAIDMB[NumSAIDMBPts];
    Double_t ArrEgSAIDMB[NumSAIDMBPts];
    Double_t ArrEgErrSAIDMB[NumSAIDMBPts];
    Double_t ArrCosthSAIDMB[NumSAIDMBPts];
    Double_t ArrCosthErrSAIDMB[NumSAIDMBPts];

    for(Int_t vv=0; vv<VecSigmaSAIDMB.size();vv++){
      ArrSigmaSAIDMB[vv] = VecSigmaSAIDMB[vv];
      ArrSigmaErrSAIDMB[vv] = VecSigmaErrSAIDMB[vv];
      ArrEgSAIDMB[vv] = VecEgSAIDMB[vv];
      ArrEgErrSAIDMB[vv] = VecEgErrSAIDMB[vv];
      ArrCosthSAIDMB[vv] = VecCosthSAIDMB[vv];
      ArrCosthErrSAIDMB[vv] = VecCosthErrSAIDMB[vv];
    }



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
    TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotUnBin=new TGraphErrors(20,ArrCosthUnBin,ArrSigmaUnBin,ArrCosthErrUnBin,ArrSigmaErrUnBin);
    TGraph* SigmaPlotApr=new TGraphErrors(20,ArrCosthApr,ArrSigmaApr,ArrCosthErrApr,ArrSigmaErrApr);
    TGraph* SigmaPlotUnBinApr=new TGraphErrors(20,ArrCosthUnBinApr,ArrSigmaUnBinApr,ArrCosthErrUnBinApr,ArrSigmaErrUnBinApr);
    TGraph* SigmaPlotNonCut=new TGraphErrors(20,ArrCosthNonCut,ArrSigmaNonCut,ArrCosthErrNonCut,ArrSigmaErrNonCut);
    TGraph* SigmaPlotCut=new TGraphErrors(20,ArrCosthCut,ArrSigmaCut,ArrCosthErrCut,ArrSigmaErrCut);
    TGraph* SigmaPlotNon=new TGraphErrors(20,ArrCosthNon,ArrSigmaNon,ArrCosthErrNon,ArrSigmaErrNon);
    TGraph* SigmaPlotStrict=new TGraphErrors(20,ArrCosthStrict,ArrSigmaStrict,ArrCosthErrStrict,ArrSigmaErrStrict);
    //    TGraph* DivisionPlotSAID=new TGraph(20,ArrCosthSAID,ArrSigmaSAIDDiv);
    TGraph* SigmaPlotSAID=new TGraphErrors(20,ArrCosth,ArrSigmaSAID,ArrCosthErrNonCut,ArrSigmaErrNonCut);
    //    TGraph* DivisionPlotMAID=new TGraph(20,ArrCosthMAIDNew,ArrSigmaMAIDDiv);
    TGraph* SigmaPlotMAID=new TGraphErrors(20,ArrCosth,ArrSigmaMAIDNew,ArrCosthErrNonCut,ArrSigmaErrNonCut);
    //    TGraph* SigmaPlotCorrectedMAID=new TGraphErrors(20,ArrCosthMAIDNew,ArrSigmaMineCorrectedMAID,ArrCosthErr,ArrSigmaErr);
    //   TGraph* SigmaPlotCorrectedSAID=new TGraphErrors(20,ArrCosthSAID,ArrSigmaMineCorrectedSAID,ArrCosthErr,ArrSigmaErr);
    //SpecMom Binned cuts Analysis
    //    TGraph* SigmaPlotSpec=new TGraphErrors(20,ArrCosthSpec,ArrSigmaSpec,ArrCosthErrSpec,ArrSigmaErrSpec);
    //    TGraph* SigmaPlotPSCF=new TGraphErrors(20,ArrCosthNon,ArrSigmaPSCF,ArrCosthErrNon,ArrSigmaErrNon);
    TGraph* SigmaPlotPSCF=new TGraphErrors(20,ArrCosth,ArrSigmaPSCF,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotPSCFCut=new TGraphErrors(20,ArrCosthCut,ArrSigmaPSCFCut,ArrCosthErrCut,ArrSigmaErrCut);


    TGraph* SigmaPlotBnGa=new TGraphErrors( sizeof(ArrSigmaBnGa)/sizeof(ArrSigmaBnGa[0]),ArrCosthBnGa,ArrSigmaBnGa,ArrCosthErrBnGa,ArrSigmaErrBnGa);
    TGraph* SigmaPlotSAIDMB=new TGraphErrors( sizeof(ArrSigmaSAIDMB)/sizeof(ArrSigmaSAIDMB[0]),ArrCosthSAIDMB,ArrSigmaSAIDMB,ArrCosthErrSAIDMB,ArrSigmaErrSAIDMB);




    //Set Marker Style/Color
    //    DivisionPlotSAID->SetMarkerStyle(31);
    //    DivisionPlotSAID->SetMarkerColor(6);
    //    DivisionPlotMAID->SetMarkerStyle(32);
    //    DivisionPlotMAID->SetMarkerColor(8);
    SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)
    SigmaPlotNonCut->SetMarkerStyle(22);//
    SigmaPlotNonCut->SetMarkerColor(6);  //black
    SigmaPlotCut->SetMarkerStyle(22);//
    SigmaPlotCut->SetMarkerColor(2);  //black
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
    SigmaPlotPSCFCut->SetMarkerStyle(22);//
    SigmaPlotPSCFCut->SetMarkerColor(9);//purple 
    //    SigmaPlotSpec->SetMarkerStyle(22);//
    //    SigmaPlotSpec->SetMarkerColor(2);  //red
    //    SigmaPlotCorrectedSAID->SetMarkerStyle(29);//Filled triangle(black(default)
    //    SigmaPlotCorrectedSAID->SetMarkerColor(9); //purple
    //    SigmaPlotCorrectedMAID->SetMarkerStyle(30);//Filled triangle(black(default)
    //    SigmaPlotCorrectedMAID->SetMarkerColor(8); //green(not lime)

    SigmaPlotUnBin->SetMarkerStyle(22);//
    SigmaPlotUnBin->SetMarkerColor(2);//red  


    SigmaPlotApr->SetMarkerStyle(22);//
    SigmaPlotApr->SetMarkerColor(3);//green  

    SigmaPlotUnBinApr->SetMarkerStyle(22);//
    SigmaPlotUnBinApr->SetMarkerColor(6);//pink  


    SigmaPlotBnGa->SetMarkerStyle(23);//filled upside down triangle(blue)
    SigmaPlotBnGa->SetMarkerColor(7);//pink
 
    SigmaPlotSAIDMB->SetMarkerStyle(23);//filled upside down triangle(blue)
    SigmaPlotSAIDMB->SetMarkerColor(1);//6=pink1=black




    //Set Fill Style/Color
    SigmaPlotSAID->SetFillStyle(0);
    SigmaPlotSAID->SetFillColor(0);
    SigmaPlotMAID->SetFillStyle(0);
    SigmaPlotMAID->SetFillColor(0);
    SigmaPlotNonCut->SetFillStyle(0);
    SigmaPlotNonCut->SetFillColor(0);
    SigmaPlotCut->SetFillStyle(0);
    SigmaPlotCut->SetFillColor(0);
    SigmaPlotNon->SetFillStyle(0);
    SigmaPlotNon->SetFillColor(0);
    SigmaPlotStrict->SetFillStyle(0);
    SigmaPlotStrict->SetFillColor(0);
    SigmaPlotPSCF->SetFillStyle(0);
    SigmaPlotPSCF->SetFillColor(0);
    SigmaPlotPSCFCut->SetFillStyle(0);
    SigmaPlotPSCFCut->SetFillColor(0);


    SigmaPlotUnBin->SetFillStyle(0);
    SigmaPlotUnBin->SetFillColor(0);

    SigmaPlotApr->SetFillStyle(0);
    SigmaPlotApr->SetFillColor(0);

    SigmaPlotUnBinApr->SetFillStyle(0);
    SigmaPlotUnBinApr->SetFillColor(0);
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

    SigmaPlotBnGa->SetFillStyle(0);//pink
    SigmaPlotBnGa->SetFillColor(0);//pink
 
    SigmaPlotSAIDMB->SetFillStyle(0);//pink
    SigmaPlotSAIDMB->SetFillColor(0);//pink

    //Set Title
    SigmaPlotSAID->SetTitle("SAID");
    SigmaPlotMAID->SetTitle("MAID");
    SigmaPlotNonCut->SetTitle("NonCut");
    SigmaPlotCut->SetTitle("CutsApr252019");
    SigmaPlotNon->SetTitle("Non");
    SigmaPlotStrict->SetTitle("StrictCuts");
    SigmaPlotPSCF->SetTitle("ProtonSAIDCorrection");
    SigmaPlotPSCFCut->SetTitle("ProtonSAIDCorrectionUsingCutsBasedAndCutResults");
    SigmaPlot->SetTitle("CoplanFits");
    SigmaPlotUnBin->SetTitle("UnBinnedFit");
    SigmaPlotApr->SetTitle("CoplanFitsApr");
    SigmaPlotUnBinApr->SetTitle("UnBinnedFitApr");
    //    SigmaPlotCorrectedSAID->SetTitle("CorrectedWithSAID");
    //    SigmaPlotCorrectedMAID->SetTitle("CorrectedWithMAID");
    //    SigmaPlotSpec->SetTitle("SpecMom0-50Mev");
    //    SigmaPlot->SetTitle("CoplanFitsOrig");//pink
    //    DivisionPlotSAID->SetTitle("SAIDDivision");//pink
    //    DivisionPlotMAID->SetTitle("MAIDDivision");//pink
    SigmaPlotBnGa->SetTitle("BonnGatchina");//pink
    SigmaPlotSAIDMB->SetTitle("SAIDMoreBins");//pink


    //Create Multigraph and add plots to it 
    TMultiGraph* mg = new TMultiGraph();
//    mg->Add(SigmaPlot);
//    mg->Add(SigmaPlotUnBin);

    mg->Add(SigmaPlotApr); //green 3
    mg->Add(SigmaPlotUnBinApr);// pink 6
    //    mg->Add(DivisionPlotSAID);
    //    mg->Add(DivisionPlotMAID);
    //    mg->Add(SigmaPlotSpec);
//    mg->Add(SigmaPlotSAID);
    //    mg->Add(SigmaPlotMAID);
    //    mg->Add(SigmaPlotNonCut);
        mg->Add(SigmaPlotCut); //red 2
    //    mg->Add(SigmaPlotNon);
//    mg->Add(SigmaPlotPSCF);
    mg->Add(SigmaPlotPSCFCut);// purple 9
//        mg->Add(SigmaPlotStrict);
    //    mg->Add(SigmaPlotCorrectedSAID);
    //    mg->Add(SigmaPlotCorrectedMAID);

    mg->Add(SigmaPlotBnGa); // cyan 7
    mg->Add(SigmaPlotSAIDMB); // black 1



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






void GetPi0BnGa(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){


  TString  Header;
  TString  Ranges;
  TString  Total ;
  TString  Line  ;
  //  TString  Reaction = "pion_00"; 
  TString  Reaction = "pion_pd"; 
  //  TString  obs = "cs";
  TString  obs = "s";
  TString  fixVar = "W";
  TString  runVar ="z"; //"cosA"; z=cosA
  Double_t W = ConvertToCME(Egamma);


  //  Header = "http://pwa.hiskp.uni-bonn.de/obs_int_new1.pl?param02="+ Reaction + "&param03="+obs+ "_&param01=BG2014_02";
  Header = "https://pwa.hiskp.uni-bonn.de/obs_int_gn.pl?param02="+ Reaction + "&param03="+obs+ "_&param01=BG2014_02";
  Ranges = "&param04=" +fixVar+Form("&param05=%f",W)+ "&param12=1&param11=20&param10=" +runVar+Form("&param06=%f",ThLow) + Form("&param07=%f",ThHigh)+ "&param08=0&param09=0";
  Total = Header + Ranges;
  Line = "wget '"+Total+"' -O tmp/PageBnGa.txt";
  gSystem->Exec(Line);




}

void GetBnGaSigmaFromFile(vector<Double_t>  &VecSigmaBnGa, vector<Double_t> &VecSigmaErrBnGa, vector<Double_t> &VecEgBnGa ,vector<Double_t> &VecEgErrBnGa ,vector<Double_t> &VecCosthBnGa ,vector<Double_t> &VecCosthErrBnGa, Double_t NThetaBins ,TString BnGaFileName ){


  Double_t lineCount=0;
  Double_t Sigma;
  Double_t SigmaErr;
  Double_t Eg;
  Double_t EgErr;
  Double_t Costh;
  Double_t CosthErr;
  std::ifstream inputFileBn(BnGaFileName);
  std::string lineBn;
  if (inputFileBn.is_open()){
    while(getline(inputFileBn, lineBn) ){
      if(lineCount<19 || lineCount>(19+2*NThetaBins)  ){
        lineCount=lineCount+1;
      }
      else{
        stringstream(lineBn)>>Costh >> Sigma;
        VecSigmaBnGa.push_back(Sigma);
        VecEgBnGa.push_back(0);
        VecCosthBnGa.push_back(Costh);
        VecSigmaErrBnGa.push_back(0.0001);
        VecEgErrBnGa.push_back(10);
        VecCosthErrBnGa.push_back(0.005);

        lineCount=lineCount+1;

      }

    }
  }
  inputFileBn.close();




}

void GetPi0SAIDMoreBins(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){


  TString  Header;
  TString  Ranges;
  TString  Total ;
  TString  Line  ;
  //  TString  Reaction = "1"; //Choosing first reaction from (http://gwdac.phys.gwu.edu/analysis/pr_analysis.html) 1 is Pi0P can check in the saved webpage
  TString  Reaction = "4"; //Choosing first reaction from (http://gwdac.phys.gwu.edu/analysis/pr_analysis.html) 1 is Pi0P can check in the saved webpage
  TString  obs = "S";
  TString  fixVar = "ELab";
  TString  runVar = "cosA";

  Double_t thetaStep = (ThHigh-ThLow)/(NThetaBins);

  Header ="http://gwdac.phys.gwu.edu/cgi-bin/go3pr2?sl=CM12&rt=" + Reaction+ "&ot="+obs;
  Ranges = "&iv="+runVar+ Form("&il=%f&ii=%f&iu=%f",ThLow,thetaStep,ThHigh)+ "&fv="+fixVar+Form("&fn=%f",Egamma);
  Total =Header +  Ranges ;
  Line = "wget '"+Total+"' -O tmp/PageSAIDMoreBins.txt";

  gSystem->Exec(Line);






}  

void GetSAIDSigmaFromFile(vector<Double_t>  &VecSigmaSAIDMB, vector<Double_t> &VecSigmaErrSAIDMB, vector<Double_t> &VecEgSAIDMB ,vector<Double_t> &VecEgErrSAIDMB ,vector<Double_t> &VecCosthSAIDMB ,vector<Double_t> &VecCosthErrSAIDMB, Double_t NThetaBins ,TString SAIDMBFileName ){


  Double_t lineCount=0;
  Double_t Sigma;
  Double_t SigmaErr;
  Double_t Eg;
  Double_t EgErr;
  Double_t Costh;
  Double_t CosthErr;
  std::ifstream inputFileBn(SAIDMBFileName);
  std::string lineBn;
  if (inputFileBn.is_open()){
    while(getline(inputFileBn, lineBn) ){
      if(lineCount<7 || lineCount>(7+NThetaBins)  ){
        lineCount=lineCount+1;
      }
      else{
        stringstream(lineBn)>>Costh >> Sigma;
        VecSigmaSAIDMB.push_back(Sigma);
        VecEgSAIDMB.push_back(0);
        VecCosthSAIDMB.push_back(Costh);
        VecSigmaErrSAIDMB.push_back(0.0001);
        VecEgErrSAIDMB.push_back(10);
        VecCosthErrSAIDMB.push_back(0.005);

        lineCount=lineCount+1;


      }

    }
  }
  inputFileBn.close();





}







