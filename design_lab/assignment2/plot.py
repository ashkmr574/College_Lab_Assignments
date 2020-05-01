from scipy import linspace,sin,pi
from pylab import plot,show,xlabel,ylabel,axhline,axvspan,axvline
print("Enter point range ",end="")
i=input()
p=int(i)
print("Enter interval ",end="")
j=input()
q=int(j)
x=linspace(0,p,p)
plot(x,sin((x*pi*q)/50),'bo')
xlabel("Voltage")
ylabel("Amplitude")
axhline(linewidth=2,color="r")
for pt in x:
	y=(sin((pt*pi*q)/50))
	print(y)
	if y >=0.0:
		axvline(pt,0.5,y+0.5,color='r')
	else:
	    axvline(pt,y+0.5,0.5,color='r')
show()