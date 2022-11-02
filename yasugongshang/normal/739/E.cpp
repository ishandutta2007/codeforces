#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
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
const int N=2005;
int n,a,b;
double t,p[N],u[N],q[N];
pair<double,pair<int,int> > dp[N];
bool check(double x,double y){
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],mp(dp[i-1].first+p[i]-x,mp(dp[i-1].second.first+1,dp[i-1].second.second)));
		dp[i]=max(dp[i],mp(dp[i-1].first+u[i]-y,mp(dp[i-1].second.first,dp[i-1].second.second+1)));
		dp[i]=max(dp[i],mp(dp[i-1].first+q[i]-x-y,mp(dp[i-1].second.first+1,dp[i-1].second.second+1)));
	}
	return dp[n].second.first<=a;
}
bool check(double x){
	double l=-1.01,r=1.01;
	while(l+(1e-9)<r){
		double mid=(l+r)/2;
		if(check(mid,x))r=mid; else l=mid;
	}
	t=r;
	check(r,x);
	return dp[n].second.second<=b&&dp[n].second.first<=a;
}
int main(){
	n=read(); a=read(); b=read();
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++)scanf("%lf",&u[i]);
	for(int i=1;i<=n;i++)q[i]=p[i]+u[i]-p[i]*u[i];
	double l=-1.01,r=1.01;
	while(l+(1e-9)<r){
		double mid=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<check(mid)<<endl;
		if(check(mid))r=mid; else l=mid;
	}
	check(t,r);
	//cout<<r<<" "<<t<<" "<<dp[n].second.first<<" "<<dp[n].second.second<<" "<<endl;
	cout<<dp[n].first+r*b+t*a<<endl;
	//cout<<check(0.6)<<endl;
}