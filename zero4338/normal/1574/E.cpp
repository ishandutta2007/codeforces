#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
const int mod=998244353;
int n,m,k;
bool deb;
map<pair<int,int>,int>c;
int cwc,cwr,clc,clr;
bool iwr[maxn],iwc[maxn],ilc[maxn],ilr[maxn];
int cntr[maxn][2],cntc[maxn][2],cntx[2];
void updatec(int x,bool col,int del)
{
	cntc[x][col]+=del;
	if(cntc[x][0]&&cntc[x][1]){if(!iwc[x]){iwc[x]=1;cwc++;}}
	else{if(iwc[x]){iwc[x]=0;cwc--;}}
	if(cntc[x][0]||cntc[x][1]){if(!ilc[x]){ilc[x]=1;clc++;}}
	else{if(ilc[x]){ilc[x]=0;clc--;}}
}
void updater(int x,bool col,int del)
{
	cntr[x][col]+=del;
	if(cntr[x][0]&&cntr[x][1]){if(!iwr[x]){iwr[x]=1;cwr++;}}
	else{if(iwr[x]){iwr[x]=0;cwr--;}}
	if(cntr[x][0]||cntr[x][1]){if(!ilr[x]){ilr[x]=1;clr++;}}
	else{if(ilr[x]){ilr[x]=0;clr--;}}
}
void change(int x,int y,int t)
{
	bool nc=(x+y)&1;
	if(c.count({x,y}))
	{
		bool v=c[{x,y}]^nc;cntx[v]--;
		updater(x,v,-1);updatec(y,v,-1);c.erase({x,y});
	}
	if(t==-1)return;
	bool col=nc^t;
	cntx[col]++;
	updater(x,col,1);updatec(y,col,1);
	c[{x,y}]=t;
}
int pow2[maxn];
int main()
{
	n=read();m=read();k=read();
	pow2[0]=1;for(int i=1;i<=max(n,m);i++)pow2[i]=2*pow2[i-1]%mod;
	while(k--)
	{
		int x=read(),y=read(),t=read();
		change(x,y,t);
		if(cwc&&cwr)printf("0\n");
		else if(cwc)printf("%d\n",pow2[n-clr]);
		else if(cwr)printf("%d\n",pow2[m-clc]);
		else
		{
			if(!clr&&!clc)printf("%d\n",(pow2[n]+pow2[m]-2)%mod);
			else printf("%d\n",(pow2[n-clr]+pow2[m-clc]-(!cntx[0]||!cntx[1]))%mod);
		}
	}
	return 0;
}