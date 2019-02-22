#include <stdlib.h>

// Need to compare unbinned, coplan fits new, strict cuts , non-strict cuts and SAID MAID lines


void PlotComparison() {
		
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/ResultsNPi0UnBinnedVsCoplanFits.root","recreate");
  
  //Coplan Fits results
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

  //StrictCuts Notsurewhatanalysis 
  vector<Double_t> VecAllChrisSigmaStrictDar;
  vector<Double_t> VecAllChrisEgStrictDar;
  vector<Double_t> VecAllChrisCosthStrictDar;
  vector<TString> VecAllChrisTypeStrictDar;
  vector<Double_t> VecAllChrisSigmaErrStrictDar;
  vector<Double_t> VecAllChrisEgErrStrictDar;
  vector<Double_t> VecAllChrisCosthErrStrictDar;

  //NonStrictCuts Notsurewhatanalysis
  vector<Double_t> VecAllChrisSigmaCutsNon;
  vector<Double_t> VecAllChrisEgCutsNon;
  vector<Double_t> VecAllChrisCosthCutsNon;
  vector<TString> VecAllChrisTypeCutsNon;
  vector<Double_t> VecAllChrisSigmaErrCutsNon;
  vector<Double_t> VecAllChrisEgErrCutsNon;
  vector<Double_t> VecAllChrisCosthErrCutsNon;


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

  //StrictCutsDariaPhiAnalysis
  Double_t AllChrisSigmaStrictDar;
  Double_t AllChrisEgStrictDar;
  Double_t AllChrisCosthStrictDar;
  TString AllChrisTypeStrictDar;
  Double_t AllChrisSigmaErrStrictDar;
  Double_t AllChrisEgErrStrictDar;
  Double_t AllChrisCosthErrStrictDar;

  //NonStrictCutsDariaPhiAnalysis
  Double_t AllChrisSigmaCutsNon;
  Double_t AllChrisEgCutsNon;
  Double_t AllChrisCosthCutsNon;
  TString AllChrisTypeCutsNon;
  Double_t AllChrisSigmaErrCutsNon;
  Double_t AllChrisEgErrCutsNon;
  Double_t AllChrisCosthErrCutsNon;

	
  //read in my results from text file
  std::ifstream inputFile("Data/MyResultsNewCoplanFitsNoSpecMomCut.txt");
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
  std::ifstream inputFileUnBin("Data/MyResultsUnBinnedNeutronSigma.txt");
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

  //StrictCuts DariaPhi
  Double_t ArrSigmaStrictDar[20];
  Double_t ArrCosthStrictDar[20];
  Double_t ArrEgStrictDar[20];
  Double_t ArrSigmaErrStrictDar[20];
  Double_t ArrCosthErrStrictDar[20];
  Double_t ArrEgErrStrictDar[20];

  //NonStrictCutsDariaPhiAnalysis
  Double_t ArrSigmaCutsNon[20];
  Double_t ArrCosthCutsNon[20];
  Double_t ArrEgCutsNon[20];
  Double_t ArrSigmaErrCutsNon[20];
  Double_t ArrCosthErrCutsNon[20];
  Double_t ArrEgErrCutsNon[20];


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

      //Strict CutsDariaPhi
      ArrSigmaStrictDar[j] = VecAllChrisSigmaStrictDar[j+i*20];
      ArrCosthStrictDar[j] = VecAllChrisCosthStrictDar[j+i*20];
      ArrEgStrictDar[j] = VecAllChrisEgStrictDar[j+i*20];
      ArrSigmaErrStrictDar[j] = VecAllChrisSigmaErrStrictDar[j+i*20];
      ArrCosthErrStrictDar[j] = VecAllChrisCosthErrStrictDar[j+i*20];
      ArrEgErrStrictDar[j] = VecAllChrisEgErrStrictDar[j+i*20];

      // NonStrictCutsDariaPhi Analysis
      ArrSigmaCutsNon[j] = VecAllChrisSigmaCutsNon[j+i*20];
      ArrCosthCutsNon[j] = VecAllChrisCosthCutsNon[j+i*20];
      ArrEgCutsNon[j] = VecAllChrisEgCutsNon[j+i*20];
      ArrSigmaErrCutsNon[j] = VecAllChrisSigmaErrCutsNon[j+i*20];
      ArrCosthErrCutsNon[j] = VecAllChrisCosthErrCutsNon[j+i*20];
      ArrEgErrCutsNon[j] = VecAllChrisEgErrCutsNon[j+i*20];


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


    TGraph* SigmaPlot=new TGraphErrors(20,ArrCosth,ArrSigma,ArrCosthErr,ArrSigmaErr);
    TGraph* SigmaPlotUnBin=new TGraphErrors(20,ArrCosthUnBin,ArrSigmaUnBin,ArrCosthErrUnBin,ArrSigmaErrUnBin);
    TGraph* SigmaPlotCutsNon=new TGraphErrors(20,ArrCosthCutsNon,ArrSigmaCutsNon,ArrCosthErrCutsNon,ArrSigmaErrCutsNon);
    TGraph* SigmaPlotStrictDar=new TGraphErrors(20,ArrCosthStrictDar,ArrSigmaStrictDar,ArrCosthErrStrictDar,ArrSigmaErrStrictDar);



    SigmaPlot->SetMarkerStyle(22);//Filled triangle(black(default)
    SigmaPlotUnBin->SetMarkerStyle(29);//Filled triangle(black(default)
    SigmaPlotStrictDar->SetMarkerStyle(22);//triangle(blue)
    SigmaPlotCutsNon->SetMarkerStyle(22);//filled triangle

    //1=black 2=red 3 = green 4=blue 5 =yellow 6 = pink 7=cyan
    //used black red cyan pink new
    SigmaPlotUnBin->SetMarkerColor(4);//(blue)
    SigmaPlotStrictDar->SetMarkerColor(6);// pink
    SigmaPlotCutsNon->SetMarkerColor(7);// light blue


    SigmaPlotUnBin->SetFillStyle(0);
    SigmaPlotUnBin->SetFillColor(0);
    SigmaPlotStrictDar->SetFillStyle(0);// pink
    SigmaPlotStrictDar->SetFillColor(0);// pink
    SigmaPlotCutsNon->SetFillStyle(0);// light blue
    SigmaPlotCutsNon->SetFillColor(0);// light blue
    SigmaPlot->SetFillStyle(0);//pink
    SigmaPlot->SetFillColor(0);//pink


    SigmaPlotUnBin->SetTitle("UnBinned");
    SigmaPlotStrictDar->SetTitle("StrictDar");// pink
    SigmaPlotCutsNon->SetTitle("CutsNon");// light blue
    SigmaPlot->SetTitle("CoplanFitsOrig");//pink



    TMultiGraph* mg = new TMultiGraph();
    mg->Add(SigmaPlot);
    mg->Add(SigmaPlotUnBin);
    mg->Add(SigmaPlotStrictDar);
    mg->Add(SigmaPlotCutsNon);

    TString hTitle ="Sigma"+PosTitle; // +VecChrisType[i*20] +(TString) i ;
    TString hName= "Sigma"+PosName; // +VecChrisType[i*20] + (TString)i ;


    SigmaPlot->GetYaxis()->SetTitle("#Sigma");
    SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
    SigmaPlot->GetXaxis()->CenterTitle();

    mg->SetName(hName);
    mg->SetTitle(hTitle+";Cos#theta_{CM};#Sigma");

    mg->Draw("AP");
    TLegend* leg = c3->BuildLegend();
    leg->SetFillStyle(0);

    //mg->Write();
    //leg->Write();//Sort the writing of the legend later
    DivisionPlotSimon->Write();
    c3->Write();

  }
  outfile->Close();
} //closing main function
	

