#include <stdlib.h>


void PlotComparisonThesisResults() {
		
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/CheckFits/OnePlotResultsPPi0UnBinnedVsStrictCutsVsCoplanFits.root","recreate");
 
  TCanvas *Canvas1 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",0,0,1600,2000);
  Canvas1->SetCanvasSize(1600,2000);
  Canvas1->SetWindowSize(1600,2000);
  Canvas1->Divide(3,4,0,0,0);

 
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

// Unbinned fit results 
  vector<Double_t> VecAllChrisSigmaUnBin;
  vector<Double_t> VecAllChrisEgUnBin;
  vector<Double_t> VecAllChrisCosthUnBin;
//  vector<TString> VecAllChrisTypeUnBin;
  vector<Double_t> VecAllChrisSigmaErrUnBin;
  vector<Double_t> VecAllChrisEgErrUnBin;
  vector<Double_t> VecAllChrisCosthErrUnBin;




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


	//StrictCuts RandBGSub
  vector<Double_t> VecAllChrisSigmaStrictBG;
  vector<Double_t> VecAllChrisEgStrictBG;
  vector<Double_t> VecAllChrisCosthStrictBG;
  vector<TString> VecAllChrisTypeStrictBG;
  vector<Double_t> VecAllChrisSigmaErrStrictBG;
  vector<Double_t> VecAllChrisEgErrStrictBG;
  vector<Double_t> VecAllChrisCosthErrStrictBG;


	//NonStrictCuts RandBGSub
  vector<Double_t> VecAllChrisSigmaNonStrictBG;
  vector<Double_t> VecAllChrisEgNonStrictBG;
  vector<Double_t> VecAllChrisCosthNonStrictBG;
  vector<TString> VecAllChrisTypeNonStrictBG;
  vector<Double_t> VecAllChrisSigmaErrNonStrictBG;
  vector<Double_t> VecAllChrisEgErrNonStrictBG;
  vector<Double_t> VecAllChrisCosthErrNonStrictBG;



	//StrictCuts DariaPhi 
  vector<Double_t> VecAllChrisSigmaStrictDar;
  vector<Double_t> VecAllChrisEgStrictDar;
  vector<Double_t> VecAllChrisCosthStrictDar;
  vector<TString> VecAllChrisTypeStrictDar;
  vector<Double_t> VecAllChrisSigmaErrStrictDar;
  vector<Double_t> VecAllChrisEgErrStrictDar;
  vector<Double_t> VecAllChrisCosthErrStrictDar;

	//CutsAnalysis
  vector<Double_t> VecAllChrisSigmaCuts;
  vector<Double_t> VecAllChrisEgCuts;
  vector<Double_t> VecAllChrisCosthCuts;
  vector<TString> VecAllChrisTypeCuts;
  vector<Double_t> VecAllChrisSigmaErrCuts;
  vector<Double_t> VecAllChrisEgErrCuts;
  vector<Double_t> VecAllChrisCosthErrCuts;


	//NonStrictDariaPhiAnalysis
  vector<Double_t> VecAllChrisSigmaCutsNon;
  vector<Double_t> VecAllChrisEgCutsNon;
  vector<Double_t> VecAllChrisCosthCutsNon;
  vector<TString> VecAllChrisTypeCutsNon;
  vector<Double_t> VecAllChrisSigmaErrCutsNon;
  vector<Double_t> VecAllChrisEgErrCutsNon;
  vector<Double_t> VecAllChrisCosthErrCutsNon;




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

	//My UnBinned Results
  Double_t AllChrisSigmaUnBin;
  Double_t AllChrisEgUnBin;
  Double_t AllChrisCosthUnBin;
//  TString AllChrisTypeUnBin;
  Double_t AllChrisSigmaErrUnBin;
  Double_t AllChrisEgErrUnBin;
  Double_t AllChrisCosthErrUnBin;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec;
  Double_t AllChrisEgSpec;
  Double_t AllChrisCosthSpec;
  TString AllChrisTypeSpec;
  Double_t AllChrisSigmaErrSpec;
  Double_t AllChrisEgErrSpec;
  Double_t AllChrisCosthErrSpec;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec2;
  Double_t AllChrisEgSpec2;
  Double_t AllChrisCosthSpec2;
  TString AllChrisTypeSpec2;
  Double_t AllChrisSigmaErrSpec2;
  Double_t AllChrisEgErrSpec2;
  Double_t AllChrisCosthErrSpec2;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec3;
  Double_t AllChrisEgSpec3;
  Double_t AllChrisCosthSpec3;
  TString AllChrisTypeSpec3;
  Double_t AllChrisSigmaErrSpec3;
  Double_t AllChrisEgErrSpec3;
  Double_t AllChrisCosthErrSpec3;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec4;
  Double_t AllChrisEgSpec4;
  Double_t AllChrisCosthSpec4;
  TString AllChrisTypeSpec4;
  Double_t AllChrisSigmaErrSpec4;
  Double_t AllChrisEgErrSpec4;
  Double_t AllChrisCosthErrSpec4;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec5;
  Double_t AllChrisEgSpec5;
  Double_t AllChrisCosthSpec5;
  TString AllChrisTypeSpec5;
  Double_t AllChrisSigmaErrSpec5;
  Double_t AllChrisEgErrSpec5;
  Double_t AllChrisCosthErrSpec5;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec6;
  Double_t AllChrisEgSpec6;
  Double_t AllChrisCosthSpec6;
  TString AllChrisTypeSpec6;
  Double_t AllChrisSigmaErrSpec6;
  Double_t AllChrisEgErrSpec6;
  Double_t AllChrisCosthErrSpec6;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec7;
  Double_t AllChrisEgSpec7;
  Double_t AllChrisCosthSpec7;
  TString AllChrisTypeSpec7;
  Double_t AllChrisSigmaErrSpec7;
  Double_t AllChrisEgErrSpec7;
  Double_t AllChrisCosthErrSpec7;

	//Binned SpecMom
  Double_t AllChrisSigmaSpec8;
  Double_t AllChrisEgSpec8;
  Double_t AllChrisCosthSpec8;
  TString AllChrisTypeSpec8;
  Double_t AllChrisSigmaErrSpec8;
  Double_t AllChrisEgErrSpec8;
  Double_t AllChrisCosthErrSpec8;


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


	//StrictCutsRandBGSub
  Double_t AllChrisSigmaStrictBG;
  Double_t AllChrisEgStrictBG;
  Double_t AllChrisCosthStrictBG;
  TString AllChrisTypeStrictBG;
  Double_t AllChrisSigmaErrStrictBG;
  Double_t AllChrisEgErrStrictBG;
  Double_t AllChrisCosthErrStrictBG;


	//NonStrictCutsRandBGSub
  Double_t AllChrisSigmaNonStrictBG;
  Double_t AllChrisEgNonStrictBG;
  Double_t AllChrisCosthNonStrictBG;
  TString AllChrisTypeNonStrictBG;
  Double_t AllChrisSigmaErrNonStrictBG;
  Double_t AllChrisEgErrNonStrictBG;
  Double_t AllChrisCosthErrNonStrictBG;



	//StrictCutsDariaPhiAnalysis
  Double_t AllChrisSigmaStrictDar;
  Double_t AllChrisEgStrictDar;
  Double_t AllChrisCosthStrictDar;
  TString AllChrisTypeStrictDar;
  Double_t AllChrisSigmaErrStrictDar;
  Double_t AllChrisEgErrStrictDar;
  Double_t AllChrisCosthErrStrictDar;


	//CutsAnalysis
  Double_t AllChrisSigmaCuts;
  Double_t AllChrisEgCuts;
  Double_t AllChrisCosthCuts;
  TString AllChrisTypeCuts;
  Double_t AllChrisSigmaErrCuts;
  Double_t AllChrisEgErrCuts;
  Double_t AllChrisCosthErrCuts;



	//NonStrictCutsDariaPhiAnalysis
  Double_t AllChrisSigmaCutsNon;
  Double_t AllChrisEgCutsNon;
  Double_t AllChrisCosthCutsNon;
  TString AllChrisTypeCutsNon;
  Double_t AllChrisSigmaErrCutsNon;
  Double_t AllChrisEgErrCutsNon;
  Double_t AllChrisCosthErrCutsNon;


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
  std::ifstream inputFile("Data/CutResultsNew.txt");
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

  //read in my unbinned results from text file
  std::ifstream inputFileUnBin("Data/CutResultsUnBinnedProtonSigma.txt");
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

  //read in my results from text file
  std::ifstream inputFileSpec("Data/CutResultsNewNonStrictSpecMomBins0to50Mev.txt");
  std::string lineSpec;
  if (inputFileSpec.is_open()){
    while(getline(inputFileSpec, lineSpec) ){
      stringstream(lineSpec)>>AllChrisSigmaSpec >>AllChrisSigmaErrSpec>>AllChrisEgSpec>>AllChrisEgErrSpec >> AllChrisCosthSpec>>AllChrisCosthErrSpec>> AllChrisTypeSpec;
      VecAllChrisSigmaSpec.push_back(AllChrisSigmaSpec);
      VecAllChrisEgSpec.push_back(AllChrisEgSpec);
      VecAllChrisCosthSpec.push_back(AllChrisCosthSpec);
      VecAllChrisTypeSpec.push_back(AllChrisTypeSpec);
      VecAllChrisSigmaErrSpec.push_back(AllChrisSigmaErrSpec);
      VecAllChrisEgErrSpec.push_back(AllChrisEgErrSpec);
      VecAllChrisCosthErrSpec.push_back(AllChrisCosthErrSpec);
    }
  }


  //read in my results from text file
  std::ifstream inputFileSpec2("Data/CutResultsNewNonStrictSpecMomBins50to100Mev.txt");
  std::string lineSpec2;
  if (inputFileSpec2.is_open()){
    while(getline(inputFileSpec2, lineSpec2) ){
      stringstream(lineSpec2)>>AllChrisSigmaSpec2 >>AllChrisSigmaErrSpec2>>AllChrisEgSpec2>>AllChrisEgErrSpec2 >> AllChrisCosthSpec2>>AllChrisCosthErrSpec2>> AllChrisTypeSpec2;
      VecAllChrisSigmaSpec2.push_back(AllChrisSigmaSpec2);
      VecAllChrisEgSpec2.push_back(AllChrisEgSpec2);
      VecAllChrisCosthSpec2.push_back(AllChrisCosthSpec2);
      VecAllChrisTypeSpec2.push_back(AllChrisTypeSpec2);
      VecAllChrisSigmaErrSpec2.push_back(AllChrisSigmaErrSpec2);
      VecAllChrisEgErrSpec2.push_back(AllChrisEgErrSpec2);
      VecAllChrisCosthErrSpec2.push_back(AllChrisCosthErrSpec2);
    }
  }

  //read in my results from text file
  std::ifstream inputFileSpec3("Data/CutResultsNewNonStrictSpecMomBins100to150Mev.txt");
  std::string lineSpec3;
  if (inputFileSpec3.is_open()){
    while(getline(inputFileSpec3, lineSpec3) ){
      stringstream(lineSpec3)>>AllChrisSigmaSpec3 >>AllChrisSigmaErrSpec3>>AllChrisEgSpec3>>AllChrisEgErrSpec3 >> AllChrisCosthSpec3>>AllChrisCosthErrSpec3>> AllChrisTypeSpec3;
      VecAllChrisSigmaSpec3.push_back(AllChrisSigmaSpec3);
      VecAllChrisEgSpec3.push_back(AllChrisEgSpec3);
      VecAllChrisCosthSpec3.push_back(AllChrisCosthSpec3);
      VecAllChrisTypeSpec3.push_back(AllChrisTypeSpec3);
      VecAllChrisSigmaErrSpec3.push_back(AllChrisSigmaErrSpec3);
      VecAllChrisEgErrSpec3.push_back(AllChrisEgErrSpec3);
      VecAllChrisCosthErrSpec3.push_back(AllChrisCosthErrSpec3);
    }
  }

  //read in my results from text file
  std::ifstream inputFileSpec4("Data/CutResultsNewNonStrictSpecMomBins150to200Mev.txt");
  std::string lineSpec4;
  if (inputFileSpec4.is_open()){
    while(getline(inputFileSpec4, lineSpec4) ){
      stringstream(lineSpec4)>>AllChrisSigmaSpec4 >>AllChrisSigmaErrSpec4>>AllChrisEgSpec4>>AllChrisEgErrSpec4 >> AllChrisCosthSpec4>>AllChrisCosthErrSpec4>> AllChrisTypeSpec4;
      VecAllChrisSigmaSpec4.push_back(AllChrisSigmaSpec4);
      VecAllChrisEgSpec4.push_back(AllChrisEgSpec4);
      VecAllChrisCosthSpec4.push_back(AllChrisCosthSpec4);
      VecAllChrisTypeSpec4.push_back(AllChrisTypeSpec4);
      VecAllChrisSigmaErrSpec4.push_back(AllChrisSigmaErrSpec4);
      VecAllChrisEgErrSpec4.push_back(AllChrisEgErrSpec4);
      VecAllChrisCosthErrSpec4.push_back(AllChrisCosthErrSpec4);
    }
  }

  //read in my results from text file
  std::ifstream inputFileSpec5("Data/CutResultsNewNonStrictSpecMomBins200to250Mev.txt");
  std::string lineSpec5;
  if (inputFileSpec5.is_open()){
    while(getline(inputFileSpec5, lineSpec5) ){
      stringstream(lineSpec5)>>AllChrisSigmaSpec5 >>AllChrisSigmaErrSpec5>>AllChrisEgSpec5>>AllChrisEgErrSpec5 >> AllChrisCosthSpec5>>AllChrisCosthErrSpec5>> AllChrisTypeSpec5;
      VecAllChrisSigmaSpec5.push_back(AllChrisSigmaSpec5);
      VecAllChrisEgSpec5.push_back(AllChrisEgSpec5);
      VecAllChrisCosthSpec5.push_back(AllChrisCosthSpec5);
      VecAllChrisTypeSpec5.push_back(AllChrisTypeSpec5);
      VecAllChrisSigmaErrSpec5.push_back(AllChrisSigmaErrSpec5);
      VecAllChrisEgErrSpec5.push_back(AllChrisEgErrSpec5);
      VecAllChrisCosthErrSpec5.push_back(AllChrisCosthErrSpec5);
    }
  }

  //read in my results from text file
  std::ifstream inputFileSpec6("Data/CutResultsNewNonStrictSpecMomBins250to300Mev.txt");
  std::string lineSpec6;
  if (inputFileSpec6.is_open()){
    while(getline(inputFileSpec6, lineSpec6) ){
      stringstream(lineSpec6)>>AllChrisSigmaSpec6 >>AllChrisSigmaErrSpec6>>AllChrisEgSpec6>>AllChrisEgErrSpec6 >> AllChrisCosthSpec6>>AllChrisCosthErrSpec6>> AllChrisTypeSpec6;
      VecAllChrisSigmaSpec6.push_back(AllChrisSigmaSpec6);
      VecAllChrisEgSpec6.push_back(AllChrisEgSpec6);
      VecAllChrisCosthSpec6.push_back(AllChrisCosthSpec6);
      VecAllChrisTypeSpec6.push_back(AllChrisTypeSpec6);
      VecAllChrisSigmaErrSpec6.push_back(AllChrisSigmaErrSpec6);
      VecAllChrisEgErrSpec6.push_back(AllChrisEgErrSpec6);
      VecAllChrisCosthErrSpec6.push_back(AllChrisCosthErrSpec6);
    }
  }

  //read in my results from text file
  std::ifstream inputFileSpec7("Data/CutResultsNewNonStrictSpecMomBins300to350Mev.txt");
  std::string lineSpec7;
  if (inputFileSpec7.is_open()){
    while(getline(inputFileSpec7, lineSpec7) ){
      stringstream(lineSpec7)>>AllChrisSigmaSpec7 >>AllChrisSigmaErrSpec7>>AllChrisEgSpec7>>AllChrisEgErrSpec7 >> AllChrisCosthSpec7>>AllChrisCosthErrSpec7>> AllChrisTypeSpec7;
      VecAllChrisSigmaSpec7.push_back(AllChrisSigmaSpec7);
      VecAllChrisEgSpec7.push_back(AllChrisEgSpec7);
      VecAllChrisCosthSpec7.push_back(AllChrisCosthSpec7);
      VecAllChrisTypeSpec7.push_back(AllChrisTypeSpec7);
      VecAllChrisSigmaErrSpec7.push_back(AllChrisSigmaErrSpec7);
      VecAllChrisEgErrSpec7.push_back(AllChrisEgErrSpec7);
      VecAllChrisCosthErrSpec7.push_back(AllChrisCosthErrSpec7);
    }
  }

  //read in my results from text file
  std::ifstream inputFileSpec8("Data/CutResultsNewNonStrictSpecMomBins350to400Mev.txt");
  std::string lineSpec8;
  if (inputFileSpec8.is_open()){
    while(getline(inputFileSpec8, lineSpec8) ){
      stringstream(lineSpec8)>>AllChrisSigmaSpec8 >>AllChrisSigmaErrSpec8>>AllChrisEgSpec8>>AllChrisEgErrSpec8 >> AllChrisCosthSpec8>>AllChrisCosthErrSpec8>> AllChrisTypeSpec8;
      VecAllChrisSigmaSpec8.push_back(AllChrisSigmaSpec8);
      VecAllChrisEgSpec8.push_back(AllChrisEgSpec8);
      VecAllChrisCosthSpec8.push_back(AllChrisCosthSpec8);
      VecAllChrisTypeSpec8.push_back(AllChrisTypeSpec8);
      VecAllChrisSigmaErrSpec8.push_back(AllChrisSigmaErrSpec8);
      VecAllChrisEgErrSpec8.push_back(AllChrisEgErrSpec8);
      VecAllChrisCosthErrSpec8.push_back(AllChrisCosthErrSpec8);
    }
  }

  //read in timingweights results from text file
  std::ifstream inputFileTiming("Data/CutResultsNewTiming.txt");
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
  std::ifstream inputFileStrict("Data/CutResultsNewStrictCutsOnlyTiming.txt");
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



  //read in StrictCutsRandBGSub results from text file
  std::ifstream inputFileStrictBG("Data/CutsNewBGSUBBEDStrictDariaPhi.txt");
  std::string lineStrictBG;
  if (inputFileStrictBG.is_open()){
    while(getline(inputFileStrictBG, lineStrictBG) ){
      stringstream(lineStrictBG)>>AllChrisSigmaStrictBG >>AllChrisSigmaErrStrictBG>>AllChrisEgStrictBG>>AllChrisEgErrStrictBG >> AllChrisCosthStrictBG>>AllChrisCosthErrStrictBG>> AllChrisTypeStrictBG;
      VecAllChrisSigmaStrictBG.push_back(AllChrisSigmaStrictBG);
      VecAllChrisEgStrictBG.push_back(AllChrisEgStrictBG);
      VecAllChrisCosthStrictBG.push_back(AllChrisCosthStrictBG);
      VecAllChrisTypeStrictBG.push_back(AllChrisTypeStrictBG);
      VecAllChrisSigmaErrStrictBG.push_back(AllChrisSigmaErrStrictBG);
      VecAllChrisEgErrStrictBG.push_back(AllChrisEgErrStrictBG);
      VecAllChrisCosthErrStrictBG.push_back(AllChrisCosthErrStrictBG);
    }
  }

  //read in NonStrictCutsRandBGSub results from text file
  std::ifstream inputFileNonStrictBG("Data/CutsNewBGSUBBEDNonStrictDariaPhi.txt");
  std::string lineNonStrictBG;
  if (inputFileNonStrictBG.is_open()){
    while(getline(inputFileNonStrictBG, lineNonStrictBG) ){
      stringstream(lineNonStrictBG)>>AllChrisSigmaNonStrictBG >>AllChrisSigmaErrNonStrictBG>>AllChrisEgNonStrictBG>>AllChrisEgErrNonStrictBG >> AllChrisCosthNonStrictBG>>AllChrisCosthErrNonStrictBG>> AllChrisTypeNonStrictBG;
      VecAllChrisSigmaNonStrictBG.push_back(AllChrisSigmaNonStrictBG);
      VecAllChrisEgNonStrictBG.push_back(AllChrisEgNonStrictBG);
      VecAllChrisCosthNonStrictBG.push_back(AllChrisCosthNonStrictBG);
      VecAllChrisTypeNonStrictBG.push_back(AllChrisTypeNonStrictBG);
      VecAllChrisSigmaErrNonStrictBG.push_back(AllChrisSigmaErrNonStrictBG);
      VecAllChrisEgErrNonStrictBG.push_back(AllChrisEgErrNonStrictBG);
      VecAllChrisCosthErrNonStrictBG.push_back(AllChrisCosthErrNonStrictBG);
    }
  }



  //read in StrictCutsDariaPhi results from text file
  std::ifstream inputFileStrictDar("Data/CutResultsNewStrictDariaPhi.txt");
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




  //read in CutsAnalysis results from text file
  std::ifstream inputFileCuts("Data/CutResultsNewCutsBasedAnalysis.txt");
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


  //read in CutsAnalysis results from text file
  std::ifstream inputFileCutsNon("Data/CutResultsNewNonStrictDariaPhi.txt");
  std::string lineCutsNon;
  if (inputFileCutsNon.is_open()){
    while(getline(inputFileCutsNon, lineCutsNon) ){
      stringstream(lineCutsNon)>>AllChrisSigmaCutsNon >>AllChrisSigmaErrCutsNon>>AllChrisEgCutsNon>>AllChrisEgErrCutsNon >> AllChrisCosthCutsNon>>AllChrisCosthErrCutsNon>> AllChrisTypeCutsNon;
      VecAllChrisSigmaCutsNon.push_back(AllChrisSigmaCutsNon);
      VecAllChrisEgCutsNon.push_back(AllChrisEgCutsNon);
      VecAllChrisCosthCutsNon.push_back(AllChrisCosthCutsNon);
      VecAllChrisTypeCutsNon.push_back(AllChrisTypeCutsNon);
      VecAllChrisSigmaErrCutsNon.push_back(AllChrisSigmaErrCutsNon);
      VecAllChrisEgErrCutsNon.push_back(AllChrisEgErrCutsNon);
      VecAllChrisCosthErrCutsNon.push_back(AllChrisCosthErrCutsNon);
    }
  }

  //read in InvWeights results from text file
  std::ifstream inputFileInv("Data/CutResultsNewInv.txt");
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
  std::ifstream inputFileLess("Data/CutResultsNewSpecMomLessThan100.txt");
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
  std::ifstream inputFileGreater("Data/CutResultsNewSpecMomGreaterThan100.txt");
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
  std::ifstream inputFile2("Data/NewSimonsResultsMyBins.txt");
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

	//My UnBinned Results
Double_t ArrSigmaUnBin[20];
Double_t ArrCosthUnBin[20];
Double_t ArrEgUnBin[20];
Double_t ArrSigmaErrUnBin[20];
Double_t ArrCosthErrUnBin[20];
Double_t ArrEgErrUnBin[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec[20];
Double_t ArrCosthSpec[20];
Double_t ArrEgSpec[20];
Double_t ArrSigmaErrSpec[20];
Double_t ArrCosthErrSpec[20];
Double_t ArrEgErrSpec[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec2[20];
Double_t ArrCosthSpec2[20];
Double_t ArrEgSpec2[20];
Double_t ArrSigmaErrSpec2[20];
Double_t ArrCosthErrSpec2[20];
Double_t ArrEgErrSpec2[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec3[20];
Double_t ArrCosthSpec3[20];
Double_t ArrEgSpec3[20];
Double_t ArrSigmaErrSpec3[20];
Double_t ArrCosthErrSpec3[20];
Double_t ArrEgErrSpec3[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec4[20];
Double_t ArrCosthSpec4[20];
Double_t ArrEgSpec4[20];
Double_t ArrSigmaErrSpec4[20];
Double_t ArrCosthErrSpec4[20];
Double_t ArrEgErrSpec4[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec5[20];
Double_t ArrCosthSpec5[20];
Double_t ArrEgSpec5[20];
Double_t ArrSigmaErrSpec5[20];
Double_t ArrCosthErrSpec5[20];
Double_t ArrEgErrSpec5[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec6[20];
Double_t ArrCosthSpec6[20];
Double_t ArrEgSpec6[20];
Double_t ArrSigmaErrSpec6[20];
Double_t ArrCosthErrSpec6[20];
Double_t ArrEgErrSpec6[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec7[20];
Double_t ArrCosthSpec7[20];
Double_t ArrEgSpec7[20];
Double_t ArrSigmaErrSpec7[20];
Double_t ArrCosthErrSpec7[20];
Double_t ArrEgErrSpec7[20];

	//My Results Spec Binned Cuts Analysis
Double_t ArrSigmaSpec8[20];
Double_t ArrCosthSpec8[20];
Double_t ArrEgSpec8[20];
Double_t ArrSigmaErrSpec8[20];
Double_t ArrCosthErrSpec8[20];
Double_t ArrEgErrSpec8[20];


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


//StrictCutsRandBGSub Timing weights
Double_t ArrSigmaStrictBG[20];
Double_t ArrCosthStrictBG[20];
Double_t ArrEgStrictBG[20];
Double_t ArrSigmaErrStrictBG[20];
Double_t ArrCosthErrStrictBG[20];
Double_t ArrEgErrStrictBG[20];


//NonStrictCutsRandBGSub Timing weights
Double_t ArrSigmaNonStrictBG[20];
Double_t ArrCosthNonStrictBG[20];
Double_t ArrEgNonStrictBG[20];
Double_t ArrSigmaErrNonStrictBG[20];
Double_t ArrCosthErrNonStrictBG[20];
Double_t ArrEgErrNonStrictBG[20];

//StrictCuts DariaPhi
Double_t ArrSigmaStrictDar[20];
Double_t ArrCosthStrictDar[20];
Double_t ArrEgStrictDar[20];
Double_t ArrSigmaErrStrictDar[20];
Double_t ArrCosthErrStrictDar[20];
Double_t ArrEgErrStrictDar[20];



//CutsBasedAnalysis
Double_t ArrSigmaCuts[20];
Double_t ArrCosthCuts[20];
Double_t ArrEgCuts[20];
Double_t ArrSigmaErrCuts[20];
Double_t ArrCosthErrCuts[20];
Double_t ArrEgErrCuts[20];

//NonStrictCutsDariaPhiAnalysis
Double_t ArrSigmaCutsNon[20];
Double_t ArrCosthCutsNon[20];
Double_t ArrEgCutsNon[20];
Double_t ArrSigmaErrCutsNon[20];
Double_t ArrCosthErrCutsNon[20];
Double_t ArrEgErrCutsNon[20];

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
	for(Int_t j=0;j<20;j++){

	//MyResults
	ArrSigma[j] = VecAllChrisSigma[j+i*20];
	ArrCosth[j] = VecAllChrisCosth[j+i*20];
	ArrEg[j] = VecAllChrisEg[j+i*20];
	ArrSigmaErr[j] = VecAllChrisSigmaErr[j+i*20];
	ArrCosthErr[j] = VecAllChrisCosthErr[j+i*20];
	ArrEgErr[j] = VecAllChrisEgErr[j+i*20];

	//MyUnBinnedResults
	ArrSigmaUnBin[j] = VecAllChrisSigmaUnBin[j+i*20];
	ArrCosthUnBin[j] = VecAllChrisCosthUnBin[j+i*20];
	ArrEgUnBin[j] = VecAllChrisEgUnBin[j+i*20];
	ArrSigmaErrUnBin[j] = VecAllChrisSigmaErrUnBin[j+i*20];
	ArrCosthErrUnBin[j] = VecAllChrisCosthErrUnBin[j+i*20];
	ArrEgErrUnBin[j] = VecAllChrisEgErrUnBin[j+i*20];

	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec[j] = VecAllChrisSigmaSpec[j+i*20];
	ArrCosthSpec[j] = VecAllChrisCosthSpec[j+i*20];
	ArrEgSpec[j] = VecAllChrisEgSpec[j+i*20];
	ArrSigmaErrSpec[j] = VecAllChrisSigmaErrSpec[j+i*20];
	ArrCosthErrSpec[j] = VecAllChrisCosthErrSpec[j+i*20];
	ArrEgErrSpec[j] = VecAllChrisEgErrSpec[j+i*20];

	
	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec2[j] = VecAllChrisSigmaSpec2[j+i*20];
	ArrCosthSpec2[j] = VecAllChrisCosthSpec2[j+i*20];
	ArrEgSpec2[j] = VecAllChrisEgSpec2[j+i*20];
	ArrSigmaErrSpec2[j] = VecAllChrisSigmaErrSpec2[j+i*20];
	ArrCosthErrSpec2[j] = VecAllChrisCosthErrSpec2[j+i*20];
	ArrEgErrSpec2[j] = VecAllChrisEgErrSpec2[j+i*20];

	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec3[j] = VecAllChrisSigmaSpec3[j+i*20];
	ArrCosthSpec3[j] = VecAllChrisCosthSpec3[j+i*20];
	ArrEgSpec3[j] = VecAllChrisEgSpec3[j+i*20];
	ArrSigmaErrSpec3[j] = VecAllChrisSigmaErrSpec3[j+i*20];
	ArrCosthErrSpec3[j] = VecAllChrisCosthErrSpec3[j+i*20];
	ArrEgErrSpec3[j] = VecAllChrisEgErrSpec3[j+i*20];

	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec4[j] = VecAllChrisSigmaSpec4[j+i*20];
	ArrCosthSpec4[j] = VecAllChrisCosthSpec4[j+i*20];
	ArrEgSpec4[j] = VecAllChrisEgSpec4[j+i*20];
	ArrSigmaErrSpec4[j] = VecAllChrisSigmaErrSpec4[j+i*20];
	ArrCosthErrSpec4[j] = VecAllChrisCosthErrSpec4[j+i*20];
	ArrEgErrSpec4[j] = VecAllChrisEgErrSpec4[j+i*20];

	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec5[j] = VecAllChrisSigmaSpec5[j+i*20];
	ArrCosthSpec5[j] = VecAllChrisCosthSpec5[j+i*20];
	ArrEgSpec5[j] = VecAllChrisEgSpec5[j+i*20];
	ArrSigmaErrSpec5[j] = VecAllChrisSigmaErrSpec5[j+i*20];
	ArrCosthErrSpec5[j] = VecAllChrisCosthErrSpec5[j+i*20];
	ArrEgErrSpec5[j] = VecAllChrisEgErrSpec5[j+i*20];

	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec6[j] = VecAllChrisSigmaSpec6[j+i*20];
	ArrCosthSpec6[j] = VecAllChrisCosthSpec6[j+i*20];
	ArrEgSpec6[j] = VecAllChrisEgSpec6[j+i*20];
	ArrSigmaErrSpec6[j] = VecAllChrisSigmaErrSpec6[j+i*20];
	ArrCosthErrSpec6[j] = VecAllChrisCosthErrSpec6[j+i*20];
	ArrEgErrSpec6[j] = VecAllChrisEgErrSpec6[j+i*20];

	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec7[j] = VecAllChrisSigmaSpec7[j+i*20];
	ArrCosthSpec7[j] = VecAllChrisCosthSpec7[j+i*20];
	ArrEgSpec7[j] = VecAllChrisEgSpec7[j+i*20];
	ArrSigmaErrSpec7[j] = VecAllChrisSigmaErrSpec7[j+i*20];
	ArrCosthErrSpec7[j] = VecAllChrisCosthErrSpec7[j+i*20];
	ArrEgErrSpec7[j] = VecAllChrisEgErrSpec7[j+i*20];

	//MyResults SPecMom bins cuts analysis
	ArrSigmaSpec8[j] = VecAllChrisSigmaSpec8[j+i*20];
	ArrCosthSpec8[j] = VecAllChrisCosthSpec8[j+i*20];
	ArrEgSpec8[j] = VecAllChrisEgSpec8[j+i*20];
	ArrSigmaErrSpec8[j] = VecAllChrisSigmaErrSpec8[j+i*20];
	ArrCosthErrSpec8[j] = VecAllChrisCosthErrSpec8[j+i*20];
	ArrEgErrSpec8[j] = VecAllChrisEgErrSpec8[j+i*20];

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


	//Strict CutsRandBGSub Timing Weights
	ArrSigmaStrictBG[j] = VecAllChrisSigmaStrictBG[j+i*20];
	ArrCosthStrictBG[j] = VecAllChrisCosthStrictBG[j+i*20];
	ArrEgStrictBG[j] = VecAllChrisEgStrictBG[j+i*20];
	ArrSigmaErrStrictBG[j] = VecAllChrisSigmaErrStrictBG[j+i*20];
	ArrCosthErrStrictBG[j] = VecAllChrisCosthErrStrictBG[j+i*20];
	ArrEgErrStrictBG[j] = VecAllChrisEgErrStrictBG[j+i*20];


	//NonStrict CutsRandBGSub Timing Weights
	ArrSigmaNonStrictBG[j] = VecAllChrisSigmaNonStrictBG[j+i*20];
	ArrCosthNonStrictBG[j] = VecAllChrisCosthNonStrictBG[j+i*20];
	ArrEgNonStrictBG[j] = VecAllChrisEgNonStrictBG[j+i*20];
	ArrSigmaErrNonStrictBG[j] = VecAllChrisSigmaErrNonStrictBG[j+i*20];
	ArrCosthErrNonStrictBG[j] = VecAllChrisCosthErrNonStrictBG[j+i*20];
	ArrEgErrNonStrictBG[j] = VecAllChrisEgErrNonStrictBG[j+i*20];

	//Strict CutsDariaPhi
	ArrSigmaStrictDar[j] = VecAllChrisSigmaStrictDar[j+i*20];
	ArrCosthStrictDar[j] = VecAllChrisCosthStrictDar[j+i*20];
	ArrEgStrictDar[j] = VecAllChrisEgStrictDar[j+i*20];
	ArrSigmaErrStrictDar[j] = VecAllChrisSigmaErrStrictDar[j+i*20];
	ArrCosthErrStrictDar[j] = VecAllChrisCosthErrStrictDar[j+i*20];
	ArrEgErrStrictDar[j] = VecAllChrisEgErrStrictDar[j+i*20];


	// CutsBased Analysis
	ArrSigmaCuts[j] = VecAllChrisSigmaCuts[j+i*20];
	ArrCosthCuts[j] = VecAllChrisCosthCuts[j+i*20];
	ArrEgCuts[j] = VecAllChrisEgCuts[j+i*20];
	ArrSigmaErrCuts[j] = VecAllChrisSigmaErrCuts[j+i*20];
	ArrCosthErrCuts[j] = VecAllChrisCosthErrCuts[j+i*20];
	ArrEgErrCuts[j] = VecAllChrisEgErrCuts[j+i*20];

	// NonStrictCutsDariaPhi Analysis
	ArrSigmaCutsNon[j] = VecAllChrisSigmaCutsNon[j+i*20];
	ArrCosthCutsNon[j] = VecAllChrisCosthCutsNon[j+i*20];
	ArrEgCutsNon[j] = VecAllChrisEgCutsNon[j+i*20];
	ArrSigmaErrCutsNon[j] = VecAllChrisSigmaErrCutsNon[j+i*20];
	ArrCosthErrCutsNon[j] = VecAllChrisCosthErrCutsNon[j+i*20];
	ArrEgErrCutsNon[j] = VecAllChrisEgErrCutsNon[j+i*20];



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

    Canvas1->cd(i+1);
//auto c3 = new TCanvas("c3","c3");

TString PosTitle =Form("%f",ArrEg[0]) ;
TString PosName = Form("%f",ArrEg[0]) ;

//Change to use TGraphErrors! 
//Also create and save multiple canvasses??? Rather than TMultiGraph since this should keep the legend
//	TGraph* SigmaPlot=new TGraph(20,ArrCosth,ArrSigma);
//	TGraph* SigmaPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaSimon);
//	TGraph* DivisionPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaDiv);

	TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
	TGraph* SigmaPlotUnBin=new TGraphErrors(20,ArrCosthUnBin,ArrSigmaUnBin,ArrCosthErrUnBin,ArrSigmaErrUnBin);
	TGraph* SigmaPlotSimon=new TGraphErrors(20,ArrCosthSimon,ArrSigmaSimon,ArrCosthSimonErr,ArrSigmaSimonErr);
	TGraph* DivisionPlotSimon=new TGraph(20,ArrCosthSimon,ArrSigmaDiv);

	TGraph* SigmaPlotLess=new TGraphErrors(20,ArrCosthLess,ArrSigmaLess,ArrCosthErrLess,ArrSigmaErrLess);
	TGraph* SigmaPlotGreater=new TGraphErrors(20,ArrCosthGreater,ArrSigmaGreater,ArrCosthErrGreater,ArrSigmaErrGreater);
	TGraph* SigmaPlotTiming=new TGraphErrors(20,ArrCosthTiming,ArrSigmaTiming,ArrCosthErrTiming,ArrSigmaErrTiming);
	TGraph* SigmaPlotStrict=new TGraphErrors(20,ArrCosthStrict,ArrSigmaStrict,ArrCosthErrStrict,ArrSigmaErrStrict);
	TGraph* SigmaPlotInv=new TGraphErrors(20,ArrCosthInv,ArrSigmaInv,ArrCosthErrInv,ArrSigmaErrInv);
	TGraph* SigmaPlotCuts=new TGraphErrors(20,ArrCosthCuts,ArrSigmaCuts,ArrCosthErrCuts,ArrSigmaErrCuts);
	TGraph* SigmaPlotCutsNon=new TGraphErrors(20,ArrCosthCutsNon,ArrSigmaCutsNon,ArrCosthErrCutsNon,ArrSigmaErrCutsNon);
	TGraph* SigmaPlotStrictDar=new TGraphErrors(20,ArrCosthStrictDar,ArrSigmaStrictDar,ArrCosthErrStrictDar,ArrSigmaErrStrictDar);

	TGraph* SigmaPlotStrictBG=new TGraphErrors(20,ArrCosthStrictBG,ArrSigmaStrictBG,ArrCosthErrStrictBG,ArrSigmaErrStrictBG);
	TGraph* SigmaPlotNonStrictBG=new TGraphErrors(20,ArrCosthNonStrictBG,ArrSigmaNonStrictBG,ArrCosthErrNonStrictBG,ArrSigmaErrNonStrictBG);

		//SpecMom Binned cuts Analysis
	TGraph* SigmaPlotSpec=new TGraphErrors(20,ArrCosthSpec,ArrSigmaSpec,ArrCosthErrSpec,ArrSigmaErrSpec);
	TGraph* SigmaPlotSpec2=new TGraphErrors(20,ArrCosthSpec2,ArrSigmaSpec2,ArrCosthErrSpec2,ArrSigmaErrSpec2);
	TGraph* SigmaPlotSpec3=new TGraphErrors(20,ArrCosthSpec3,ArrSigmaSpec3,ArrCosthErrSpec3,ArrSigmaErrSpec3);
	TGraph* SigmaPlotSpec4=new TGraphErrors(20,ArrCosthSpec4,ArrSigmaSpec4,ArrCosthErrSpec4,ArrSigmaErrSpec4);
	TGraph* SigmaPlotSpec5=new TGraphErrors(20,ArrCosthSpec5,ArrSigmaSpec5,ArrCosthErrSpec5,ArrSigmaErrSpec5);
	TGraph* SigmaPlotSpec6=new TGraphErrors(20,ArrCosthSpec6,ArrSigmaSpec6,ArrCosthErrSpec6,ArrSigmaErrSpec6);
	TGraph* SigmaPlotSpec7=new TGraphErrors(20,ArrCosthSpec7,ArrSigmaSpec7,ArrCosthErrSpec7,ArrSigmaErrSpec7);
	TGraph* SigmaPlotSpec8=new TGraphErrors(20,ArrCosthSpec8,ArrSigmaSpec8,ArrCosthErrSpec8,ArrSigmaErrSpec8);


SigmaPlotSimon->SetMarkerStyle(21);  //filled square(red)
SigmaPlotSimon->SetMarkerColor(2);  //red

DivisionPlotSimon->SetMarkerStyle(23);//filled upside down triangle(blue)
DivisionPlotSimon->SetMarkerColor(4);//blue

SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotUnBin->SetMarkerStyle(29);//Filled triangle(black(default)
SigmaPlotLess->SetMarkerStyle(29);//filled star(yellow)
SigmaPlotGreater->SetMarkerStyle(31);//line star (like two crosses at 90deg to each other)(blue)
SigmaPlotTiming->SetMarkerStyle(33);//diamond(light blue)
SigmaPlotStrict->SetMarkerStyle(29);//filled star(blue)
SigmaPlotStrictBG->SetMarkerStyle(29);//filled star(blue)
SigmaPlotNonStrictBG->SetMarkerStyle(29);//filled star(blue)
SigmaPlotStrictDar->SetMarkerStyle(22);//triangle(blue)
SigmaPlotCuts->SetMarkerStyle(31);//line star(yellow)
SigmaPlotCutsNon->SetMarkerStyle(22);//filled triangle
SigmaPlotInv->SetMarkerStyle(34);//Celtic cross(pink)


	//SpecMom binned markers
SigmaPlotSpec->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotSpec2->SetMarkerStyle(29);//Filled triangle(black(default)
SigmaPlotSpec3->SetMarkerStyle(31);//Filled triangle(black(default)
SigmaPlotSpec4->SetMarkerStyle(33);//Filled triangle(black(default)
SigmaPlotSpec5->SetMarkerStyle(34);//Filled triangle(black(default)
SigmaPlotSpec6->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotSpec7->SetMarkerStyle(22);//Filled triangle(black(default)
SigmaPlotSpec8->SetMarkerStyle(22);//Filled triangle(black(default)
	//SpecMom binned marker colors
SigmaPlotSpec->SetMarkerColor(2);  //red
SigmaPlotSpec2->SetMarkerColor(4);  //blue
SigmaPlotSpec3->SetMarkerColor(1);  //black
SigmaPlotSpec4->SetMarkerColor(3);  //green
SigmaPlotSpec5->SetMarkerColor(5);  //yellow
SigmaPlotSpec6->SetMarkerColor(6);  //pink
SigmaPlotSpec7->SetMarkerColor(7);  //cyan
SigmaPlotSpec8->SetMarkerColor(28);  //brown
//SPec Mom for legend
SigmaPlotSpec->SetFillStyle(0);
SigmaPlotSpec->SetFillColor(0);
SigmaPlotSpec2->SetFillStyle(0);
SigmaPlotSpec2->SetFillColor(0);
SigmaPlotSpec3->SetFillStyle(0);
SigmaPlotSpec3->SetFillColor(0);
SigmaPlotSpec4->SetFillStyle(0);
SigmaPlotSpec4->SetFillColor(0);
SigmaPlotSpec5->SetFillStyle(0);
SigmaPlotSpec5->SetFillColor(0);
SigmaPlotSpec6->SetFillStyle(0);
SigmaPlotSpec6->SetFillColor(0);
SigmaPlotSpec7->SetFillStyle(0);
SigmaPlotSpec7->SetFillColor(0);
SigmaPlotSpec8->SetFillStyle(0);
SigmaPlotSpec8->SetFillColor(0);
//SpecMom Titles

SigmaPlotSpec->SetTitle("SpecMom0-50Mev");
SigmaPlotSpec2->SetTitle("SpecMom50-100Mev");
SigmaPlotSpec3->SetTitle("SpecMom100-150Mev");
SigmaPlotSpec4->SetTitle("SpecMom150-200Mev");
SigmaPlotSpec5->SetTitle("SpecMom200-250Mev");
SigmaPlotSpec6->SetTitle("SpecMom250-300Mev");
SigmaPlotSpec7->SetTitle("SpecMom300-350Mev");
SigmaPlotSpec8->SetTitle("SpecMom350-400Mev");





//1=black 2=red 3 = green 4=blue 5 =yellow 6 = pink 7=cyan
//used black red cyan pink new
SigmaPlotUnBin->SetMarkerColor(4);//(blue)
SigmaPlotLess->SetMarkerColor(5);//(yellow)
SigmaPlotGreater->SetMarkerColor(4);//(blue)
SigmaPlotTiming->SetMarkerColor(7);//light blue
SigmaPlotStrict->SetMarkerColor(4);// blue
SigmaPlotStrictBG->SetMarkerColor(3);// green
SigmaPlotNonStrictBG->SetMarkerColor(5);//yellow
SigmaPlotStrictDar->SetMarkerColor(6);// pink
SigmaPlotCuts->SetMarkerColor(5);// blue
SigmaPlotCutsNon->SetMarkerColor(7);// light blue
SigmaPlotInv->SetMarkerColor(6);//pink


SigmaPlotUnBin->SetFillStyle(0);
SigmaPlotUnBin->SetFillColor(0);
SigmaPlotLess->SetFillStyle(0);
SigmaPlotLess->SetFillColor(0);
SigmaPlotGreater->SetFillStyle(0);
SigmaPlotGreater->SetFillColor(0);
SigmaPlotTiming->SetFillStyle(0);//light blue
SigmaPlotTiming->SetFillColor(0);//light blue
SigmaPlotStrict->SetFillStyle(0);// blue
SigmaPlotStrict->SetFillColor(0);// blue
SigmaPlotStrictBG->SetFillStyle(0);// green
SigmaPlotStrictBG->SetFillColor(0);// green
SigmaPlotNonStrictBG->SetFillStyle(0);//yellow
SigmaPlotNonStrictBG->SetFillColor(0);//yellow
SigmaPlotStrictDar->SetFillStyle(0);// pink
SigmaPlotStrictDar->SetFillColor(0);// pink
SigmaPlotCuts->SetFillStyle(0);// blue
SigmaPlotCuts->SetFillColor(0);// blue
SigmaPlotCutsNon->SetFillStyle(0);// light blue
SigmaPlotCutsNon->SetFillColor(0);// light blue
SigmaPlotInv->SetFillStyle(0);//pink
SigmaPlotInv->SetFillColor(0);//pink
SigmaPlot->SetFillStyle(0);//pink
SigmaPlot->SetFillColor(0);//pink
SigmaPlotSimon->SetFillStyle(0);//pink
SigmaPlotSimon->SetFillColor(0);//pink
DivisionPlotSimon->SetFillStyle(0);//pink
DivisionPlotSimon->SetFillColor(0);//pink


SigmaPlotUnBin->SetTitle("UnBinnedFit");
SigmaPlotLess->SetTitle("Less");
SigmaPlotGreater->SetTitle("Greater");
SigmaPlotTiming->SetTitle("Timing");//light blue
SigmaPlotStrict->SetTitle("Strict");// blue
SigmaPlotStrictBG->SetTitle("StrictBG");// green
SigmaPlotNonStrictBG->SetTitle("NonStrictBG");//yellow
//SigmaPlotStrictDar->SetTitle("StrictDar");// pink
SigmaPlotStrictDar->SetTitle("StrictCuts");// pink
SigmaPlotCuts->SetTitle("Cuts");// blue
SigmaPlotCutsNon->SetTitle("CutsNon");// light blue
SigmaPlotInv->SetTitle("Inv");//pink
SigmaPlot->SetTitle("CoplanFits");//pink
SigmaPlotSimon->SetTitle("Simon");//pink
DivisionPlotSimon->SetTitle("Division");//pink



TMultiGraph* mg = new TMultiGraph();
mg->SetMaximum(1);
mg->SetMinimum(0);
mg->Add(SigmaPlot);
mg->Add(SigmaPlotUnBin);
//mg->Add(SigmaPlotLess);
//mg->Add(SigmaPlotGreater);
//mg->Add(SigmaPlotTiming);
//mg->Add(SigmaPlotStrict);
mg->Add(SigmaPlotStrictDar);
//////mg->Add(SigmaPlotStrictBG);
//////mg->Add(SigmaPlotNonStrictBG);
//mg->Add(SigmaPlotCuts);
//mg->Add(SigmaPlotCutsNon);
//mg->Add(SigmaPlotInv);
//mg->Add(SigmaPlotSimon);
//mg->Add(DivisionPlotSimon);

//SpecMom add to multigraph
//mg->Add(SigmaPlotSpec);
//mg->Add(SigmaPlotSpec2);
//mg->Add(SigmaPlotSpec3);
//mg->Add(SigmaPlotSpec4);
//mg->Add(SigmaPlotSpec5);
//mg->Add(SigmaPlotSpec6);
//mg->Add(SigmaPlotSpec7);
//mg->Add(SigmaPlotSpec8);





TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;


//  SigmaPlotSimon->SetTitle(hTitle+"Simon");
//  SigmaPlotSimon->SetName(hName+"Simon");

//  DivisionPlotSimon->SetTitle(hTitle+"Divi");
//  DivisionPlotSimon->SetName(hName+"Divi");

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
//TLegend* leg = c3->BuildLegend();
TLegend* leg = gPad->BuildLegend();
leg->SetFillStyle(0);

//mg->Write();
leg->Write();//Sort the writing of the legend later
DivisionPlotSimon->Write();
//c3->Write();

}
Canvas1->Write();
outfile->Close();
} //closing main function
	

