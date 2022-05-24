echo "Enter How many"
read n
echo "0"
echo "1"

first=0
second=1

for((i=0;i<n-2;i++))
do
third=$((second+first))
echo "$third"
first=$second
second=$third
done
