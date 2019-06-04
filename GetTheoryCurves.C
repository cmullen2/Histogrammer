#include <stdlib.h>
#include <TString.h>
//Read in data from 
void GetSigmaFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecSigmaErr, vector<Double_t> &VecEg ,vector<Double_t> &VecEgErr ,vector<Double_t> &VecCosth ,vector<Double_t> &VecCosthErr, TString InFileName );
//Read in theory points from files
void GetSigmaTheoryFromFile(Double_t  ArrSigma2[], Double_t ArrCosth2[],  TString InFileName2,  Double_t NThetaBins2, Double_t IsTheoryMAID );
Double_t ConvertToCME(Double_t taggE);
//Download theory files for SAID and MAID
void GetPi0SAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);  
void GetPi0MAID(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);
//Simon results from SAID
void GetPi0SAIDDataResults(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow,Double_t EgammaHigh ,Double_t EgammaLow);  
void GetPreviousDataResults(TString InFileDataResults, Double_t EgammaBin);  
void GetPreviousDataResultsSigmaFromFile(vector<Double_t>  &VecSigmaDR, vector<Double_t> &VecSigmaErrDR, vector<Double_t> &VecEgDR ,vector<Double_t> &VecEgErrDR ,vector<Double_t> &VecCosthDR ,vector<Double_t> &VecCosthErrDR, TString PrevDataFileName );
//TheoryDataFromBnGa
void GetPi0BnGa(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);
void GetBnGaSigmaFromFile(vector<Double_t>  &VecSigmaBnGa, vector<Double_t> &VecSigmaErrBnGa, vector<Double_t> &VecEgBnGa ,vector<Double_t> &VecEgErrBnGa ,vector<Double_t> &VecCosthBnGa ,vector<Double_t> &VecCosthErrBnGa, Double_t NThetaBins ,TString BnGaFileName );
//Theory Data From SAID to use for comparison on plots
void GetPi0SAIDMoreBins(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow);  
void GetSAIDSigmaFromFile(vector<Double_t>  &VecSigmaSAIDMB, vector<Double_t> &VecSigmaErrSAIDMB, vector<Double_t> &VecEgSAIDMB ,vector<Double_t> &VecEgErrSAIDMB ,vector<Double_t> &VecCosthSAIDMB ,vector<Double_t> &VecCosthErrSAIDMB, Double_t NThetaBins ,TString SAIDMBFileName );




void GetTheoryCurves() {
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/DeleteWMV3.root","recreate"); 
  Double_t TheoryThetaBinsDouble = 40;
  Double_t TheoryThetaBins = 20;
  Double_t TheoryThetaLowSAID = -1;
  Double_t TheoryThetaLowMAID = 0;
  Double_t TheoryThetaHighSAID =1 ;
  Double_t TheoryThetaHighMAID =180 ;
  Double_t TheoryEgamma;
  Double_t TheoryEgammaHigh;
  Double_t TheoryEgammaLow;
  //Results from coplan fit then histograms May 6th 2019
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

  TString InFile = "Data/Results410To710NewCoplanFitsApr2019.txt";
  GetSigmaFromFile( VecAllChrisSigma, VecAllChrisSigmaErr, VecAllChrisEg, VecAllChrisEgErr, VecAllChrisCosth,  VecAllChrisCosthErr,  InFile );

  //My Results
  Double_t ArrSigma[20];
  Double_t ArrCosth[20];
  Double_t ArrEg[20];
  Double_t ArrSigmaErr[20];
  Double_t ArrCosthErr[20];
  Double_t ArrEgErr[20];



  for(Int_t i=0;i<16;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
    for(Int_t j=0;j<20;j++){

      //MyResults
      ArrSigma[j] = VecAllChrisSigma[j+i*20];
      ArrCosth[j] = VecAllChrisCosth[j+i*20];
      ArrEg[j] = VecAllChrisEg[j+i*20];
      ArrSigmaErr[j] = VecAllChrisSigmaErr[j+i*20];
      ArrCosthErr[j] = VecAllChrisCosthErr[j+i*20];
      ArrEgErr[j] = VecAllChrisEgErr[j+i*20];
      TheoryEgamma= VecAllChrisEg[j+i*20];
      TheoryEgammaHigh= VecAllChrisEg[j+i*20] +2.5;
      TheoryEgammaLow= VecAllChrisEg[j+i*20] -2.5;
    }
    Double_t ArrSigmaSAID[20];
    Double_t ArrSigmaSAIDDiv[20];
    Double_t ArrSigmaSAIDCutsDiv[20];
    Double_t ArrSigmaSAIDUnBinDiv[20];
    Double_t ArrSigmaSAIDUnBinDivErr[20];
    Double_t ArrCosthSAID[20];
    TString InFileNameSAID = "tmp/PageSAID.txt";
    Double_t IsSAID=0;
    TString InFileNameBnGa = "tmp/PageBnGa.txt";
    vector<Double_t> VecSigmaBnGa;
    vector<Double_t> VecSigmaErrBnGa;
    vector<Double_t> VecEgBnGa;
    vector<Double_t> VecEgErrBnGa;
    vector<Double_t> VecCosthBnGa;
    vector<Double_t> VecCosthErrBnGa;
    TString InFileNameSAIDMB = "tmp/PageSAIDMoreBins.txt";
    vector<Double_t> VecSigmaSAIDMB;
    vector<Double_t> VecSigmaErrSAIDMB;
    vector<Double_t> VecEgSAIDMB;
    vector<Double_t> VecEgErrSAIDMB;
    vector<Double_t> VecCosthSAIDMB;
    vector<Double_t> VecCosthErrSAIDMB;
    Double_t ArrSigmaMAID[20];
    Double_t ArrSigmaMAIDNew[20];
    Double_t ArrSigmaMAIDDiv[20];
    Double_t ArrCosthMAID[20];
    Double_t ArrCosthMAIDNew[20];
    TString InFileNameMAID = "tmp/PageMAID.txt";
    Double_t IsMAID=1;
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
    Double_t ArrSigmaMineCorrectedSAIDCuts[20];
    Double_t ArrSigmaMineCorrectedSAIDUnBin[20];
    //GetSAID Predictions
    GetPi0SAID( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighSAID, TheoryThetaLowSAID);
    GetSigmaTheoryFromFile(ArrSigmaSAID, ArrCosthSAID ,  InFileNameSAID,  TheoryThetaBins,IsSAID);
    //GetMAID predictions //MAID File gives me 21 for some reason, fix later,removed last(180) point for now
    GetPi0MAID( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighMAID, TheoryThetaLowMAID);
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


    std::ofstream textfileSAIDMBFinalResults;
    textfileSAIDMBFinalResults.open("SAIDMoreBinsProtonResults.txt",std::ios_base::app);

    std::ofstream textfileBnGaFinalResults;
    textfileBnGaFinalResults.open("BnGaProtonResults.txt",std::ios_base::app);

    std::ofstream textfileSimonFinalResults;
    textfileSimonFinalResults.open("SimonProtonResults.txt",std::ios_base::app);

    for(Int_t vv=0; vv<VecSigmaBnGa.size();vv++){
      ArrSigmaBnGa[vv] = VecSigmaBnGa[vv];
      ArrSigmaErrBnGa[vv] = VecSigmaErrBnGa[vv];
//      ArrEgBnGa[vv] = VecEgBnGa[vv];
      ArrEgBnGa[vv] = TheoryEgamma;
      ArrEgErrBnGa[vv] = VecEgErrBnGa[vv];
      ArrCosthBnGa[vv] = VecCosthBnGa[vv];
      ArrCosthErrBnGa[vv] = VecCosthErrBnGa[vv];
textfileBnGaFinalResults << ArrSigmaBnGa[vv] <<"    "<< ArrSigmaErrBnGa[vv]<< "    "<<ArrEgBnGa[vv] <<"    "<<ArrEgErrBnGa[vv]<<"    "<<ArrCosthBnGa[vv]<<"   "<<ArrCosthErrBnGa[vv]<<endl; 
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
//      ArrEgSAIDMB[vv] = VecEgSAIDMB[vv];
      ArrEgSAIDMB[vv] = TheoryEgamma;
      ArrEgErrSAIDMB[vv] = VecEgErrSAIDMB[vv];
      ArrCosthSAIDMB[vv] = VecCosthSAIDMB[vv];
      ArrCosthErrSAIDMB[vv] = VecCosthErrSAIDMB[vv];
textfileSAIDMBFinalResults << ArrSigmaSAIDMB[vv] <<"    "<< ArrSigmaErrSAIDMB[vv]<< "    "<<ArrEgSAIDMB[vv] <<"    "<<ArrEgErrSAIDMB[vv]<<"    "<<ArrCosthSAIDMB[vv]<<"   "<<ArrCosthErrSAIDMB[vv]<<endl; 
    }
    //Get the Data that SAID uses for this bin since do not have simons data in Glasgow
    GetPi0SAIDDataResults( TheoryEgamma,  TheoryThetaBins, TheoryThetaHighSAID, TheoryThetaLowSAID,TheoryEgammaHigh,TheoryEgammaLow);
    GetPreviousDataResults(InFileNameSAIDData,TheoryEgamma );
    GetPreviousDataResultsSigmaFromFile( VecSigmaGA, VecSigmaErrGA,VecEgGA ,VecEgErrGA ,VecCosthGA ,VecCosthErrGA, PrevDataFileNameGA );
    Int_t a = VecSigmaGA.size();
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

textfileSimonFinalResults << ArrSigmaPrevDataGA[ff] <<"    "<< ArrSigmaErrPrevDataGA[ff]<< "    "<<ArrEgPrevDataGA[ff] <<"    "<<ArrEgErrPrevDataGA[ff]<<"    "<<ArrCosthPrevDataGA[ff]<<"   "<<ArrCosthErrPrevDataGA[ff]<<endl; 
    }
    //May Overwrite every iter Probs need to close every cos iter


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
  // cout << OutData.size() << endl << endl;
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
    // cout <<  (TString)it->first << endl;
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
  //  cout << Total << endl;
  Line = "wget '"+Total+"' -O tmp/PageSAIDDataResults.txt";

  //  cout << Line << endl;
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
  //  cout << Total << endl;
  Line = "wget '"+Total+"' -O tmp/PageSAID.txt";

  //  cout << Line << endl;
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
  //  cout << Total << endl;
  Line = "wget '"+Total+"' -O tmp/PageMAID.txt";

  //  cout << Line << endl;
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

void GetSigmaTheoryFromFile(Double_t  ArrSigma[], Double_t ArrCosth[] , TString InFileName,Double_t NThetaBins, Double_t IsTheorySAIDMAIDorBnGa ){

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

  //IsTheorySAIDMAIDBnGa :  0=SAID, 1=MAID, 2=BnGa



  std::ifstream inputFileSpec(InFileName);
  std::string lineSpec;
  if (inputFileSpec.is_open()){
    while(getline(inputFileSpec, lineSpec) ){
      if(IsTheorySAIDMAIDorBnGa==1){
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
      else if(IsTheorySAIDMAIDorBnGa==0){ 
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
      else if(IsTheorySAIDMAIDorBnGa==2){

	if(lineCount<19 || lineCount>(19+2*NThetaBins)  ){
	  lineCount=lineCount+1;
	}     
	else{
	  stringstream(lineSpec)>>Costh>>Sigma ;
	  lineCount=lineCount+1;
	  VecSigma.push_back(Sigma);
	  VecCosth.push_back(Costh);
	  //	  cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWQQQQQQQQQQQQQQQQQQQQQQQQ  " << Sigma << endl;
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

void GetPi0BnGa(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){
	
  TString  Header;
  TString  Ranges;
  TString  Total ;
  TString  Line  ;
  TString  Reaction = "pion_00"; 
  TString  obs = "s";
  TString  fixVar = "W";
  // TString  fixVar = "ELab";
  TString  runVar ="z"; //"cosA"; z=cosA
  Double_t W = ConvertToCME(Egamma);



  //	sprintf(Header, "http://pwa.hiskp.uni-bonn.de/obs_int_new1.pl?param02=%s&param03=%s_&param01=BG2014_02",  Reaction, obs);
  //  sprintf(Ranges, "&param04=%s&param05=%f&param12=1&param11=20&param10=%s&param06=%f&param07=%f&param08=0&param09=0", fixVar, W, runVar, Low, High);

  //  sprintf(Total, "%s%s", Header, Ranges);
  // sprintf(Line, "wget %c%s%c -O tmp/PageBnGa.txt", 34, Total, 34); //PRINT CHR$(34) gives "

  Header = "http://pwa.hiskp.uni-bonn.de/obs_int_new1.pl?param02="+ Reaction + "&param03="+obs+ "_&param01=BG2014_02";
  Ranges = "&param04=" +fixVar+Form("&param05=%f",W)+ "&param12=1&param11=20&param10=" +runVar+Form("&param06=%f",ThLow) + Form("&param07=%f",ThHigh)+ "&param08=0&param09=0";
  Total = Header + Ranges;
  Line = "wget '"+Total+"' -O tmp/PageBnGa.txt";
  gSystem->Exec(Line);





}


void GetBnGaSigmaFromFile(vector<Double_t>  &VecSigmaBnGa, vector<Double_t> &VecSigmaErrBnGa, vector<Double_t> &VecEgBnGa ,vector<Double_t> &VecEgErrBnGa ,vector<Double_t> &VecCosthBnGa ,vector<Double_t> &VecCosthErrBnGa, Double_t NThetaBins, TString BnGaFileName ){

  Double_t lineCount=0;
  Double_t Sigma;
  Double_t SigmaErr;
  Double_t Eg;
  Double_t EgErr;
  Double_t Costh;
  Double_t CosthErr;
  std::ifstream inputFileBn(BnGaFileName);
  //    std::ifstream inputFileGA("tmp/PreviousData/430.000000/GA\(16\).txt");
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

	//	cout << Sigma << "    APPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP" << endl;

      }

    }
  }
  inputFileBn.close();

}


Double_t ConvertToCME(Double_t taggE){

  return TMath::Sqrt((938.27+taggE)*(938.27+taggE)-taggE*taggE);

}


void GetPi0SAIDMoreBins(Double_t Egamma, Double_t NThetaBins,Double_t ThHigh, Double_t ThLow){

  TString  Header;
  TString  Ranges;
  TString  Total ;
  TString  Line  ;
  TString  Reaction = "1"; //Choosing first reaction from (http://gwdac.phys.gwu.edu/analysis/pr_analysis.html) 1 is Pi0P can check in the saved webpage
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





