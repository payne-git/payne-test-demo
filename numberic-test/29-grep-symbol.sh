#!/bin/bash


for a in base64encode close connect 
do
	echo "#################################"
	echo $a
	grep -rn "$a" ./* | grep -v "for a in" | grep -v ";$"
	echo "#################################"
	sleep 1
done