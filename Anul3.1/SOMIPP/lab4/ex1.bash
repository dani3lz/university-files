#!/bin/bash

grep -rs 'ACPI' /var/log/ > errors.log
cat errors.log
exit 0
