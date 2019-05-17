#include <stdlib.h>
#include <TString.h>

void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName );
void GetCorrectionFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecEg ,vector<Double_t> &VecCosth , TString InFileName );
Double_t ConvertToCME(Double_t taggE);



void PlotResultsThesis() {
		
  //  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ResultsNPi0TheoryDataComparisonNPi0Theory.root","recreate");
  //  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/TestDelSoon.root","recreate");
  //  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/DevCodeNPi0.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/MeetingFeb28/NPi0AllPlotted.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr112019/NPi0CoplanFitsAndUnBinnedVersusNewVersionOfBoth.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr112019/NPi0CoplanFitsOldVsNewApr.root","recreate");
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr112019/NPi0UnBinnedOldVersusNewApr.root","recreate");

  Double_t NDataEgBins = 24 ; //Number of bins in data for looping
  Double_t TheoryThetaBinsDouble = 40;
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


  TString InFileNon = "Data/MyResultsBGSUBBEDNPi0NonStrictCutsSpecMomCutAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaNon, VecAllChrisSigmaErrNon, VecAllChrisEgNon, VecAllChrisEgErrNon, VecAllChrisCosthNon,  VecAllChrisCosthErrNon,  InFileNon );


  TString InFileStrict = "Data/MyResultsBGSUBBEDNPi0StrictCutsSpecMomCutAnalysis.txt";
  GetSigmaFromFile( VecAllChrisSigmaStrict, VecAllChrisSigmaErrStrict, VecAllChrisEgStrict, VecAllChrisEgErrStrict, VecAllChrisCosthStrict,  VecAllChrisCosthErrStrict,  InFileStrict );


  //PSCF Proton SAID Correction Factor
  TString InFilePSCF = "../SAIDProtonCorrectionFactor.txt";
  GetCorrectionFromFile( VecAllChrisSigmaPSCF, VecAllChrisEgPSCF, VecAllChrisCosthPSCF, InFilePSCF );



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
	cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX00000" << VecAllChrisSigmaPSCF[5+(i-9)*20]<< "  " << VecAllChrisSigmaPSCF[6+(i-9)*20] <<"  " <<  VecAllChrisSigmaPSCF[7+(i-9)*20] <<"  " <<  VecAllChrisSigmaPSCF[8+(i-9)*20] <<"   " <<  VecAllChrisSigmaPSCF[9+(i-9)*20] <<endl;



	//	}
	//	else{
	//	  ArrSigmaPSCF[j]=0;
	//	}

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

    SigmaPlotUnBin->SetMarkerStyle(22);//
    SigmaPlotUnBin->SetMarkerColor(2);//red  


    SigmaPlotApr->SetMarkerStyle(22);//
    SigmaPlotApr->SetMarkerColor(3);//green  

    SigmaPlotUnBinApr->SetMarkerStyle(22);//
    SigmaPlotUnBinApr->SetMarkerColor(6);//pink  


    SigmaPlotBnGa->SetMarkerStyle(23);//filled upside down triangle(blue)
    SigmaPlotBnGa->SetMarkerColor(7);//pink
 
    SigmaPlotSAIDMB->SetMarkerStyle(23);//filled upside down triangle(blue)
    SigmaPlotSAIDMB->SetMarkerColor(6);//pink




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
    SigmaPlotNon->SetTitle("Non");
    SigmaPlotStrict->SetTitle("StrictCuts");
    SigmaPlotPSCF->SetTitle("ProtonSAIDCorrection");
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
    mg->Add(SigmaPlotUnBin);

//    mg->Add(SigmaPlotApr);
    mg->Add(SigmaPlotUnBinApr);
    //    mg->Add(DivisionPlotSAID);
    //    mg->Add(DivisionPlotMAID);
    //    mg->Add(SigmaPlotSpec);
//    mg->Add(SigmaPlotSAID);
    //    mg->Add(SigmaPlotMAID);
    //    mg->Add(SigmaPlotNonCut);
    //    mg->Add(SigmaPlotNon);
//    mg->Add(SigmaPlotPSCF);
//        mg->Add(SigmaPlotStrict);
    //    mg->Add(SigmaPlotCorrectedSAID);
    //    mg->Add(SigmaPlotCorrectedMAID);

//    mg->Add(SigmaPlotBnGa);
//    mg->Add(SigmaPlotSAIDMB);



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













