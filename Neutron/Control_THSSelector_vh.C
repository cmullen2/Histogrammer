{
  //optional Set input file directory, could be done with --hsin or setenv HSIN
 // HSin("/w/work1/home/chris/LatestAnalysisRuns/Data/DataJul17/HaspectOutput/TestMulti/");
//  HSin("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HaspectOutput/Pi0Analysis/AllFilesDev3.0/");
 // HSin("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HaspectOutput/Pi0Analysis/AllFilesDev9.5/");
//  HSin("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HaspectOutput/Pi0Analysis/AllFilesDev10PhiDaria/");
  HSin("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HaspectOutput/Pi0Analysis/V11AllFilesOnlyNeutron/");
  //optional set ouput directory or file.
  //Directory=>1 out file for every in file
  //file=> 1 total output file
  //HSout("/w/work1/home/chris/HistoSelector/InvMassCutBinsFixedCutsSameAsConfigBins2.root");
//  HSout("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/NPi0ResultsStrictCutsSpecMomCutAnalysis.root");
//  HSout("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/NPi0ResultsCoplanFitsNoSpecMomCutsWithCorrectNeutronAsOfApr2019.root");
//  HSout("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr112019//NPi0ResultsCutsAnalysisWithCorrectNeutronAsOfApr2019.root");
  HSout("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestNeutronApr252019/NPi0ResultsCutsAnalysisSimulationCutsWithCorrectNeutronAsOfApr2019TimingExtendedTo40SpecMomCut.root");
  
  //Set up the input chain to be analysed,could remove HSin() if you want
  TChain* tree=new TChain("HSParticles","datachain");
  //tree->Add(HSin()+"Dev19.0Files20PhysicsAll.root");
  tree->Add(HSin()+"Physics_CBTaggTAPS_*");
// tree->Add(HSin()+"Physics_CBTaggTAPS_*.root");

  //if using proof
  //Give proof destination file (env variables can't be read directly
  if(gProof) {gProof->AddInput(new TNamed("HSOUT",HSout().Data()));tree->SetProof();}


  tree->Process("THSSelector_vh.C++");
  
  //Not actually sure if this is needed or not...
  if(gProof)gProof->ClearData(TProof::kUnregistered | TProof::kForceClear);
}
