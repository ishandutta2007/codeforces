#include<bits/stdc++.h>
using namespace std;
const double P=acos(-1);
double n,r;
int main()
{
	cin>>n>>r;
	printf("%.7lf",r*sin(P/n)/(1-sin(P/n))); 
	return 0;
}