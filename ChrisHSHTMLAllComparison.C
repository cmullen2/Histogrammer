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
  cout << " Getting Fit Result  "<< FitName<< "for fit of " << FitVariable << endl;
  gSystem->Exec("mkdir -p /home/chris/public_html/Meetings/outhtmlComparisonFits/Proton/AllCompared/"); 



  ofstream outHtml;
  TString outDir="/home/chris/public_html/Meetings/outhtmlComparisonFits/Proton/AllCompared/";
//  TString outDir="/home/chris/public_html/Meetings/outhtmlComparisonFits/Proton/"+FitType+FitName+FitVariable +"/";
  outHtml.open(outDir+"summary.html");
  TCanvas *can = new TCanvas("can","can",800,600);
  gStyle->SetOptFit();

  outHtml << "<HTML>" << endl;
  outHtml << "<head>" << endl;
  outHtml << "<style>" << endl;
  outHtml << "body {" << endl;
  outHtml << "    background-color: white;" << endl;
  outHtml << "}" << endl;
  outHtml << "" << endl;
  outHtml << "h1 {" << endl;
  outHtml << "    color: black;" << endl;
  outHtml << "    margin-left: 40px;" << endl;
  outHtml << "    background-color: lightgrey;" << endl;
  outHtml << "}" << endl;
  outHtml << "td {" << endl;
  outHtml << "    border: 1px solid black;" << endl;
  outHtml << "    text-align: center;" << endl;
  outHtml << "}" << endl;
  outHtml << "</style>" << endl;
  outHtml << "</head> " << endl;
  outHtml << "<body>" << endl;
  outHtml << "<TABLE>" << endl;


  Int_t histcounter=0;
  Int_t FitTypeCounter=0;

  
  for(Int_t i=0;i<DataBins->GetN();i++){	
  //for(Int_t i=22;i<23;i++){	
    //loop through the bins and get the workspace files for fitting
    TString JobName=DataBins->GetBinName(i);
    TString JobName1=DataBins->GetBinName(i);
    TString JobName2=DataBins->GetBinName(i);
    TString JobName3=DataBins->GetBinName(i);
    TString JobName4=DataBins->GetBinName(i);
    cout<<"Getting Result from JobName "<<JobName<< endl;
    gSystem->Setenv("JOBNAME",JobName);
    cout << "First " <<gPad <<endl;
 
//    if(histcounter%5==0){//Make an array to store four header names? Can then just use array[0] etc It will not work on the first iteration! Could just use DataBins GetBinName(i,i+1,i+1,i+3)
	outHtml << "<TR>";   //Need to add condition here to set up 4 headers for the next four fits  
	outHtml << "<TD><h1>"+JobName+"</h1>";
	outHtml << "<TD><h1>"+JobName +"</h1>";
	outHtml << "<TD><h1>"+JobName+"</h1>";
	outHtml << "<TD><h1>"+JobName+"</h1>";
	outHtml << "<TD><h1>"+JobName+"</h1>";

	outHtml << "<TR>";   //Need to add condition here to set up 4 headers for the next four fits  
//}
//    histcounter++;

TString imFileNamePos;
TString imFileNameNeg;
TString imFileNameUnBin;
TString imFileNameCuts;
TString imFileNameCoplan;


//if(FitTypeCounter==0){ //Pos Coplan Fit
 imFileNamePos="../Pos/CoplanarityPolyBG/Coplanarity/"+JobName+FitVariable+"1.gif" ;
//} 

//if(FitTypeCounter==1){ //Neg Coplan Fit
 TString JobNameNeg=JobName1.ReplaceAll("PolStateD","PolStateD-"); 
 imFileNameNeg="../Neg/CoplanarityPolyBG/Coplanarity/"+JobNameNeg+FitVariable+"1.gif" ;
//}

//if(FitTypeCounter==2){ // Unbinned Asym
 TString JobNameIntermediate = JobName2.ReplaceAll("_PolStateD0.50_","_");
 TString JobNameUnBin = JobNameIntermediate.ReplaceAll("InvMass140.00_","InvMass140.00_Phi0.00_");
 imFileNameUnBin="../ned/UnBinnedPhiOffsetParamFixedSaveAsym/AsymCan/"+JobNameUnBin+"AsymCan1.gif" ;
//}

//if(FitTypeCounter==3){ //Cuts Based Asym
 TString JobNameTemp=JobName3.ReplaceAll("TopoMine0.50_GammaAveTagDiffTime-30.00_","Asymmetry_Phi_SignalTiming_");
 TString JobNameTemp2=JobNameTemp.ReplaceAll("_DCorrect0.49_AnyErrs0.00_","_");
 TString JobNameTemp3=JobNameTemp2.ReplaceAll("Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","-Phi_SignalTiming");

 TString BinName= JobName3.ReplaceAll("Asymmetry_Phi_SignalTiming_","_");
 TString BinName2= BinName.ReplaceAll("_DCorrect0.49_AnyErrs0.00_PolStateD0.50_Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","_"); 
 TString JobNameCuts=JobNameTemp3+ BinName2 +"PolStateD-0.50_";
 imFileNameCuts="../CutsAnalysisAsyms/"+JobNameCuts +".gif" ;
//}

//if(FitTypeCounter==4){//Coplan Fits Asym
 TString JobNameCop =JobName4.ReplaceAll("TopoMine0.50_GammaAveTagDiffTime-30.00_","Asymmetry_Phi_Sig_") ;
 TString JobNameCop2 =JobNameCop.ReplaceAll("_DCorrect0.49_AnyErrs0.00_","_") ;
 TString JobNameCop3 =JobNameCop2.ReplaceAll("Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","-Phi_Sig") ;

 TString BinNameC= JobName4.ReplaceAll("Asymmetry_Phi_Sig_","_");
 TString BinNameC2= BinNameC.ReplaceAll("_DCorrect0.49_AnyErrs0.00_PolStateD0.50_Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_","_"); 
 TString JobNameCoplan= JobNameCop3 + BinNameC2 + "PolStateD-0.50_";
 imFileNameCoplan="../CoplanFitsAsyms/"+ JobNameCoplan+".gif" ;
//}


//if(FitTypeCounter<4){
//FitTypeCounter = FitTypeCounter+1;
//}
//else{
//FitTypeCounter=0;
//}



    outHtml << "<td><image src=\""+imFileNamePos+"\" width=\"80%\"></image>" << endl;
    outHtml << "<td><image src=\""+imFileNameNeg+"\" width=\"80%\"></image>" << endl;
    outHtml << "<td><image src=\""+imFileNameUnBin+"\" width=\"80%\"></image>" << endl;
    outHtml << "<td><image src=\""+imFileNameCuts+"\" width=\"80%\"></image>" << endl;
    outHtml << "<td><image src=\""+imFileNameCoplan+"\" width=\"80%\"></image>" << endl;


//    outHtml << "<TR>";   //Need to add condition here to set up 4 headers for the next four fits  


  }

}
 
