#shell
clear
f=1
while [ $f -gt 0 ]
do
echo "1.Display students in a given stream"
echo "2.Display students not in computer science"
echo "3.Display failed students"
echo "4.count number of failed students"
echo "5.count number of students in computer science or electronics"
echo "6.count number of students having surname chaudhari or choudhary"
echo "7.find string which is 4 character long and starts with b"
echo "8.find students whose roll number starts with 1"
echo "9.find students whose stipend is between 7000 and 8999"
echo "10.stop"
read n
case $n in
1) echo "Enter stream name"
   read name
   grep -i $name stu
;;
2) grep -i -v "computerscience" stu
;;
3)awk -F "|" '$5 =="F" { print }' stu
;;
4) awk -F "|" '$5=="F" { print } ' stu > tt
 cat < tt | wc -l
;;
5) grep -i "computerscience" stu > tt1
   grep -i  "electronics" stu >> tt1
   cat < tt1 | wc -l
;;
6)awk -F "|" '$3 == "chaudhari" { print } ' stu > tl
  awk -F "|" '$3=="choudhary" {print} ' stu >>tl
 cat < tl | wc -l
;;
7)awk -F "|" 'length($2) ==4 {print $2} ' stu > ttt
  awk -F "|" 'length($3) ==4 {print $3} ' stu >>ttt
  awk -F "|" 'length($4)==4 {print $4}' stu >> ttt
  grep -i -E "^b[a-z][A-Z]" ttt
;;
8) grep -E "^1[0-9]" stu
;;
9) awk -F "|" '$6 >= 7000 {print }' stu > tpp
   awk -F "|" '$6 < 9000 {print} ' tpp
;;
10) f=0
;;
*) echo "wrong input"
esac
done
