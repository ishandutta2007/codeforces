#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1010,B=1001000;
int n,m,a[M],b[M];
bitset<M*M> dp[M];
int d1x[M],d1y[M],d2x[M],d2y[M];
void work(){
	
	n=read();
	int sa=0,sb=0;
	F(i,1,n) a[i]=read(),sa+=a[i];
	m=read();
	F(i,1,m) b[i]=read(),sb+=b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if (n^m || sa&1 || sb&1){
		cout<<"No\n";
		return ;
	}
	sa/=2; sb/=2;
	dp[0].reset();
	dp[0][0]=1;
	F(i,1,n){
		dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
	}
	if (!dp[n][sa]){
		cout<<"No\n";
		return ;
	}
	int pos=sa,pr=n;
	d1x[0]=d2x[0]=0;
	while (pr>0){
		if (pos>=a[pr] && dp[pr-1][pos-a[pr]]) d1x[++d1x[0]]=a[pr],pos-=a[pr];
		else d2x[++d2x[0]]=a[pr];
		pr--;
	}
	
	dp[0].reset();
	dp[0][0]=1;
	F(i,1,n){
		dp[i]=dp[i-1]|(dp[i-1]<<b[i]);
	}
	if (!dp[n][sb]){
		cout<<"No\n";
		return ;
	}
	pos=sb,pr=n;
	d1y[0]=d2y[0]=0;
	while (pr>0){
		if (pos>=b[pr] && dp[pr-1][pos-b[pr]]) d1y[++d1y[0]]=b[pr],pos-=b[pr];
		else d2y[++d2y[0]]=b[pr];
		pr--;
	}
	F(i,1,d2x[0]){
		d1x[++d1x[0]]=-d2x[i];
	}
	F(i,1,d2y[0]){
		d1y[++d1y[0]]=-d2y[i];
	}
	int px=0,py=0;
	cout<<"Yes\n";
	cout<<px<<" "<<py<<"\n";
	F(i,1,n){
//		cout<<d1x[i]<<" "<<d1y[i]<<"   nmd\n";
		px+=d1x[i];
		cout<<px<<" "<<py<<"\n";
		py+=d1y[n-i+1];
		if (i^n) cout<<px<<" "<<py<<"\n";
	}
}
int main(){
	int T=read();
	while (T--){
		work();
	}
	return 0;
}