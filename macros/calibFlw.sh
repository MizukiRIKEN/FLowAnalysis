#!/bin/bash                                                                                                                                           

source runList.sh

export DBP2=_rf.v8.0

#RUN0={$RNF124} DB0=$DBP2 VER=0 root  openFlw.C 
RUN0={$RNF108} DB0=$DBP2 VER=0 root  calibFlw.C 


#RUN0={$RN132t} DB0=$DBP2 VER=3 root -b -q calibFlw.C > logz


