#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int n,a[M],t[M];
void solve(){
	n=read();
	int mx=0;
	F(i,1,n) a[i]=read(),t[a[i]]++,mx=max(mx,t[a[i]]);
	F(i,1,n) t[i]=0;
	if (mx>(n+1)/2){
		puts("-1");
		return ;
	}
	int lst=1,k=1;
	F(i,2,n){
		if (a[i]==a[i-1]){
			t[a[lst]]++;
			t[a[i-1]]++;
			lst=i;
			k++;
		}
	}
	t[a[n]]++; t[a[lst]]++;
	mx=0;
	F(i,1,n) mx=max(mx,t[i]);
	k=max(mx-1,k);
	cout<<k-1<<"\n";
	F(i,1,n) t[i]=0;
}
int main(){
	int T=read();
	while (T--) solve();
	return 0;
}
/*
1
4
1 3 2 1
*/
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/