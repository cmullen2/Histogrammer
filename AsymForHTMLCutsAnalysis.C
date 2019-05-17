#include <stdlib.h>




void MakeSigmaGraph(vector<Double_t> sigma, vector<Double_t> error, vector<Double_t> plotVar, vector<Double_t> plotVarError, Int_t numBins, TString hTitle, TString hName );

void AsymForHTMLCutsAnalysis() {
		
  TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0StrictCutsDariaPhiRandBGSub.root");
  TFile *outfile =new TFile("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/CheckFits/AsymsBGSUBBEDPPi0StrictCutsDariaPhiRandBGSub.root","recreate");
  string dirs[1] = {"SignalTiming"};
  vector<TString> histNames;
  vector<TString> phihistNames;
  vector<Double_t> VecSigma;
  vector<Double_t> VecSigmaErr;
  vector<Double_t> VecCosth;
  vector<Double_t> VecCosthErr;
  Int_t BinsCounter = 0;
	
					
    TDirectory *weightsDir = infile->GetDirectory(dirs[0].c_str());	//WeightsDir is top lev folder
    TIter	nextTbinDir(weightsDir->GetListOfKeys());
    TKey 	*tbinKey;
			
    while ((tbinKey=(TKey*)nextTbinDir())) {
			
      TDirectory *tbinDir = weightsDir->GetDirectory(tbinKey->GetName()); //tbinDir is my W var.
      TIter	nextEbinDir(tbinDir->GetListOfKeys());
      TKey 	*ebinKey;
				
      while ((ebinKey=(TKey*)nextEbinDir())) {
					
	TDirectory *ebinDir = tbinDir->GetDirectory(ebinKey->GetName()); //ebinDir is my costh
	TIter nextPolbinDir(ebinDir->GetListOfKeys());
	TKey  *polbinKey;

	while ((polbinKey=(TKey*)nextPolbinDir())){   //Looping round my polarisation states - +

	  TDirectory *polbinDir = ebinDir->GetDirectory(polbinKey->GetName());
	  TIter	nextHist(polbinDir->GetListOfKeys());
	  TKey	*histKey;
					
	  int histNum = 0;
	  while ((histKey=(TKey*)nextHist())) {
									
	    histNum++;
	    TString IsPhi = (TString)histKey->GetName();
	    TString IsPolPos = (TString)polbinDir->GetName();
            TString phiHist = "Phi_"+ dirs[0]+ "_" + (TString)tbinDir->GetName()+ (TString)ebinDir->GetName()  + (TString)polbinDir->GetName() ;




	    if(IsPhi==phiHist && IsPolPos=="PolStateD-0.50_"){

 TString PolPosName ="/" + dirs[0]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD0.50_/Phi_" +dirs[0]+ "_" + (TString)tbinDir->GetName() +  (TString)ebinDir->GetName()  + "PolStateD0.50_"  ;
              TString PolarPosName ="/" + dirs[0]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD0.50_/Polarisation_"+dirs[0]+ "_" + (TString)tbinDir->GetName()  +  (TString)ebinDir->GetName()  + "PolStateD0.50_"  ;
              TString PolarNegName ="/" + dirs[0]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD-0.50_/Polarisation_"+dirs[0]+ "_" + (TString)tbinDir->GetName()  +  (TString)ebinDir->GetName()  + "PolStateD-0.50_" ;
	      TH1F* PolarPos = (TH1F*)infile->Get(PolarPosName);
	      TH1F* PolarNeg = (TH1F*)infile->Get(PolarNegName);
	      TH1F* PolPos = (TH1F*)infile->Get(PolPosName);
	      TH1F* hist = (TH1F*) histKey->ReadObj();
	      //Give Asym a proper name and heading
	      TH1* Asym = PolPos->GetAsymmetry(hist);
	      TF1* fit=new TF1("cos2phi","[0]+[1]*cos(TMath::DegToRad()*(2*x+[2]))",-180,180);
	      fit->SetParLimits(2,87.53,93.09);
	      Asym->Fit("cos2phi");
	      //Asym->Draw(); 
	      Double_t MeanPolPos =  PolarPos->GetMean();
	      Double_t MeanPolNeg =  PolarNeg->GetMean();
	      Double_t AvePol = (MeanPolPos + MeanPolNeg)/2;
	      Double_t Par1 = fit->GetParameter(1) ;
	      Double_t Err1 =fit->GetParError(1) ;
	 	if(AvePol==0)AvePol=0.0000000001;
	      Double_t Sigma = Par1/AvePol;  //Need a histo for each W var. or store in an array and use a separate function to plot the sigma plots so that I can change the binning without rerunning selector.
	      Err1 = Sigma* (Err1/Par1) ;
	      BinsCounter = BinsCounter+1;
	      string thetabin = (string)ebinDir->GetName() ;
	      //cout << thetabin << endl;
	      Double_t thetalen = thetabin.size();
	      string thetabin3 = thetabin.substr(5,thetalen -1 );
	      //cout << thetabin3 << endl;
	      Double_t CosthBin = stod(thetabin3); //Can I cast straight to double here?
	      cout << dirs[0]  << CosthBin << " Costh " <<"Sigma=Par1/AvePol  " << Sigma << "=" << Par1 << "/"<< AvePol  <<endl;
	      VecSigma.push_back(Sigma);
	      VecSigmaErr.push_back(Err1);
	      VecCosth.push_back(CosthBin);
	      VecCosthErr.push_back(0.1);
	      Asym->Write();
	  //    hist->Write();
	  //    PolPos->Write();
//	      PolarPos->Write();
//	      PolarNeg->Write();
	    } //Closing if 
	  }  //Closing while hist key		
	}   //Closing while nextPolbin
      }    //Closing while nextEbindir costh
	TString Wbin = (TString)tbinDir->GetName();
	TString Wname = dirs[0] +  (TString)tbinDir->GetName();
	MakeSigmaGraph(VecSigma, VecSigmaErr, VecCosth, VecCosthErr, BinsCounter, Wbin, Wname); //Errors both wrong, costh is just the bin size might need changed. Sigma is the fit param error doesn't account for the division
	VecSigmaErr.clear();
	VecSigma.clear();
	VecCosth.clear();
	VecCosthErr.clear();
	BinsCounter=0;
    }     //Closing while nextTbindir W
  outfile->Close();
} //closing main function
	

void MakeSigmaGraph(vector<Double_t> sigma, vector<Double_t> error, vector<Double_t> plotVar, vector<Double_t> plotVarError, Int_t numBins, TString hTitle,TString hName ){


  TGraph* SigmaPlot = new TGraphErrors(numBins,&(plotVar[0]),&(sigma[0]),&(plotVarError[0]),&(error[0])); 
SigmaPlot->Draw("AP");
SigmaPlot->SetTitle(hTitle);
SigmaPlot->SetName(hName);
SigmaPlot->GetYaxis()->SetTitle("#Sigma");
SigmaPlot->GetXaxis()->SetTitle("Cos#theta_{CM} ");
SigmaPlot->GetXaxis()->CenterTitle();
//SigmaPlot->Write();

}



