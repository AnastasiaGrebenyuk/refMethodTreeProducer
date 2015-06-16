#define myHLTSelector_cxx
// The class definition in myHLTSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("myHLTSelector.C")
// root> T->Process("myHLTSelector.C","some options")
// root> T->Process("myHLTSelector.C+")
//

#include "myHLTSelector.h"
#include <TH2.h>
#include <TStyle.h>
#include <TLorentzVector.h>




void myHLTSelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
    
    myIterator = 0;
    doByPart = 1;


}

void myHLTSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t myHLTSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either myHLTSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
    fChain->GetTree()->GetEntry(entry);
    myIterator++;
    //fChain->GetEntry(entry);
    if (myIterator%100==0) cout << '\r' << " i=" << myIterator << endl;
   // cout << "event=" << T_Event_EventNumber << endl;
    vector<genParticle> theGenParticles;

    int nbGenPart = T_Gen_Eta->size();

    if (doByPart){
        for (int i = 0 ; i < nbGenPart ; i++){
            genParticle theGen;
            theGen.pt = T_Gen_Pt->at(i);
            theGen.phi = T_Gen_Phi->at(i);
            theGen.eta = T_Gen_Eta->at(i);
            theGen.px = T_Gen_Px->at(i);
            theGen.py = T_Gen_Py->at(i);
            theGen.pz = T_Gen_Pz->at(i);
            theGen.energy = T_Gen_Energy->at(i);
            theGen.pdgID = T_Gen_pdgID->at(i);
            if (fabs(theGen.pdgID)!=13) continue;
            theGenParticles.push_back(theGen);
        }
        nbGenPart = theGenParticles.size();
        if (nbGenPart<2) return kTRUE;
        std::sort(theGenParticles.begin(), theGenParticles.end());
    }
    /*  cout << "hello !, il y a " << theGenParticles.size() << " in the event" << endl;
     for (int i = 0 ; i < nbGenPart ; i++){
     cout << "pt=" << theGenParticles.at(i).pt << " PDGid=" << theGenParticles.at(i).pdgID << endl;
     
     */
     HLT_Mu8_TrkIsoVVL_v1 = T_Event_pathsFired->at(0);
     HLT_Mu17_TrkIsoVVL_v1 = T_Event_pathsFired->at(1);
     HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1 = T_Event_pathsFired->at(2);
     HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1 = T_Event_pathsFired->at(3);
     HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1 = T_Event_pathsFired->at(4);
     HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1 = T_Event_pathsFired->at(5);
    
    genParticle theLead = theGenParticles.at(0);
    genParticle theTrail {.pt=-1};
    if (doByPart){
        for (int i = 1 ; i<nbGenPart ; i++){
            if ((theLead.pdgID*theGenParticles.at(i).pdgID<0)){
                theTrail = theGenParticles.at(i);
                break;
            }
        }
        if (theTrail.pt==-1) return kTRUE;
    }
    
    // cout << "theLead=" << theLead.pt << " " << theLead.pdgID << endl;
    //  cout << "theTrail=" << theTrail.pt << " " << theTrail.pdgID << endl;
    if (doByPart){
        MatchWithTrigger(&theLead);
        MatchWithTrigger(&theTrail);
        ptLead = theLead.pt;
        etaLead = theLead.eta;
        isoLead = theLead.isoAtL3;
        ptL3Lead = theLead.ptAtL3;
        passL3Mu17Lead = theLead.passL3Mu17;
        passL3Mu8Lead = theLead.passL3Mu8;
        
        passL3Mu17Mu8Lead = theLead.passL3Mu17Mu8;
        passL3Mu17Mu8dZLead = theLead.passL3Mu17Mu8dZ;
        
        passL3Mu17TkMu8Lead = theLead.passL3Mu17TkMu8;
        passL3Mu17TkMu8dZLead = theLead.passL3Mu17TkMu8dZ;
        
    
        ptTrail = theTrail.pt;
        etaTrail = theTrail.eta;
        isoTrail = theLead.isoAtL3;
        ptL3Trail = theTrail.ptAtL3;

       // passL3M24Trail = theTrail.passL3M24;
        //passL3IsoM24Trail = theTrail.passL3IsoM24;
        
        passL3Mu17Trail = theTrail.passL3Mu17;
        passL3Mu8Trail = theTrail.passL3Mu8;
        
        passL3Mu17Mu8Trail = theTrail.passL3Mu17Mu8;
        passL3Mu17Mu8dZTrail = theTrail.passL3Mu17Mu8dZ;
        
        passL3Mu17TkMu8Trail = theTrail.passL3Mu17TkMu8;
        passL3Mu17TkMu8dZTrail = theTrail.passL3Mu17TkMu8dZ;
        
        TLorentzVector *theLeadVector = new TLorentzVector(theLead.px, theLead.py, theLead.pz, theLead.energy);
        TLorentzVector *theTrailVector = new TLorentzVector(theTrail.px, theTrail.py, theTrail.pz, theTrail.energy);
        
        TLorentzVector sumMuons = *theLeadVector + *theTrailVector;
        
        mass = sumMuons.M();
        
        /*ptLead = theTrail.pt;
        etaLead = theTrail.eta;
        isoLead = theLead.isoAtL3;
        passL3M24Lead = theTrail.passL3M24;
        passL3IsoM24Lead = theTrail.passL3IsoM24;*/
    }
    
    
    
   /* float minIso = 100;
    float theIso;
    for (int k = 0 ; k < T_Trig_Eta->size() ; k++){
        theIso = (theMax(0,T_Trig_detBasedCALO->at(k)) + T_Trig_TkIsoVeto->at(k))/T_Trig_Pt->at(k);
        if (theIso<minIso) minIso = theIso;
    }
    bestIso = minIso;*/
    
    
    myTree->Fill();
    // if (entry>1000) Abort("the end !!!");

   return kTRUE;
}

void myHLTSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void myHLTSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
    
    // the results graphically or save the results to file.
    myFile->Write();
    myFile->Close();

}

void myHLTSelector::MatchWithTrigger(genParticle *theGen){
    int nbTriggerLeg = T_Trig_Pt->size();
    theGen->passL1M24=0;
    theGen->passL2M24=0;
    theGen->passL3M24=0;
    theGen->passL3IsoM24=0;
    theGen->ptAtL2 = 0;
    theGen->passL3Mu8 = 0;
    theGen->passL3Mu17 = 0;
    theGen->passL3Mu17Mu8dZ = 0;
    theGen->passL3Mu17Mu8 = 0;
    theGen->passL3Mu17TkMu8 = 0;
    theGen->passL3Mu17TkMu8dZ = 0;
    for (int i = 0 ; i < nbTriggerLeg ; i++){
        float deltaR = sqrt(pow(theGen->eta-T_Trig_Eta->at(i),2)+ pow(acos(cos((theGen->phi-T_Trig_Phi->at(i)))),2));
        //cout << "deltaR=" << deltaR << endl;
        //if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==1)) {theGen->passL2M24=1; theGen->ptAtL2 = T_Trig_Pt->at(i);}
        //if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==2)) {theGen->passL3M24=1; }
       /* if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==0)) {
            theGen->passL3IsoM24=1;
            theGen->ptAtL3 = T_Trig_Pt->at(i);
            theGen->etaAtL3 = T_Trig_Eta->at(i);
            theGen->phiAtL3 = T_Trig_Phi->at(i);
            //theGen->isoAtL3 = (T_Trig_detBasedCALO->at(i)+T_Trig_trackerIso->at(i))/T_Trig_Pt->at(i);
        }*/
        if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==0)) { theGen->passL3Mu8 = 1; theGen->ptAtL3 = T_Trig_Pt->at(i); theGen->etaAtL3 = T_Trig_Eta->at(i); theGen->phiAtL3 = T_Trig_Phi->at(i);}
        if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==1)) { theGen->passL3Mu17 = 1; theGen->ptAtL3 = T_Trig_Pt->at(i); theGen->etaAtL3 = T_Trig_Eta->at(i); theGen->phiAtL3 = T_Trig_Phi->at(i);}
        if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==2)) { theGen->passL3Mu17Mu8 = 1; theGen->ptAtL3 = T_Trig_Pt->at(i); theGen->etaAtL3 = T_Trig_Eta->at(i); theGen->phiAtL3 = T_Trig_Phi->at(i);}
        if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==3)) { theGen->passL3Mu17Mu8dZ = 1; theGen->ptAtL3 = T_Trig_Pt->at(i); theGen->etaAtL3 = T_Trig_Eta->at(i); theGen->phiAtL3 = T_Trig_Phi->at(i);}
        if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==4)) { theGen->passL3Mu17TkMu8 = 1; theGen->ptAtL3 = T_Trig_Pt->at(i); theGen->etaAtL3 = T_Trig_Eta->at(i); theGen->phiAtL3 = T_Trig_Phi->at(i);}
        if ((deltaR<0.1)&&(T_Trig_Leg->at(i)==5)) { theGen->passL3Mu17TkMu8dZ = 1; theGen->ptAtL3 = T_Trig_Pt->at(i); theGen->etaAtL3 = T_Trig_Eta->at(i); theGen->phiAtL3 = T_Trig_Phi->at(i);}

    }
}

float myHLTSelector::theMax(float a, float b){
    if (a>b) return a;
    else return b;
}

