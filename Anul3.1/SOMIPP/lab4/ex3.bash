#? /bin/bash

cat /var/log/Xorg.0.log > full.log
sed -i "s/II/Information/" full.log
sed -i "s/WW/Warning/" full.log
cat full.log
exit 0
