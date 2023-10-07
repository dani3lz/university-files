#!/bin/bash

clear
ps -aux | sort -n -k 2 | grep "^daniel" | awk '{print "PID: "$2}' > pid.txt
cat pid.txt
lines=`wc -l < pid.txt`
echo "Numarul de procese: $lines"
exit 0
