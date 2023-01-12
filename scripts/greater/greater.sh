echo "Enter the numbers"
read n1 n2 n3

if [[ $n1 -ge "$n2" ]] && [[ $n1 -ge $n3 ]] 
then
echo $n1

elif [[ $n2 -ge $n3 ]] && [[ $n2 -ge $n1 ]] 
then
echo $n2

else
echo $n3
fi
