#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=100;
int n,k;
int a[maxn];
ll Pow10[maxn];
int ans[maxn];
int main()
{
	T=read();
	Pow10[0]=1;for(int i=1;i<=10;i++)Pow10[i]=Pow10[i-1]*10;
	for(int t=1;t<=T;t++)
	{
		n=read();k=read()+1;
		generate_n(a+1,n,read);a[n+1]=a[n]+10;
		int up=0;
		for(int i=1;i<=n;i++)
		{
			if(Pow10[a[i+1]-a[i]]-1>k)
			{
				up=a[i];
				while(k){ans[up]=k%10;k/=10;up++;}
				up--;
				break;
			}
			else
			{
				k-=Pow10[a[i+1]-a[i]]-1;
				for(int j=a[i];j<a[i+1];j++)ans[j]=9;
				up=a[i+1]-1;
			}
		}
		for(int i=up;i>=0;i--)printf("%d",ans[i]);printf("\n");
	}
	return 0;
}