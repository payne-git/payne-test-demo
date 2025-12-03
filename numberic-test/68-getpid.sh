#!/bin/bash

PROCESS=oob
VALUE=`ps aux | grep -i $PROCESS | grep -v grep | awk '{ if (NR==1) {print $1}}'`

echo $VALUE > /tmp/oob_tmp

