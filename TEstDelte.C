{


Double_t ArrCosth[36] = {0.876,0.845 ,0.807 ,0.764 ,0.718 ,0.668 ,0.615 ,0.559 ,0.500 ,0.438 ,0.374 ,0.309 ,0.242 ,0.173 ,0.105 ,0.035 ,-0.035,-0.104,-0.173,-0.242,-0.309,-0.374,-0.438,-0.499,-0.559,-0.614,-0.668,-0.718,-0.764,-0.808,-0.846,-0.882,-0.912,-0.938,-0.961,-0.977};
Double_t ArrSigma[36] = {1.378,0.644 ,0.241,0.225 ,0.253 ,0.315 ,0.318 ,0.346 ,0.483 ,0.447 ,0.534 ,0.499 ,0.532 ,0.504 ,0.585 ,0.574 ,0.590 ,0.616 ,0.667 ,0.647 ,0.644 ,0.616 ,0.647 ,0.650 ,0.692 ,0.662 ,0.668 ,0.850 ,0.530 ,0.667 ,0.436 ,0.653 ,0.152 ,0.595 ,-0.036,-0.063};




auto c3 = new TCanvas("c3","c3");
TGraph* SigmaPlot=new TGraph(36,ArrCosth,ArrSigma);
SigmaPlot->SetMarkerStyle(25);//Filled triangle(black(default)
SigmaPlot->SetMarkerColor(2);  //red
SigmaPlot->SetFillStyle(0);
SigmaPlot->SetFillColor(0);
SigmaPlot->SetTitle("SAID");



SigmaPlot->Draw("AP");




}





