##build a calculator
echo "Enter the number 1 :"
read a
echo "Enter the number 2 : "
read b
echo "Menu"
echo "1.Add"
echo "2.Sub"
echo "3.Mult"
echo "4.Div"
read n
case $n in
1)
echo "a + b = " $((a+b));;
2)
echo "a - b = " $((a-b));;
3)
echo "a * b = " $((a*b));;
4)
echo "a / b = " $((a/b));;
*)
echo "Invalid Input"
esac
