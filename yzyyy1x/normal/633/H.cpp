#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
const int N=30010;
void read(int &x)
{
	char c=getchar();x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
}
void write(long long x){if(x>=10)write(x/10);putchar(x%10+'0');}
struct gg{
	int a,id,b;
}mp[N];
int Q,n,m,F[N];
bool cmp(gg x,gg y)
{return x.a<y.a;}
int main()
{
	register int i,j;
	read(n),read(m);
	F[1]=F[2]=1%m;
	for(i=3;i<=n;i++)F[i]=(F[i-1]+F[i-2])%m;
	for(i=1;i<=n;i++)
	{
		read(mp[i].a);
		mp[i].id=i;
		mp[i].b=mp[i].a%m;
	}
	sort(mp+1,mp+n+1,cmp);
	read(Q);
	int l,r,las,cnt;long long ans;
	for(i=1;i<=Q;i++)
	{
		las=-1,ans=0,cnt=0;read(l),read(r);
		for(j=1;j<=n;j++)
		{
			if(mp[j].id>=l&&mp[j].id<=r)
			{
				if(mp[j].a!=las)ans+=mp[j].b*F[++cnt],las=mp[j].a;
			}
		}
		write(ans%m),puts("");
	}	
}