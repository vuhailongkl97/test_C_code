#!/bin/bash

#-1 . use expand if it need ( it use tabs instead of spaces)
# 0. choose where should add flag for debug, save-temp
# 1. add -save-temps or debug flag
# 2. prepare all file for  cscope 
# 3. 

input="$1"
while IFS= read -r line
do
	code="$(echo $line | sed -n 's/[[:space:]]*\(.*\);/\1/p')"
	space="$(echo "$line" | sed -n 's/\([[:space:]]*\).*/\1/p')"
	number_space="$(echo "$space" | wc -m )"	
	echo $code $number_space
	
done < "$input"

