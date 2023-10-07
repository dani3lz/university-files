#!/bin/bash

v1="#!/bin/sh"
v2="#!/bin/bash"
v3="#!/usr/bin/perl"
v4="#!/usr/bin/tcl"

c1=0
c2=0
c3=0
c4=0

files=`ls /bin/*`
for f in $files
do
    if [[ -x $f ]];
    then
    read < $f row
            if [[ $row =~ $v1 ]];
            then
                c1=$((c1+1))
            elif [[ $row =~ $v2 ]];
            then
                c2=$((c2+1))
            elif [[ $row =~ $v3 ]];
            then
                c3=$((c3+1))
            elif [[ $row =~ $v4 ]];
            then
                c4=$((c4+1))
            fi
    fi
done

echo "$v1 -- $c1"
echo "$v2 -- $c2"
echo "$v3 -- $c3"
echo "$v4 -- $c4"

exit 0
