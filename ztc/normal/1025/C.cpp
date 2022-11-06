#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n=0,i,b[100002],maxx=0,maxxx;
bool a[100002];
char c;
int main()
{
	c=getchar();
	while(c!='\n')
	{
		n+=1;
		a[n]=(c=='w');
		b[n]=b[n-1]*(a[n-1]^a[n])+1;
		maxx=max(maxx,b[n]);
		if(b[n]==n)maxxx=n;
		c=getchar();
	}
	if(a[n]^a[1]&&b[n]!=n)maxx=max(maxx,maxxx+b[n]);
	printf("%d",maxx);
	return 0;
}