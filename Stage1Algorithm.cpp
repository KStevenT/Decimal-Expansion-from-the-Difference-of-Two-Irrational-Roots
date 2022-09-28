//STAGE 1

#include <iostream>
#include <mpreal.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using mpfr::mpreal;

struct ab {long a,b; mpreal diff; string diffstr;};

#define digits 20
#define digitstocompare 14

bool fcompare(ab x,ab y)
{
    if (x.diff > y.diff)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool fcomparestr(ab x, ab y)
{
for(long i=0;i<x.diffstr.length();i++)
	{
		if(x.diffstr[i]>y.diffstr[i]) return true;
		else if(x.diffstr[i] < y.diffstr[i]) return false;
	}
return false;
}

bool isSquareFree (long m)
{
    long n,sum1=0;
    for (n=2;n<=m/2;n++)
	{
		sum1=0;
		while (m % n == 0)
		{
			m/=n;
			sum1++;
			if (sum1==2)
			{return false;}
		}
	}
	return true;
}

long getSquareFreeFactor(long m)
{
 long d;
 long factors=1;
 for(d=2;d<=m;d++){
   long n=0;
   while(m%d==0){
     m=m/d;
     n++;
   }
   if(n%2==1) factors = factors*d;
 }
 return factors;
}

long isSquare(long m){
  long d;
  for(d=2;d<=m;d++){
    long n=0;
    while(m%d==0){
      m=m/d;
      n++;
    }
    if(n%2==1) return 0;
  }
  return 1;
}

int main ()
{
    mpreal::set_default_prec(mpfr::digits2bits(digits));
    long i,j;
    string hasil,hasil2;
    mpreal b,c,d,sqr1,sqr2,fractPart,intPart,fractPart2,intPart2,fractPart3,intPart3,p;
    vector<ab> ablist;
    ab e;
    long a = 10000;
    for (i=0;i<a;i++)
    {
        //if (isSquareFree(i+1)==false)
        if (isSquare(i+1)==1)
        {
            continue;
        }
        else{
        for (j=0;j<100;j++)
        {
            //if(isSquareFree(j+1)==false)
            if (isSquare(j+1)==1)
            {
                continue;
            }
           else if ((getSquareFreeFactor(i+1))==(getSquareFreeFactor(j+1)))
           {
               continue;
           }
           else
           {
               sqr1=i+1;
               sqr1=sqrt(sqr1);
               sqr2=j+1;
               sqr2=sqrt(sqr2);
                e.a = i+1;
                e.b = j+1;
                e.diff = modf((sqr1 - sqr2),intPart);
                e.diffstr=e.diff.toString().substr(0,digitstocompare+2);
               ablist.push_back(e);
            }
               }
            }
    }

cout << "Sorting..."<<endl;
    sort (ablist.begin(),ablist.end(),fcomparestr);
    long count=0;
    ofstream f;
    f.open("result53.txt");

    for (i=0;i<ablist.size()-1;i++)
    {
               if(ablist[i].diffstr.compare(ablist[i+1].diffstr)==0)
        {
            count++;
            f<< ablist[i].diffstr  << " A= " << (ablist[i]).a << " A+1= " << (ablist[i+1]).a << " B= "<< (ablist[i]).b << " B+1= "<< (ablist[i+1]).b <<endl;
        }
    }

    cout<<"total number of combinations: " << ablist.size() << endl;
    cout<<"total count of collisions: " << count << endl;
    f.close();
    return 0;}










