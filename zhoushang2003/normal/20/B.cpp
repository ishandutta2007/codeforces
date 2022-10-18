#include<bits/stdc++.h>
using namespace std;
double a,b,c,p,A,B;
int main()
{
	cin>>a>>b>>c;
	if(a==0)
		if(b==0)
			if(c==0)
				cout<<-1;
			else
				cout<<0;
		else
			printf("1\n%.5lf",-c/b);
	else
	{
		p=b*b-4*a*c;
		if(p<0)
		{
			cout<<0;
			return 0;
		}
		A=(-b+sqrt(p))/2/a,B=(-b-sqrt(p))/2/a;
		if(A==B)
			printf("1\n%.5lf",A);
		else
			printf("2\n%.5lf\n%.5lf",min(A,B),max(A,B));
	}
	return 0;
}