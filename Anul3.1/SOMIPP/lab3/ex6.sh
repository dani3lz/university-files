#! /bin/bash
dir=$(echo "$PWD" | cut -d "/" -f2) #/home/daniel/lab3
if test $dir = "home"
then
exit 0
else
exit 1
fi
