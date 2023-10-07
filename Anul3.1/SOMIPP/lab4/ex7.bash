#!/bin/bash

man bash | grep -o '[[:alpha:]]\{4,\}' | uniq -c | sort -r | head -4
exit 0
