#!/bin/bash

OPTION_FILE=./license
LINE_FILE=./tmp-license


upper_str()
{
    #echo "######################"
    upper=`echo $1 | tr "[a-z]" "[A-Z]"`
    echo $upper
}


getoption()
{
    #echo $#
    if [ "$#" != 1 ]; then
        echo "Usage: getoption optionname"
        return 1
    fi

    name=`upper_str $1`
    maybe1="^ *$name *="
    maybe2="^ *$name "
    echo "$maybe1"
    #echo "\r\n"
    #echo "$maybe2"

    while read line
    do
        #echo $line
        echo $line > $LINE_FILE
        value1=`sed -n -e "/^ *#.*/p" $LINE_FILE`
        #echo $value1
        [ -n "$value1" ]
        if [ $? = 0 ]; then
            #cat $LINE_FILE
            continue
        fi

        #echo "!!!!!!!!!!!!!!!!!!!"
        optline=`sed -n "/$maybe1/p" $LINE_FILE`
        #echo "###########"
        #echo $optline
        #echo "###########"
        if [ -n "$optline" ]; then
            optvalue=`echo $optline | sed 's/.*[[:blank:],=]//g'`
            #echo "@@@@@@@@@@@@@"
            echo $optvalue
            #echo "@@@@@@@@@@@@@"
            #return 0
        fi

        optline=`sed -n  "/$maybe2/p" $LINE_FILE`
        if [ -n "$optline" ] ; then
            optvalue=`echo $optline | sed 's/.*[[:blank:],=]//g'`
            echo $optvalue
            return 0
        fi

        sleep 1
    done<$OPTION_FILE
    #rm -f $LINE_FILE
    return 1
}


value=`getoption $1`
echo $value
#sleep 1
#getoption ospf

