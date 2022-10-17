#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
signed main(){
	int T=read();
	while(T--)
	{
		int n,m,d;
		n=read();
		m=read();
		d=read();
		if(d==0)
		{
			if(n==m)
			{
				puts("YES");
			}
			else puts("NO");
			continue;
		}
		else 
		{
			int s=abs(n-m);
			if(ceil(1.0*s/min(n,m))<=d)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}