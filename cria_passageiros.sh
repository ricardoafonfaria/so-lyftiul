#!/bin/bash
cat /etc/passwd | grep "^a[2-9]" | awk -F '[:,]' '{print $1 ":" $5 ":::" $1 "@iscte-iul.pt:"}' | sed "s/^a//g" > passageiros.txt
echo "Passageiros criados."
