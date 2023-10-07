#!/bin/bash

clear
if test -f "ppid_sorted.txt";
then
    rm ppid_sorted.txt
fi

list=`ls /proc | grep "[[:digit:]]\+"`

for l in $list
do
    pid=`grep -sr "^Pid" /proc/$l/status | awk '{print $2}'`
    if [[ $pid == "" ]];
    then
    continue
    fi
    ppid=`grep -sr "^PPid" /proc/$l/status | awk '{print $2}'`
    avg=`grep -sr "^se.sum_exec_runtime" /proc/$l/sched | awk '{print $3}'`
    echo "ProcessID=$pid:Parent_ProcessID=$ppid:Average_Time=$avg" >> ppid_sorted.txt
done

sorted=`cat ppid_sorted.txt | sort -t '=' -k3 -n`
echo "$sorted" > ppid_sorted.txt
cat ppid_sorted.txt

exit 0
