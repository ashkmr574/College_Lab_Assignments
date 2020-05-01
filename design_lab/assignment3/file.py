import random                              #import random module for random number generator
f=open("wordlist.txt")                     #open file wordlist.txt, by default it will open in read mode
r=f.read().split()                         #reading from file and spliting words, storing in list
i=1                                        #initilize loop counter
print("%%%"+"-"*25+"%%%")
print("Press enter to start the process")  #message printing
print("You can enter N to stop")
while(input()!='N'):
	q=random.randrange(0,len(r),1)         #generating random number from range 0 to length of list
	print("Pass#%d> %d: %s" %(i,q+1,r[q])) #printing desired result in the format mentioned
	i=i+1                                  #incrementing loop counter
f.close()                                  #close the file