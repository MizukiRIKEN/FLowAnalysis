#!/bin/bash

source setup.sh

export MNMACRO=DoFlow_adv.C        ##<--- MACRO name

##---->>> EDIT here
##<----------- data
export MNRNF={$RNF132}             ##<--- 
export MNDB=BTt                    ##<---
export MNVERSION=41.2              ##   <------@@ input 
##<----

##------------- RPSim
export MNDB=rpsim                  ##<---

export MNVERSION=19                ##   <------@@ input 
export MNDBVERSION=$MNVERSION

source SetEnvRPSim.sh

export MNOVER=0
##<-----------


export SUFX=$MNDB
export MNrunOne='SUFX=$MNDB  VER=$MNVERSION root $MACRO.C'

function doflowmulti()
{
    if [ -n "$1" ]; then
	export MNOVER=$1
    fi
    echo Output Version is  $MNOVER

    PARTICLES=("3" "4" "5" "6" "8")
    typeset -i I=0;
    while(( $I < ${#PARTICLES[@]} ))
    do
	echo $I 
	doflowbatch ${PARTICLES[I]}
	let I++;
	if [ $I -ge ${#PARTICLES[@]} ]; then
	    break;
	fi
    done
}

function doflowbatch() 
{
    LC=0 UC=40 RUN={$MNRNF} VER=$MNVERSION OUTVER=$MNOVER root -b -q $MNMACRO\($1\)
}

function doflow() 
{
    if [ -n "$3" ]; then
	export MNOVER=$3
	echo "output version -> "  $MNOVER
    elif [ -n "$2" ]; then
	export MNOVER=$2
    fi

    LC=0 UC=80 RPBS=$2 RUN={$MNRNF} VER=$MNVERSION OUTVER=$MNOVER root $MNMACRO\($1\)
}

echo $MNVERSION to $MNOVER
cat DoFlow.sh |grep function
env|grep MN

echo "doflow -2   :: Get centrality and Psi dependent correction"
echo "doflow -4   :: Get Psi dependent correction parameter"
echo "doflow -3   :: Get overall correction factor"
echo "doflow      :: open files "
echo "doflow 2 0(output version#) :: DoFlow_adv.C"
echo "-1:pi- 1:pi+, 2:p, 3:d, 4:t, 5:3He, 6: 4He, 7:n, 8:H" 
echo "Type  run #(partid) #(Output version)"


function doflowmdependence() 
{
    
    LC=0  UC=30  RUN=$MNRNF VER=$MNVERSION root -b -q $MNMACRO\(-4\)  
    LC=30 UC=40  RUN=$MNRNF VER=$MNVERSION root -b -q $MNMACRO\(-4\)
    LC=40 UC=50  RUN=$MNRNF VER=$MNVERSION root -b -q $MNMACRO\(-4\)
    LC=50 UC=80  RUN=$MNRNF VER=$MNVERSION root -b -q $MNMACRO\(-4\)

    LC=0  UC=30  RUN=$MNRNF VER=$MNVERSION OUTVER=5 root -b -q $MNMACRO\(8\)   
    LC=30 UC=40  RUN=$MNRNF VER=$MNVERSION OUTVER=6 root -b -q $MNMACRO\(8\) 
    LC=40 UC=50  RUN=$MNRNF VER=$MNVERSION OUTVER=7 root -b -q $MNMACRO\(8\) 
    LC=50 UC=80  RUN=$MNRNF VER=$MNVERSION OUTVER=8 root -b -q $MNMACRO\(8\) 
}
