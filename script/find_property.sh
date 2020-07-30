#!/bin/bash
FILE=$1

while :  
do
     STR=$(grep -En "^. include .*$" $FILE | head -n 1  )
     if [ -z "$STR" ]; then 
	     echo "ok null done"
	     exit 0
     else 
	FILE_FOR_REPLACE=$(echo $STR  | cut  -d " " -f 3)
	LINE=$(echo $STR  | cut  -d " " -f 1 | sed -n "s/^\([0-9]*\).*$/\1/p")
	#echo $LINE $FILE_FOR_REPLACE   
	#echo $FILE_FOR_REPLACE
	sed  -i "${LINE}r $FILE_FOR_REPLACE" $FILE
	sed -i "${LINE}d" $FILE
	     
     fi

done 


