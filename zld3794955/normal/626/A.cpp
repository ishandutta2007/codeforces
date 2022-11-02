#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=220;
char ch[N]={};
int n;
int main()
{	
	cin>>n>>(ch+1);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int x=0,y=0;
		for(int j=i;j<=n;++j)
		{
			if(ch[j]=='U')
				++y;
			if(ch[j]=='D')
				--y;
			if(ch[j]=='L')
				--x;
			if(ch[j]=='R')
				++x;
			if(x==0 && y==0)
				++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}