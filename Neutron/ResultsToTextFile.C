#include <stdlib.h>




void ResultsToTextFile() {
		
//  TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/NPi0ResultCoplan3BG.root");
  TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/NPi0ResultsCoplanFitsNoSpecMomCuts.root");
  //  string dirs[3] = {"BG","Sig", "Cut1"};
  string dirs[3] = {"Random","Sig", "Cut1"};
//  string dirs[3] = {"Sig","ThreeBGs","Cut1"};
  //  string dirs[4] = {"NPipPi0","PPi0Pim","Sig", "Cut1"};
  vector<TString> histNames;
  vector<TString> phihistNames;
  vector<Double_t> VecSigma;
  vector<Double_t> VecSigmaErr;
  vector<Double_t> VecCosth;
  vector<Double_t> VecCosthErr;


  vector<string> VecFolder;
  vector<Double_t>  VecAllEg;		
  vector<Double_t>  VecAllSigma;		
  vector<Double_t>  VecAllCosth;		
  vector<Double_t>  VecAllEgErr;		
  vector<Double_t>  VecAllSigmaErr;		
  vector<Double_t>  VecAllCosthErr;		

  Int_t BinsCounter = 0;



  // all histograms for each bin
  for (int i=0; i<3; i++) {
    //  for (int i=0; i<4; i++) {
					
    TDirectory *weightsDir = infile->GetDirectory(dirs[i].c_str());	//WeightsDir is top lev folder
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

	    if(IsPhi=="Phi" && IsPolPos=="PolStateD-0.50_"){
	      TString PolPosName ="/" + dirs[i]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD0.50_/Phi";
	      TString PolarPosName ="/" + dirs[i]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD0.50_/Polarisation";
	      TString PolarNegName ="/" + dirs[i]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD-0.50_/Polarisation";
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
	      Double_t thetalen = thetabin.size();
	      string thetabin3 = thetabin.substr(5,thetalen -1 );
	      Double_t CosthBin = stod(thetabin3); //Can I cast straight to double here?
	      cout << dirs[i]  << CosthBin << " Costh " <<"Sigma=Par1/AvePol  " << Sigma << "=" << Par1 << "/"<< AvePol  <<endl;
	      VecSigma.push_back(Sigma);
	      VecSigmaErr.push_back(Err1);
	      VecCosth.push_back(CosthBin);
	      VecCosthErr.push_back(0.1);

	      VecAllSigma.push_back(Sigma);		
	      VecAllCosth.push_back(CosthBin);		
	      TString EgbinName = (TString)tbinDir->GetName();
	      string EgbinName2 = (string)EgbinName(10,6);
	      Double_t Egbin = stod(EgbinName2);
	      VecAllEg.push_back(Egbin);		
	      VecFolder.push_back(dirs[i]);

	      VecAllEgErr.push_back(10);		
	      VecAllSigmaErr.push_back(Err1);		
	      VecAllCosthErr.push_back(0.05);		

	    } //Closing if 
	  }  //Closing while hist key		
	}   //Closing while nextPolbin
      }    //Closing while nextEbindir costh
      TString Wbin = (TString)tbinDir->GetName();
      TString Wname = dirs[i] +  (TString)tbinDir->GetName();
      //	Double_t WbinD =(Double_t) Wbin(10,6);
      string WbinString =(string)Wbin(10,6);
      Double_t WbinD =stod(WbinString);
      VecCosth.clear();
      VecCosthErr.clear();
      BinsCounter=0;
    }     //Closing while nextTbindir W
  }  //Closing For loop
  //Can Make the function for drawing tgraph for sigma here and add simons code for adding sigma theory curves too.


std::ofstream textfile;
textfile.open("MyResultsNewCoplanFitsNoSpecMomCut.txt",std::ios_base::app);

for(Int_t ddd=0; ddd<VecAllSigma.size(); ddd++ ){
  textfile <<VecAllSigma[ddd]<<"  "<<VecAllSigmaErr[ddd]<<"  "<< VecAllEg[ddd]<<"  "<<VecAllEgErr[ddd]<<"  "<<VecAllCosth[ddd]<<"  "<<VecAllCosthErr[ddd]<<"  "<<VecFolder[ddd]<<endl;

}


//  outfile->Close();
} //closing main function
	

