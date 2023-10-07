#!/bin/bash/

clear
commands=`ls /sbin/`
proc_cmd=`ps -aux | awk '{print $11}'`

if test -f "procs.txt";
then
    rm procs.txt
fi

i=0

for pc in $proc_cmd
do  
    for cmd in $commands
    do
        if [[ $pc =~ $cmd ]]
        then
            nr=$((i+1))
            ps -aux | awk '{print $2}' | sed $nr!d >> procs.txt
        fi
    done
    i=$((i+1))
done

cat procs.txt
exit 0




