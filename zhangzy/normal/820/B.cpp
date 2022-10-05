#include<cstdio>
#include<iostream>
#include<cmath>
#define xxx 100100
#define inf 520233
using namespace std;
int n,ans;
double mi=520233.0,a,each;

int main() 
{
	cin>>n>>a;
	each=(double)180/(double)(n);
	for (int i=1;i<=n-2;i++)
		if (abs(each*(double)i-a)<mi)
		{
			mi=abs(each*(double)i-a);
			ans=i;
		}
	printf("%d %d %d",n,n-1,ans);
}