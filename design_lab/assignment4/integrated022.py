''' Name:- Integrated solution
   Author:- Ashish Kumar
   Purpose:- Create a python script for accepting an integer (n) and generate following point series:
             x: n integer points from 0 to (n-1)
			 y: y=x*x
             Design an effective mechanism for plotting these with minimal or nil effort from the user. '''
from scipy import *                                                   # scipy package is imported
from pylab import *                                                   # pylab package is imported
a,b=loadtxt('series.txt',unpack=True, delimiter=',')                  # reading from file and storing in a and b lists                     
plot(a,b,'o')                                                         # plotting the graph 
plot(a,b,'r')                                                         # adding red colour to graph
show()                                                                # showing the graph	