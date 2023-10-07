#! /bin/bash
clear
echo "Introduceti primul sir:"
read str1
echo "Introduceti al doiela sir"
read str2
if test "$str1" = "$str2"
then
echo "Sirurile sunt egale"
else
echo "Sirurile nu sunt egale"
fi
