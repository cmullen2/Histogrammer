#include <stdlib.h>


//TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/PPi0StrictCutsDariaPhiRandBGSub.root");
TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/PPi0NonStrictCutsDariaPhiRandBGSub.root");

void RandBGSub() { 
 // TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0StrictCutsDariaPhiRandBGSub.root","recreate");	
  TFile* ofile = new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0NonStrictCutsDariaPhiRandBGSub.root","recreate");	

  string dirs[5] = {"Random","TimeCoinc", "Cut1","SignalTiming","BackgroundTiming"};
				
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
	  hist->Add(histBg,-1.0);
//	cout<< histKey->GetName() << " =signal  " <<endl; 
//	cout<< histBgName << " =background  " <<endl; 
	  hist->Write();  //Sort out file name and set up directory structure in outfile

	}  //Closing while hist key		
      }   //Closing while nextPolbin
    }    //Closing while nextEbindir costh
  }     //Closing while nextTbindir W
  ofile->Close();
} //closing main function
	

