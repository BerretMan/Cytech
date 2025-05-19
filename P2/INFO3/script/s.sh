#!/bin/bash

if [ $# -ne 1 ] 
then 
	echo "pas le bon nombre d'argument"
else
	if [ ! -f "$1" ]
	then
		echo "pas un fichier"
	fi
fi

N_LIGNE="$(wc -l < $1)"
head -1 $1
cat $1 | tail -n "$((N_LIGNE-1))" | sort -t' ' -k2nr
