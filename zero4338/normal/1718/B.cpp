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
const int maxn=105;
int n,c[maxn];
ll fib[maxn];
int siz[maxn],to;
bool solve(int id)
{
	static int osiz[maxn];
	memcpy(osiz,siz,sizeof(int)*(to+1));
	int now=c[id];
	for(int i=to;i>=0;i--)
		if(fib[i]<=now)
		{
			now-=fib[i];
			siz[i]--;
		}
	now=c[id]-1;
	for(int i=to;i>=2;i--)
		if(fib[i]<=now)
		{
			now-=fib[i];
			siz[i]++;
		}
	bool flag=true;
	if(now){flag=false;siz[1]++;now=0;}
	if(flag)for(int i=1;i<=to;i++)if(siz[i]>1){flag=false;break;}
	memcpy(siz,osiz,sizeof(int)*(to+1));
	return flag;
}
int main()
{
	fib[0]=fib[1]=1;
	for(int i=2;i<=61;i++)fib[i]=fib[i-1]+fib[i-2];
	T=read();
	while(T--)
	{
		generate_n(c,n=read(),read);
		ll sum=accumulate(c,c+n,0ll);
		to=0;
		for(int i=0;;i++)
		{
			if(fib[i+2]-1>sum)break;
			to=i;
		}
		if(fib[to+2]-1!=sum){puts("NO");continue;}
		bool flag=true;
		memset(siz,0,sizeof(int)*(to+1));
		for(int i=0;i<n;i++)
		{
			int now=c[i];
			bool last=0;
			for(int j=to;j>=0;j--)
				if(fib[j]<=now&&!last)
				{
					siz[j]++;
					now-=fib[j];
					last=true;
				}
				else last=false;
			if(now){flag=false;break;}
		}
		if(!flag){puts("NO");continue;}
		flag=false;
		for(int i=0;i<n;i++)if(solve(i)){flag=true;break;}
		puts(flag?"YES":"NO");
	}
	return 0;
}