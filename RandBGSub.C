#include <stdlib.h>


//TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/PPi0StrictCutsDariaPhiRandBGSub.root");
//TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/PPi0NonStrictCutsDariaPhiRandBGSub.root");
//TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/PPi0CutResultsSimulationCutsApr2019TimingExtended40.root");
TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/PPi0CutResultsMay2019CoplanBinningSystematicsV2.root");

void RandBGSub() { 
 // TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0StrictCutsDariaPhiRandBGSub.root","recreate");	
//  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0NonStrictCutsDariaPhiRandBGSub.root","recreate");	
//  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/BGSUBBEDPPi0PPi0CutResultsSimulationCutsApr2019TimingExtended40.root","recreate");	
//  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/BGSUBBEDPPi0CutResultsMay2019CoplanBinningSystematicsV2CoplanN10To10.root","recreate");	
//  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/BGSUBBEDPPi0CutResultsMay2019CoplanBinningSystematicsV2CoplanN30ToN10.root","recreate");	
//  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/BGSUBBEDPPi0CutResultsMay2019CoplanBinningSystematicsV2Coplan10To30.root","recreate");	
  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/BGSUBBEDPPi0CutResultsMay2019CoplanBinningSystematicsV2CoplanN30ToN10And10To30.root","recreate");	

//  string dirs[5] = {"Random","TimeCoinc", "Cut1","SignalTiming","BackgroundTiming"};
//  string dirs[5] = {"Random","TimeCoinc", "Cut1","SignalTimingCoplanN10To10","BackgroundTimingCoplanN10To10"};
//  string dirs[5] = {"Random","TimeCoinc", "Cut1","SignalTimingCoplanN30ToN10","BackgroundTimingCoplanN30ToN10"};
//  string dirs[5] = {"Random","TimeCoinc", "Cut1","SignalTimingCoplan10To30","BackgroundTimingCoplan10To30"};
  string dirs[5] = {"Random","TimeCoinc", "Cut1","SignalTimingCoplanN30ToN10And10To30","BackgroundTimingCoplanN30ToN10And10To30"};
				
  TDirectory *weightsDir = infile->GetDirectory(dirs[3].c_str());	//WeightsDir is top lev folder
  TIter	nextTbinDir(weightsDir->GetListOfKeys());
  TKey 	*tbinKey;
  TDirectory *outWeightsDir = ofile->mkdir(dirs[3].c_str());

  while ((tbinKey=(TKey*)nextTbinDir())) {
    TDirectory *tbinDir = weightsDir->GetDirectory(tbinKey->GetName()); //tbinDir is my W var.
    TIter	nextEbinDir(tbinDir->GetListOfKeys());
    TKey 	*ebinKey;
    TDirectory *outTBinDir = outWeightsDir->mkdir(tbinKey->GetName());

    while ((ebinKey=(TKey*)nextEbinDir())) {
      TDirectory *ebinDir = tbinDir->GetDirectory(ebinKey->GetName()); //ebinDir is my costh
      TIter nextPolbinDir(ebinDir->GetListOfKeys());
      TKey  *polbinKey;
      TDirectory *outEBinDir = outTBinDir->mkdir(ebinKey->GetName());

      while ((polbinKey=(TKey*)nextPolbinDir())){   //Looping round my polarisation states - +
	TDirectory *polbinDir = ebinDir->GetDirectory(polbinKey->GetName());
	TIter	nextHist(polbinDir->GetListOfKeys());
	TKey	*histKey;
	TDirectory *outPolBinKey = outEBinDir->mkdir(polbinKey->GetName());
	outPolBinKey->cd();			

	while ((histKey=(TKey*)nextHist())) {
	  //Getting  Signal and bg histo
	  TH1F* hist = (TH1F*) histKey->ReadObj();
	  TString histBgName ="/" + dirs[4] + "/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/" + (TString)polbinDir->GetName() + "/" + (TString)histKey->GetName() ;
   	  TH1F* histBg = (TH1F*)infile->Get(histBgName); 
	  //Adding signal and bg histo based on ratio of two windows
//	  hist->Add(histBg,-1.0);
	  hist->Add(histBg,-0.5);
//	cout<< histKey->GetName() << " =signal  " <<endl; 
//	cout<< histBgName << " =background  " <<endl; 
	  hist->Write();  //Sort out file name and set up directory structure in outfile

	}  //Closing while hist key		
      }   //Closing while nextPolbin
    }    //Closing while nextEbindir costh
  }     //Closing while nextTbindir W
  ofile->Close();
} //closing main function
	

