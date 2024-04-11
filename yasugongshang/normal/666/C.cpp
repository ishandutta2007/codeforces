#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline long long read(){
	long long x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const long long N=100005,mod=1000000007;
long long ans[N],ni[N],ycl[N],fac[N],op[N],q[N],m,dq,dp[N];
char ch[N];
vector<long long> v[N];
inline long long c(long long a,long long b){
	return fac[a]*ni[b]%mod*ni[a-b]%mod;
}
inline long long ksm(long long a,long long b){
	long long t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
int main(){
	m=read();
	fac[0]=ni[0]=ycl[0]=1;
	for(long long i=1;i<N;i++){
		fac[i]=fac[i-1]*i%mod; ni[i]=ksm(fac[i],mod-2); ycl[i]=ycl[i-1]*25%mod;
	}
	scanf("%s",&ch); dq=strlen(ch);
	for(long long i=1;i<=m;i++){
		op[i]=read(); 
		if(op[i]==1){
			scanf("%s",&ch);
			dq=strlen(ch);
		}else{
			q[i]=read(); v[dq].push_back(i); 
		}
	}
	for(long long i=1;i<=100000;i++)if(v[i].size()){
		dp[i-1]=0;
		for(long long j=i;j<=100000;j++){
			dp[j]=((long long)dp[j-1]*26+(long long)ycl[j-i]*c(j-1,i-1))%mod;
		}
		for(long long j=0;j<v[i].size();j++){
			if(q[v[i][j]]>=i)ans[v[i][j]]=dp[q[v[i][j]]];
		}
	}
	for(long long i=1;i<=m;i++)if(op[i]==2)writeln(ans[i]);
}