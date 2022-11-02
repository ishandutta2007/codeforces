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
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005,mod=1000000007;
char ch[N];
int fac[N],ni[N],n,sum1[N],sum2[N],ans;
inline int ksm(int a,int b){
	int t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
inline int c(int n,int m){
	return (long long)fac[n]*ni[m]%mod*ni[n-m]%mod;
}
int main(){
	scanf("%s",ch+1); n=strlen(ch+1); fac[0]=ni[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=(long long)fac[i-1]*i%mod; 
	}
	ni[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i;i--)ni[i]=(long long)ni[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+(ch[i]=='(');
	for(int i=n;i;i--)sum2[i]=sum2[i+1]+(ch[i]==')');
	for(int i=1;i<=n;i++)if(ch[i]=='('){
		ans=(ans+c(sum1[i]+sum2[i+1]-1,sum1[i]))%mod;
	}
	cout<<ans<<endl;
}