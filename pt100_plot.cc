#include "TTree.h"
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TObject.h"
#include "TMath.h"
#include "TPad.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TLegend.h"
#include "TCut.h"
#include "TF1.h"
#include "TAxis.h"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"


void pt100_plot()
{	
	gStyle	->SetOptStat(0);
	//gStyle	->SetOptFit(0);
	//gStyle	->SetOptStat("m");
	gStyle	->SetOptFit(1);

	gStyle	->SetPalette(1);
	
	gStyle->SetStatBorderSize(0);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFillColor(10);
	gStyle->SetStatColor(10);
	gStyle->SetStatFont(42);
	gStyle->SetMarkerStyle(1);
	gStyle->SetMarkerColor(2);
	
	////////////////////////////////////////////////////////////////////////
	// DATA
	const char *DataFolder 	= "./";	// idark05x
	
	Char_t  DataFile[500];
	sprintf(DataFile, "%s/pt100_calibrationPoints.txt", DataFolder);			

	TTree *t1	= new TTree("t1","t1");
	t1->ReadFile(DataFile, "T:R");
	
	int k = t1->GetEntries();
	cout << "Length of the DATA Tree   k = "	<< k << endl;
	
	float T;
	float R;
	
	t1->SetBranchAddress("T",	&T);
	t1->SetBranchAddress("R",	&R);
	////////////////////////////////////////////////////////////////////////

	double x[k];
	double y[k];
	
	for(int i=0;i<k;i++){
		t1->GetEntry(i);
		x[i] = T;
		y[i] = R;
		//cout <<"T = "<< T <<" ;  "<<"R = "<< R[k]
	}
	
	
	TGraph *gr_TR = new TGraph(k, y, x);
	
	TCanvas *c_TR = new TCanvas("c_TZly", "c_TZly", 0, 0, 700, 500);
			 c_TR->SetFillColor(10);
			 c_TR->SetGrid();
			//c_TR->SetLogy();
			//c_TR->SetLogx();
	
		gr_TR	->	Draw("AP");
		gr_TR	->	SetTitle(0);
		gr_TR	->	GetXaxis()	->	SetTitle("Resistance [Ohm]");
		gr_TR	->	GetYaxis()	->	SetTitle("Temperature [K]");
		gr_TR	-> 	GetXaxis() 	-> 	CenterTitle(true);
		gr_TR	-> 	GetYaxis() 	-> 	CenterTitle(true);

	TF1 *f_TR = new TF1("f_TR","pol6",0,150);
		 f_TR->SetLineColor(1);
		 f_TR->SetLineWidth(3);
	gr_TR->Fit(f_TR,"R");
	f_TR->Draw("same");
		

	c_TR->Update();
	
}

		