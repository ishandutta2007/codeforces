#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=4e5+10;
int n,I,a[M],t[M];
int tt[M];
int main(){
	n=read(); I=read();
	int mxlog=min(I*8/n,30);
	int mk=1<<mxlog;
	F(i,1,n) t[i]=a[i]=read();
	sort(t+1,t+n+1);
	int N=unique(t+1,t+n+1)-t-1;
	F(i,1,n){
		a[i]=lower_bound(t+1,t+N+1,a[i])-t;
		tt[a[i]]++;
	}
	F(i,1,N){
		tt[i]+=tt[i-1];
	}
	if (mk>=N) return puts("0"),0;
	int ans=0;
	F(i,mk,N){
		ans=max(ans,tt[i]-tt[i-mk]);
	}
	cout<<n-ans<<"\n";
	return 0;
}