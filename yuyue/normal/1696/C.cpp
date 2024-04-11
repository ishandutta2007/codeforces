#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10; 
int n,m,a[M],b[M],k,c[M];
void work(){
	n=read(); k=read();
	F(i,1,n){
		a[i]=read();
		c[i]=1;
		while (a[i]%k==0) c[i]*=k,a[i]/=k;
	}
	m=read();
	F(i,1,m){
		b[i]=read();
	}
	int j=1;
	F(i,1,m){
		int num=1;
		while (b[i]%k==0) num*=k,b[i]/=k;	
		while (num){
			while (!c[j] && j<=n) j++;
			if (j==n+1 || a[j]!=b[i]){
				cout<<"No\n";
				return ;
			}
			int o=min(num,c[j]);
			c[j]-=o;
			num-=o;
		}
	}
	if (!c[n])
	cout<<"Yes\n";
	else cout<<"No\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
1
1 2
8
1
4
*/