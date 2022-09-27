gcc ex3.c -o ex3 
./ex3 3 &
echo "With n = 3"
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
echo "\n\n"
echo "With n = 5"
./ex3 5 &
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$