#include <stdlib.h>
#include <TString.h>

void GetCorrectionFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecEg ,vector<Double_t> &VecCosth,vector<Double_t> &VecCorrFac , vector<Double_t> &VecCorrFacErr ,TString InFileName );
Double_t ConvertToCME(Double_t taggE);

void PlotCorrectionVEg() {
		
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/ProtonCorrectionFactorVEgammaFromOnlyCutsBased.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/ProtonCorrectionFactorVEgamma.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/ProtonCorrectionFactorVEgammaFromUnBin.root","recreate");
//  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/ProtonCorrectionFactorVEgammaFromUnBinWeightedMean.root","recreate");
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/DelMEV2.root","recreate");
  //Proton SAID Correction Factor
  vector<Double_t> VecAllChrisSigmaPSCF;
  vector<Double_t> VecAllChrisEgPSCF;
  vector<Double_t> VecAllChrisCosthPSCF;
  vector<Double_t> VecAllChrisCorrectionFactorPSCF;
  vector<Double_t> VecAllChrisCorrectionFactorPSCFErr;
////////////////////////////////////////////////////////////////////////////////////////////////
  //PSCF Proton SAID Correction Factor
  TString InFilePSCF = "PCSAIDProtonCorrectionFactorUnBin.txt";
  GetCorrectionFromFile( VecAllChrisSigmaPSCF, VecAllChrisEgPSCF, VecAllChrisCosthPSCF, VecAllChrisCorrectionFactorPSCF, VecAllChrisCorrectionFactorPSCFErr,InFilePSCF );

//////////////////////////////////////////////////////////////////////////////////////////////////
  Double_t ArrCorrFactor[16];
  Double_t ArrEgPSCF[16];
  Double_t ArrEgPSCFErrs[16];
  Double_t ArrCorrFactorErrs[16];
///////////////////////////////////////////////////////////////////////////////////////////////////
  for(Int_t i=0;i<16;i++){//Number of eg bins//Deprecated*Number of folders(rand,sig,cut1) 41*3
	ArrCorrFactor[i]= VecAllChrisCorrectionFactorPSCF[5 +i*20];
	ArrEgPSCF[i] = VecAllChrisEgPSCF[5+i*20];

	ArrCorrFactorErrs[i]=VecAllChrisCorrectionFactorPSCFErr[5+i*20];
	ArrEgPSCFErrs[i] = 10;
}   

    auto c3 = new TCanvas("c3","c3");
    //Declare Graphs
    TGraph* SigmaPlotPSCF=new TGraphErrors(16,ArrEgPSCF,ArrCorrFactor,ArrEgPSCFErrs,ArrCorrFactorErrs);
    SigmaPlotPSCF->SetMarkerStyle(22);//
    SigmaPlotPSCF->SetMarkerColor(9);//purple  
    //Set Fill Style/Color
    SigmaPlotPSCF->SetFillStyle(0);
    SigmaPlotPSCF->SetFillColor(0);
    //Set Title
    SigmaPlotPSCF->SetTitle("ProtonSAIDCorrectionUnBinWM");
    //Create Multigraph and add plots to it 
    TMultiGraph* mg = new TMultiGraph();
    mg->Add(SigmaPlotPSCF);
    mg->Draw("AP");
    TLegend* leg = c3->BuildLegend();
    leg->SetFillStyle(0);
    mg->Write();
    c3->Write();
    outfile->Close();
} //closing main function



Double_t ConvertToCME(Double_t taggE){

  return TMath::Sqrt((938.27+taggE)*(938.27+taggE)-taggE*taggE);

}

void GetCorrectionFromFile(vector<Double_t>  &VecSigma, vector<Double_t> &VecEg ,vector<Double_t> &VecCosth , vector<Double_t> &VecCorrFac, vector<Double_t> &VecCorrFacErr,TString InFileName ){

  Double_t Sigma;
  Double_t Eg;
  Double_t Costh;
  Double_t CorrectionFactor;
  Double_t CorrectionFactorError;

  std::ifstream inputFileSpec(InFileName);
  std::string lineSpec;
  if (inputFileSpec.is_open()){
    while(getline(inputFileSpec, lineSpec) ){
      stringstream(lineSpec)>>Sigma >>Eg >> Costh >>CorrectionFactor>>CorrectionFactorError;
      VecSigma.push_back(Sigma);
      VecEg.push_back(Eg);
      VecCosth.push_back(Costh);
      VecCorrFac.push_back(CorrectionFactor);
      VecCorrFacErr.push_back(CorrectionFactorError);
	
    }
  }

}
