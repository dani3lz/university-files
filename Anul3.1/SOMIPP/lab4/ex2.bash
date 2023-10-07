#!/bin/bash

grep -r ".log" /var/log/ | wc -l
exit 0

