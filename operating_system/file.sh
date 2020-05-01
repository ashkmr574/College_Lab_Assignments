#file permission and file count
clear
echo "Enter password"
stty -echo
read password
stty echo
v="ashish"
f=1
if [ $password = $v ] ; then
while [ $f -gt 0 ]
do
echo "1.check permission of a file"
echo "2.check number of files in current directory"
echo "3.count number of connected users"
echo "4.exit"
echo "Enter your choice"
read n;
case $n in
1)echo "Enter the existing file name"
read s
if [ -r $s ] ; then 
echo "you have read permission"
else
echo "you do not have read permission"
fi
if [ -w $s ] ; then
echo "you have write permission"
else
echo "you do not have write permission"
fi
if [ -x $s ] ; then
echo "you have execute permission"
else
echo "you do not have execute permission"
fi
echo ""
;;
2)echo -n "number of files/folders : "
ls -l | wc -l
;;
3)echo -n "number of connected users : "
who | wc -l
;;
4) f=0
;;
*)echo "invalid input"
;;
esac
done
else
echo "invalid password"
fi
