#include <stdio.h>
#include <math.h>
typedef double (*DfD) (double); //This allows the user to declare any function they would like to integrate(It will be used later)
double function(double x);//first function prototype of the polynomial of 1/(y-x)
double f(float L1,float L2);//second function prototype for evaluating an integral using trapezoidal method(part 1)
double simpson(DfD f,double x0, double x1, int n);/*third function for part 2 of the assignment used for evaluating the root using
                                                                                                                            bisection with reference to the real value obtained from the trapezidal method*/

int main()//start of main
{
	 float L1=1,L2,L,middle=0,tolerance=1,integral,upper,lower;/*lower and upper are arbitrary numbers
                                                            	                                                                                         used for the bisection method*/
	 lower=0;
	 upper=1;
	 printf("please provide a value for L2 that ranges between 0.5 and 0.99\n");
	 fflush(stdout);
	 scanf("%f",&L2);
	for(L=L2;L>0.5;L-=0.01)
	{
	  printf("L2=%.4f%%L1\t",L);
	  printf("Ln(L2/L1)=%f\t",f(L1,L));
	  integral=-1*f(L1,L2);
		for(;fabs(tolerance)>=0.00001;)//using the bisection method to evluate the root of the polynomial
		{
		  middle=(lower+upper)/2;
			if (((simpson(function,middle,0.005,10000)-integral)*(simpson(function,upper,0.005,10000)-integral))>0)
			{
			 upper=middle;
			}
			else
			{
			 lower=middle;
			}
			tolerance=(simpson(function,middle,0.005,1000000))-integral;
    }
		printf("x1=%f\n",middle);
	}
	 return 0;
}//end of main
double function(double x)//first function of the polynomial of 1/(y-x)
	 {
   double f;
   f=8.38-31.976*x+39.911*x*x-13.542*x*x*x; //this polynomial is equal to 1/(y-x)
	 return f;
	}


double f(float L1,float L2)//second function  for evaluating an integral using trapezoidal method
  {
	 float sum=0,sigma,xi,p,xii;
	 int n;
	 sigma=(L2-L1)/pow(10,4);
	 for(n=0;n<pow(10,4);n++)
		{
		 xi=L1+n*sigma;
			xii=L1+(n+1)*sigma;
		 p=1/(xi)+1/(xii);
		 sum=sum+0.5*p*sigma;
		}
	 return sum;
  }

double simpson(DfD f,double x0, double x1, int n)//third function of simpson's method for evauating integrals
	{
		double x,sum, dx =(x0-x1)/n;
		sum=f(x1)+f(x0);
		for(x =x1; x<= x0-dx;x+=dx)
		sum+=2.0*f(x+dx) +
		4.0*f(x+ dx/2);
		return sum*dx/ 6.0;
  }
