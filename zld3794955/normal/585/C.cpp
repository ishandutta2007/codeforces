#include<bits/stdc++.h>
using namespace std;
const int N=1010;
long long x,y,t[N]={};
char ch[N]={};
int main()
{
	cin>>x>>y;
	if(__gcd(x,y)==1)
	{
		int tot=0;
		while(x && y)
		{
			if(x>y)
			{
				++tot;
				ch[tot]='A';
				t[tot]=x/y;
				x%=y;
			}
			else
			{
				++tot;
				ch[tot]='B';
				t[tot]=y/x;
				y%=x;
			}
		}
		--t[tot];
		for(int i=1;i<=tot;++i)
			cout<<t[i]<<ch[i];
		cout<<endl;
	}
	else
		puts("Impossible");
	return 0;
}