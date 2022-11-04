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
#define int long long
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
const int N=1000005;
vector<int> v[N];
int a,b,p,x,ans,mod;
inline int ksm(int a,int b){
	int t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
inline int ni(int a){
	return ksm(a,mod-2);
}
inline int calc(int b,int z){
	int tt=b/(p-1),ttt=upper_bound(v[z].begin(),v[z].end(),b%(p-1))-v[z].begin();
	return tt*v[z].size()+ttt;
}
signed main(){
	cin>>a>>b>>p>>x; mod=p;
	int t=a,zs=1;
	for(int i=0;i<p-1;i++){
		v[zs].push_back(i);
		zs=zs*t%p;
	}
	x++;
	for(int i=1;i<p;i++){
		//cout<<calc((x-i)/p+((x-i)%p>0)-1,b*ni(i*ksm(a,i)%mod)%mod)<<" "<<i<<" "<<(x-i)/p+((x-i)%p>0)<<" "<<b*ni(i*ksm(a,i)%mod)%mod<<endl;
		ans+=calc((x-i)/p+((x-i)%p>0)-1,b*ni(i*ksm(a,i)%mod)%mod);
	}
	cout<<ans<<endl;
}