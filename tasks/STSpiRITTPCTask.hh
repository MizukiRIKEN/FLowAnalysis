#ifndef STSpiRITTPCTask_hh
#define STSpiRITTPCTask_hh

// FAIRROOT classes
#include "FairTask.h"
#include "FairRunAna.h"
#include "FairRootManager.h"
#include "STRecoTrack.hh"
#include "STParticle.hh"
#include "STMassFunction.hh"
#include "ST_ClusterNum_DB.hh"
#include "STBDC.hh"
#include "STFlowInfo.hh"
#include "STFlowTask.hh"
#include "STLorentzBoostVector.hh"
#include "STBootStrap.hh"
#include "STEventHeader.hh"
#include "TDatime.h"
#include "TRandom3.h"
#include "STFlowCorrection.hh"
#include <TMath.h>
#include "STFlowCorrection.hh"
#include "STRunToBeamA.hh"
#include "TObject.h"
#include "FairLink.h"

class STSpiRITTPCTask : public FairTask
{
public:
  STSpiRITTPCTask();

  virtual ~STSpiRITTPCTask();

  InitStatus Init();
  void       Exec(Option_t *opt);
  void       FinishEvent();
  void       Finish(){fActive = kFALSE;}

  void   SetPersistence(Bool_t value = kTRUE);
  void   SetRunInfo(TString vDir, TString tver, TString sver){rootDir = vDir, tVer = tver, sVer=sver;}  

  Long64_t GetEventID()  {return fEventIDLast;}
  Long64_t GetEntries() {return nEntry;}
  void     SetProcessingNumberOfEvent(Long64_t val) { val < nEntry ? prcEntry = val : prcEntry = nEntry;
    LOG(INFO) << " process number " << prcEntry << FairLogger::endl;
  }

private:
  Bool_t fIsPersistence;         ///< Persistence check variable
  Bool_t fIsFlowAnalysis;        ///< flow analysis flag
  Bool_t fIsFlowCorrection;      ///< reaction plane flattening correction
  Bool_t fIsBootStrap;           ///< bootstrap analysis flag
  Bool_t fIsSubeventAnalysis;    ///< Subevent analysis flag  
  UInt_t selReactionPlanef;      // track quality for reaction plane 


  FairRunAna      *fRunAna;       //!
  FairLogger      *fLogger;       //!
  FairRootManager *fRootManager;  //!
  

  ST_ClusterNum_DB* db;    //!
  
  UInt_t  iRun;
  TString tVer;  //!
  TString sVer;  //!

  TString rootDir; //!       
  TChain *fChain;  //!
  STEventHeader *eventHeader    = NULL;  //!
  TClonesArray *trackArray     = NULL;  //!
  TClonesArray *trackVAArray   = NULL;  //!
  TClonesArray *vertexArray    = NULL;  //!
  TClonesArray *vertexVAArray  = NULL;  //!
  TClonesArray *vertexBDCArray = NULL;  //!

  TClonesArray   *tpcParticle;  //!

  //--- mass fitter
  STMassFunction *massFitter;   //!

  TClonesArray *flowAnalysis; //!
  STFlowInfo   *fflowinfo;    //!
  STFlowTask   *fflowtask;    //!

  TClonesArray *aflowcorrArray[2];  //!

  UInt_t  ntrack[7]; //!
  
  Double_t ProjA;  //!
  Double_t ProjB;  //!


private:
  Long64_t fEventID;      //! 
  Long64_t fEventIDLast;  //!
  Long64_t nEntry;
  Long64_t prcEntry;      //!
  TDatime  dtime;         //! 
  TDatime  beginTime;     //!  
  

  void   Clear();
  Bool_t SetupParameters();
  Bool_t SetupInputDataFile();
  Bool_t SetupFlowDataBase();

  void   ProceedEvent();
  void   SetupEventInfo();
  void   SetupTrackQualityFlag(STParticle *apart);

  // for flow analysis
  // vector<UInt_t> mtkbin[2];		             //!
  // vector< TString > vfname[2];	                     //!
  // vector< vector<Double_t> >  binmax;	             //!
  // vector< vector<Double_t> >  binmin;	             //!
  // vector< pair<Double_t, Double_t> > pbinmin[2]; //!
  // TRandom3 rnd; //!

  //  void   SetupFlow(STParticle &apart);
  //  void   DoFlowAnalysis(STParticle &apart);
  //  void   DoSubeventAnalysis();
  //  UInt_t *RandomDivide2(const UInt_t npart);
  //  UInt_t SetFLowDatabaseFiles(UInt_t version);
  //  TVector3 Psi_FlatteningCorrection(UInt_t isel, Int_t ival, TVector3 Pvec);
  //  TVector3 Psi_ReCenteringCorrection(UInt_t isel, Int_t ival, TVector3 Pvec);
  //  Int_t  GetCorrectionIndex(UInt_t isel, UInt_t ival, Double_t fval);
  //  Int_t  GetMultiplicityCorretionIndex(UInt_t isel, UInt_t ival);
  //  Int_t  GetThetaCorrectionIndex(UInt_t isel, Int_t ival, Double_t fval);
  //  void   DoIndividualReactionPlaneAnalysis();

public:
  void   SetFlowAnalysis(Bool_t val) {fIsFlowAnalysis = val;}
  Bool_t GetFlowAnalysisFlag()       {return fIsFlowAnalysis;}
  void   SetSubEventAnalysis(Bool_t val) {fIsSubeventAnalysis = val;}
  Bool_t GetSubEventAnalysisFlag()   {return fIsSubeventAnalysis;}
  void   SetBootStrap(Bool_t val)    {fIsBootStrap = val;}
  Bool_t GetBootStrapFlag()          {return fIsBootStrap;}

  // return input file chain
  TChain* GetChain()                 {return fChain;}

  // // Flow parameters
  // TVector2 unitP;      // sum of unit pt vector
  // TVector3 unitP_fc;
  // TVector3 unitP_rc;

  // TVector2 unitP_1;
  // TVector2 unitP_2;
  // UInt_t   mtrack_1;
  // UInt_t   mtrack_2;

  // STBootStrap *bs_unitP; // = new STBootStrap(100);
  // Double_t bsPhi[3];
  // Double_t bsPhi_1[3];
  // Double_t bsPhi_2[3];


  ClassDef(STSpiRITTPCTask, 0);

};

#endif


