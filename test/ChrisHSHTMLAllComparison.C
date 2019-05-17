//run with
// setenv FILEDIR $PWD/outBins/
// root --THSBins ScriptName.C
void ChrisHSHTMLAllComparison(){
  //Open file containing binning information in a THSBins
  //This also contains entry lists for each event analysed
  TString fileDir=gSystem->Getenv("FILEDIR");
  TFile* file=new TFile(fileDir+"/DataEntries.root");
  THSBins* DataBins=(THSBins*)file->Get("HSDataBins");

  TString FitName = "CoplanarityPolyBG/";
  TString FitVariable="Coplanarity";


  Int_t Len = fileDir.Length();
  TString FitType=fileDir(Len-4,Len);

  gSystem->Setenv("FITNAME",FitName);
  gSystem->Setenv("FITVAR",FitVariable);
  gSystem->Setenv("FITTYPE",FitType);


Int_t FitTypeCounter=0;
  Int_t histcounter=0;
  
  for(Int_t i=0;i<DataBins->GetN();i++){	
    TString JobName=DataBins->GetBinName(i);
    gSystem->Setenv("JOBNAME",JobName);
    histcounter++;

TString imFileName;

if(FitTypeCounter==0){ //Pos Coplan Fit
 imFileName="../Pos/CoplanarityPolyBG/Coplanarity/"+JobName+FitVariable+"1.gif" ;
} 

if(FitTypeCounter==1){ //Neg Coplan Fit
 TString JobNameNeg=JobName.ReplaceAll("PolStateD","PolStateD-"); 
 imFileName="../Neg/CoplanarityPolyBG/Coplanarity/"+JobNameNeg+FitVariable+"1.gif" ;
}

if(FitTypeCounter==2){ // Unbinned Asym
 TString JobNameIntermediate = JobName.ReplaceAll("_PolStateD0.50_","_");
 TString JobNameUnBin = JobNameIntermediate.ReplaceAll("InvMass140.00_","InvMass140.00_Phi0.00_");
 imFileName="../ned/UnBinnedPhiOffsetParamFixedSaveAsym/AsymCan/"+JobNameUnBin+"AsymCan1.gif" ;
}

if(FitTypeCounter==3){ //Cuts Based Asym
 TString JobNameTemp=JobName.ReplaceAll("TopoMine0.50_GammaAveTagDiffTime-30.00_","Asymmetry_Phi_SignalTiming_");
 TString JobNameTemp2=JobNameTemp.ReplaceAll("_DCorrect0.49_AnyErrs0.00_","_");
 TString JobNameTemp3=JobNameTemp2.ReplaceAll("Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","-Phi_SignalTiming");

 TString BinName= JobName.ReplaceAll("Asymmetry_Phi_SignalTiming_","_");
 TString BinName2= BinName.ReplaceAll("_DCorrect0.49_AnyErrs0.00_PolStateD0.50_Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","_"); 
 TString JobNameCuts=JobNameTemp3+ BinName2 +"PolStateD-0.50_";
 imFileName="../CutsAnalysisAsyms/"+JobNameCuts +".gif" ;
}

if(FitTypeCounter==4){//Coplan Fits Asym
 TString JobNameCop =JobName.ReplaceAll("TopoMine0.50_GammaAveTagDiffTime-30.00_","Asymmetry_Phi_Sig_") ;
 TString JobNameCop2 =JobNameCop.ReplaceAll("_DCorrect0.49_AnyErrs0.00_","_") ;
 TString JobNameCop3 =JobNameCop2.ReplaceAll("Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","-Phi_Sig") ;

 TString BinNameC= JobName.ReplaceAll("Asymmetry_Phi_Sig_","_");
 TString BinNameC2= BinNameC.ReplaceAll("_DCorrect0.49_AnyErrs0.00_PolStateD0.50_Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","_"); 
 TString JobNameCoplan= JobNameCop3 + BinNameC2 + "PolStateD-0.50_";
 imFileName="../CoplanFitsAsyms/"+ JobNameCoplan+".gif" ;
}


  }

}
 
