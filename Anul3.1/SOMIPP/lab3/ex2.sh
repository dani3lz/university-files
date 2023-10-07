#! /bin/bash
clear
echo "Introduceti trei numere intregi:"
read int1 int2 int3

if test $int1 -gt $int2 && test $int1 -gt $int3
then
echo "Primul numar este cel mai mare"
elif test $int2 -gt $int1 && test $int2 -gt $int3
then
echo "Al doilea numar este cel mai mare"
else
echo "Al treilea numar este cel mai mare"
fi



