#include <stdlib.h>



void RandBGSubResultsToTextFileSpecMomBins() {
		
  TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/BGSUBBEDPPi0NonStrictCutsSpecMomBins.root");
  string dirs[1] = {"SignalTiming"};
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

        TDirectory *polbinDir = ebinDir->GetDirectory(polbinKey->GetName()); //ebinDir is my costh
        TIter nextSpecbinDir(polbinDir->GetListOfKeys());
        TKey  *specbinKey;


	while ((specbinKey=(TKey*)nextSpecbinDir())){   //Looping round my specmom bins
	  TDirectory *specbinDir = polbinDir->GetDirectory(specbinKey->GetName());
	  TIter	nextHist(specbinDir->GetListOfKeys());
	  TKey	*histKey;
					
	  int histNum = 0;
	  while ((histKey=(TKey*)nextHist())) {
									
	    histNum++;
	    TString IsPhi = (TString)histKey->GetName();
	    TString IsPolPos = (TString)polbinDir->GetName();
	    TString phiHist = "Phi_"+ dirs[0]+ "_" + (TString)tbinDir->GetName()+ (TString)ebinDir->GetName()  + (TString)polbinDir->GetName() +(TString)specbinDir->GetName() ;

	    cout << IsPhi << "   ISPhi" <<endl;
	    cout << phiHist << "   hPhi"<<endl;

	    if(IsPhi==phiHist && IsPolPos=="PolStateD-0.50_"){
	      TString PolPosName ="/" + dirs[0]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD0.50_/" + (TString)specbinDir->GetName() + "/Phi_" +dirs[0]+ "_" + (TString)tbinDir->GetName() +  (TString)ebinDir->GetName()  + "PolStateD0.50_" + (TString)specbinDir->GetName()  ;
	      TString PolarPosName ="/" + dirs[0]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD0.50_/" + (TString)specbinDir->GetName()+ "/Polarisation_"+dirs[0]+ "_" + (TString)tbinDir->GetName()  +  (TString)ebinDir->GetName()  + "PolStateD0.50_" + (TString)specbinDir->GetName()  ;
	      TString PolarNegName ="/" + dirs[0]+"/" + (TString)tbinDir->GetName()+ "/"  +  (TString)ebinDir->GetName() + "/PolStateD-0.50_/" + (TString)specbinDir->GetName()+   "/Polarisation_"+dirs[0]+ "_" + (TString)tbinDir->GetName()  +  (TString)ebinDir->GetName()  + "PolStateD-0.50_" + (TString)specbinDir->GetName() ;
		cout << PolarPosName << "Pos" << endl;
		cout << PolarNegName << "Neg" << endl;
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
	      cout << dirs[0]  << CosthBin << " Costh " <<"Sigma=Par1/AvePol  " << Sigma << "=" << Par1 << "/"<< AvePol  <<endl;
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
	      VecFolder.push_back(dirs[0]);

	      VecAllEgErr.push_back(10);		
	      VecAllSigmaErr.push_back(Err1);		
	      VecAllCosthErr.push_back(0.05);		

	    } //Closing if 
	  }  //Closing while hist key		
	}  //Closing while specbins key		
      }   //Closing while nextPolbin
    }    //Closing while nextEbindir costh
    TString Wbin = (TString)tbinDir->GetName();
    TString Wname = dirs[0] +  (TString)tbinDir->GetName();
    //	Double_t WbinD =(Double_t) Wbin(10,6);
    string WbinString =(string)Wbin(10,6);
    Double_t WbinD =stod(WbinString);
    VecCosth.clear();
    VecCosthErr.clear();
    BinsCounter=0;
  }     //Closing while nextTbindir W


  std::ofstream textfile;
  textfile.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins0to50Mev.txt",std::ios_base::app);

  std::ofstream textfile2;
  textfile2.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins50to100Mev.txt",std::ios_base::app);

  std::ofstream textfile3;
  textfile3.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins100to150Mev.txt",std::ios_base::app);

  std::ofstream textfile4;
  textfile4.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins150to200Mev.txt",std::ios_base::app);

  std::ofstream textfile5;
  textfile5.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins200to250Mev.txt",std::ios_base::app);

  std::ofstream textfile6;
  textfile6.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins250to300Mev.txt",std::ios_base::app);

  std::ofstream textfile7;
  textfile7.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins300to350Mev.txt",std::ios_base::app);

  std::ofstream textfile8;
  textfile8.open("MyResultsNewBGSUBBEDNonStrictSpecMomBins350to400Mev.txt",std::ios_base::app);


  for(Int_t ddd=0; ddd<VecAllSigma.size(); ddd=ddd+8 ){
    textfile  <<VecAllSigma[ddd]<<"  "<<VecAllSigmaErr[ddd]<<"  "<< VecAllEg[ddd]<<"  "<<VecAllEgErr[ddd]<<"  "<<VecAllCosth[ddd]<<"  "<<VecAllCosthErr[ddd]<<"  "<<VecFolder[ddd]<<endl;
    textfile2 <<VecAllSigma[ddd+1]<<"  "<<VecAllSigmaErr[ddd+1]<<"  "<< VecAllEg[ddd+1]<<"  "<<VecAllEgErr[ddd+1]<<"  "<<VecAllCosth[ddd+1]<<"  "<<VecAllCosthErr[ddd+1]<<"  "<<VecFolder[ddd+1]<<endl;
    textfile3 <<VecAllSigma[ddd+2]<<"  "<<VecAllSigmaErr[ddd+2]<<"  "<< VecAllEg[ddd+2]<<"  "<<VecAllEgErr[ddd+2]<<"  "<<VecAllCosth[ddd+2]<<"  "<<VecAllCosthErr[ddd+2]<<"  "<<VecFolder[ddd+2]<<endl;
    textfile4 <<VecAllSigma[ddd+3]<<"  "<<VecAllSigmaErr[ddd+3]<<"  "<< VecAllEg[ddd+3]<<"  "<<VecAllEgErr[ddd+3]<<"  "<<VecAllCosth[ddd+3]<<"  "<<VecAllCosthErr[ddd+3]<<"  "<<VecFolder[ddd+3]<<endl;
    textfile5 <<VecAllSigma[ddd+4]<<"  "<<VecAllSigmaErr[ddd+4]<<"  "<< VecAllEg[ddd+4]<<"  "<<VecAllEgErr[ddd+4]<<"  "<<VecAllCosth[ddd+4]<<"  "<<VecAllCosthErr[ddd+4]<<"  "<<VecFolder[ddd+4]<<endl;
    textfile6 <<VecAllSigma[ddd+5]<<"  "<<VecAllSigmaErr[ddd+5]<<"  "<< VecAllEg[ddd+5]<<"  "<<VecAllEgErr[ddd+5]<<"  "<<VecAllCosth[ddd+5]<<"  "<<VecAllCosthErr[ddd+5]<<"  "<<VecFolder[ddd+5]<<endl;
    textfile7 <<VecAllSigma[ddd+6]<<"  "<<VecAllSigmaErr[ddd+6]<<"  "<< VecAllEg[ddd+6]<<"  "<<VecAllEgErr[ddd+6]<<"  "<<VecAllCosth[ddd+6]<<"  "<<VecAllCosthErr[ddd+6]<<"  "<<VecFolder[ddd+6]<<endl;
    textfile8 <<VecAllSigma[ddd+7]<<"  "<<VecAllSigmaErr[ddd+7]<<"  "<< VecAllEg[ddd+7]<<"  "<<VecAllEgErr[ddd+7]<<"  "<<VecAllCosth[ddd+7]<<"  "<<VecAllCosthErr[ddd+7]<<"  "<<VecFolder[ddd+7]<<endl;

  }

} //closing main function
	

