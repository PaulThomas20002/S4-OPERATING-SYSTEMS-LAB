echo "Enter the number 1"
read a
echo "Enter the number 2"
read b

temp=0

echo "Number 1 = $a"
echo "Number 2 = $b"
echo -e
temp=$b
b=$a
a=$temp

echo "Number 1 = $a"
echo "Number 2 = $b"
