#to sort an array
clear
echo "ENTER NO OF TERMS"
read n
echo "enter elements one by one"
for((i=0;i<n;i++))
do
read a[$i]
done
echo "entered array is\n"
for((i=0;i<n;i++))
do
echo ${a[$i]}
done
for((i=0;i<n;i++))
do
for((j=0;j<$n-1;j++))
do
if [ ${a[$j]} -gt ${a[$j+1]} ]; then
temp=${a[$j]}
a[$j]=${a[$j+1]}
a[$j+1]=$temp
fi
done
done
echo "sorted array is\n"
for((i=0;i<n;i++))
do
echo ${a[$i]}
done


