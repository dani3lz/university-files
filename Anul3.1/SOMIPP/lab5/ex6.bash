#!/bin/bash

bash ex5.bash
clear
list=`cat ppid_sorted.txt`
nr=`cat ppid_sorted.txt | wc -l`
i=0
summ=0
new_list=""
counter=0
tpid="n"
tppid="n"
tsumm=0

for row in $list
do
    counter=$((counter+1))
     if [[ "$counter" -eq "$nr" ]]
     then
        ppid1=`echo "$row" | cut -d "=" -f3 | cut -d ":" -f1`
        pid1=`echo "$row" | cut -d "=" -f2 | cut -d ":" -f1`
        tv=`grep -s "^voluntary_ctxt_switches" /proc/$tpid/status | awk '{print $2}'`
        tnv=`grep -s "^nonvoluntary_ctxt_switches" /proc/$tpid/status | awk '{print $2}'`
        tsumm=$((tsumm+$tv+$tnv))

        v=`grep -s "^voluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
        nv=`grep -s "^nonvoluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
        summ=$((summ+$v+$nv))

        new_list+="Sum_switches_of_ParentID=$tppid is $tsumm"$'\n\n'"$row"$'\n'"Sum_switches_of_ParentID=$ppid1 is $summ"
        break
    fi
    if [[ "$i" -eq 0 ]]
    then
        ppid1=`echo "$row" | cut -d "=" -f3 | cut -d ":" -f1`
        pid1=`echo "$row" | cut -d "=" -f2 | cut -d ":" -f1`
        
        i=$((i+1))
        if [[ "$counter" -gt 1 ]]
        then
            if [[ "$ppid1" -eq "$ppid2" ]]
            then
                v=`grep -s "^voluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
                nv=`grep -s "^nonvoluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
                summ=$((summ+$v+$nv))
                new_list+="$row"$'\n'
                continue
            fi
            if [[ "$tpid" != "n" ]]
            then
                v=`grep -s "^voluntary_ctxt_switches" /proc/$tpid/status | awk '{print $2}'`
                nv=`grep -s "^nonvoluntary_ctxt_switches" /proc/$tpid/status | awk '{print $2}'`
                tsumm=$((tsumm+$v+$nv))
                new_list+="Sum_switches_of_ParentID=$tppid is $tsumm"$'\n\n'
                tpid="n"
                tppid="n"
                tsumm=0
            fi
        fi
        new_list+="$row"$'\n'
        continue    
    fi




    ppid2=`echo "$row" | cut -d "=" -f3 | cut -d ":" -f1`
    pid2=`echo "$row" | cut -d "=" -f2 | cut -d ":" -f1`
    if [[ "$ppid1" -eq "$ppid2" ]]
    then
        v=`grep -s "^voluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
        nv=`grep -s "^nonvoluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
        summ=$((summ+$v+$nv))
        new_list+="$row"$'\n'
        tppid="n"
        tpid="n"

    else
        v=`grep -s "^voluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
        nv=`grep -s "^nonvoluntary_ctxt_switches" /proc/$pid1/status | awk '{print $2}'`
        summ=$((summ+$v+$nv))
        new_list+="Sum_switches_of_ParentID=$ppid1 is $summ"$'\n\n'"$row"$'\n'

        tppid=$ppid2
        tpid=$pid2

        summ=0
        i=0
    fi
done

echo "$new_list" > ppid_calculated.txt
cat ppid_calculated.txt

exit 0
