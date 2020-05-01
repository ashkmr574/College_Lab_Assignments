# shell program
grep -i 'majumdar' majumdar > ashisha
awk -F "|" '{print $1,$2}' ashisha
echo ""
awk -F "|" '$3 < 50000 {print $3}' majumdar > tempo5
awk -F "|" '$3 > 60000 {print $3}' majumdar >> tempo5
#cut -d "|" -f3 majumdar>hhelo
#grep -v -c -E "^5[0-9][0-9][0-9][0-9]|^6[0][0][0][0]" hhelo
cat < tempo5 | wc -l
echo ""
grep -i "^[AEIOU]" majumdar>tempo
cut -d "|" -f4 tempo


