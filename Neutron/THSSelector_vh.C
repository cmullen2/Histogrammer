#define THSSelector_vh_cxx
// The class definition in THSSelector_vh.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("THSSelector_vh.C")
// root> T->Process("THSSelector_vh.C","some options")
// root> T->Process("THSSelector_vh.C+")
//


#include "THSSelector_vh.h"
#include <TH2.h>
#include <TStyle.h>

void THSSelector_vh::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
//If you want to split histograms into different kinematic bins, include and configure the lines below

   fBins=new THSBins("HSBins");
   fBins->AddAxis("BeamEnergy",24,240,720);
   fBins->AddAxis("Costh",20,-1,1);
   fBins->AddAxis("PolStateD",2,-1,1);
   if(!fInput) fInput=new TList();
   fInput->Add(fBins); 
}

void THSSelector_vh::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();  //What does this line do???
   THSOutput::HSSlaveBegin(fInput,fOutput);
   //Get weights from file
//   THSHisto::LoadWeights("WEIGHTFILE_DIR+NAME","WEIGHTNAME");
    //THSHisto::LoadWeights("/w/work1/home/chris/LatestAnalysisRuns/Data/DataJul17/HaspectOutput/Fitting/WeightsSum/WeightsBothTotal.root","HSsWeights");
   // THSHisto::LoadWeights("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/Fitting/Pi0Analysis/MergeWeights/ProtonWeightsSum/Coplan2BGs/WeightsBothTotal.root","HSsWeights");
//    THSHisto::LoadWeights("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/Fitting/Pi0Analysis/MergeWeights/ProtonWeightsSum/CoplanPoly2ndOrder/MoreBins/WeightsBothTotal.root","HSsWeights");
//    THSHisto::LoadWeights("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/Fitting/Pi0Analysis/MergeWeights/NeutronWeightsSum/Coplan3BG/WeightsBothTotal.root","HSsWeights");
//    THSHisto::LoadWeights("/scratch/chris/NeutronWeights/WeightsBothTotal.root","HSsWeights");
//    THSHisto::LoadWeights("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/Fitting/Pi0Analysis/MergeWeights/NeutronWeightsSum/OnlyTimingWeights/StrictCuts/WeightsBothTotal.root","HSsWeights");
//    THSHisto::LoadWeights("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/Fitting/Pi0Analysis/MergeWeights/NeutronWeightsSum/CoplanPoly2ndOrder/WeightsBothTotal.root","HSsWeights");
//////    THSHisto::LoadWeights("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/Fitting/Pi0Analysis/MergeWeights/NeutronWeightsSum/CoplanPoly2ndOrderV2/WeightsBothTotal.root","HSsWeights");
  //Initialise the ouput tree
   //Only done once. THSOutput::FinishOutput Resets the tree before new files
   //If you want to save additional branches to a new file, do it here
   //If you are creating a HSParticle tree via fStrParticles then do not create a new tree here, just add the extra branches
   fOutTree=new TTree("HSParticles","A tree containing reconstructed particles"); 
  //e.g. Make some objects to make branch with, these should be declared in the .h file 
  //e.g. fp1=new TLorentzVector();
  //e.g.  fOutTree->Branch("p1",&fp1,buff,split);
  //Initialise and configure histogramming
   THSHisto::InitialiseHisto(fInput);
   //Load histograms for each species that has a weight
///////   THSHisto::LoadCutsForWeights(); //Loop over weights species and make weighted histograms for each
   THSHisto::LoadCut("Cut1");
   THSHisto::LoadCut("SignalTiming");
   THSHisto::LoadCut("BackgroundTiming");
 //  THSHisto::LoadCut("SignalWithPol0Cut");
   THSHisto::LoadHistograms();


}

Bool_t THSSelector_vh::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);
   THSOutput::HSProcessStart(entry);
 //below you can give vars corresponding to fBins axis
 //  fWeight=0; //For unweighted histograms
   //if(fBins) fCurrBin=fBins->FindBin(var1,var2,...);//if fBins is defined need to give this meaningful arguments
   if(fBins) fCurrBin=fBins->FindBin(*BeamEnergy,*Costh,*PolStateD);
  // if(fBins) fCurrBin=fBins->FindBin(*PolStateD);
   FillHistograms("Cut1");



  fWeight=1;
  if(*GammaAveTagDiffTime>-5 && *GammaAveTagDiffTime<5)FillHistograms("SignalTiming");
  if( (*GammaAveTagDiffTime>-30 && *GammaAveTagDiffTime<-20) || (*GammaAveTagDiffTime<30 && *GammaAveTagDiffTime>20) )FillHistograms("BackgroundTiming");


//   FillHistograms("SignalWithPol0Cut");
   THSHisto::GetWeightEvent(*UID); //get weights for this event, use fgID as works when permutating also
   THSHisto::FillCutsForWeights(); //Fill weighted hists
   THSOutput::HSProcessFill();
   return kTRUE;
}

void THSSelector_vh::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void THSSelector_vh::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.


	

}
 
void THSSelector_vh::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1","M_{p1}",100,0,2)));
  fOutput->Add(MapHist(new TH1F("MissMass","M_{miss}",100,1850,2300)));
//  fOutput->Add(MapHist(new TH1F("AlsoMissMass","M_{miss}",100,1850,2300)));
  fOutput->Add(MapHist(new TH1F("Phi","Phi",20,-180,180)));
  fOutput->Add(MapHist(new TH1F("Timing","Timing",130,-80,50)));
  fOutput->Add(MapHist(new TH1F("Coplanarity","Coplanarity",100,-50,50)));
  fOutput->Add(MapHist(new TH1F("InvMass","InvMass_{Pi0}",100,75,200)));
  fOutput->Add(MapHist(new TH1F("SpectatorMomentum","SpectatorMomentum",100,0,1000)));
  fOutput->Add(MapHist(new TH1F("ConeAngle","ConeAngle",100,0,0.52)));
  fOutput->Add(MapHist(new TH1F("Polarisation","Polarisation",100,-1.1,1.1)));
  fOutput->Add(MapHist(new TH1F("W","W",100,950,2300)));
  fOutput->Add(MapHist(new TH1F("Costh","Costh",100,-1,1)));
  fOutput->Add(MapHist(new TH1F("PolState","PolState",10,-2,2)));
  fOutput->Add(MapHist(new TH1F("BeamEnergy","BeamEnergy",300,0,1500)));
  fOutput->Add(MapHist(new TH1F("PolErrs","PolErrs",10,-2,2)));
  fOutput->Add(MapHist(new TH1F("WII","WII",100,-300,200)));

  //2D histos
/*  fOutput->Add(MapHist(new TH2F("MissMassVsW","MissMassVsW",200,0,4000,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("PhiVsW","PhiVsW",200,-180,180,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("TimingVsW","TimingVsW",200,-100,0,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("CoplanarityVsW","CoplanarityVsW",200,-180,180,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("InvMassVsW","InvMassVsW",200,0,300,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("SpectatorMomentumVsW","SpectatorMomentumVsW",200,0,2000,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("ConeAngleVsW","ConeAngleVsW",200,0,3.2,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("PolarisationVsW","PolarisationVsW",200,-1.1,1.1,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("CosthVsW","CosthVsW",200,-1,1,200,950,2300)));
  fOutput->Add(MapHist(new TH2F("BeamEnergyVsW","BeamEnergyVsW",200,0,1600,200,950,2300)));

  fOutput->Add(MapHist(new TH2F("CoplanarityVsTiming","CoplanarityVsTiming",200,-180,180,200,-100,0)));
  fOutput->Add(MapHist(new TH2F("CoplanarityVsPhi","CoplanarityVsPhi",200,-180,180,200,-180,180)));
  fOutput->Add(MapHist(new TH2F("TimingVsPhi","TimingVsPhi",200,-100,0,200,-180,180)));
*/

  //end of histogram list
  //ParticleList("NAME"); //Create standard histograms for a THSParticle
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void THSSelector_vh::FillHistograms(TString sCut){
  if(fBins&&fCurrBin==-1) return; //Outwith bin limits so no hists
  fCurrCut=sCut;

//if(*W>1040 &&  *Costh<0.8 ){
//if(*MissMass< && *MissMass>){
//if(*InvMass<200 && *InvMass>80){
if(*InvMass<160 && *InvMass>110){
  if(*PolErrs==0){ //Should I include this or not? NEEd to test on proton channel(only 0 outside of lp fit)
	if(*AnyErrs==0){
		if(*TopoMine==-1){
			if(*BeamEnergy>240 && *BeamEnergy<720){
			//	if(*GammaAveTagDiffTime<20 && *GammaAveTagDiffTime>-80){
				if(*GammaAveTagDiffTime<40 && *GammaAveTagDiffTime>-80){
					//if(*Coplanarity<50 && *Coplanarity>-50){
					if(*Coplanarity<30 && *Coplanarity>-30){
					//	if(*MissMass<2300 && *MissMass>1850){
						if(*MissMass<2100 && *MissMass>1850){
//							if(*ConeAngle<0.5){
							if(*ConeAngle<0.3){
								if(*SpecMom<200){
					//	if(*Pol>0.04){

  //Get histogram from list
  //Fill histogram
  FindHist("MissMass")->Fill(*MissMass,fWeight);//1D
//  FindHist("AlsoMissMass")->Fill(*MissMass,fWeight);//1D
  FindHist("Phi")->Fill(*Phi,fWeight);//1D
  FindHist("Timing")->Fill(*GammaAveTagDiffTime,fWeight);//1D
  FindHist("Coplanarity")->Fill(*Coplanarity,fWeight);//1D
  FindHist("InvMass")->Fill(*InvMass,fWeight);//1D
  FindHist("SpectatorMomentum")->Fill(*SpecMom,fWeight);//1D
  FindHist("ConeAngle")->Fill(*ConeAngle,fWeight);//1D
  FindHist("Polarisation")->Fill(*Pol,fWeight);//1D
  FindHist("W")->Fill(*W,fWeight);//1D
  FindHist("Costh")->Fill(*Costh,fWeight);//1D
  FindHist("PolState")->Fill(*PolState,fWeight);//1D
  FindHist("BeamEnergy")->Fill(*BeamEnergy,fWeight);//1D
  FindHist("PolErrs")->Fill(*PolErrs,fWeight);
  FindHist("WII")->Fill(*WII,fWeight);

  //2D histos(Not allowed due to memory constraints)
/*  ((TH2F*)FindHist("MissMassVsW"))->Fill(*MissMass,*W,fWeight);
  ((TH2F*)FindHist("PhiVsW"))->Fill(*Phi,*W,fWeight);
  ((TH2F*)FindHist("TimingVsW"))->Fill(*GammaAveTagDiffTime,*W,fWeight);
  ((TH2F*)FindHist("CoplanarityVsW"))->Fill(*Coplanarity,*W,fWeight);
  ((TH2F*)FindHist("InvMassVsW"))->Fill(*InvMass,*W,fWeight);
  ((TH2F*)FindHist("SpectatorMomentumVsW"))->Fill(*SpecMom,*W,fWeight);
  ((TH2F*)FindHist("ConeAngleVsW"))->Fill(*ConeAngle,*W,fWeight);
  ((TH2F*)FindHist("PolarisationVsW"))->Fill(*Pol,*W,fWeight);
  ((TH2F*)FindHist("CosthVsW"))->Fill(*Costh,*W,fWeight);
  ((TH2F*)FindHist("BeamEnergyVsW"))->Fill(*BeamEnergy,*W,fWeight);

  ((TH2F*)FindHist("CoplanarityVsTiming"))->Fill(*Coplanarity,*GammaAveTagDiffTime,fWeight);
  ((TH2F*)FindHist("CoplanarityVsPhi"))->Fill(*Coplanarity,*Phi,fWeight);
  ((TH2F*)FindHist("TimingVsPhi"))->Fill(*GammaAveTagDiffTime,*Phi,fWeight);
*/
//}
}//SpecMom
}//MissMass
}//ConeAngle
}//CoplanarityCut
}//Timing cut
}//W cut
}//Topo cut
}//AnyErrs cut
}//PolErrs cut
}//InvMass cut
//}//MissMass cut

//}
  //Find and fill weighted hist below here
  //e.g. FindHist("Mp1")->Fill(fp1->M(),fWeight);
  //e.g. ((TH2F*)FindHist("Mp1VMmiss"))->Fill(fp1->M(),Mmiss,fWeight);
  //Fill THSParticle histogram with values from THSParticle PART
  //FillParticles("NAME",&PART);
}
