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
const long long mod=1000000007;
long long s[1005][1005],tong[1005],v[1005][1005],n,m,father[1005];
char ch[1005][1005];
inline long long getfather(long long x){
	return father[x]==x?x:father[x]=getfather(father[x]);
}
inline long long quick_mod(long long a,long long b,long long p)
{
    long long ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)  {ans =(long long) ans * a % p; }
        b>>=1;
        a=(long long)a * a % p;
    }
    return ans;
}

inline long long C(long long n,long long m)
{
    if(m>n) return 0;  if(m>n-m)m=n-m;
    long long s1=1,s2=1;
    for(long long i=0; i<m; i++)
    {s1=(long long)s1*(n-i)%mod; s2=(long long)s2*(i+1)%mod;}
    return (long long)s1*quick_mod(s2,mod-2,mod)%mod;
}
int main(){
	//cout<<(long long)15*203*115975*115975%mod<<endl;
	m=read(); n=read();
	for(long long i=1;i<=m;i++)father[i]=i;
	for(long long i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
	}
	for(long long i=1;i<=m;i++)for(long long j=i+1;j<=m;j++){
		long long flag=0;
		for(long long k=1;k<=n;k++){
			if(ch[k][i]!=ch[k][j]){
				flag=1; break;
			}
		}
		if(!flag)father[i]=j;
	}
	for(long long i=1;i<=m;i++)tong[getfather(i)]++;
	long long ans=1;
	s[1][1]=1;
	for(long long i=2;i<=1000;i++)for(long long j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+(long long)s[i-1][j]*j)%mod;
	for(long long i=1;i<=1000;i++)for(long long j=1;j<=i;j++)s[i][0]=(s[i][0]+s[i][j])%mod; s[0][0]=1;
	for(long long i=1;i<=m;i++){ans=(long long)ans*s[tong[i]][0]%mod; }
	cout<<ans<<endl;
	return 0;
}
/*
dp[i]=dp[i-j]*dp[j]*c(i,j)
1.000
111
2 3 4 5
6 7 8
1 2 5 15
15
1 2 
000
111
001
110

*/