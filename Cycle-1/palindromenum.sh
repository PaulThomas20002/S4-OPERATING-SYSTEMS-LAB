echo "Enter the number"
read n
m=$n
sum=0
p=0

while [ $n != 0 ]
do
p=$((n%10))
#echo $p
sum=$((sum*10+p))
#echo $sum
n=$((n/10))
done
#echo $sum

if [ $sum == $m ]
then
echo "Palindrome"
else
echo "Not Palindrome"
fi
