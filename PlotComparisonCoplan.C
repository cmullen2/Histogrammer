#include <stdlib.h>


void PlotComparisonCoplan() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ChrisResultsTempComparisonNewResultsWithErrorsCoplanBinsV2.root","recreate");
  
//  vector<Double_t> VecChrisSigma;
//  vector<TString> VecChrisType;
//  vector<Double_t> VecChrisCosth;
//  vector<Double_t> VecChrisEg;
  vector<Double_t> VecAllChrisSigma;
  vector<Double_t> VecAllChrisEg;
  vector<Double_t> VecAllChrisCosth;
  vector<TString> VecAllChrisType;
  vector<Double_t> VecAllChrisSigmaErr;
  vector<Double_t> VecAllChrisEgErr;
  vector<Double_t> VecAllChrisCosthErr;


	//Coplan-40 weights only(-40,-20,0,20,40)
  vector<Double_t> VecAllChrisSigmaN40;
  vector<Double_t> VecAllChrisEgN40;
  vector<Double_t> VecAllChrisCosthN40;
  vector<TString> VecAllChrisTypeN40;
  vector<Double_t> VecAllChrisSigmaErrN40;
  vector<Double_t> VecAllChrisEgErrN40;
  vector<Double_t> VecAllChrisCosthErrN40;


	//Coplan-20 weights only(-40,-20,0,20,40)
  vector<Double_t> VecAllChrisSigmaN20;
  vector<Double_t> VecAllChrisEgN20;
  vector<Double_t> VecAllChrisCosthN20;
  vector<TString> VecAllChrisTypeN20;
  vector<Double_t> VecAllChrisSigmaErrN20;
  vector<Double_t> VecAllChrisEgErrN20;
  vector<Double_t> VecAllChrisCosthErrN20;

	//Coplan0 weights only(-40,-20,0,20,40)
  vector<Double_t> VecAllChrisSigma0;
  vector<Double_t> VecAllChrisEg0;
  vector<Double_t> VecAllChrisCosth0;
  vector<TString> VecAllChrisType0;
  vector<Double_t> VecAllChrisSigmaErr0;
  vector<Double_t> VecAllChrisEgErr0;
  vector<Double_t> VecAllChrisCosthErr0;

	//Coplan20 weights only(-40,-20,0,20,40)
  vector<Double_t> VecAllChrisSigma20;
  vector<Double_t> VecAllChrisEg20;
  vector<Double_t> VecAllChrisCosth20;
  vector<TString> VecAllChrisType20;
  vector<Double_t> VecAllChrisSigmaErr20;
  vector<Double_t> VecAllChrisEgErr20;
  vector<Double_t> VecAllChrisCosthErr20;

	//Coplan40 weights only(-40,-20,0,20,40)
  vector<Double_t> VecAllChrisSigma40;
  vector<Double_t> VecAllChrisEg40;
  vector<Double_t> VecAllChrisCosth40;
  vector<TString> VecAllChrisType40;
  vector<Double_t> VecAllChrisSigmaErr40;
  vector<Double_t> VecAllChrisEgErr40;
  vector<Double_t> VecAllChrisCosthErr40;

	//Timing weights only
  vector<Double_t> VecAllChrisSigmaTiming;
  vector<Double_t> VecAllChrisEgTiming;
  vector<Double_t> VecAllChrisCosthTiming;
  vector<TString> VecAllChrisTypeTiming;
  vector<Double_t> VecAllChrisSigmaErrTiming;
  vector<Double_t> VecAllChrisEgErrTiming;
  vector<Double_t> VecAllChrisCosthErrTiming;

	//StrictCuts Timing Weights only
  vector<Double_t> VecAllChrisSigmaStrict;
  vector<Double_t> VecAllChrisEgStrict;
  vector<Double_t> VecAllChrisCosthStrict;
  vector<TString> VecAllChrisTypeStrict;
  vector<Double_t> VecAllChrisSigmaErrStrict;
  vector<Double_t> VecAllChrisEgErrStrict;
  vector<Double_t> VecAllChrisCosthErrStrict;


	//CutsAnalysis
  vector<Double_t> VecAllChrisSigmaCuts;
  vector<Double_t> VecAllChrisEgCuts;
  vector<Double_t> VecAllChrisCosthCuts;
  vector<TString> VecAllChrisTypeCuts;
  vector<Double_t> VecAllChrisSigmaErrCuts;
  vector<Double_t> VecAllChrisEgErrCuts;
  vector<Double_t> VecAllChrisCosthErrCuts;



	//Inv weights only
  vector<Double_t> VecAllChrisSigmaInv;
  vector<Double_t> VecAllChrisEgInv;
  vector<Double_t> VecAllChrisCosthInv;
  vector<TString> VecAllChrisTypeInv;
  vector<Double_t> VecAllChrisSigmaErrInv;
  vector<Double_t> VecAllChrisEgErrInv;
  vector<Double_t> VecAllChrisCosthErrInv;

	//SpecMom<100MeV
  vector<Double_t> VecAllChrisSigmaLess;
  vector<Double_t> VecAllChrisEgLess;
  vector<Double_t> VecAllChrisCosthLess;
  vector<TString> VecAllChrisTypeLess;
  vector<Double_t> VecAllChrisSigmaErrLess;
  vector<Double_t> VecAllChrisEgErrLess;
  vector<Double_t> VecAllChrisCosthErrLess;

	//SpecMom>100Mev
  vector<Double_t> VecAllChrisSigmaGreater;
  vector<Double_t> VecAllChrisEgGreater;
  vector<Double_t> VecAllChrisCosthGreater;
  vector<TString> VecAllChrisTypeGreater;
  vector<Double_t> VecAllChrisSigmaErrGreater;
  vector<Double_t> VecAllChrisEgErrGreater;
  vector<Double_t> VecAllChrisCosthErrGreater;

	//Simons Results
  vector<Double_t> VecAllSimonSigma;
  vector<Double_t> VecAllSimonEg;
  vector<Double_t> VecAllSimonCosth;
  vector<Double_t> VecAllSimonSigmaErr;
  vector<Double_t> VecAllSimonEgErr;
  vector<Double_t> VecAllSimonCosthErr;

	//My Results
  Double_t AllChrisSigma;
  Double_t AllChrisEg;
  Double_t AllChrisCosth;
  TString AllChrisType;
  Double_t AllChrisSigmaErr;
  Double_t AllChrisEgErr;
  Double_t AllChrisCosthErr;

	//Coplanbins-40 (-40,-20,0,20,40)
  Double_t AllChrisSigmaN40;
  Double_t AllChrisEgN40;
  Double_t AllChrisCosthN40;
  TString AllChrisTypeN40;
  Double_t AllChrisSigmaErrN40;
  Double_t AllChrisEgErrN40;
  Double_t AllChrisCosthErrN40;

	//Coplanbins-20 (-40,-20,0,20,40)
  Double_t AllChrisSigmaN20;
  Double_t AllChrisEgN20;
  Double_t AllChrisCosthN20;
  TString AllChrisTypeN20;
  Double_t AllChrisSigmaErrN20;
  Double_t AllChrisEgErrN20;
  Double_t AllChrisCosthErrN20;

	//Coplanbins0 (-40,-20,0,20,40)
  Double_t AllChrisSigma0;
  Double_t AllChrisEg0;
  Double_t AllChrisCosth0;
  TString AllChrisType0;
  Double_t AllChrisSigmaErr0;
  Double_t AllChrisEgErr0;
  Double_t AllChrisCosthErr0;

	//Coplanbins20 (-40,-20,0,20,40)
  Double_t AllChrisSigma20;
  Double_t AllChrisEg20;
  Double_t AllChrisCosth20;
  TString AllChrisType20;
  Double_t AllChrisSigmaErr20;
  Double_t AllChrisEgErr20;
  Double_t AllChrisCosthErr20;

	//Coplanbins40 (-40,-20,0,20,40)
  Double_t AllChrisSigma40;
  Double_t AllChrisEg40;
  Double_t AllChrisCosth40;
  TString AllChrisType40;
  Double_t AllChrisSigmaErr40;
  Double_t AllChrisEgErr40;
  Double_t AllChrisCosthErr40;


	//Timing Weights
  Double_t AllChrisSigmaTiming;
  Double_t AllChrisEgTiming;
  Double_t AllChrisCosthTiming;
  TString AllChrisTypeTiming;
  Double_t AllChrisSigmaErrTiming;
  Double_t AllChrisEgErrTiming;
  Double_t AllChrisCosthErrTiming;

	//StrictCuts
  Double_t AllChrisSigmaStrict;
  Double_t AllChrisEgStrict;
  Double_t AllChrisCosthStrict;
  TString AllChrisTypeStrict;
  Double_t AllChrisSigmaErrStrict;
  Double_t AllChrisEgErrStrict;
  Double_t AllChrisCosthErrStrict;


	//CutsAnalysis
  Double_t AllChrisSigmaCuts;
  Double_t AllChrisEgCuts;
  Double_t AllChrisCosthCuts;
  TString AllChrisTypeCuts;
  Double_t AllChrisSigmaErrCuts;
  Double_t AllChrisEgErrCuts;
  Double_t AllChrisCosthErrCuts;


	//InvWeights
  Double_t AllChrisSigmaInv;
  Double_t AllChrisEgInv;
  Double_t AllChrisCosthInv;
  TString AllChrisTypeInv;
  Double_t AllChrisSigmaErrInv;
  Double_t AllChrisEgErrInv;
  Double_t AllChrisCosthErrInv;

	//SpecMom<100
  Double_t AllChrisSigmaLess;
  Double_t AllChrisEgLess;
  Double_t AllChrisCosthLess;
  TString AllChrisTypeLess;
  Double_t AllChrisSigmaErrLess;
  Double_t AllChrisEgErrLess;
  Double_t AllChrisCosthErrLess;

	//SpecMom>100
  Double_t AllChrisSigmaGreater;
  Double_t AllChrisEgGreater;
  Double_t AllChrisCosthGreater;
  TString AllChrisTypeGreater;
  Double_t AllChrisSigmaErrGreater;
  Double_t AllChrisEgErrGreater;
  Double_t AllChrisCosthErrGreater;


	//Simon Results
  Double_t AllSimonSigma;
  Double_t AllSimonEg;
  Double_t AllSimonCosth;
  Double_t AllSimonSigmaErr;
  Double_t AllSimonEgErr;
  Double_t AllSimonCosthErr;
	
  //read in my results from text file
  std::ifstream inputFile("CutResultsNew.txt");
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



  //read in coplan binned results from text file
  std::ifstream inputFileCoplanBinned("CutResultsNewInvCoplanBinned.txt");
  std::string lineCoplanBinned;
  Double_t counterCoplan = 0;
  if (inputFileCoplanBinned.is_open()){
    while(getline(inputFileCoplanBinned, lineCoplanBinned) ){
if(counterCoplan==0){
      stringstream(lineCoplanBinned)>>AllChrisSigmaN40 >>AllChrisSigmaErrN40>>AllChrisEgN40>>AllChrisEgErrN40 >> AllChrisCosthN40>>AllChrisCosthErrN40>> AllChrisTypeN40;
      VecAllChrisSigmaN40.push_back(AllChrisSigmaN40);
      VecAllChrisEgN40.push_back(AllChrisEgN40);
      VecAllChrisCosthN40.push_back(AllChrisCosthN40);
      VecAllChrisTypeN40.push_back(AllChrisTypeN40);
      VecAllChrisSigmaErrN40.push_back(AllChrisSigmaErrN40);
      VecAllChrisEgErrN40.push_back(AllChrisEgErrN40);
      VecAllChrisCosthErrN40.push_back(AllChrisCosthErrN40);
      counterCoplan=counterCoplan+1;
}
else if(counterCoplan==1){
      stringstream(lineCoplanBinned)>>AllChrisSigmaN20 >>AllChrisSigmaErrN20>>AllChrisEgN20>>AllChrisEgErrN20 >> AllChrisCosthN20>>AllChrisCosthErrN20>> AllChrisTypeN20;
      VecAllChrisSigmaN20.push_back(AllChrisSigmaN20);
      VecAllChrisEgN20.push_back(AllChrisEgN20);
      VecAllChrisCosthN20.push_back(AllChrisCosthN20);
      VecAllChrisTypeN20.push_back(AllChrisTypeN20);
      VecAllChrisSigmaErrN20.push_back(AllChrisSigmaErrN20);
      VecAllChrisEgErrN20.push_back(AllChrisEgErrN20);
      VecAllChrisCosthErrN20.push_back(AllChrisCosthErrN20);
      counterCoplan=counterCoplan+1;
}
else if(counterCoplan==2){
      stringstream(lineCoplanBinned)>>AllChrisSigma0 >>AllChrisSigmaErr0>>AllChrisEg0>>AllChrisEgErr0 >> AllChrisCosth0>>AllChrisCosthErr0>> AllChrisType0;
      VecAllChrisSigma0.push_back(AllChrisSigma0);
      VecAllChrisEg0.push_back(AllChrisEg0);
      VecAllChrisCosth0.push_back(AllChrisCosth0);
      VecAllChrisType0.push_back(AllChrisType0);
      VecAllChrisSigmaErr0.push_back(AllChrisSigmaErr0);
      VecAllChrisEgErr0.push_back(AllChrisEgErr0);
      VecAllChrisCosthErr0.push_back(AllChrisCosthErr0);
      counterCoplan=counterCoplan+1;
}
else if(counterCoplan==3){
      stringstream(lineCoplanBinned)>>AllChrisSigma20 >>AllChrisSigmaErr20>>AllChrisEg20>>AllChrisEgErr20 >> AllChrisCosth20>>AllChrisCosthErr20>> AllChrisType20;
      VecAllChrisSigma20.push_back(AllChrisSigma20);
      VecAllChrisEg20.push_back(AllChrisEg20);
      VecAllChrisCosth20.push_back(AllChrisCosth20);
      VecAllChrisType20.push_back(AllChrisType20);
      VecAllChrisSigmaErr20.push_back(AllChrisSigmaErr20);
      VecAllChrisEgErr20.push_back(AllChrisEgErr20);
      VecAllChrisCosthErr20.push_back(AllChrisCosthErr20);
      counterCoplan=counterCoplan+1;
}
else if(counterCoplan==4){
      stringstream(lineCoplanBinned)>>AllChrisSigma40 >>AllChrisSigmaErr40>>AllChrisEg40>>AllChrisEgErr40 >> AllChrisCosth40>>AllChrisCosthErr40>> AllChrisType40;
      VecAllChrisSigma40.push_back(AllChrisSigma40);
      VecAllChrisEg40.push_back(AllChrisEg40);
      VecAllChrisCosth40.push_back(AllChrisCosth40);
      VecAllChrisType40.push_back(AllChrisType40);
      VecAllChrisSigmaErr40.push_back(AllChrisSigmaErr40);
      VecAllChrisEgErr40.push_back(AllChrisEgErr40);
      VecAllChrisCosthErr40.push_back(AllChrisCosthErr40);
      counterCoplan=0;
}

    }
  }


  //read in timingweights results from text file
  std::ifstream inputFileTiming("CutResultsNewTiming.txt");
  std::string lineTiming;
  if (inputFileTiming.is_open()){
    while(getline(inputFileTiming, lineTiming) ){
      stringstream(lineTiming)>>AllChrisSigmaTiming >>AllChrisSigmaErrTiming>>AllChrisEgTiming>>AllChrisEgErrTiming >> AllChrisCosthTiming>>AllChrisCosthErrTiming>> AllChrisTypeTiming;
      VecAllChrisSigmaTiming.push_back(AllChrisSigmaTiming);
      VecAllChrisEgTiming.push_back(AllChrisEgTiming);
      VecAllChrisCosthTiming.push_back(AllChrisCosthTiming);
      VecAllChrisTypeTiming.push_back(AllChrisTypeTiming);
      VecAllChrisSigmaErrTiming.push_back(AllChrisSigmaErrTiming);
      VecAllChrisEgErrTiming.push_back(AllChrisEgErrTiming);
      VecAllChrisCosthErrTiming.push_back(AllChrisCosthErrTiming);
    }
  }


  //read in StrictCuts results from text file
  std::ifstream inputFileStrict("CutResultsNewStrictCutsOnlyTiming.txt");
  std::string lineStrict;
  if (inputFileStrict.is_open()){
    while(getline(inputFileStrict, lineStrict) ){
      stringstream(lineStrict)>>AllChrisSigmaStrict >>AllChrisSigmaErrStrict>>AllChrisEgStrict>>AllChrisEgErrStrict >> AllChrisCosthStrict>>AllChrisCosthErrStrict>> AllChrisTypeStrict;
      VecAllChrisSigmaStrict.push_back(AllChrisSigmaStrict);
      VecAllChrisEgStrict.push_back(AllChrisEgStrict);
      VecAllChrisCosthStrict.push_back(AllChrisCosthStrict);
      VecAllChrisTypeStrict.push_back(AllChrisTypeStrict);
      VecAllChrisSigmaErrStrict.push_back(AllChrisSigmaErrStrict);
      VecAllChrisEgErrStrict.push_back(AllChrisEgErrStrict);
      VecAllChrisCosthErrStrict.push_back(AllChrisCosthErrStrict);
    }
  }


  //read in CutsAnalysis results from text file
  std::ifstream inputFileCuts("CutResultsNewCutsBasedAnalysis.txt");
  std::string lineCuts;
  if (inputFileCuts.is_open()){
    while(getline(inputFileCuts, lineCuts) ){
      stringstream(lineCuts)>>AllChrisSigmaCuts >>AllChrisSigmaErrCuts>>AllChrisEgCuts>>AllChrisEgErrCuts >> AllChrisCosthCuts>>AllChrisCosthErrCuts>> AllChrisTypeCuts;
      VecAllChrisSigmaCuts.push_back(AllChrisSigmaCuts);
      VecAllChrisEgCuts.push_back(AllChrisEgCuts);
      VecAllChrisCosthCuts.push_back(AllChrisCosthCuts);
      VecAllChrisTypeCuts.push_back(AllChrisTypeCuts);
      VecAllChrisSigmaErrCuts.push_back(AllChrisSigmaErrCuts);
      VecAllChrisEgErrCuts.push_back(AllChrisEgErrCuts);
      VecAllChrisCosthErrCuts.push_back(AllChrisCosthErrCuts);
    }
  }



  //read in InvWeights results from text file
  std::ifstream inputFileInv("CutResultsNewInv.txt");
  std::string lineInv;
  if (inputFileInv.is_open()){
    while(getline(inputFileInv, lineInv) ){
      stringstream(lineInv)>>AllChrisSigmaInv >>AllChrisSigmaErrInv>>AllChrisEgInv>>AllChrisEgErrInv >> AllChrisCosthInv>>AllChrisCosthErrInv>> AllChrisTypeInv;
      VecAllChrisSigmaInv.push_back(AllChrisSigmaInv);
      VecAllChrisEgInv.push_back(AllChrisEgInv);
      VecAllChrisCosthInv.push_back(AllChrisCosthInv);
      VecAllChrisTypeInv.push_back(AllChrisTypeInv);
      VecAllChrisSigmaErrInv.push_back(AllChrisSigmaErrInv);
      VecAllChrisEgErrInv.push_back(AllChrisEgErrInv);
      VecAllChrisCosthErrInv.push_back(AllChrisCosthErrInv);
    }
  }


  //read in my lessthan results from text file
  std::ifstream inputFileLess("CutResultsNewSpecMomLessThan100.txt");
  std::string lineLess;
  if (inputFileLess.is_open()){
    while(getline(inputFileLess, lineLess) ){
      stringstream(lineLess)>>AllChrisSigmaLess >>AllChrisSigmaErrLess>>AllChrisEgLess>>AllChrisEgErrLess >> AllChrisCosthLess>>AllChrisCosthErrLess>> AllChrisTypeLess;
      VecAllChrisSigmaLess.push_back(AllChrisSigmaLess);
      VecAllChrisEgLess.push_back(AllChrisEgLess);
      VecAllChrisCosthLess.push_back(AllChrisCosthLess);
      VecAllChrisTypeLess.push_back(AllChrisTypeLess);
      VecAllChrisSigmaErrLess.push_back(AllChrisSigmaErrLess);
      VecAllChrisEgErrLess.push_back(AllChrisEgErrLess);
      VecAllChrisCosthErrLess.push_back(AllChrisCosthErrLess);
    }
  }



  //read in my greaterthan results from text file
  std::ifstream inputFileGreater("CutResultsNewSpecMomGreaterThan100.txt");
  std::string lineGreater;
  if (inputFileGreater.is_open()){
    while(getline(inputFileGreater, lineGreater) ){
      stringstream(lineGreater)>>AllChrisSigmaGreater >>AllChrisSigmaErrGreater>>AllChrisEgGreater>>AllChrisEgErrGreater >> AllChrisCosthGreater>>AllChrisCosthErrGreater>> AllChrisTypeGreater;
      VecAllChrisSigmaGreater.push_back(AllChrisSigmaGreater);
      VecAllChrisEgGreater.push_back(AllChrisEgGreater);
      VecAllChrisCosthGreater.push_back(AllChrisCosthGreater);
      VecAllChrisTypeGreater.push_back(AllChrisTypeGreater);
      VecAllChrisSigmaErrGreater.push_back(AllChrisSigmaErrGreater);
      VecAllChrisEgErrGreater.push_back(AllChrisEgErrGreater);
      VecAllChrisCosthErrGreater.push_back(AllChrisCosthErrGreater);
    }
  }


//  std::ifstream inputFile2("SimonsResultsMyBins.txt");
  std::ifstream inputFile2("NewSimonsResultsMyBins.txt");
  std::string line2;


  if (inputFile2.is_open()){
    while(getline(inputFile2, line2) ){
      stringstream(line2)>>AllSimonSigma>>AllSimonSigmaErr >>AllSimonEg>>AllSimonEgErr >> AllSimonCosth>>AllSimonCosthErr;
      VecAllSimonSigma.push_back(AllSimonSigma);
      VecAllSimonEg.push_back(AllSimonEg);
      VecAllSimonCosth.push_back(AllSimonCosth);

      VecAllSimonSigmaErr.push_back(AllSimonSigmaErr);
      VecAllSimonEgErr.push_back(AllSimonEgErr);
      VecAllSimonCosthErr.push_back(AllSimonCosthErr);
    }
  }
	//My Results
Double_t ArrSigma[20];
Double_t ArrCosth[20];
Double_t ArrEg[20];
Double_t ArrSigmaErr[20];
Double_t ArrCosthErr[20];
Double_t ArrEgErr[20];


	//CoplanBinnedN40
Double_t ArrSigmaN40[20];
Double_t ArrCosthN40[20];
Double_t ArrEgN40[20];
Double_t ArrSigmaErrN40[20];
Double_t ArrCosthErrN40[20];
Double_t ArrEgErrN40[20];


	//CoplanBinnedN20
Double_t ArrSigmaN20[20];
Double_t ArrCosthN20[20];
Double_t ArrEgN20[20];
Double_t ArrSigmaErrN20[20];
Double_t ArrCosthErrN20[20];
Double_t ArrEgErrN20[20];


	//CoplanBinned0
Double_t ArrSigma0[20];
Double_t ArrCosth0[20];
Double_t ArrEg0[20];
Double_t ArrSigmaErr0[20];
Double_t ArrCosthErr0[20];
Double_t ArrEgErr0[20];


	//CoplanBinned20
Double_t ArrSigma20[20];
Double_t ArrCosth20[20];
Double_t ArrEg20[20];
Double_t ArrSigmaErr20[20];
Double_t ArrCosthErr20[20];
Double_t ArrEgErr20[20];


	//CoplanBinned40
Double_t ArrSigma40[20];
Double_t ArrCosth40[20];
Double_t ArrEg40[20];
Double_t ArrSigmaErr40[20];
Double_t ArrCosthErr40[20];
Double_t ArrEgErr40[20];



//Timing weights
Double_t ArrSigmaTiming[20];
Double_t ArrCosthTiming[20];
Double_t ArrEgTiming[20];
Double_t ArrSigmaErrTiming[20];
Double_t ArrCosthErrTiming[20];
Double_t ArrEgErrTiming[20];


//StrictCuts Timing weights
Double_t ArrSigmaStrict[20];
Double_t ArrCosthStrict[20];
Double_t ArrEgStrict[20];
Double_t ArrSigmaErrStrict[20];
Double_t ArrCosthErrStrict[20];
Double_t ArrEgErrStrict[20];


//CutsBasedAnalysis
Double_t ArrSigmaCuts[20];
Double_t ArrCosthCuts[20];
Double_t ArrEgCuts[20];
Double_t ArrSigmaErrCuts[20];
Double_t ArrCosthErrCuts[20];
Double_t ArrEgErrCuts[20];


//Inv Weights
Double_t ArrSigmaInv[20];
Double_t ArrCosthInv[20];
Double_t ArrEgInv[20];
Double_t ArrSigmaErrInv[20];
Double_t ArrCosthErrInv[20];
Double_t ArrEgErrInv[20];

//SpecMom<100
Double_t ArrSigmaLess[20];
Double_t ArrCosthLess[20];
Double_t ArrEgLess[20];
Double_t ArrSigmaErrLess[20];
Double_t ArrCosthErrLess[20];
Double_t ArrEgErrLess[20];

//SpecMom>100
Double_t ArrSigmaGreater[20];
Double_t ArrCosthGreater[20];
Double_t ArrEgGreater[20];
Double_t ArrSigmaErrGreater[20];
Double_t ArrCosthErrGreater[20];
Double_t ArrEgErrGreater[20];

//Simons results
Double_t ArrSigmaSimon[20];
Double_t ArrSigmaDiv[20];
Double_t ArrCosthSimon[20];
Double_t ArrEgSimon[20];
Double_t ArrSigmaSimonErr[20];
Double_t ArrSigmaDivErr[20];  //Need to think about computing this! Or set to zero for now.
Double_t ArrCosthSimonErr[20];
Double_t ArrEgSimonErr[20];




for(Int_t i=0;i<11;i++){//Number of eg bins*Number of folders(rand,sig,cut1) 41*3
//	VecChrisSigma.clear();
//	VecChrisCosth.clear();
//	VecChrisType.clear();
//	VecChrisEg.clear();
	for(Int_t j=0;j<20;j++){
//	VecChrisSigma.push_back(VecAllChrisSigma[j+i*20]);
//	VecChrisCosth.push_back(VecAllChrisCosth[j+i*20]);
//	VecChrisType.push_back(VecAllChrisType[j+i*20]);
//	VecChrisEg.push_back(VecAllChrisEg[j+i*20]);

	//MyResults
	ArrSigma[j] = VecAllChrisSigma[j+i*20];
	ArrCosth[j] = VecAllChrisCosth[j+i*20];
	ArrEg[j] = VecAllChrisEg[j+i*20];
	ArrSigmaErr[j] = VecAllChrisSigmaErr[j+i*20];
	ArrCosthErr[j] = VecAllChrisCosthErr[j+i*20];
	ArrEgErr[j] = VecAllChrisEgErr[j+i*20];


	//CoplanBinnedN40
	ArrSigmaN40[j] = VecAllChrisSigmaN40[j+i*20];
	ArrCosthN40[j] = VecAllChrisCosthN40[j+i*20];
	ArrEgN40[j] = VecAllChrisEgN40[j+i*20];
	ArrSigmaErrN40[j] = VecAllChrisSigmaErrN40[j+i*20];
	ArrCosthErrN40[j] = VecAllChrisCosthErrN40[j+i*20];
	ArrEgErrN40[j] = VecAllChrisEgErrN40[j+i*20];

	//CoplanN20
	ArrSigmaN20[j] = VecAllChrisSigmaN20[j+i*20];
	ArrCosthN20[j] = VecAllChrisCosthN20[j+i*20];
	ArrEgN20[j] = VecAllChrisEgN20[j+i*20];
	ArrSigmaErrN20[j] = VecAllChrisSigmaErrN20[j+i*20];
	ArrCosthErrN20[j] = VecAllChrisCosthErrN20[j+i*20];
	ArrEgErrN20[j] = VecAllChrisEgErrN20[j+i*20];

	//coplan0
	ArrSigma0[j] = VecAllChrisSigma0[j+i*20];
	ArrCosth0[j] = VecAllChrisCosth0[j+i*20];
	ArrEg0[j] = VecAllChrisEg0[j+i*20];
	ArrSigmaErr0[j] = VecAllChrisSigmaErr0[j+i*20];
	ArrCosthErr0[j] = VecAllChrisCosthErr0[j+i*20];
	ArrEgErr0[j] = VecAllChrisEgErr0[j+i*20];

	//coplan20
	ArrSigma20[j] = VecAllChrisSigma20[j+i*20];
	ArrCosth20[j] = VecAllChrisCosth20[j+i*20];
	ArrEg20[j] = VecAllChrisEg20[j+i*20];
	ArrSigmaErr20[j] = VecAllChrisSigmaErr20[j+i*20];
	ArrCosthErr20[j] = VecAllChrisCosthErr20[j+i*20];
	ArrEgErr20[j] = VecAllChrisEgErr20[j+i*20];


	//coplan40
	ArrSigma40[j] = VecAllChrisSigma40[j+i*20];
	ArrCosth40[j] = VecAllChrisCosth40[j+i*20];
	ArrEg40[j] = VecAllChrisEg40[j+i*20];
	ArrSigmaErr40[j] = VecAllChrisSigmaErr40[j+i*20];
	ArrCosthErr40[j] = VecAllChrisCosthErr40[j+i*20];
	ArrEgErr40[j] = VecAllChrisEgErr40[j+i*20];







	//Timing Weights
	ArrSigmaTiming[j] = VecAllChrisSigmaTiming[j+i*20];
	ArrCosthTiming[j] = VecAllChrisCosthTiming[j+i*20];
	ArrEgTiming[j] = VecAllChrisEgTiming[j+i*20];
	ArrSigmaErrTiming[j] = VecAllChrisSigmaErrTiming[j+i*20];
	ArrCosthErrTiming[j] = VecAllChrisCosthErrTiming[j+i*20];
	ArrEgErrTiming[j] = VecAllChrisEgErrTiming[j+i*20];


	//Strict Cuts Timing Weights
	ArrSigmaStrict[j] = VecAllChrisSigmaStrict[j+i*20];
	ArrCosthStrict[j] = VecAllChrisCosthStrict[j+i*20];
	ArrEgStrict[j] = VecAllChrisEgStrict[j+i*20];
	ArrSigmaErrStrict[j] = VecAllChrisSigmaErrStrict[j+i*20];
	ArrCosthErrStrict[j] = VecAllChrisCosthErrStrict[j+i*20];
	ArrEgErrStrict[j] = VecAllChrisEgErrStrict[j+i*20];


	// CutsBased Analysis
	ArrSigmaCuts[j] = VecAllChrisSigmaCuts[j+i*20];
	ArrCosthCuts[j] = VecAllChrisCosthCuts[j+i*20];
	ArrEgCuts[j] = VecAllChrisEgCuts[j+i*20];
	ArrSigmaErrCuts[j] = VecAllChrisSigmaErrCuts[j+i*20];
	ArrCosthErrCuts[j] = VecAllChrisCosthErrCuts[j+i*20];
	ArrEgErrCuts[j] = VecAllChrisEgErrCuts[j+i*20];

	//InvWeights
	ArrSigmaInv[j] = VecAllChrisSigmaInv[j+i*20];
	ArrCosthInv[j] = VecAllChrisCosthInv[j+i*20];
	ArrEgInv[j] = VecAllChrisEgInv[j+i*20];
	ArrSigmaErrInv[j] = VecAllChrisSigmaErrInv[j+i*20];
	ArrCosthErrInv[j] = VecAllChrisCosthErrInv[j+i*20];
	ArrEgErrInv[j] = VecAllChrisEgErrInv[j+i*20];

	//MyResultsLess
	ArrSigmaLess[j] = VecAllChrisSigmaLess[j+i*20];
	ArrCosthLess[j] = VecAllChrisCosthLess[j+i*20];
	ArrEgLess[j] = VecAllChrisEgLess[j+i*20];
	ArrSigmaErrLess[j] = VecAllChrisSigmaErrLess[j+i*20];
	ArrCosthErrLess[j] = VecAllChrisCosthErrLess[j+i*20];
	ArrEgErrLess[j] = VecAllChrisEgErrLess[j+i*20];

	//MyResultsGreater
	ArrSigmaGreater[j] = VecAllChrisSigmaGreater[j+i*20];
	ArrCosthGreater[j] = VecAllChrisCosthGreater[j+i*20];
	ArrEgGreater[j] = VecAllChrisEgGreater[j+i*20];
	ArrSigmaErrGreater[j] = VecAllChrisSigmaErrGreater[j+i*20];
	ArrCosthErrGreater[j] = VecAllChrisCosthErrGreater[j+i*20];
	ArrEgErrGreater[j] = VecAllChrisEgErrGreater[j+i*20];

	//Simons Results
	ArrSigmaSimon[j] = VecAllSimonSigma[j+i*20];
	ArrCosthSimon[j] = VecAllSimonCosth[j+i*20];
	ArrEgSimon[j] = VecAllSimonEg[j+i*20];
	ArrSigmaSimonErr[j] = VecAllSimonSigmaErr[j+i*20];
	ArrCosthSimonErr[j] = VecAllSimonCosthErr[j+i*20];
	ArrEgSimonErr[j] = VecAllSimonEgErr[j+i*20];

	if(VecAllSimonSigma[j+i*20]!=0){
	ArrSigmaDiv[j] = VecAllChrisSigma[j+i*20]/VecAllSimonSigma[j+i*20]; 

}
	else{

	ArrSigmaDiv[j]=0;

}


}
	
auto c3 = new TCanvas("c3","c3");

TString PosTitle =Form("%f",ArrEg[0]) ;
TString PosName = Form("%f",ArrEg[0]) ;

//Change to use TGraphErrors! 
//Also create and save multiple canvasses??? Rather than TMultiGraph since this should keep the legend
//	TGraph* SigmaPlot=new TGraph(20,ArrCosth,ArrSigma);
//	TGraph* SigmaPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaSimon);
//	TGraph* DivisionPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaDiv);

	TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
	TGraph* SigmaPlotSimon=new TGraphErrors(20,ArrCosthSimon,ArrSigmaSimon,ArrCosthSimonErr,ArrSigmaSimonErr);
	TGraph* DivisionPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaDiv);

	TGraph* SigmaPlotLess=new TGraphErrors(20,ArrCosthLess,ArrSigmaLess,ArrCosthErrLess,ArrSigmaErrLess);
	TGraph* SigmaPlotGreater=new TGraphErrors(20,ArrCosthGreater,ArrSigmaGreater,ArrCosthErrGreater,ArrSigmaErrGreater);
	TGraph* SigmaPlotTiming=new TGraphErrors(20,ArrCosthTiming,ArrSigmaTiming,ArrCosthErrTiming,ArrSigmaErrTiming);
	TGraph* SigmaPlotStrict=new TGraphErrors(20,ArrCosthStrict,ArrSigmaStrict,ArrCosthErrStrict,ArrSigmaErrStrict);
	TGraph* SigmaPlotInv=new TGraphErrors(20,ArrCosthInv,ArrSigmaInv,ArrCosthErrInv,ArrSigmaErrInv);
	TGraph* SigmaPlotCuts=new TGraphErrors(20,ArrCosthCuts,ArrSigmaCuts,ArrCosthErrCuts,ArrSigmaErrCuts);


	TGraph* SigmaPlotN40=new TGraphErrors(20,ArrCosthN40,ArrSigmaN40,ArrCosthErrN40,ArrSigmaErrN40);
	TGraph* SigmaPlotN20=new TGraphErrors(20,ArrCosthN20,ArrSigmaN20,ArrCosthErrN20,ArrSigmaErrN20);
	TGraph* SigmaPlot0=new TGraphErrors(20,ArrCosth0,ArrSigma0,ArrCosthErr0,ArrSigmaErr0);
	TGraph* SigmaPlot20=new TGraphErrors(20,ArrCosth20,ArrSigma20,ArrCosthErr20,ArrSigmaErr20);
	TGraph* SigmaPlot40=new TGraphErrors(20,ArrCosth40,ArrSigma40,ArrCosthErr40,ArrSigmaErr40);







SigmaPlotSimon->SetMarkerStyle(21);  //filled square(red)
SigmaPlotSimon->SetMarkerColor(2);  //red

DivisionPlotSimon->SetMarkerStyle(23);//filled upside down triangle(blue)
DivisionPlotSimon->SetMarkerColor(4);//blue

SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotN40->SetMarkerStyle(29);//star
SigmaPlotN20->SetMarkerStyle(31);//line star
SigmaPlot0->SetMarkerStyle(33);//diamond
SigmaPlot20->SetMarkerStyle(20);//circle
SigmaPlot40->SetMarkerStyle(34);//celticcross

SigmaPlotLess->SetMarkerStyle(29);//filled star(yellow)
SigmaPlotGreater->SetMarkerStyle(31);//line star (like two crosses at 90deg to each other)(blue)
SigmaPlotTiming->SetMarkerStyle(33);//diamond(light blue)
SigmaPlotStrict->SetMarkerStyle(29);//filled star(blue)
SigmaPlotCuts->SetMarkerStyle(31);//line star(yellow)
SigmaPlotInv->SetMarkerStyle(34);//Celtic cross(pink)


//Yell,blue,lblue.red.pink total=black

SigmaPlotN40->SetMarkerColor(5);//(yellow)
SigmaPlotN20->SetMarkerColor(4);//(blue)
SigmaPlot0->SetMarkerColor(7);//(lightblue)
SigmaPlot20->SetMarkerColor(2);//(red)
SigmaPlot40->SetMarkerColor(6);//(pink)


SigmaPlotLess->SetMarkerColor(5);//(yellow)
SigmaPlotGreater->SetMarkerColor(4);//(blue)
SigmaPlotTiming->SetMarkerColor(7);//light blue
SigmaPlotStrict->SetMarkerColor(5);// blue
SigmaPlotCuts->SetMarkerColor(6);// blue
SigmaPlotInv->SetMarkerColor(6);//pink

TMultiGraph* mg = new TMultiGraph();
mg->Add(SigmaPlot);
//mg->Add(SigmaPlotN40);
mg->Add(SigmaPlotN20);
mg->Add(SigmaPlot0);
mg->Add(SigmaPlot20);
//mg->Add(SigmaPlot40);
//mg->Add(SigmaPlotLess);
//mg->Add(SigmaPlotGreater);
//mg->Add(SigmaPlotTiming);
mg->Add(SigmaPlotStrict);
mg->Add(SigmaPlotCuts);
//mg->Add(SigmaPlotInv);
//mg->Add(SigmaPlotSimon);
//mg->Add(DivisionPlotSimon);


TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;


  SigmaPlotSimon->SetTitle(hTitle+"Simon");
  SigmaPlotSimon->SetName(hName+"Simon");

  DivisionPlotSimon->SetTitle(hTitle+"Divi");
  DivisionPlotSimon->SetName(hName+"Divi");

//  SigmaPlot->Draw("AP*");
  SigmaPlot->SetTitle(hTitle);
  SigmaPlot->SetName(hName);
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


mg->Write();
leg->Write();//Sort the writing of the legend later
DivisionPlotSimon->Write();


}
outfile->Close();
} //closing main function
	

