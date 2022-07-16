echo "Enter the Number"
read n
y=$n
s=0
k=10 

while [ $n -gt 0 ]
do
r=$((n % k))
i=$((r * r * r))
s=$((s + i))
n=$((n / k ))
done

echo $s
if [ $s == $y ]
then  
echo "$s is an Armstrong number"
else
echo "$s is not an Armstrong number"
fi
#supports only 3 digit numbers :)