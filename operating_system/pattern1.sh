# pattern1
#1
#23
#456
#78910
echo "enter number of rows"
read n
k=1
for((i=0;i<n;i++))
do
for((j=0;j<=i;j++))
do
echo -n $k
echo -n " "
k=`expr $k + 1`
done
echo ""
done

