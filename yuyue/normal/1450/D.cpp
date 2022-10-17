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
vector<int> ad[M],dl[M];
int n,a[M],s[M],tp,L[M],R[M],ban[M],t[M];
void solve(){
	n=read();
	F(i,1,n) a[i]=read(),ad[i].clear(),dl[i].clear();
	s[tp=1]=0; a[0]=a[n+1]=-1;
	F(i,1,n){
		while (a[s[tp]]>=a[i]) tp--;
		L[i]=s[tp];
		s[++tp]=i;
	}
	s[tp=1]=n+1;
	DF(i,n,1){
		while (a[s[tp]]>a[i]) tp--;
		R[i]=s[tp];
		s[++tp]=i;
	}
	F(i,1,n){
		int tl=R[i]-L[i]-1;
//		cout<<R[i]<<" "<<L[i]<<"    gg\n";
		if (R[i]-i>=2 && i-L[i]>=2){
			ban[2]++;
			ban[tl]--;
			ad[tl].pb(a[i]);
			dl[tl+1].pb(a[i]);
			ad[1].pb(a[i]);
			dl[2].pb(a[i]);
		}
		else{
			ad[1].pb(a[i]);
			dl[tl+1].pb(a[i]);
		}
	}
	int num=0,lim=n;
	string ans;
	F(i,1,n){
		ban[i]+=ban[i-1];
		F(j,0,SZ(dl[i])){
			int y=dl[i][j];			
//			cout<<y<<" "<<t[y]<<"  del\n";

			if (y>lim) continue;
			t[y]--;
			if (!t[y]) num--;
		}
		F(j,0,SZ(ad[i])){
			int y=ad[i][j];	
			if (y>lim) continue;
			if (!t[y]) num++;
			t[y]++;
		}
		if (t[lim+1]) num--;
//		cout<<num<<"   hh\n";
		ans+=(num==lim && !ban[i] ? '1' : '0');
		lim--;
	}
	F(i,1,n) t[i]=ban[i]=0;
	cout<<ans<<"\n";
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