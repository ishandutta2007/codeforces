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
int T;
const int xx=108;
int a[xx];
int main(){
//	for(int i=1;i<=1000000;i++)
//	{
//		if(int(sqrt(i))==sqrt(i))vis[i]=1;
//	}
	T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int vis=0;
		for(int i=1;i<=n;i++)
		{
			if((int)sqrt(a[i])!=sqrt(a[i]))
			{
//				cout<<i<<"\n";
			puts("YES");
				vis=1;
				break;
			}
		}
		if(!vis)
		{
				puts("NO");
		}
	}
	return 0;
}