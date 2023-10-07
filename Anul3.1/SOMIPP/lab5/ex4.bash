#!/bin/bash/

clear
if test -f "pid_size.txt";
then
    rm pid_size.txt
fi

list=`ls /proc | grep "[[:digit:]]\+"`

for p in $list
do
    if test -f "/proc/$p/statm";
    then
        size=`cat -s /proc/$p/statm | awk '{print $1}'`    
        resident=`cat -s /proc/$p/statm | awk '{print $2}'`
        dif=$(($size-$resident))
        echo "$p:$dif" >> pid_size.txt
    fi   
done

sorted=`cat pid_size.txt | sort -t ':' -k2 -n -r`
echo "$sorted" > pid_size.txt
cat pid_size.txt
exit 0
