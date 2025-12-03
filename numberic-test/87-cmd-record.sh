#! /bin/bash

RECORD_FILE=$(pwd)/cmd_record


RUN_CMD_AND_RECORD()
{
	if [ `cat $RECORD_FILE | wc -l` -ge 10 ]
	then
		> $RECORD_FILE
	fi
	
	echo -n "cmd : " >> $RECORD_FILE
	echo $1 >> $RECORD_FILE
	echo "############### result ###############" >> $RECORD_FILE
	$1 >> $RECORD_FILE &>> $RECORD_FILE
	echo "############### result ###############" >> $RECORD_FILE
}


RUN_CMD_AND_RECORD "cat oob_confa"