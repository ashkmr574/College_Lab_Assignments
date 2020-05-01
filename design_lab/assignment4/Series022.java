/* Name:- Integrated solution
   Author:- Ashish Kumar
   Purpose:- Create a python script for accepting an integer (n) and generate following point series:
             x: n integer points from 0 to (n-1)
			 y: y=x*x
             Design an effective mechanism for plotting these with minimal or nil effort from the user.
*/
/*
Execution Instructions:-
step-1 open cmd and go to the folder where the java file and python file is in saved.
       for example, if file is in Downloads, then cd Downloads.
step-2 run command :- javac Series022.java
step-3 run command :- java Series022

Note:- java and python file should be in same directory.	   
*/
import java.io.*;                                                                    //header file import
class Series022
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));       
		FileWriter x=null;															//Filewriter object declaration
		int n,i,last;																	//variable declaration
		while(true)                                                                 // while loop for continued input if invalid input is given
		{
			try                                                                      // Exception handling, Try block begins
			{
				System.out.print(" Enter the Range(N)(greater than zero): ");        //Ask user for input
				n=Integer.parseInt(br.readLine());                                   //taking input and converting into integer
				if(n ==0)                                                            // if value is less than zero ask user to input a positive number 
				{
					System.out.println("wWe cannot plot graph for 0 input points..Try again");  //Appropriate error message printing
					continue;
				}
				x=new FileWriter("series.txt");				                         // filewriter object creation
				if(n<0)                                                              // if value of n is negative then accordingly variables are initialised
				{
					i=n+1;
					last=1;
				}
				else
				{
					i=0;
					last=n;                                                          // appropriate starting and ending point is initialised
				}
				for(;i<last;i++)                                                     // loop for generating series
				{
					x.write(String.valueOf(i));										// writing value of x in file
					x.write(',');                
					x.write(String.valueOf(i*i));                                   // writing value of x*x in file
					x.write('\n');
				}
				x.close();                                                            // closing the file
				Runtime.getRuntime().exec("python integrated022.py");                 // running python script for curve plotting
				break;
			}
			catch(Exception e)                                                           // Exception handling, catch block
			{
				System.out.println("Invalid Input..The limit should be between 1 to N"); // Error massage printing
			}
		}
	}
}