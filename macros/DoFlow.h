
TString fsys[] = {"^{132}Sn+^{124}Sn","^{108}Sn+^{112}Sn","^{124}Sn+^{112}Sn","^{112}Sn+^{124}Sn", "pp", "RPSim"};
TString lsys[] = {"^{132}Sn",        "^{108}Sn",            "^{124}Sn",           "^{112}Sn"     , "pp","^{100}Sn"  };
TString rsys[] = {"132",        "108",        "124",        "112"};
TString tsys[] = {"124",        "112",        "112",        "124"};
TString fpid[] = {"proton","deuteron","triton","3He","4He","neutron","H"};  
TString lpid[] = {"1H",    "2H",      "3H"    ,"3He","4He","N"      ,"H"};  
UInt_t  Asys[] = { 132,   108,  124, 112};
 
const UInt_t nsys = 4;
const UInt_t nprt = 5;
TString  iopt[]     = {"","same","same","same","same", "same", "same"};
UInt_t   imark[]    = {20, 25, 26, 32, 24, 21, 22, 23};  
Color_t  icol[] = {  kRed, kBlue, kGreen+2, kMagenta, kOrange, kViolet};

UInt_t ic = 0;
TCanvas *cc;
const Int_t nbinx = 30;
UInt_t id = 0;

UInt_t  trkcut[][2] = {{42,52}, {55,80},   {40,55},    {30,40},  {0, 30}};
TString trklabel[]  = {"_42to52", "_55to80", "_40to55", "_30to40", "_0to30"};


//Double_t yrange1[] = { -0.8, -0.25, -0.15, -0.05, 0.05, 0.15, 0.25, 0.35, 0.45, 0.5, 0.8};
//Double_t yrange1_20200531[] = {-0.5, -0.45, -0.35, -0.25, -0.05, 0.05, 0.15, 0.25, 0.35, 0.45, 0.5};
// data Double_t yrange1[] = { -0.2, -0.05, 0.05, 0.15, 0.25, 0.35, 0.45, 0.5};
Double_t yrange1[]    = {-0.5,  -0.25,  -0.20, -0.15,  -0.1,  -0.05, 0.05,  0.1,  0.15,  0.2,  0.25,  0.3,  0.35,  0.45, 0.5}; //by v52.10
//Double_t yrange1nrm[] = {-1.35, -0.675, -0.54, -0.404, -0.27, -0.135, 0., 0.135, 0.27, 0.404, 0.54, 0.675, 0.81, 0.944, 1.2,  1.35}; upto v52.15.12

Double_t yrange1nrm[] = {-1.5, -0.75, -0.6, -0.45, -0.3, -0.15, -0.07, 0.07, 0.15, 0.3, 0.45, 0.6, 0.75, 1.0,  3.5};
const UInt_t ybin1 = sizeof(yrange1nrm)/sizeof(Double_t);

//Double_t yrange2[] = { -0.8, -0.2, -0.05,  0.05, 0.2, 0.35, 0.5, 0.8};
// data Double_t yrange2[] = { -0.2, -0.05,  0.05, 0.2, 0.35, 0.5};
//Double_t yrange2_20200531[] = { -0.5, -0.35, -0.2, -0.05,  0.05, 0.2, 0.35, 0.5};
//Double_t yrange2[] = { -0.5, -0.25 -0.15, -0.1, -0.05, 0.,  0.05, 0.1, 0.15, 0.25, 0.35, 0.5}; //v52.0.9
//Double_t yrange2nrm[] = { -1.35, -0.675,  -0.27,  0.,  0.27,  0.675, 0.944, 1.35};  upto v52.15.12

Double_t yrange2[]    = { -0.5,  -0.25,   -0.1,   0.,  0.1,   0.25 , 0.35,  0.5};
Double_t yrange2nrm[] = { -1.5, -1.0, -0.5, -0.3,  -0.15, 0.15, 0.3, 0.5, 1.0, 3.5};
const UInt_t ybin2 = sizeof(yrange2nrm)/sizeof(Double_t);

//Double_t y_cm[]  = { 0.382453, 0.364873, 0.390302, 0.354066, 0.371326, 0.382453}; //by v52.9
Double_t y_bm[]  = { 0.360199, 0.377779, 0.354065, 0.390301, 0.371326, 0.360199};
Double_t y_cm[] =  { 0.382006, 0.36444,  0.389983, 0.353648, 0.371326, 0.382006,   0.37093, 0.37093, 0.37192, 0.371788, 0.371326, 0.37093};
//                    132AA    108AA     124AA     112AA     pp         100(sim)    132nn    108nn    124nn    112nn    pp         100nn
// pt bin
const UInt_t   ptbin1  = 8; //16
const UInt_t   ptbin2  = 5; //10
Double_t pt_max = 800.;

const Double_t ut_max[] = {2.2, 1.6, 1.2, 1.2, 1.0, 2.2} ;
Double_t dpt1 = 0.275;
Double_t dpt2 = 0.44;
// Psi bin
const UInt_t  psibin = 12;

				   
TString  Partname[] = {"pi-","pi+","Proton","Deuteron" ,"Triton", "3He", "4He", "Neutron", "H",   "Triton"};
TString  partname[] = {"pi-","pi+","proton","deuteron" ,"triton", "3He", "4He", "neutron", "H",   "triton"};
UInt_t   partid[]   = {211,    211,    2212, 1000010020, 1000010030, 1000020030, 1000020040, 2112, 1000010040, 1000010030};
Double_t partA[]    = {0.15,   0.15,      1.,         2.,         3.,         3.,         4.,   1.,        1.,   3.};

//  UInt_t mrange[] = {70, 60, 55, 50, 45, 40, 35, 30, 25, 20, 0}; //mtrack4
UInt_t mrange[] = {800, 100, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5, 0};
const UInt_t mbin = sizeof(mrange)/sizeof(UInt_t);

Int_t  Seltrk = 2;
Int_t  Lcent  = 0;  // {75, 45, 30, 20, 0};
Int_t  Ucent  = 80;
Int_t  RPBase;

const UInt_t npsi = 12; // Number of bin in Psi
Double_t dphi = 2.*TMath::Pi()/ (Double_t)npsi ;

TString amdpartname[] = {"prt","deut","trit","3He","4He","neut","H"};

Bool_t bCorr = kFALSE;

Double_t y_norm = 1.;
