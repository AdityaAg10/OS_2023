#! /bin/bash

echo "Enter first numeber"
read one
echo "Enter the second number"
read two
if [ $one -lt $two ]
then
echo "First number is smaller"
else
echo "Second number is smaller"
fi
