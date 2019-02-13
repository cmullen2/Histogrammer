#include <stdlib.h>
#include <numeric>
#include <functional>
#include <iostream>



Double_t ConvertToBeamE(Double_t CME );

vector<Double_t> ConstructBins(Double_t XMin, Double_t XMax, Double_t NBins);


void CompareToSimons() {
  std::ifstream inputFile("SigmaTableExHeads.txt");
  std::string line;

  vector<Double_t> MyCosthBins = ConstructBins(-1,1,20);
  Double_t BinWidth=(MyCosthBins[1] - MyCosthBins[0])/2 ;
//  cout << "Bin Width " <<BinWidth << endl;

  Double_t CMELow;//COMEnergy Low
  Double_t CMEHigh; //COMEnergy high
  Double_t CSTLE; //Costh low erro
  Double_t CSTMid;//Costh
  Double_t CSTHE;//Costh high error
  Double_t Sigma; //Sigma
  Double_t SigmaE; //SigmaError
  vector<Double_t> VCMEL;//COMEnergy Low
  vector<Double_t> VCME; //COMEnergy high
  vector<Double_t> VCosthLErr; //Costh low error
  vector<Double_t> VCosthMid;//Costh 
  vector<Double_t> VCosthHErr;//Costh high error
  vector<Double_t> VSigma; //Sigma
  vector<Double_t> VSigmaE; //SigmaError

  vector<Double_t> VNewCosth;//Costh high error
  vector<Double_t> VNewWeightedSigma; //Sigma
  vector<Double_t> VNewWeightedSigmaError; //Sigma
  vector<Double_t> VNewSigma; //Sigma
  vector<Double_t> VNewSigmaE; //Sigma Error
  vector<Double_t> VNewEgam; 

  Int_t NCosthBins =0;
  vector<Int_t> VNCosthBins; 
  Double_t PrevE = 1302;
  Int_t counter2 =0;
  Int_t counter =0;
  if (inputFile.is_open()){
    while(getline(inputFile, line) ){
	
      stringstream(line)>>CMELow >>CMEHigh >> CSTLE >> CSTMid >> CSTHE >> Sigma >> SigmaE;
      if(CMELow == PrevE){
	NCosthBins = NCosthBins+1;
      }
      else{
	VNCosthBins.push_back(NCosthBins);
	counter2 = counter2 +1;
	NCosthBins=1;	
	PrevE = CMELow;
      }
			
      VCMEL.push_back(CMELow);
      VCME.push_back(CMEHigh);
      VCosthLErr.push_back(CSTLE);
      VCosthMid.push_back(CSTMid);
      VCosthHErr.push_back(CSTHE);
      VSigma.push_back(Sigma);
      VSigmaE.push_back(SigmaE);
      counter= counter +1;
    }
    VNCosthBins.push_back(NCosthBins); //Number of costh bins for each Egamma bin
  }
  Double_t Summation =accumulate(VNCosthBins.begin(),VNCosthBins.end(),0); //Total Number of bins
  Double_t WeightedMeanSigmaSum=0;
  Double_t WeightsSum=0;
  Double_t SigmaSum=0;
  Double_t SigmaErrSum=0;
  Double_t DivCounter=0;
  Double_t TestCounter=0;

  for(Int_t i=0;i<VNCosthBins.size();i++){  //Number of Egamma bins loop 51bins 0-50
    for(Int_t j=0;j<MyCosthBins.size();j++){  //Number of my bins for Costh 20bins 0-19
      Double_t Wait = std::accumulate(VNCosthBins.begin(),VNCosthBins.begin() +i,0) ;
      VNewEgam.push_back(ConvertToBeamE(VCME[std::accumulate(VNCosthBins.begin(),VNCosthBins.begin() +i,0)]));   // + VNCosthBins[i-1] ]));
      VNewCosth.push_back(MyCosthBins[j]);
      WeightedMeanSigmaSum=0;
      WeightsSum=0;
      SigmaSum=0;
      SigmaErrSum=0;
      DivCounter=0;
      for(Int_t k=0;k<VNCosthBins[i];k++){ //Number of Simons costh bins in this egamma bin
	Double_t CurrentSimonCosthBin = std::accumulate(VNCosthBins.begin(),VNCosthBins.begin() +i,0);

	if( VCosthMid[CurrentSimonCosthBin+k]>MyCosthBins[j]-BinWidth &&  VCosthMid[CurrentSimonCosthBin+k]<MyCosthBins[j]+BinWidth    ){
	  DivCounter =DivCounter+1;
	  WeightedMeanSigmaSum = WeightedMeanSigmaSum + VSigma[CurrentSimonCosthBin+k]*1/(VSigmaE[CurrentSimonCosthBin+k]);
	  WeightsSum = WeightsSum + (1/VSigmaE[CurrentSimonCosthBin+k]); 
	  SigmaSum = SigmaSum + VSigma[CurrentSimonCosthBin+k];
	  SigmaErrSum = SigmaErrSum + VSigmaE[CurrentSimonCosthBin+k];
	cout <<"Individual    " << VSigmaE[CurrentSimonCosthBin+k] <<"  Sigma = " << VSigma[CurrentSimonCosthBin+k] << endl;
	}
      }
	cout << "Summation " << 1/sqrt(WeightsSum) << "    " << SigmaErrSum/DivCounter <<"    " <<DivCounter <<"     " <<"   "   <<endl;
      VNewWeightedSigma.push_back(WeightedMeanSigmaSum/WeightsSum);
      VNewWeightedSigmaError.push_back( 1/sqrt(WeightsSum) );
      VNewSigma.push_back(SigmaSum/DivCounter);
      VNewSigmaE.push_back(SigmaErrSum/DivCounter);
    
    }
  }

  for(Int_t i=0; i<1020;i++){
//	cout <<VNewSigmaE[i]<< "     " <<  VNewSigma[i] << "   i="<<i<<"    "<< VNewWeightedSigma[i]<< "    " << VNewWeightedSigmaError[i]<< endl;
    if(TMath::IsNaN(VNewSigma[i])){
      VNewSigma[i]=0;

	//cout <<VNewSigmaE[i] <<"    " << VNewSigma[i] << "   i="<<i<< endl;
    }
    if(TMath::IsNaN(VNewSigmaE[i])){
      VNewSigmaE[i]=0;
    }
  }


  //*************************************************************************************************
  //Now constructing the new energy bins!
  vector<Double_t> MyEgBins = ConstructBins(420,660,12);
  Double_t BinWidthEg=(MyEgBins[1] - MyEgBins[0])/2 ;
  Double_t DivisionCounter =0;
  vector<Double_t> SigmaSummations;	
  vector<Double_t> SigmaSummationsE;	


  for(Int_t aa=0; aa<MyCosthBins.size();aa++){
    SigmaSummations.push_back(0);
    SigmaSummationsE.push_back(0);
  }

  vector<Double_t> VFinalSigma;
  vector<Double_t> VFinalSigmaE;
  vector<Double_t> VFinalEgam;
  vector<Double_t> VFinalCosth;
  vector<Double_t> VFinalEgamE;
  vector<Double_t> VFinalCosthE;

  for(Int_t jj=0;jj<MyEgBins.size();jj++){  //Number of my bins for Eg 11bins 0-10
    //Fill here
    if(SigmaSummations[4]!=0){   //Check if array element 4 isn't zero, this probably means the array has been filled and should be pushed back
      for(Int_t cc=0;cc<MyCosthBins.size(); cc++){
	VFinalSigma.push_back(SigmaSummations[cc]/DivisionCounter);
	VFinalSigmaE.push_back(SigmaSummationsE[cc]/DivisionCounter);
	VFinalEgam.push_back(MyEgBins[jj-1]);
	VFinalCosth.push_back(MyCosthBins[cc]);
	VFinalEgamE.push_back(10);
	VFinalCosthE.push_back(0.05);
	SigmaSummations[cc]=0;
	SigmaSummationsE[cc]=0;
	
      }
	DivisionCounter=0;
    }
    for(Int_t kk=0;kk<VNCosthBins.size();kk++){ //Number of Simons egamma bins in this costh bin	
      if(VNewEgam[kk*MyCosthBins.size()]<(MyEgBins[jj]+BinWidthEg ) && VNewEgam[kk*MyCosthBins.size()]>(MyEgBins[jj]-BinWidthEg ) ){
	DivisionCounter = DivisionCounter +1;
	for(Int_t bb=0; bb<MyCosthBins.size();bb++){

	  SigmaSummations[bb] = SigmaSummations[bb] + VNewSigma[bb+kk*MyCosthBins.size()];
	  SigmaSummationsE[bb] = SigmaSummationsE[bb] + VNewSigmaE[bb+kk*MyCosthBins.size()];
	}
      }
    }
  }

std::ofstream outfile;
outfile.open("TESTNewSimonsResultsMyBins.txt",std::ios_base::app);


for(Int_t dd=0; dd<VFinalSigma.size();dd++){
//cout << "Sigma="<<VFinalSigma[dd] <<"   EGam="<<VFinalEgam[dd] <<"   Costh="<<VFinalCosth[dd]<<endl;
outfile<<VFinalSigma[dd] <<"  "<<VFinalSigmaE[dd] <<"  "<<VFinalEgam[dd]<<"  "<<VFinalEgamE[dd] <<"  "<<VFinalCosth[dd]<< "  "<< VFinalCosthE[dd]<<endl;

}

//Output to text file and load it in my sigma script.
//Should make a general function for the above taking in two params for bins and the requested bins


} //closing main function
	



Double_t ConvertToBeamE(Double_t CME){

  return ( (CME*CME) - (938.27*938.27))/(2*938.27) ;
  //return TMath::Sqrt((938.27+taggE)*(938.27+taggE)-taggE*taggE);

}


vector<Double_t> ConstructBins(Double_t XMin, Double_t XMax, Double_t NBins ){


  vector<Double_t> Bins;

  Double_t BinSize = (XMax - XMin)/NBins;
  for(Int_t l=0;l<NBins;l++){
    Double_t BinVar=XMin +l*BinSize +BinSize/2;

    Bins.push_back(BinVar);
//	cout << BinSize<< endl;
//	cout << BinVar <<"=BinVars" <<endl;

  }


  return Bins;

}


