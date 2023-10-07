#!/bin/bash

grep -e '[[:alnum:].]\+\@[[:alnum:]]\+[.][[:alpha:]]\+' -rohsI /etc/ | sort | uniq -i > emails.lst

nr=`cat emails.lst | wc -l`
i=1
while [[ $i < $nr ]]
do
    sed -i $i' s/$/,/' emails.lst
    i=$((i+1))
done
cat emails.lst
exit 0


