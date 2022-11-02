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
	int x=0; char ch=gc(); bool positive=1;
	for (;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for (;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
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
vector<long long> v;
int n,n1,a[20];
long long ans,mid,k;
inline void dfs(int p,long long sum){
	if(p>n1){
		v.push_back(sum); return;
	}
	for(int i=0;;i++){
		dfs(p+1,sum);
		if(sum>1e18/a[p])return;
		sum*=a[p];
	}
}
inline void ddd(int p,long long sum){
	if(p>n){
	    //cout<<(upper_bound(&v[0],&v[v.size()],mid/sum)-&v[0])<<endl;
		ans+=upper_bound(&v[0],&v[v.size()],mid/sum)-&v[0]; return;
	}
	for(int i=0;;i++){
		ddd(p+1,sum);
		if(sum>1e18/a[p])return;
		sum*=a[p];
	}
}
int main(){
	n=read(); if(n>6)n1=6; else n1=n-1;
	for(int i=1;i<=n;i++)a[i]=read();
	cin>>k;
	dfs(1,1);
	sort(v.begin(),v.end());
	long long l=1,r=1e18;
	while(l<r){
		mid=l+r>>1; ans=0;
	    ddd(n1+1,1); //cout<<ans<<endl;
		if(ans<k)l=mid+1; else r=mid;
	}
	cout<<l<<endl;
}