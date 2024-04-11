#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
int X[M],Y[M],n,a[M],b[M];
LL sa[M],sb[M];
bool vis[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n) a[i]=read(),sa[i]=sa[i-1]+a[i];
	F(i,1,n) b[i]=read(),sb[i]=sb[i-1]+b[i];
	bool fl=0;
	if (sa[n]>sb[n]) swap(sa,sb),swap(a,b),fl=1;
	int j=0;
	F(i,0,n){
		while (sb[j]<sa[i]) j++;
		int del=sb[j]-sa[i];
		if (vis[del]){
			int la=X[del]+1,lb=Y[del]+1;
			if (fl){
				cout<<j-lb+1<<"\n";
				F(k,lb,j){
					cout<<k<<" ";
				}
				cout<<"\n"<<i-la+1<<"\n";
				F(k,la,i){
					cout<<k<<" ";
				}
				cout<<"\n";	
			} 
			else{
				cout<<i-la+1<<"\n";
				F(k,la,i){
					cout<<k<<" ";
				}
				cout<<"\n"<<j-lb+1<<"\n";
				F(k,lb,j){
					cout<<k<<" ";
				}
				cout<<"\n";	
			}
			return 0;
		}
		else{
			vis[del]=1;
			X[del]=i;
			Y[del]=j;
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/