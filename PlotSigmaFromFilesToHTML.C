void PlotSigmaFromFilesToHTML() {
	
  ofstream outHtml;
  outHtml.open("/home/chris/public_html/Meetings/outhtmlSigmaPlots/Proton/SigmaPPi0CutsAnalysisCutResultsRawVTheory/summary.html");
//  TCanvas *can = new TCanvas("can","can",800,600);
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
	
  int histNum = 0;
  int FigCount = 0;

		
  TFile *infile = TFile::Open("/w/work3/home/chris/LatestAnalysisRuns/Data/DataJul18/HistoSelector/Pi0Analysis/LatestProtonApr252019/SigmaPPi0CutsAnalysisCutResultsRawVTheory.root");
  TIter next(infile->GetListOfKeys());
  TKey *key;
  while( (key=(TKey*)next() )  ){
    TClass *cl = gROOT->GetClass(key->GetClassName());
//    if (!cl->InheritsFrom("TH1")) continue;
//    TH1F* hist = (TH1F*) key->ReadObj();
    if (!cl->InheritsFrom("TCanvas")) continue;
    TCanvas* hist = (TCanvas*) key->ReadObj();
    hist->Draw();

//    hist->GetYaxis()->SetRangeUser(0.3,0.9);

    TString heading =  key->GetName();
//    outHtml << "<TR><TD><h1>"+heading+"</h1>" << endl;
//    outHtml << "<TR><TD>" << endl;
//    outHtml << "<TABLE>" << endl;

    if (histNum%2==0){
//	 outHtml << "<TR><TD><h1>"+heading+"</h1>" << endl;
   	 outHtml << "<TR>"; // new row every 4 hists             
	
}

    histNum++;
    FigCount++;
    TString FigCountS =Form("%d",FigCount);

    TString imFileName = (TString)key->GetName() + (".gif");
    gPad->SaveAs("/home/chris/public_html/Meetings/outhtmlSigmaPlots/Proton/SigmaPPi0CutsAnalysisCutResultsRawVTheory/"+FigCountS+imFileName);
    //can->Clear();	
    outHtml << "<td><image src=\""+FigCountS+imFileName+"\" width=\"80%\"></image>" << endl;

  }

  outHtml << "</TABLE>" << endl;
  outHtml << "</body>" << endl;
  outHtml << "</HTML>" << endl;
  outHtml.close();
}
	

