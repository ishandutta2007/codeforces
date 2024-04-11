#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define db double
#define ll long long
using namespace std;

int n,m,a,b,c,d,time;

int main()
{
	int i,j;
	cin>>n>>m>>a>>b>>c>>d;
	time=(20-n)*60-m;
	time=max(0,time);
	if(time==0)
	{
		printf("%.10lf",(db)((a+d-1)/d*c*0.8));
		return 0;
	}
	printf("%.10lf",min((db)((a+d-1)/d*c),(a+time*b+d-1)/d*c*0.8));
}