#!/bin/bash
echo "How many windows do you want?"
read times
gcc subscriber.c -o subscriber
gcc publisher.c -o publisher
for i in `seq 1 $times`
do
    gnome-terminal -- ./subscriber
done
./publisher