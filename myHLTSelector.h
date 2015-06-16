//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Mar  3 14:17:25 2015 by ROOT version 6.02/04
// from TTree eventsTree/
// found on file: fichier_1.root
//////////////////////////////////////////////////////////

#ifndef myHLTSelector_h
#define myHLTSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

#include <iostream>

struct genParticle{
    float pt;
    float eta;
    float phi;
    float energy;
    float px;
    float py;
    float pz;
    float pdgID;
    float ptAtL2;
    float ptAtL3;
    float etaAtL3;
    float phiAtL3;
    float isoCaloAtL3;
    float isoTrkAtL3;
    float isoAtL3;
    int passL1M24;
    int passL2M24;
    int passL3M24;
    int passL3IsoM24;
    int passL3Mu17Mu8dZ;
    int passL3Mu17Mu8;
    int passL3Mu17TkMu8dZ;
    int passL3Mu17TkMu8;
    int passL3Mu17;
    int passL3Mu8;
    bool operator<(const genParticle& a) const
    {
        return pt > a.pt;
    }
    
};

class myHLTSelector : public TSelector {
public :
    
    int myIterator;

    
    TFile *myFile;
    TTree *myTree;
    
    int doByPart;
    
    float mass;
    float ptLead;
    float etaLead;
    float isoLead;
    float ptL3Lead;
    int passL2M24Lead;
    int passL3M24Lead;
    int passL3IsoM24Lead;
    int passL3Mu17Lead;
    int passL3Mu8Lead;
    int passL3Mu17Mu8Lead;
    int passL3Mu17Mu8dZLead;
    int passL3Mu17TkMu8Lead;
    int passL3Mu17TkMu8dZLead;
    
    float combIsoLead;
    float ecalLead;
    float hcalLead;
    float PfEcalLead;
    float PfHcalLead;
    
    float ptTrail;
    float etaTrail;
    float isoTrail;
    float ptL3Trail;
    float bestIso;
    int passL2M24Trail;
    int passL3M24Trail;
    int passL3M24IsoTrail;
    int passL3Mu17Trail;
    int passL3Mu8Trail;
    int passL3Mu17Mu8Trail;
    int passL3Mu17Mu8dZTrail;
    int passL3Mu17TkMu8Trail;
    int passL3Mu17TkMu8dZTrail;
    
    int HLT_OldIsoMu24_eta2p1_v1;
    int HLT_IsoMu17_eta2p1_v1;
    int HLT_IsoMu20_v1;
    int HLT_IsoMu20_eta2p1_v1;
    int HLT_IsoMu24_eta2p1_v1;
    int HLT_IsoMu27_v1;
    int HLT_IsoTkMu20_v1;
    int HLT_IsoTkMu20_eta2p1_v1;
    int HLT_IsoTkMu24_eta2p1_v1;
    int HLT_IsoTkMu27_v1;
    int HLT_Mu27_TkMu8_v1;
    int HLT_Mu30_TkMu11_v1;
    int HLT_Mu40_TkMu11_v1;
    int HLT_Mu20_v1;
    int HLT_Mu24_eta2p1_v1;
    int HLT_Mu50_v1;
    int HLT_Mu8_TrkIsoVVL_v1;
    int HLT_Mu17_TrkIsoVVL_v1;
    int HLT_Mu24_TrkIsoVVL_v1;
    int HLT_Mu34_TrkIsoVVL_v1;
    int HLT_DoubleMu33NoFiltersNoVtx_v1;
    int HLT_DoubleMu38NoFiltersNoVtx_v1;
    int HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1;
    int HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx;
    int HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1;
    int HLT_L2Mu10_L1SingleMu16_v1;
    int HLT_L2Mu10_L1SingleMu5_v1;
    int HLT_L2Mu0_L1SingleMuOpen_v1;
    int HLT_Mu17_Mu8_DZ_v1;
    int HLT_Mu17_Mu8_v1;
    int HLT_Mu17_TkMu8_DZ_v1;
    int HLT_Mu17_TkMu8_v1;
    int HLT_Mu17_Mu8_SameSign_DZ_v1;
    int HLT_Mu17_Mu8_SameSign_v1;
    int HLT_Mu17_Mu8_SameSign_DZ_DPhi_v1;
    int HLT_Mu17_Mu8_SameSign_DPhi_v1;
    int HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1;
    int HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1;
    int HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1;
    int HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1;

    
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

    // Declaration of leaf types
    Int_t           T_Event_RunNumber;
    Int_t           T_Event_EventNumber;
    Int_t           T_Event_LuminosityBlock;
    Int_t           T_Event_nPU;
    Float_t         T_Event_nTruePU;
    Int_t           T_Event_nPUm;
    Int_t           T_Event_nPUp;
    Float_t         T_Event_AveNTruePU;
    Int_t           antiMuEnrichementVeto;
    vector<int>     *T_Event_pathsFired;
    vector<float>   *T_Trig_Eta;
    vector<float>   *T_Trig_Pt;
    vector<float>   *T_Trig_Phi;
    vector<int>     *T_Trig_Leg;
    vector<float>   *T_Trig_TkIsoVeto;
    vector<float>   *T_Trig_trackerIso;
    vector<float>   *T_Trig_detBasedHCAL;
    vector<float>   *T_Trig_detBasedECAL;
    vector<float>   *T_Trig_detBasedCALO;
    vector<float>   *T_Trig_PFecal;
    vector<float>   *T_Trig_PFhcal;
    vector<float>   *T_Trig_rho;
    vector<float>   *T_Gen_Eta;
    vector<float>   *T_Gen_Phi;
    vector<float>   *T_Gen_Pt;
    vector<float>   *T_Gen_Px;
    vector<float>   *T_Gen_Py;
    vector<float>   *T_Gen_Pz;
    vector<float>   *T_Gen_Energy;
    vector<int>     *T_Gen_pdgID;
    vector<int>     *T_Gen_MotherID;
    vector<int>     *T_Gen_FromW;
    vector<int>     *T_Gen_FromTau;
    
    // List of branches
    TBranch        *b_T_Event_RunNumber;   //!
    TBranch        *b_T_Event_EventNumber;   //!
    TBranch        *b_T_Event_LuminosityBlock;   //!
    TBranch        *b_T_Event_nPU;   //!
    TBranch        *b_T_Event_nTruePU;   //!
    TBranch        *b_T_Event_nPUm;   //!
    TBranch        *b_T_Event_nPUp;   //!
    TBranch        *b_T_Event_AveNTruePU;   //!
    TBranch        *b_antiMuEnrichementVeto;   //!
    TBranch        *b_T_Event_pathsFired;   //!
    TBranch        *b_T_Trig_Eta;   //!
    TBranch        *b_T_Trig_Pt;   //!
    TBranch        *b_T_Trig_Phi;   //!
    TBranch        *b_T_Trig_Leg;   //!
    TBranch        *b_T_Trig_TkIsoVeto;   //!
    TBranch        *b_T_Trig_trackerIso;   //!
    TBranch        *b_T_Trig_detBasedHCAL;   //!
    TBranch        *b_T_Trig_detBasedECAL;   //!
    TBranch        *b_T_Trig_detBasedCALO;   //!
    TBranch        *b_T_Trig_PFecal;   //!
    TBranch        *b_T_Trig_PFhcal;   //!
    TBranch        *b_T_Trig_rho;   //!
    TBranch        *b_T_Gen_Eta;   //!
    TBranch        *b_T_Gen_Phi;   //!
    TBranch        *b_T_Gen_Pt;   //!
    TBranch        *b_T_Gen_Px;   //!
    TBranch        *b_T_Gen_Py;   //!
    TBranch        *b_T_Gen_Pz;   //!
    TBranch        *b_T_Gen_Energy;   //!
    TBranch        *b_T_Gen_pdgID;   //!
    TBranch        *b_T_Gen_MotherID;   //!
    TBranch        *b_T_Gen_FromW;   //!
    TBranch        *b_T_Gen_FromTau;   //!

   myHLTSelector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~myHLTSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   virtual void    MatchWithTrigger(genParticle *);
   virtual float   theMax(float, float);

   ClassDef(myHLTSelector,0);
};

#endif

#ifdef myHLTSelector_cxx
void myHLTSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
    
    myFile = new TFile("theOutFile.root","RECREATE");
    myTree = new TTree("myTree","");
    myTree->Branch("ptLead",&ptLead,"ptLead/F");
    myTree->Branch("ptL3Lead",&ptL3Lead,"ptL3Lead/F");
    myTree->Branch("etaLead",&etaLead,"etaLead/F");
    myTree->Branch("isoLead",&isoLead,"isoLead/F");
    myTree->Branch("passL2M24Lead",&passL2M24Lead,"passL2M24Lead/I");
    myTree->Branch("passL3M24Lead",&passL3M24Lead,"passL3M24Lead/I");
    myTree->Branch("passL3IsoM24Lead",&passL3IsoM24Lead,"passL3IsoM24Lead/I");
    
    myTree->Branch("passL3Mu17Lead",&passL3Mu17Lead,"passL3Mu17Lead/I");
    myTree->Branch("passL3Mu8Lead",&passL3Mu8Lead,"passL3Mu8Lead/I");
    myTree->Branch("passL3Mu17Mu8Lead",&passL3Mu17Mu8Lead,"passL3Mu17Mu8Lead/I");
    myTree->Branch("passL3Mu17Mu8dZLead",&passL3Mu17Mu8dZLead,"passL3Mu17Mu8dZLead/I");
    myTree->Branch("passL3Mu17TkMu8Lead",&passL3Mu17TkMu8Lead,"passL3Mu17Lead/I");
    myTree->Branch("passL3Mu17TkMu8dZLead",&passL3Mu17TkMu8dZLead,"passL3Mu17TkMu8dZLead/I");

    myTree->Branch("passL3Mu17Trail",&passL3Mu17Trail,"passL3Mu17Trail/I");
    myTree->Branch("passL3Mu8Trail",&passL3Mu8Trail,"passL3Mu8Trail/I");
    myTree->Branch("passL3Mu17Mu8Trail",&passL3Mu17Mu8Trail,"passL3Mu17Mu8Trail/I");
    myTree->Branch("passL3Mu17Mu8dZTrail",&passL3Mu17Mu8dZTrail,"passL3Mu17Mu8dZTrail/I");
    myTree->Branch("passL3Mu17TkMu8Trail",&passL3Mu17TkMu8Trail,"passL3Mu17Trail/I");
    myTree->Branch("passL3Mu17TkMu8dZTrail",&passL3Mu17TkMu8dZTrail,"passL3Mu17TkMu8dZTrail/I");
    
    /*myTree->Branch("combIsoLead",&combIsoLead,"combIsoLead/F");
    myTree->Branch("ecalLead",&ecalLead,"ecalLead/F");
    myTree->Branch("hcalLead",&hcalLead,"hcalLead/F");
    myTree->Branch("PfEcalLead",&PfEcalLead,"PfEcalLead/F");
    myTree->Branch("PfHcalLead",&PfHcalLead,"PfHcalLead/F");*/
    
    myTree->Branch("ptTrail",&ptTrail,"ptTrail/F");
    myTree->Branch("ptL3Trail",&ptL3Trail,"ptL3Trail/F");
    myTree->Branch("etaTrail",&etaTrail,"etaTrail/F");
 /*   myTree->Branch("isoTrail",&isoTrail,"isoTrail/F");
    myTree->Branch("passL2M24Trail",&passL2M24Trail,"passL2M24Trail/I");
    myTree->Branch("passL3M24Trail",&passL3M24Trail,"passL3M24Trail/I");
    myTree->Branch("passL3M24IsoTrail",&passL3M24IsoTrail,"passL3M24IsoTrail/I");*/
    
    myTree->Branch("mass",&mass,"mass/F");
    myTree->Branch("antiMuEnrichementVeto",&antiMuEnrichementVeto,"antiMuEnrichementVeto/I");
    
    myTree->Branch("T_Event_EventNumber",&T_Event_EventNumber,"T_Event_EventNumber/I");
    myTree->Branch("T_Event_nPU",&T_Event_nPU,"T_Event_nPU/I");
    /*myTree->Branch("HLT_OldIsoMu24_eta2p1_v1",&HLT_OldIsoMu24_eta2p1_v1,"HLT_OldIsoMu24_eta2p1_v1/I");
    myTree->Branch("HLT_IsoMu17_eta2p1_v1",&HLT_IsoMu17_eta2p1_v1,"HLT_IsoMu17_eta2p1_v1/I");
    myTree->Branch("HLT_IsoMu20_v1",&HLT_IsoMu20_v1,"HLT_IsoMu20_v1/I");
    myTree->Branch("HLT_IsoMu20_eta2p1_v1",&HLT_IsoMu20_eta2p1_v1,"HLT_IsoMu20_eta2p1_v1/I");
    myTree->Branch("HLT_IsoMu24_eta2p1_v1",&HLT_IsoMu24_eta2p1_v1,"HLT_IsoMu24_eta2p1_v1/I");
    myTree->Branch("HLT_IsoMu27_v1",&HLT_IsoMu27_v1,"HLT_IsoMu27_v1/I");
    myTree->Branch("HLT_IsoTkMu20_v1",&HLT_IsoTkMu20_v1,"HLT_IsoTkMu20_v1/I");
    myTree->Branch("HLT_IsoTkMu20_eta2p1_v1",&HLT_IsoTkMu20_eta2p1_v1,"HLT_IsoTkMu20_eta2p1_v1/I");
    myTree->Branch("HLT_IsoTkMu24_eta2p1_v1",&HLT_IsoTkMu24_eta2p1_v1,"HLT_IsoTkMu24_eta2p1_v1/I");
    myTree->Branch("HLT_IsoTkMu27_v1",&HLT_IsoTkMu27_v1,"HLT_IsoTkMu27_v1/I");
    myTree->Branch("HLT_Mu27_TkMu8_v1",&HLT_Mu27_TkMu8_v1,"HLT_Mu27_TkMu8_v1/I");
    myTree->Branch("HLT_Mu30_TkMu11_v1",&HLT_Mu30_TkMu11_v1,"HLT_Mu30_TkMu11_v1/I");
    myTree->Branch("HLT_Mu40_TkMu11_v1",&HLT_Mu40_TkMu11_v1,"HLT_Mu40_TkMu11_v1/I");
    myTree->Branch("HLT_Mu20_v1",&HLT_Mu20_v1,"HLT_Mu20_v1/I");
    myTree->Branch("HLT_Mu24_eta2p1_v1",&HLT_Mu24_eta2p1_v1,"HLT_Mu24_eta2p1_v1/I");
    myTree->Branch("HLT_Mu50_v1",&HLT_Mu50_v1,"HLT_Mu50_v1/I");*/
    myTree->Branch("HLT_Mu8_TrkIsoVVL_v1",&HLT_Mu8_TrkIsoVVL_v1,"HLT_Mu8_TrkIsoVVL_v1/I");
    myTree->Branch("HLT_Mu17_TrkIsoVVL_v1",&HLT_Mu17_TrkIsoVVL_v1,"HLT_Mu17_TrkIsoVVL_v1/I");
   /* myTree->Branch("HLT_Mu24_TrkIsoVVL_v1",&HLT_Mu24_TrkIsoVVL_v1,"HLT_Mu24_TrkIsoVVL_v1/I");
    myTree->Branch("HLT_Mu34_TrkIsoVVL_v1",&HLT_Mu34_TrkIsoVVL_v1,"HLT_Mu34_TrkIsoVVL_v1/I");
    myTree->Branch("HLT_DoubleMu33NoFiltersNoVtx_v1",&HLT_DoubleMu33NoFiltersNoVtx_v1,"HLT_DoubleMu33NoFiltersNoVtx_v1/I");
    myTree->Branch("HLT_DoubleMu38NoFiltersNoVtx_v1",&HLT_DoubleMu38NoFiltersNoVtx_v1,"HLT_DoubleMu38NoFiltersNoVtx_v1/I");
    myTree->Branch("HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1",&HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1,"HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1/I");
    myTree->Branch("HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx",&HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx,"HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx/I");
    myTree->Branch("HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1",&HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1,"HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1/I");
    myTree->Branch("HLT_L2Mu10_L1SingleMu16_v1",&HLT_L2Mu10_L1SingleMu16_v1,"HLT_L2Mu10_L1SingleMu16_v1/I");
    myTree->Branch("HLT_L2Mu10_L1SingleMu5_v1",&HLT_L2Mu10_L1SingleMu5_v1,"HLT_L2Mu10_L1SingleMu5_v1/I");
    myTree->Branch("HLT_L2Mu0_L1SingleMuOpen_v1",&HLT_L2Mu0_L1SingleMuOpen_v1,"HLT_L2Mu0_L1SingleMuOpen_v1/I");
    myTree->Branch("HLT_Mu17_Mu8_DZ_v1",&HLT_Mu17_Mu8_DZ_v1,"HLT_Mu17_Mu8_DZ_v1/I");
    myTree->Branch("HLT_Mu17_Mu8_v1",&HLT_Mu17_Mu8_v1,"HLT_Mu17_Mu8_v1/I");
    myTree->Branch("HLT_Mu17_TkMu8_DZ_v1",&HLT_Mu17_TkMu8_DZ_v1,"HLT_Mu17_TkMu8_DZ_v1/I");
    myTree->Branch("HLT_Mu17_TkMu8_v1",&HLT_Mu17_TkMu8_v1,"HLT_Mu17_TkMu8_v1/I");
    myTree->Branch("HLT_Mu17_Mu8_SameSign_DZ_v1",&HLT_Mu17_Mu8_SameSign_DZ_v1,"HLT_Mu17_Mu8_SameSign_DZ_v1/I");
    myTree->Branch("HLT_Mu17_Mu8_SameSign_v1",&HLT_Mu17_Mu8_SameSign_v1,"HLT_Mu17_Mu8_SameSign_v1/I");
    myTree->Branch("HLT_Mu17_Mu8_SameSign_DZ_DPhi_v1",&HLT_Mu17_Mu8_SameSign_DZ_DPhi_v1,"HLT_Mu17_Mu8_SameSign_DZ_DPhi_v1/I");
    myTree->Branch("HLT_Mu17_Mu8_SameSign_DPhi_v1",&HLT_Mu17_Mu8_SameSign_DPhi_v1,"HLT_Mu17_Mu8_SameSign_DPhi_v1/I");*/
    myTree->Branch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1",&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1,"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1/I");
    myTree->Branch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1",&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1,"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1/I");
    myTree->Branch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1",&HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1,"HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1/I");
    myTree->Branch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1",&HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1,"HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1/I");

    
    // Set object pointer
    T_Event_pathsFired = 0;
    T_Trig_Eta = 0;
    T_Trig_Pt = 0;
    T_Trig_Phi = 0;
    T_Trig_Leg = 0;
    T_Trig_TkIsoVeto = 0;
    T_Trig_trackerIso = 0;
    T_Trig_detBasedHCAL = 0;
    T_Trig_detBasedECAL = 0;
    T_Trig_detBasedCALO = 0;
    T_Trig_PFecal = 0;
    T_Trig_PFhcal = 0;
    T_Trig_rho = 0;
    T_Gen_Eta = 0;
    T_Gen_Phi = 0;
    T_Gen_Pt = 0;
    T_Gen_Px = 0;
    T_Gen_Py = 0;
    T_Gen_Pz = 0;
    T_Gen_Energy = 0;
    T_Gen_pdgID = 0;
    T_Gen_MotherID = 0;
    T_Gen_FromW = 0;
    T_Gen_FromTau = 0;
    // Set branch addresses and branch pointers
    if (!tree) return;
    fChain = tree;
    fChain->SetMakeClass(1);
    
    fChain->SetBranchAddress("T_Event_RunNumber", &T_Event_RunNumber, &b_T_Event_RunNumber);
    fChain->SetBranchAddress("T_Event_EventNumber", &T_Event_EventNumber, &b_T_Event_EventNumber);
    fChain->SetBranchAddress("T_Event_LuminosityBlock", &T_Event_LuminosityBlock, &b_T_Event_LuminosityBlock);
    fChain->SetBranchAddress("T_Event_nPU", &T_Event_nPU, &b_T_Event_nPU);
    fChain->SetBranchAddress("T_Event_nTruePU", &T_Event_nTruePU, &b_T_Event_nTruePU);
    fChain->SetBranchAddress("T_Event_nPUm", &T_Event_nPUm, &b_T_Event_nPUm);
    fChain->SetBranchAddress("T_Event_nPUp", &T_Event_nPUp, &b_T_Event_nPUp);
    fChain->SetBranchAddress("T_Event_AveNTruePU", &T_Event_AveNTruePU, &b_T_Event_AveNTruePU);
   // fChain->SetBranchAddress("antiMuEnrichementVeto", &antiMuEnrichementVeto, &b_antiMuEnrichementVeto);
    fChain->SetBranchAddress("T_Event_pathsFired", &T_Event_pathsFired, &b_T_Event_pathsFired);
    fChain->SetBranchAddress("T_Trig_Eta", &T_Trig_Eta, &b_T_Trig_Eta);
    fChain->SetBranchAddress("T_Trig_Pt", &T_Trig_Pt, &b_T_Trig_Pt);
    fChain->SetBranchAddress("T_Trig_Phi", &T_Trig_Phi, &b_T_Trig_Phi);
    fChain->SetBranchAddress("T_Trig_Leg", &T_Trig_Leg, &b_T_Trig_Leg);
    /*    fChain->SetBranchAddress("T_Trig_TkIsoVeto", &T_Trig_TkIsoVeto, &b_T_Trig_TkIsoVeto);
    fChain->SetBranchAddress("T_Trig_trackerIso", &T_Trig_trackerIso, &b_T_Trig_trackerIso);
    fChain->SetBranchAddress("T_Trig_detBasedHCAL", &T_Trig_detBasedHCAL, &b_T_Trig_detBasedHCAL);
    fChain->SetBranchAddress("T_Trig_detBasedECAL", &T_Trig_detBasedECAL, &b_T_Trig_detBasedECAL);
    fChain->SetBranchAddress("T_Trig_detBasedCALO", &T_Trig_detBasedCALO, &b_T_Trig_detBasedCALO);
    fChain->SetBranchAddress("T_Trig_PFecal", &T_Trig_PFecal, &b_T_Trig_PFecal);
    fChain->SetBranchAddress("T_Trig_PFhcal", &T_Trig_PFhcal, &b_T_Trig_PFhcal);*/
    //fChain->SetBranchAddress("T_Trig_rho", &T_Trig_rho, &b_T_Trig_rho);
    fChain->SetBranchAddress("T_Gen_Eta", &T_Gen_Eta, &b_T_Gen_Eta);
    fChain->SetBranchAddress("T_Gen_Phi", &T_Gen_Phi, &b_T_Gen_Phi);
    fChain->SetBranchAddress("T_Gen_Pt", &T_Gen_Pt, &b_T_Gen_Pt);
    fChain->SetBranchAddress("T_Gen_Px", &T_Gen_Px, &b_T_Gen_Px);
    fChain->SetBranchAddress("T_Gen_Py", &T_Gen_Py, &b_T_Gen_Py);
    fChain->SetBranchAddress("T_Gen_Pz", &T_Gen_Pz, &b_T_Gen_Pz);
    fChain->SetBranchAddress("T_Gen_Energy", &T_Gen_Energy, &b_T_Gen_Energy);
    fChain->SetBranchAddress("T_Gen_pdgID", &T_Gen_pdgID, &b_T_Gen_pdgID);
    fChain->SetBranchAddress("T_Gen_MotherID", &T_Gen_MotherID, &b_T_Gen_MotherID);
    fChain->SetBranchAddress("T_Gen_FromW", &T_Gen_FromW, &b_T_Gen_FromW);
    fChain->SetBranchAddress("T_Gen_FromTau", &T_Gen_FromTau, &b_T_Gen_FromTau);
}

Bool_t myHLTSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef myHLTSelector_cxx
