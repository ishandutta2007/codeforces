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
const int xx=2e5+5;
int T,n,a[xx];
signed main(){
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		int mn=1e9;
		for(int i=1;i<n;i++)mn=min(mn,a[i+1]-a[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i+1]-a[i]==mn)
			{
				cout<<a[i]<<" ";
				for(int j=i+2;j<=n;j++)cout<<a[j]<<" ";
				for(int j=1;j<i;j++)cout<<a[j]<<" ";
				cout<<a[i+1]<<" ";
				puts("");
				break;
			}
		}
	}
	
	return 0;
}