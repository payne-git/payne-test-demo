#remove_c_file.sh
#!/bin/bash

function GBK_match() {
	cd $1
	local FILE
	for FILE in `ls`
	do
		#echo "$FILE 111"
		if [ -d $FILE ]
		then
			#echo $PWD/$FILE
			GBK_match $PWD/$FILE
		fi
		#echo $FILE
		encoding_file=`file $FILE`
		if [[ `file $FILE | grep "ISO-8859"` != "" ]]
		then
			#echo $PWD/$encoding_file
			continue
		elif [ -d $FILE ]
		then
			#echo " 111 $PWD/$encoding_file"
			continue
		else
			echo $PWD/$encoding_file
		fi
		#sleep 1
	done
	#sleep 5
	cd ../
}



GBK_match $PWD/.




