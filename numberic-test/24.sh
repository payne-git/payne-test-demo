#!/bin/bash


string="4"

num=$string


TCP_MEM=`cat /mnt/hgfs/topsec_work/2.6.27-tos-diff/test/xu_txt`
for x in $TCP_MEM
do  
    LIMIT_TCP_MEM=$LIMIT_TCP_MEM$((x/2))" "
done
echo $LIMIT_TCP_MEM > /mnt/hgfs/topsec_work/2.6.27-tos-diff/test/xu_txt

#if test 0 -eq 1;then
#注释
<<!
if [ $0 ];then
	echo "dai can"
	echo $0
	echo $#
else
	echo "bu dai"
fi
!
#注释


if [ $string = "3" -o $string = "4" ]
then
	echo $string
fi

if [ $string = 5 ]
then
	echo num
fi
#fi
