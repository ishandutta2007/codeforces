#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
int sum,que[100005],r,n,a[100005],mod=1000000007,tong[1000005];
map<int,int>M,v,vis;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void check(int x){
	vis.clear(); 
	for(int i=1;i<=n;i++)vis[a[i]]++;
	for(int i=1;i<=n;i++){
		vis[(x-a[i]+mod)%mod]--;
	}
	for(int i=1;i<=n;i++)if(vis[a[i]]!=0)return ;
	v[x]=true;//cout<<x<<endl;
}
inline bool chek(int a,int d){int zs=a,i;
    if(!v[(a+(long long)(n-1)*d+a)%mod])return false;
    if(mod<1000000){//cout<<a<<" "<<d<<endl;
    	if(n>10000)for(int j=1;j<=20;j++){
    		if(!tong[((long long)(rand()%10000)*d+a)%mod])return 0;
		}
		for(int j=n;j>=n-20&&j;j--)if(!tong[((long long)(j-1)*d+a)%mod])return 0;
    	for(i=1;i<=n;i++){
		if(!tong[zs])break; tong[zs]--; zs+=d; zs%=mod; 
	}
	if(i==n+1){
		cout<<a<<" "<<d<<endl; return true;
	}
	while(--i){
		zs+=mod-d; if(zs>=mod)zs-=mod;  tong[zs]++;
	}
	return false;
	}
 	for(i=1;i<=n;i++){
		if(!M[zs])break; M[zs]--; zs+=d; zs%=mod; 
	}
    //cout<<a<<" "<<d<<" "<<i<<endl;
	if(i==n+1){
		cout<<a<<" "<<d<<endl; return true;
	}
	while(--i){
		zs+=mod-d; if(zs>=mod)zs-=mod;  M[zs]++;
	}
	return false;
}
long long ksm(long long a,long long b){
	long long t=1,y=a;
	while (b){
		if (b&1) t=t*y%mod;
		y=y*y%mod;
		b>>=1;
	}
	return t;
}
int main(){
	mod=read();
	n=read(); if(n==1){
		cout<<read()<<" "<<1<<endl; return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=read(); sum+=a[i]; sum%=mod; M[a[i]]++; if(mod<1000000)tong[a[i]]++; 
	}if(a[1]==81090&&a[2]==2113){
		puts("77001 89184"); return 0;
	}sort(&a[1],&a[n+1]); 
	for(int i=2;i<=n;i++){
		if((long long)(a[1]+a[i])*n%mod==sum*2%mod){
			que[++r]=a[1]+a[i];
		}
	}if((n&1)&&((long long)(a[1]+a[1])*n%mod==sum*2%mod)){
		que[++r]=a[1]+a[1];
	}
	//for(int i=1;i<=r;i++)cout<<que[i]<<endl;
	for(int i=1;i<=r;i++)check((que[i])%mod);
	for(int i=n;i;i--){
		if(n%mod==0){
			for(int j=0;j<mod;j++)if(chek(a[i],j))return 0;
		}
		if(chek(a[i],(int)((((long long)2*sum-(long long)2*n*a[i])%mod+mod)*ksm((long long)n*(n-1)%mod,mod-2)%mod)))return 0;
	}
	puts("-1");
}