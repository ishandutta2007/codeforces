#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int p=5000005;
long long g[p];
bool heshu[p]; int n,T,k,r,que[p],m;
inline int read()// 
{
	int a=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	a=a*10+ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a;
}
inline void write(long long a)
{
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}int mod=1000000007,ans;
int main(){
	for(int i=2;i<p;i++){
	    if(!heshu[i]){que[++r]=i; }
        for(int j=1;j<=r&&i<=(p-1)/que[j];j++){
            heshu[k=i*que[j]]=1;
            if (i%que[j]==0){ break;}
        }
    }
    int t=read(),l=read(),r=read();
    for(int i=1;i<=r;i++){g[i]=((long long)i*(i-1))>>1;if(!heshu[i])continue;int zs=0,meiju=sqrt(i);for(int j=1;que[j]<=meiju;j++)if(i%que[j]==0){
		g[i]=min(g[i],g[i/que[j]]+(((long long)i*(que[j]-1))>>1)); zs++; if(zs==2||g[i]<=(i*(que[j+1]-1))>>1)break;
	}}
	for(int i=l,tt;i<=r;i++){g[i]%=mod;
		if(i==l)tt=1; else tt=(long long)tt*t%mod;
		ans=(ans+tt*g[i])%mod;
	}
	write(ans);
}