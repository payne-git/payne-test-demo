#!/bin/bash

OPTION_FILE="./option_file"

if [ "`cat $OPTION_FILE|grep -c IPS=enable`" != 0 ] ; then
    echo "IPS is enable"
elif [ "`cat $OPTION_FILE|grep -c IPS=disable`" != 0 ] ; then
    sed -i 's/IPS=disable/IPS=enable/g' $OPTION_FILE
    echo "IPS_EXPIRE=2024-10-15" >> $OPTION_FILE
else
    echo "IPS=enable" >> $OPTION_FILE
    echo "IPS_EXPIRE=2024-10-15" >> $OPTION_FILE
fi
if [ "`cat $OPTION_FILE|grep -c AV=enable`" != 0 ] ; then
    echo "AV is enable"
elif [ "`cat $OPTION_FILE|grep -c AV=disable`" != 0 ] ; then
    sed -i 's/AV=disable/AV=enable/g' $OPTION_FILE
    echo "AVJSS_EXPIRE=2024-10-15" >> $OPTION_FILE
else
    echo "AV=enable" >> $OPTION_FILE
    echo "AVJSS_EXPIRE=2024-10-15" >> $OPTION_FILE
fi
if [ "`cat $OPTION_FILE|grep -c TTI=enable`" != 0 ] ; then
    echo "TTI is enable"
elif [ "`cat $OPTION_FILE|grep -c TTI=disable`" != 0 ] ; then
    sed -i 's/TTI=disable/TTI=enable/g' $OPTION_FILE
    echo "TTI_EXPIRE=2024-10-15" >> $OPTION_FILE
else
    echo "TTI=enable" >> $OPTION_FILE
    echo "TTI_EXPIRE=2024-10-15" >> $OPTION_FILE
fi