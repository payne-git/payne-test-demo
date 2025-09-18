#!/bin/sh

RES_COL=60
MOVE_TO_COL="echo -ne \\033[${RES_COL}G"
SUCCESS="echo -n \\033[1;32m"
FAILURE="echo -n \\033[1;31m"
NORMAL="echo -n \\033[0;39m"

echo_success() {
    #$MOVE_TO_COL
    echo -n "[ "
    $SUCCESS
    echo -n "OK"
    $NORMAL
    echo " ]"
    return 0
}

echo_failure() {
    #$MOVE_TO_COL
    echo -n "[ "
    $FAILURE
    echo -n "FAILED"
    $NORMAL
    echo " ]"
    return 1
}

func() {
    $1 > /dev/null 2>&1
    if [ $? -eq 0 ] ; then
        echo_success
    else
        echo_failure
    fi
}




echo "########start########"
echo -n "START TEST MOD OK..."
func " ls "
echo -n "START TEST MOD FAILED..."
func " mm "
echo "########end########"
