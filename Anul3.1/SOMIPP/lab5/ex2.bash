#!/bin/bash/

clear
ps -aux | sort -rn -k 9 | head -1 | awk '{print "PID: "$2}'

