date 
sleep 3
mkdir root
date 
sleep 3
mkdir home
date
sleep 3
ls / -ltr > root/root.txt
date
sleep 3
ls ~ -ltr sort > home/home.txt
cat root/root.txt
cat home/home.txt
ls root
ls home
