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
const int xx=1e6+5;
int vis[xx];
//int table[]={2,3,8,9,32,33,128,129,512,513,2048,2049,8192,8193,32768,32769,131072,131073,524288,52489,209952,209953}
signed main(){
//	freopen("a.out","w",stdout);
//	vis[1]=0;//0 
//	for(int i=2;i<=1000000;i++)
//	{
//		for(int j=2;j*j<=i;j++)
//		{
//			if(i%j==0)
//			{
//				vis[i]|=!(vis[i-j]);
//				vis[i]|=!(vis[i-i/j]);
//			}
//		}
//		if(vis[i]==vis[i-1])cout<<i<<",";
////		if(vis[i]&&(i&3!=1))cout<<i<<" ";
////		cout<<i<<" "<<vis[i]<<"\n";
//	}
	int T=read();
	while(T--)
	{
		int a=read();
		ll now=2;
		int s=0;
		while(now<=a)
		{
			if(now<=a)s++;
			if(now+1<=a)s++;
			now*=4;
		}
		int op=(a+s+1)&1;
//		if(a<=10000)op=vis[a];
//		else if(a%3==1)op=0;
		if(op==0)puts("Bob");
		else puts("Alice");
	}
//	cout<<vis[a]<<'\n';
	return 0;
}