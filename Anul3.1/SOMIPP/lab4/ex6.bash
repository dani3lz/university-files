#!/bin/bash

i=0
users=`cut -d ':' -f1,3 < /etc/passwd | sort -t: -k 2 -n | cut -d ':' -f1`
uids=`cut -d ':' -f3 < /etc/passwd | sort -n`
for user in $users
do
    echo -e "\nUtilizator:\t$user"
    j=0
    for uid in $uids
    do
        if [[ $i -eq $j ]]
        then
        echo -e "UID:\t\t$uid"
        break
        fi
        j=$((j+1))
    done
    i=$((i+1))
done
exit 0


