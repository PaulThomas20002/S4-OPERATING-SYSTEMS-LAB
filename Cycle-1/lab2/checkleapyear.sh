echo "Enter the year "
read a

if [ $((a % 400)) == 0 ]
then
echo "Leap year"
#fi

elif [ $((a % 100)) == 0 ]
then
echo "Not"
#fi

elif [ $((a % 4)) == 0 ]
then
echo "Leap"

else
echo "Not leap"
fi
