read -p 'Enter the number: ' n
temp=$n
num=0
while [ $n -ne 0 ]
do
num=$(expr $num \* 10)
k=$(expr $n % 10)
num=$(expr $num + $k)
n=$(expr $n / 10)
done

echo "The reverse of $temp is $num"
