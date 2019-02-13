#define THSSelector_vh_cxx

#include "THSSelector_vh.h"
#include <TH2.h>
#include <TStyle.h>

void THSSelector_vh::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   TString option = GetOption();
   fBins=new THSBins("HSBins");
   fBins->AddAxis("BeamEnergy",41,100,920);
   fBins->AddAxis("Costh",20,-1,1);
   fBins->AddAxis("PolStateD",2,-1,1);
   if(!fInput) fInput=new TList();
   fInput->Add(fBins); 
}

void THSSelector_vh::SlaveBegin(TTree * /*tree*/)
{

   TString option = GetOption();  //What does this line do???
   THSOutput::HSSlaveBegin(fInput,fOutput);
    THSHisto::LoadWeights("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/Fitting/Pi0Analysis/MergeWeights/ProtonWeightsSum/OnlyTimingWeights/StrictCutsSpecMom/WeightsBothTotal.root","HSsWeights");
   fOutTree=new TTree("HSParticles","A tree containing reconstructed particles"); 
   THSHisto::InitialiseHisto(fInput);
   THSHisto::LoadCutsForWeights(); //Loop over weights species and make weighted histograms for each
   THSHisto::LoadCut("Cut1");
   THSHisto::LoadHistograms();


}

Bool_t THSSelector_vh::Process(Long64_t entry)
{

   fReader.SetLocalEntry(entry);
   THSOutput::HSProcessStart(entry);
   if(fBins) fCurrBin=fBins->FindBin(*BeamEnergy,*Costh,*PolStateD);
   FillHistograms("Cut1");
   THSHisto::GetWeightEvent(*UID); //get weights for this event, use fgID as works when permutating also
   THSHisto::FillCutsForWeights(); //Fill weighted hists
   THSOutput::HSProcessFill();
   return kTRUE;
}

void THSSelector_vh::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
}

void THSSelector_vh::Terminate()
{
   THSOutput::HSTerminate();
}
 
void THSSelector_vh::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  fOutput->Add(MapHist(new TH1F("MissMass","M_{miss}",100,1850,2300)));
  fOutput->Add(MapHist(new TH1F("Phi","Phi",20,-180,180)));
  fOutput->Add(MapHist(new TH1F("Timing","Timing",100,-80,20)));
  fOutput->Add(MapHist(new TH1F("Coplanarity","Coplanarity",100,-15,15)));
  fOutput->Add(MapHist(new TH1F("InvMass","InvMass_{Pi0}",100,75,200)));
  fOutput->Add(MapHist(new TH1F("SpectatorMomentum","SpectatorMomentum",100,0,1000)));
  fOutput->Add(MapHist(new TH1F("ConeAngle","ConeAngle",100,0,0.4)));
  fOutput->Add(MapHist(new TH1F("Polarisation","Polarisation",100,-1.1,1.1)));
  fOutput->Add(MapHist(new TH1F("W","W",100,950,2300)));
  fOutput->Add(MapHist(new TH1F("Costh","Costh",100,-1,1)));
  fOutput->Add(MapHist(new TH1F("PolState","PolState",10,-2,2)));
  fOutput->Add(MapHist(new TH1F("BeamEnergy","BeamEnergy",50,380,740)));
  fOutput->Add(MapHist(new TH1F("PolErrs","PolErrs",10,-2,2)));
  fOutput->Add(MapHist(new TH1F("WII","WII",100,-300,200)));
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void THSSelector_vh::FillHistograms(TString sCut){
  if(fBins&&fCurrBin==-1) return; //Outwith bin limits so no hists
  fCurrCut=sCut;
if(*InvMass<200 && *InvMass>80){
  if(*PolErrs==0){
	if(*AnyErrs==0){
		if(*TopoMine==1){
			if(*BeamEnergy>400 && *BeamEnergy<720){
				if(*GammaAveTagDiffTime<20 && *GammaAveTagDiffTime>-80){
					if(*Coplanarity<10 && *Coplanarity>-10){
						if(*MissMass<2000 && *MissMass>1850){
							if(*ConeAngle<0.3 ){
								if(*SpecMom<200){

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

//}
}//SpecMom Cut
}//ConeAngleCut
}//MissMassCut
}//CoplanarityCut
}//Timing cut
}//W cut
}//Topo cut
}//AnyErrs cut
}//PolErrs cut
}//InvMass cut
//}//MissMass cut

}
