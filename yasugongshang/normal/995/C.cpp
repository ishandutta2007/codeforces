#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
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
const int N=100005,xian=(ll)1500000*1500000;
#define PI pair<int,int>
int q[N],ans[N],n;
PI a[N];
inline ll cal(PI x){
	return x.first*x.first+x.second*x.second; 
} 
PI solve(int l,int r){
	if(l==r)return a[q[l]];
	int mid=(l+r)>>1;
	while(1){
		random_shuffle(&q[l],&q[r+1]);
		PI t1=solve(l,mid),t2=solve(mid+1,r);
		PI t3=mp(t1.first+t2.first,t1.second+t2.second),t4=mp(t1.first-t2.first,t1.second-t2.second);
		PI t=cal(t3)<cal(t4)?t3:t4; 
		if(cal(t)<=xian)return t;
	}
}
PI sol(int l,int r){
	if(l==r)return a[q[l]];
	int mid=(l+r)>>1;
	while(1){
		PI t1=sol(l,mid),t2=sol(mid+1,r);
		PI t3=mp(t1.first+t2.first,t1.second+t2.second),t4=mp(t1.first-t2.first,t1.second-t2.second),t;
		if(cal(t3)<cal(t4)){
			t=t3;
		}else{
			t=t4; ans[mid+1]*=-1; ans[r+1]*=-1;
		
		}
		if(cal(t)<=xian)return t;
	}
}
int an[N];
signed main(){
	n=read(); 
	for(int i=1;i<=n;i++){
		a[i].first=read(); a[i].second=read(); q[i]=i; ans[i]=1;
	}
	solve(1,n);
	sol(1,n); ans[0]=1;
	for(int i=1;i<=n;i++)ans[i]*=ans[i-1];
	for(int i=1;i<=n;i++)an[q[i]]=ans[i];
	for(int i=1;i<=n;i++)if(an[i]==1){
		putchar('1'); putchar(' ');
	}else{
		putchar('-'); putchar('1'); putchar(' ');
	}
}