#include <stdlib.h>
#include <TString.h>

// FIX SAID By getting -1->1 with 0.05 increments and only use either a curve/line or every second point(skip -1 but select -0.95)


void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName );
//void GetSigmaTheoryFromFile(vector<Double_t>  &VecSigma2, vector<Double_t> &VecCosth2,  TString InFileName2,  Double_t NThetaBins2 );
void GetSigmaTheoryFromFile(Double_t  ArrSigma2[], Double_t ArrCosth2[],  TString InFileName2,  Double_t NThetaBins2, Double_t IsTheoryMAID );

Double_t ConvertToCME(Double_t taggE);


void GetPi0SAIDDataResults(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow,Double_t EgammaHigh ,Double_t EgammaLow);  //Next Step MAID, and getting the right theory points, DONE
void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);  //Next Step MAID, and getting the right theory points, DONE
// get NPi0 cuts sorted using the sims and run cuts analysis,
//  do fits analysis,
//  do unbinned phi for both channels, 
//  get a correction factor for costheta0 bin from SAID for every bin from PPi0 and apply to NPi0,
//   then classification with the separate folder  
void GetPi0MAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);
//void DecodePi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);

void GetPreviousDataResults(TString InFileDataResults, Double_t EgammaBin);  
void GetPreviousDataResultsSigmaFromFile(vector<Double_t>  &VecSigmaDR, vector<Double_t> &VecSigmaErrDR, vector<Double_t> &VecEgDR ,vector<Double_t> &VecEgErrDR ,vector<Double_t> &VecCosthDR ,vector<Double_t> &VecCosthErrDR, TString PrevDataFileName );



void TestFuncArray() {
		
 // TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/PPi0SAIDCorrection10PercentCorrection.root","recreate");
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/PPi0SimonAllPointsVsCoplanFits.root","recreate");
  

  Double_t TheoryThetaBins = 20;
  Double_t TheoryThetaLowSAID = -1;
  Double_t TheoryThetaLowMAID = 0;
  Double_t TheoryThetaHighSAID =1 ;
  Double_t TheoryThetaHighMAID =180 ;
  Double_t TheoryEgamma;
  Double_t TheoryEgammaHigh;
  Double_t TheoryEgammaLow;


  vector<Double_t> VecAllChrisSigma;
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

  //Simons Results
  vector<Double_t> VecAllSimonSigma;
  vector<Double_t> VecAllSimonEg;
  vector<Double_t> VecAllSimonCosth;
  vector<Double_t> VecAllSimonSigmaErr;
  vector<Double_t> VecAllSimonEgErr;
  vector<Double_t> VecAllSimonCosthErr;

  //Simons Results WeightedMean
  vector<Double_t> VecAllSimonSigmaV2;
  vector<Double_t> VecAllSimonEgV2;
  vector<Double_t> VecAllSimonCosthV2;
  vector<Double_t> VecAllSimonSigmaErrV2;
  vector<Double_t> VecAllSimonEgErrV2;
  vector<Double_t> VecAllSimonCosthErrV2;


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

  //Simon Results
  Double_t AllSimonSigma;
  Double_t AllSimonEg;
  Double_t AllSimonCosth;
  Double_t AllSimonSigmaErr;
  Double_t AllSimonEgErr;
  Double_t AllSimonCosthErr;
	
  //Simon Results
  Double_t AllSimonSigmaV2;
  Double_t AllSimonEgV2;
  Double_t AllSimonCosthV2;
  Double_t AllSimonSigmaErrV2;
  Double_t AllSimonEgErrV2;
  Double_t AllSimonCosthErrV2;




  //  Double_t Eg1 =580 ;
  //  Double_t NThetaBins = 20 ;
  //  Double_t ThetaHigh =180 ;
  //  Double_t ThetaLow =0 ;
  // GetPi0SAID( Eg1, NThetaBins, ThetaHigh, ThetaLow);

  TString InFile = "Data/CutResultsNew.txt";
  GetSigmaFromFile( VecAllChrisSigma, VecAllChrisSigmaErr, VecAllChrisEg, VecAllChrisEgErr, VecAllChrisCosth,  VecAllChrisCosthErr,  InFile );


  TString InFileSpec = "Data/CutResultsNewNonStrictSpecMomBins0to50Mev.txt";
  GetSigmaFromFile( VecAllChrisSigmaSpec, VecAllChrisSigmaErrSpec, VecAllChrisEgSpec, VecAllChrisEgErrSpec, VecAllChrisCosthSpec,  VecAllChrisCosthErrSpec,  InFileSpec);


  TString InFileSimon = "Data/NewSimonsResultsMyBins.txt";
  GetSigmaFromFile( VecAllSimonSigma, VecAllSimonSigmaErr, VecAllSimonEg, VecAllSimonEgErr, VecAllSimonCosth,  VecAllSimonCosthErr,  InFileSimon);

  TString InFileSimonV2 = "Data/Feb19NewSimonsResultsMyBins.txt";
  GetSigmaFromFile( VecAllSimonSigmaV2, VecAllSimonSigmaErrV2, VecAllSimonEgV2, VecAllSimonEgErrV2, VecAllSimonCosthV2,  VecAllSimonCosthErrV2,  InFileSimonV2);


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

  //Simons results
  Double_t ArrSigmaSimon[20];
  Double_t ArrSigmaDiv[20];
  Double_t ArrCosthSimon[20];
  Double_t ArrEgSimon[20];
  Double_t ArrSigmaSimonErr[20];
  Double_t ArrSigmaDivErr[20];  //Need to think about computing this! Or set to zero for now.
  Double_t ArrCosthSimonErr[20];
  Double_t ArrEgSimonErr[20];

  //Simons results
  Double_t ArrSigmaSimonV2[20];
  Double_t ArrSigmaDivV2[20];
  Double_t ArrCosthSimonV2[20];
  Double_t ArrEgSimonV2[20];
  Double_t ArrSigmaSimonErrV2[20];
  Double_t ArrSigmaDivErrV2[20];  //Need to think about computing this! Or set to zero for now.
  Double_t ArrCosthSimonErrV2[20];
  Double_t ArrEgSimonErrV2[20];



  for(Int_t i=0;i<11;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
    for(Int_t j=0;j<20;j++){

      //MyResults
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

      //Simons Results
      ArrSigmaSimon[j] = VecAllSimonSigma[j+i*20];
      ArrCosthSimon[j] = VecAllSimonCosth[j+i*20];
      ArrEgSimon[j] = VecAllSimonEg[j+i*20];
      ArrSigmaSimonErr[j] = VecAllSimonSigmaErr[j+i*20];
      ArrCosthSimonErr[j] = VecAllSimonCosthErr[j+i*20];
      ArrEgSimonErr[j] = VecAllSimonEgErr[j+i*20];

      //Simons Results
      ArrSigmaSimonV2[j] = VecAllSimonSigmaV2[j+i*20];
      ArrCosthSimonV2[j] = VecAllSimonCosthV2[j+i*20];
      ArrEgSimonV2[j] = VecAllSimonEgV2[j+i*20];
      ArrSigmaSimonErrV2[j] = VecAllSimonSigmaErrV2[j+i*20];
      ArrCosthSimonErrV2[j] = VecAllSimonCosthErrV2[j+i*20];
      ArrEgSimonErrV2[j] = VecAllSimonEgErrV2[j+i*20];

      if(VecAllSimonSigma[j+i*20]!=0){
	ArrSigmaDiv[j] = VecAllChrisSigma[j+i*20]/VecAllSimonSigma[j+i*20]; 
      }
      else{
	ArrSigmaDiv[j]=0;
      }

      if(VecAllSimonSigmaV2[j+i*20]!=0){
        ArrSigmaDivV2[j] = VecAllChrisSigma[j+i*20]/VecAllSimonSigmaV2[j+i*20];
      }
      else{
        ArrSigmaDivV2[j]=0;
      }


      TheoryEgamma= VecAllChrisEg[j+i*20];
      TheoryEgammaHigh= VecAllChrisEg[j+i*20] +10;
      TheoryEgammaLow= VecAllChrisEg[j+i*20] -10;

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

    TString InFileNameSAIDData = "tmp/PageSAIDDataResults.txt";
    vector<Double_t> VecSigmaGA;
    vector<Double_t> VecSigmaErrGA;
    vector<Double_t> VecEgGA;
    vector<Double_t> VecEgErrGA;
    vector<Double_t> VecCosthGA;
    vector<Double_t> VecCosthErrGA;

    TString PrevDataDir;
    TString PrevDataDir1 ="tmp/PreviousData/" ;
    TString PrevDataFileNameGA;
    PrevDataDir = PrevDataDir1 + Form("%f",TheoryEgamma)+"/"; //+ ".000000/";
    PrevDataFileNameGA = PrevDataDir + "GA\(16\).txt";
    cout << TheoryEgamma <<"YASDASJDJASJDJASNDJNASNDNASNDNSA" << endl;

    Double_t ArrSigmaMineCorrectedMAID[20];
    Double_t ArrSigmaMineCorrectedSAID[20];



    //GetSAID Predictions
    GetPi0SAID( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighSAID, TheoryThetaLowSAID);
    //    GetSigmaTheoryFromFile(VecSigmaSAID, VecCosthSAID ,  InFileNameSAID,  TheoryThetaBins);
    GetSigmaTheoryFromFile(ArrSigmaSAID, ArrCosthSAID ,  InFileNameSAID,  TheoryThetaBins,IsMAID);

    //GetMAID predictions //MAID File gives me 21 for some reason, fix later,removed last(180) point for now
    GetPi0MAID( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighMAID, TheoryThetaLowMAID);
    IsMAID=1;
    GetSigmaTheoryFromFile(ArrSigmaMAID, ArrCosthMAID ,  InFileNameMAID,  TheoryThetaBins,IsMAID);



    //Get the Data that SAID uses for this bin since do not have simons data in Glasgow
    GetPi0SAIDDataResults( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighSAID, TheoryThetaLowSAID,TheoryEgammaHigh,TheoryEgammaLow);
    GetPreviousDataResults(InFileNameSAIDData,TheoryEgamma );
    GetPreviousDataResultsSigmaFromFile( VecSigmaGA, VecSigmaErrGA,VecEgGA ,VecEgErrGA ,VecCosthGA ,VecCosthErrGA, PrevDataFileNameGA );


	Int_t a = VecSigmaGA.size();
	cout <<a << endl;


Double_t ArrSigmaPrevDataGA[a];
Double_t ArrSigmaErrPrevDataGA[a];
Double_t ArrEgPrevDataGA[a];
Double_t ArrEgErrPrevDataGA[a];
Double_t ArrCosthPrevDataGA[a];
Double_t ArrCosthErrPrevDataGA[a];

for(Int_t ff=0; ff<VecSigmaGA.size();ff++){

 ArrSigmaPrevDataGA[ff] = VecSigmaGA[ff];
 ArrSigmaErrPrevDataGA[ff] = VecSigmaErrGA[ff];
 ArrEgPrevDataGA[ff] = VecEgGA[ff];
 ArrEgErrPrevDataGA[ff] = VecEgErrGA[ff];
 ArrCosthPrevDataGA[ff] = VecCosthGA[ff];
 ArrCosthErrPrevDataGA[ff] = VecCosthErrGA[ff];



}





    for(Int_t j=0;j<20;j++){

      if(ArrSigmaSAID[j]!=0){
	ArrSigmaSAIDDiv[j] = VecAllChrisSigma[j+i*20]/ArrSigmaSAID[j]; 
//	ArrSigmaSAIDDiv[j] = VecAllChrisSigma[j+i*20]/( (ArrSigmaSAID[5]+ArrSigmaSAID[6]+ArrSigmaSAID[7]+ArrSigmaSAID[8]+ArrSigmaSAID[9]) /5); //New method Feb19
      }
      else{
	ArrSigmaSAIDDiv[j]=0;
      }

	
      //Convert ArrCosthMAID to Costh from theta and reverse the ordering in both arrays
      ArrCosthMAIDNew[j] = TMath::Cos( TMath::DegToRad()*  (ArrCosthMAID[19-j] ) );
      ArrSigmaMAIDNew[j] = ArrSigmaMAID[19-j];

      if(ArrSigmaMAIDNew[j]!=0){
	ArrSigmaMAIDDiv[j] = VecAllChrisSigma[j+i*20]/ArrSigmaMAIDNew[j]; 
//	ArrSigmaMAIDDiv[j] = VecAllChrisSigma[j+i*20]/ArrSigmaMAIDNew[j]; //New method feb19 to use 0->-0.5 average
      }
      else{
	ArrSigmaMAIDDiv[j]=0;
      }

    }

    //May Overwrite every iter Probs need to close every cos iter
    std::ofstream textfile;
    textfile.open("SAIDProtonCorrectionFactor.txt",std::ios_base::app);

    for(Int_t j=0;j<20;j++){

//      ArrSigmaMineCorrectedMAID[j]=VecAllChrisSigma[j+i*20]/ArrSigmaMAIDDiv[10];
//      ArrSigmaMineCorrectedSAID[j]=VecAllChrisSigma[j+i*20]/ArrSigmaSAIDDiv[10] ;
//      textfile << ArrSigmaSAIDDiv[j] <<"  " << VecAllChrisEg[j+i*20]  <<"  " << VecAllChrisCosth[j+i*20] <<endl;


      ArrSigmaMineCorrectedMAID[j]=VecAllChrisSigma[j+i*20]/( 1.1 );
//      ArrSigmaMineCorrectedMAID[j]=VecAllChrisSigma[j+i*20]/( (ArrSigmaMAIDDiv[5] + ArrSigmaMAIDDiv[6] + ArrSigmaMAIDDiv[7] + ArrSigmaMAIDDiv[8] +ArrSigmaMAIDDiv[9])/5 );
      ArrSigmaMineCorrectedSAID[j]=VecAllChrisSigma[j+i*20]/(   (ArrSigmaSAIDDiv[5]+ ArrSigmaSAIDDiv[6] +ArrSigmaSAIDDiv[7] + ArrSigmaSAIDDiv[8] +ArrSigmaMAIDDiv[9]   )/5 );
      textfile << ArrSigmaSAIDDiv[j] << "    " << VecAllChrisEg[j+i*20] <<"   " << VecAllChrisCosth[j+i*20] <<endl;

    }


    auto c3 = new TCanvas("c3","c3");
    TString PosTitle =Form("%f",ArrEg[0]) ;
    TString PosName = Form("%f",ArrEg[0]) ;
    TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotSimon=new TGraphErrors(20,ArrCosthSimon,ArrSigmaSimon,ArrCosthSimonErr,ArrSigmaSimonErr);
    TGraph* DivisionPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaDiv);
    TGraph* SigmaPlotSimonV2=new TGraphErrors(20,ArrCosthSimonV2,ArrSigmaSimonV2,ArrCosthSimonErrV2,ArrSigmaSimonErrV2);
    TGraph* DivisionPlotSimonV2=new TGraph(20,ArrCosthSimonV2,ArrSigmaDivV2);
    TGraph* DivisionPlotSAID=new TGraph(20,ArrCosthSAID,ArrSigmaSAIDDiv);
//    TGraph* SigmaPlotSAID=new TGraphErrors(20,ArrCosthSAID,ArrSigmaSAID,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotSAID=new TGraphErrors(20,ArrCosth,ArrSigmaSAID,ArrCosthErr,ArrSigmaErr);
    TGraph* DivisionPlotMAID=new TGraph(20,ArrCosthMAIDNew,ArrSigmaMAIDDiv);
    TGraph* SigmaPlotMAID=new TGraphErrors(20,ArrCosthMAIDNew,ArrSigmaMAIDNew,ArrCosthErr,ArrSigmaErr);
//    TGraph* SigmaPlotCorrectedMAID=new TGraphErrors(20,ArrCosthMAIDNew,ArrSigmaMineCorrectedMAID,ArrCosthErr,ArrSigmaErr);
//    TGraph* SigmaPlotCorrectedSAID=new TGraphErrors(20,ArrCosthSAID,ArrSigmaMineCorrectedSAID,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotCorrectedMAID=new TGraphErrors(20,ArrCosth,ArrSigmaMineCorrectedMAID,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotCorrectedSAID=new TGraphErrors(20,ArrCosth,ArrSigmaMineCorrectedSAID,ArrCosthErr,ArrSigmaErr);

    TGraph* SigmaPlotGA=new TGraphErrors(sizeof(ArrSigmaPrevDataGA)/sizeof(ArrSigmaPrevDataGA[0]),ArrCosthPrevDataGA,ArrSigmaPrevDataGA,ArrCosthErrPrevDataGA,ArrSigmaErrPrevDataGA);

    //SpecMom Binned cuts Analysis
    TGraph* SigmaPlotSpec=new TGraphErrors(20,ArrCosthSpec,ArrSigmaSpec,ArrCosthErrSpec,ArrSigmaErrSpec);


    SigmaPlotSimon->SetMarkerStyle(21);  //filled square(red)
    SigmaPlotSimon->SetMarkerColor(2);  //red

    DivisionPlotSimon->SetMarkerStyle(23);//filled upside down triangle(blue)
    DivisionPlotSimon->SetMarkerColor(4);//blue
    DivisionPlotSAID->SetMarkerStyle(31);
    DivisionPlotSAID->SetMarkerColor(6);
    DivisionPlotMAID->SetMarkerStyle(32);
    DivisionPlotMAID->SetMarkerColor(8);

    SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)


    SigmaPlotSimonV2->SetMarkerStyle(21);  //filled square()
    SigmaPlotSimonV2->SetMarkerColor(3);  //green
    SigmaPlotSimonV2->SetFillStyle(0);
    SigmaPlotSimonV2->SetFillColor(0);
    SigmaPlotSimonV2->SetTitle("Simon WMean");

    DivisionPlotSimonV2->SetMarkerStyle(23);//filled upside down triangle(blue)
    DivisionPlotSimonV2->SetMarkerColor(6);//pink
    DivisionPlotSimonV2->SetFillStyle(0);//pink
    DivisionPlotSimonV2->SetFillColor(0);//pink
    DivisionPlotSimonV2->SetTitle("DivisionWMean");//pink

    SigmaPlotGA->SetMarkerStyle(25);//Filled triangle(black(default)
    SigmaPlotGA->SetMarkerColor(2);  //red
    SigmaPlotGA->SetFillStyle(0);
    SigmaPlotGA->SetFillColor(0);
    SigmaPlotGA->SetTitle("GASimon");


    SigmaPlotSAID->SetMarkerStyle(21);//Filled triangle(black(default)
    SigmaPlotSAID->SetMarkerColor(6);  //red
    SigmaPlotSAID->SetFillStyle(0);
    SigmaPlotSAID->SetFillColor(0);
    SigmaPlotSAID->SetTitle("SAID");

    SigmaPlotMAID->SetMarkerStyle(20);//Filled triangle(black(default)
    SigmaPlotMAID->SetMarkerColor(7); 
    SigmaPlotMAID->SetFillStyle(0);
    SigmaPlotMAID->SetFillColor(0);
    SigmaPlotMAID->SetTitle("MAID");


    SigmaPlotCorrectedSAID->SetMarkerStyle(20);//Filled triangle(black(default)
    SigmaPlotCorrectedSAID->SetMarkerColor(4); 
    SigmaPlotCorrectedSAID->SetFillStyle(0);
    SigmaPlotCorrectedSAID->SetFillColor(0);
    SigmaPlotCorrectedSAID->SetTitle("CorrectedWithSAID");

    SigmaPlotCorrectedMAID->SetMarkerStyle(20);//Filled triangle(black(default)
    SigmaPlotCorrectedMAID->SetMarkerColor(7); 
    SigmaPlotCorrectedMAID->SetFillStyle(0);
    SigmaPlotCorrectedMAID->SetFillColor(0);
    SigmaPlotCorrectedMAID->SetTitle("CorrectedWith1.1");


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

    DivisionPlotSAID->SetFillStyle(0);//pink
    DivisionPlotSAID->SetFillColor(0);//pink
    DivisionPlotMAID->SetFillStyle(0);
    DivisionPlotMAID->SetFillColor(0);

    SigmaPlot->SetTitle("CoplanFitsOrig");//pink
    SigmaPlotSimon->SetTitle("Simon");//pink
    DivisionPlotSimon->SetTitle("Division");//pink
    DivisionPlotSAID->SetTitle("SAIDDivision");//pink
    DivisionPlotMAID->SetTitle("MAIDDivision");//pink



    TMultiGraph* mg = new TMultiGraph();
    mg->Add(SigmaPlot);
    mg->Add(SigmaPlotGA);
    //    mg->Add(SigmaPlotSimon);
//    mg->Add(SigmaPlotSimonV2);
    //    mg->Add(DivisionPlotSimon);
   // mg->Add(DivisionPlotSimonV2);
    //    mg->Add(DivisionPlotSAID);
    //    mg->Add(DivisionPlotMAID);

    //SpecMom add to multigraph
    //mg->Add(SigmaPlotSpec);
//    mg->Add(SigmaPlotSAID);
    //    mg->Add(SigmaPlotMAID);
//    mg->Add(SigmaPlotCorrectedSAID);
//    mg->Add(SigmaPlotCorrectedMAID);

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
    DivisionPlotSimonV2->Write();
    DivisionPlotSAID->Write();
    DivisionPlotMAID->Write();
    c3->Write();

  }
  outfile->Close();
} //closing main function
	

//////////////////////////////////////////////////////////////////////////////MainFuncClosed/////

void GetPreviousDataResultsSigmaFromFile(vector<Double_t>  &VecSigmaDR, vector<Double_t> &VecSigmaErrDR, vector<Double_t> &VecEgDR ,vector<Double_t> &VecEgErrDR ,vector<Double_t> &VecCosthDR ,vector<Double_t> &VecCosthErrDR, TString PrevDataFileName ){

    Double_t Sigma;
    Double_t SigmaErr;
    Double_t Eg;
    Double_t EgErr;
    Double_t Costh;
    Double_t CosthErr;
    std::ifstream inputFileGA(PrevDataFileName);
//    std::ifstream inputFileGA("tmp/PreviousData/430.000000/GA\(16\).txt");
    std::string lineGA;
    if (inputFileGA.is_open()){
      while(getline(inputFileGA, lineGA) ){
	stringstream(lineGA)>>Eg >> Costh>> Sigma >>SigmaErr;
	VecSigmaDR.push_back(Sigma);
	VecEgDR.push_back(Eg);
	VecCosthDR.push_back(Costh);
	VecSigmaErrDR.push_back(SigmaErr);
	VecEgErrDR.push_back(10);
	VecCosthErrDR.push_back(0.05);
      }
    }
inputFileGA.close();



}










void GetPreviousDataResults(TString InFileDataResults, Double_t EgammaBin ){

  FILE*    iFile      = fopen(InFileDataResults,"r");
  map< TString, std::vector< std::vector< Double_t > > > OutData;
  Char_t   Buffer[255];
  Char_t   temp[255];
  Float_t Energy = 0;
  Int_t   Number = 0;
  Char_t   Name[255];
  Float_t Theta = 0;
  Float_t Value = 0;
  Float_t Error = 0;

  while(fgets( Buffer, sizeof(Buffer), iFile )){
    sscanf(Buffer,"%s",temp);

    if(strcmp(temp,"E=") ) continue;

    sprintf(temp,"HI");
    sscanf(Buffer,"%*s%f%*s%d%s",&Energy,&Number,Name);
    //     cout << endl << Energy << " " << Number << " " <<  Name << endl;
    
    for(Int_t i = 0;i<Number;i++){

      fgets( Buffer, sizeof(Buffer), iFile );

      sscanf(Buffer,"%f%f%f",&Theta,&Value,&Error);

      std::vector< Double_t > OutPoint;

      OutPoint.push_back(Energy);
      OutPoint.push_back(Theta);
      OutPoint.push_back(Value);
      OutPoint.push_back(Error);
      OutPoint.push_back(Number);
      

      OutData[Name].push_back(OutPoint);
    }
  }

  fclose(iFile);
  cout << OutData.size() << endl << endl;
    for(map< TString, std::vector< std::vector< Double_t > > >::iterator it = OutData.begin(); it!=OutData.end(); it++){

      ofstream oFile;
      TString Dir1 = "tmp/PreviousData/";
      TString Directory = Dir1 +Form("%f",EgammaBin);
      TString DirectoryCMD = "mkdir " + Directory;
      gSystem->Exec(DirectoryCMD);
      oFile.open(Directory+"/"+(TString)it->first+".txt");

      for(Int_t j = 0; j<OutData[it->first].size(); j++){
	oFile << OutData[it->first][j][0] << " " <<TMath::Cos(TMath::DegToRad()*OutData[it->first][j][1]) << " " << OutData[it->first][j][2] << " " << OutData[it->first][j][3] <<" "<< OutData[it->first][j][4] << endl;
    }
	//oFile << "SKIP " << endl;
	cout <<  (TString)it->first << endl;
        oFile.close();

    }

  } 

  void GetPi0SAIDDataResults(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow,Double_t EgammaHigh, Double_t EgammaLow){



    TString  Header;
    TString  Ranges;
    TString  Total ;
    TString  Line  ;
    TString  Reaction = "1"; //Choosing first reaction from (http://gwdac.phys.gwu.edu/analysis/pr_analysis.html) 1 is Pi0P can check in the saved webpage
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
    Ranges = "&iv="+runVar+ Form("&il=%f&ii=%f&iu=%f",ThLow,thetaStep,ThHigh)+ "&fv="+fixVar+Form("&fn=%f&u=%f&l=%f",Egamma,EgammaLow,EgammaHigh);
    Total =Header +  Ranges ;
    cout << Total << endl;
    Line = "wget '"+Total+"' -O tmp/PageSAIDDataResults.txt";

    cout << Line << endl;
    /*
      sprintf(Header, "http://gwdac.phys.gwu.edu/cgi-bin/go3pr2?sl=CM12&rt=%d&ot=%s", Reaction, obs);
      sprintf(Ranges, "&iv=%s&il=%f&ii=%f&iu=%f&fv=%s&fn=%f", runVar, ThLow, thetaStep, ThHigh, fixVar, W);
      sprintf(Total, "%s%s", Header, Ranges);
      sprintf(Line, "wget %c%s%c -O tmp/PageSAID.txt", 34, Total, 34); //PRINT CHR$(34) gives "
    */
    gSystem->Exec(Line);


  }




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

  void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){


    TString  Header;
    TString  Ranges;
    TString  Total ;
    TString  Line  ;
    TString  Reaction = "1"; //Choosing first reaction from (http://gwdac.phys.gwu.edu/analysis/pr_analysis.html) 1 is Pi0P can check in the saved webpage
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


  }

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
    TString  Reaction = "1"; //Choosing first reaction from (https://maid.kph.uni-mainz.de/maid2007/polariz.html) 1 is Pi0P can check in the saved webpage
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


  }




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

inputFileSpec.close();


  }


  Double_t ConvertToCME(Double_t taggE){

    return TMath::Sqrt((938.27+taggE)*(938.27+taggE)-taggE*taggE);

  }



  ///cgi-bin/maid1?switch=215&param2=1&param4=1&param50=3&value35=0&value36=1232&value37=30&value41=10&value42=180&param99=0&param11=1&param12=1&param13=1&param14=1&param15=1&param16=1&param17=1&param18=1&param19=1&param20=1&param21=1&param22=1&param23=1&param24=1&param25=1&param26=1&value11=1.0&value12=1.0&value13=1.0&value51=1.0&value52=1.0&value53=1.0&value54=1.0&value55=1.0&value56=1.0&value57=1.0&value58=1.0&value59=1.0&value60=1.0&value61=1.0&value62=1.0&value63=1.0&value64=1.0&value65=1.0&value66=1.0&value67=1.0&value68=1.0&value69=1.0&value70=1.0&value71=1.0&value72=1.0&value73=1.0&value74=1.0&value75=1.0&value76=1.0&value77=1.0&value78=1.0&value79=1.0&value80=1.0&value81=1.0&value82=1.0&value83=1.0&value84=1.0



