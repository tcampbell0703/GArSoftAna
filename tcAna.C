#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TDirectory.h>

#include "./evtClass.C"

void tcAna() {

	TFile* inF = new TFile("anatree.root", "OPEN");
	if(!inF){
		cout << "Falied to load input file, exiting" << endl;
		return;
	}
	TDirectory* inDir = (TDirectory*)inF->Get("anatree.root:/anatree");
	if(!inDir){
		cout << "Falied to load input directory, exiting" << endl;
		return;
	}
	TTree* inT = (TTree*)inDir->Get("GArAnaTree");
	if(!inT){
		cout << "Falied to load input tree, exiting" << endl;
		return;
	}

	garEvt* gEvt = new garEvt();
	gEvt->SetBranchAddresses(inT);

	for(int iEntry=0; iEntry<inT->GetEntries(); iEntry++){
		inT->GetEntry(iEntry);
	}
	inF->Close();
}
