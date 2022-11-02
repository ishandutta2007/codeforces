#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	printf("%.12f\n",a*d/(a*d+c*b-a*c));
}