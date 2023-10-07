#! /bin/bash
clear
echo "Introduceti numere intregi:"
nr=0
while true
do
read int
nr=$((nr+1))
if test $((int % 2)) -eq 0
then
echo "Au fost introduse $nr numere"
break
fi
done
