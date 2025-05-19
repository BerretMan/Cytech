#!/bin/bash

if [[ !($# -ge 3 &&  "$#%2" -ne 0) ]]
then
	echo "Pas une expression valide"
fi

calc() 
{
	if [ "$2" = '+' ]
	then 
		echo	$(($1 + $3))	
	fi
	
	if [ "$2" = 'x' ]
	then 
		echo	$(($1 * $3))	
	fi

	if [ "$2" = '-' ]
	then 
		echo	$(($1 - $3))	
	fi

	if [ "$2" = '/' ]
	then 
		echo	$(($1 / $3))	
	fi

	if [ "$2" = "^" ]
	then
		echo $(($1**$3))
	fi
}

a=$1
shift

while  [ $# -ge 2 ]
do
	operator=$1
	b=$2
	a=$(calc $a $operator $b)
	shift 2
done

echo $a

