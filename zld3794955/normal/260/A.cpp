#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100100;
int a,b,n;
char ans[N]={};
int main()
{	
	cin>>a>>b>>n;
	sprintf(ans+1,"%d",a);
	int l=strlen(ans+1),l2=l;
	for(int i=1;i<=n;++i)
		for(int d=0;d<=9;++d)
			if((a*10+d)%b==0)
			{
				ans[++l2]=d+'0';
				a=(a*10+d)%b;
				break;
			}
	if(l2!=l+n)
		puts("-1");
	else
		puts(ans+1);
	return 0;
}