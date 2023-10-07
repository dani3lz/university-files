#! /bin/bash
clear
echo "Introduceti caractere:"
str=""
while true
do
read ch
str="$str$ch"
if test $ch = "q"
then
break
fi
done
echo "$str"
