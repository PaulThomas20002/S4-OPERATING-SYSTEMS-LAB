for n in {1..5};
do
echo $n
done

echo "Read the number"
read n
for((i=1; i<=n; i++))
do
echo "$i"
done
