#!/bin/bash

if [ $# -ne 1 ]
then
	echo "pas le bon nombre d'args"
	exit 1
fi

if [ ! -d $1 ]
then 
	echo "pas répertoire"
	exit 2
fi
