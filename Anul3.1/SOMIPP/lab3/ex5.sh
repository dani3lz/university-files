#! /bin/bash
clear
while true
do
    PS3="Numarul: "
    select opt in "Start nano" "Start xed" "Start browser" "Exit"
    do
        case $opt in
        "Start nano")
        exec nano
        ;;
        "Start xed")
        exec xed
        ;;
        "Start browser")
        exec firefox
        ;;
        "Exit")
        break 2
        ;;
        *)
        echo "Nu exista asa nr: $REPLY"
        ;;
        esac
    done
done
