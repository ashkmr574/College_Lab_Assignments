# unique
echo "ENter a file name"
read s;
sort -t "|" -k 1 $s > file1
cut -d "|" -f1 file1 > file2
uniq -u file2 > file3


