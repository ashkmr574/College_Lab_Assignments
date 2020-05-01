# sort the file a/c to roll number

echo "enter file name"
read s;
sort -t "|" -r -k 2 $s > temp2
