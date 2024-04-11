#include<iostream>
#include<cstdio>
using namespace std;
double a,b,c,d;
double a_1,a_2,b_1,b_2,a_a,b_a;
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	a_1=3.0*a/10.0; a_2=a-a/250.0*c;
	if (a_1>a_2) a_a=a_1;
	else a_a=a_2;
	b_1=3.0*b/10.0; b_2=b-b/250.0*d;
	if (b_1>b_2) b_a=b_1;
	else b_a=b_2;
	if (a_a>b_a) cout<<"Misha"<<endl;
	if (a_a<b_a) cout<<"Vasya"<<endl;
	if (a_a==b_a) cout<<"Tie"<<endl;
}