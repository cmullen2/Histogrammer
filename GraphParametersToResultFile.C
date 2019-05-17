#include <vector>


 TList * Graphs=new TList();
 

void GraphParametersToResultFile(TString DirName, TString FitName,TString Var){

  gROOT->LoadMacro("$HSANA/THSBins.C+");

  vector<TString> VecAllEg;
  vector<Double_t> VecAllEgErr;
  vector<Double_t> VecAllSigma;
  vector<Double_t> VecAllSigmaErr;
  vector<Double_t> VecAllCosth;
  vector<Double_t> VecAllCosthErr;

  TFile* file=new TFile(DirName+"DataEntries.root");
  THSBins* DataBins=(THSBins*)file->Get("HSDataBins");
  TString BinName=DataBins->GetBinName(0);
  cout<<BinName<<endl;

  Int_t va= DataBins->GetAxisi(Var);
  TString AxisName=Var;

  // TList * Graphs=new TList();
  Graphs->SetName("AllGraphs");
  for(Int_t ib=0;ib<DataBins->GetN();ib++){
    TString redName=DataBins->GetBinName(ib);
    //Strip the variable we are plotting from the name
    //so we can find the relevent graph
    TString axisBin=redName(redName.Index(AxisName),TString(redName(redName.Index(AxisName)+AxisName.Sizeof()-1,redName.Sizeof())).First("_")+AxisName.Sizeof());
    redName.Replace(redName.Index(AxisName),TString(redName(redName.Index(AxisName)+AxisName.Sizeof()-1,redName.Sizeof())).First("_")+AxisName.Sizeof(),"");
    
 
    Int_t iP=DataBins->GetParti(va,axisBin);//index for this bin on this axis
    cout<<redName<<" "<<axisBin<<" "<<iP<<" "<<va<<endl;
    //Open the file with the results
    //TFile* fileR=new TFile(DirName+TString("Plots")+DataBins->GetBinName(ib)+".root");
    TFile* fileR=new TFile(DirName+FitName+TString("Results")+DataBins->GetBinName(ib)+".root");
   if(!fileR->IsOpen()) continue;
    RooFitResult* result=dynamic_cast<RooFitResult*>(gDirectory->Get("HSFitResult"));
    file->cd();
    RooArgList Pars= result->floatParsFinal();
    //Loop over parameters getting values and error for graph
    TGraphErrors* graph=0;
    for(Int_t ipar=0;ipar<Pars.getSize();ipar++){
      //if graph doesn't exist yet create new one
      if(!(graph= dynamic_cast<TGraphErrors*>(Graphs->FindObject(redName+Pars[ipar].GetName())))){
	graph=new TGraphErrors(0);
	graph->SetNameTitle(redName+Pars[ipar].GetName(),redName+Pars[ipar].GetName());
	Graphs->Add(graph);
      }
      Int_t Npoint=graph->GetN();
      cout<<redName<<" "<<DataBins->GetAxis(va).GetBinCenter(iP+1)<<endl;
      graph->SetPoint(Npoint,DataBins->GetAxis(va).GetBinCenter(iP+1),((RooRealVar*)(&Pars[ipar]))->getVal());
      graph->SetPointError(Npoint,DataBins->GetAxis(va).GetBinWidth(iP+1)/2,((RooRealVar*)(&Pars[ipar]))->getError());


	//Get Energy from BinName
/*	
      TString reduceNameStart = redName.ReplaceAll("TopoMine0.50_GammaAveTagDiffTime-30.00_BeamEnergy"," ");
      TString reduceNameEnd = reduceNameStart.ReplaceAll("_DCorrect0.49_AnyErrs0.00_Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_Phi0.00_"," ");	

      VecAllSigma.push_back( ((RooRealVar*)(&Pars[ipar]))->getVal() ); //Includes Sigma but also param B the angle offset and the total yield for bin
      VecAllSigmaErr.push_back(  ((RooRealVar*)(&Pars[ipar]) )->getError()    );
      VecAllCosth.push_back(DataBins->GetAxis(va).GetBinCenter(iP+1)) ;
      VecAllCosthErr.push_back(DataBins->GetAxis(va).GetBinWidth(iP+1)/2) ;
      VecAllEg.push_back(reduceNameEnd); //Need to transform redName by replacing the start and end of it by BeamEnergy
      VecAllEgErr.push_back(10); //Need to transform redName by replacing the start and end of it by BeamEnergy
*/

    }

      TString reduceNameStart = redName.ReplaceAll("TopoMine0.50_GammaAveTagDiffTime-30.00_BeamEnergy"," ");
      TString reduceNameEnd = reduceNameStart.ReplaceAll("_DCorrect0.49_AnyErrs0.00_Coplanarity0.00_MissMass2075.00_ConeAngle0.25_InvMass140.00_Phi0.00_"," ");	

      VecAllSigma.push_back( ((RooRealVar*)(&Pars[0]))->getVal() ); //Includes Sigma but also param B the angle offset and the total yield for bin
      VecAllSigmaErr.push_back(  ((RooRealVar*)(&Pars[0]) )->getError()    );
      VecAllCosth.push_back(DataBins->GetAxis(va).GetBinCenter(iP+1)) ;
      VecAllCosthErr.push_back(DataBins->GetAxis(va).GetBinWidth(iP+1)/2) ;
      VecAllEg.push_back(reduceNameEnd); //Need to transform redName by replacing the start and end of it by BeamEnergy
      VecAllEgErr.push_back(10); //Need to transform redName by replacing the start and end of it by BeamEnergy





    
    delete result;
    fileR->Close();
    delete fileR;
    //TGraphErrors* graph=Graphs->Get(redName);
  }

//  TFile* fileG=new TFile(DirName+ FitName +"ParGraphs"+Var+".root","recreate");
//  Graphs->Write();
//  fileG->Close();
//  delete fileG;


  file->Close();
  delete file;


std::ofstream textfile;
//textfile.open("MyResultsUnBinnedProtonSigma.txt",std::ios_base::app);
//textfile.open("MyResultsUnBinnedProtonSigmaScaleHalfToTwo.txt",std::ios_base::app);
textfile.open("MyResultsUnBinnedProtonSigmaMay17th.txt",std::ios_base::app);

for(Int_t ddd=0; ddd<VecAllSigma.size(); ddd++ ){
  textfile <<VecAllSigma[ddd]<<"  "<<VecAllSigmaErr[ddd]<<"  "<< VecAllEg[ddd]<<"  "<< VecAllEgErr[ddd]<<"  " <<VecAllCosth[ddd] <<"  " << VecAllCosthErr[ddd] <<endl;

}


  return;


}
