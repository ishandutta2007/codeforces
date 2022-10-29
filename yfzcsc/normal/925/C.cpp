#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100100],c[100100],b[100100],tp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int j=n,nxt;j>=1;j=nxt){
		int nw,ntp=0,mtp=0;
		for(nw=60;nw>=0&&(a[j]>>nw&1)==0;--nw);
		for(nxt=j;nxt>=1&&(a[nxt]>>nw&1);nxt--);
		int ans=0;
		for(int i=1;i<=tp;++i)ans+=b[i]>>nw&1;
		if(j-nxt-1>ans)return puts("No"),0;
		for(int k=nxt+1;k<=j;++k){
			c[++ntp]=a[k],c[++ntp]=b[++mtp];
			while(mtp<tp&&(b[mtp]>>nw&1)==0)c[++ntp]=b[++mtp];
		}
		while(mtp<tp)c[++ntp]=b[++mtp];
		tp=ntp;
		for(int i=1;i<=tp;++i)b[i]=c[i];//,printf("[%lld]",b[i]);;puts("");
	}
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%lld ",b[i]);
}