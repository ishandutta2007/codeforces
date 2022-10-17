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
int n,m,a[M],b[M],k,c[M],xa[M],xb[M],f[M][20],g[M][20],dis[M];
void work(){
	n=read(); 
	F(i,1,n) a[i]=read();
	dis[1]=0;
	int ta=1,tb=1;
//	sa[1]=sb[1]=0;
	xa[1]=xb[1]=1;
	F(i,2,n){
		while (ta && a[xa[ta]]<a[i]) ta--;
		while (tb && a[xb[tb]]>a[i]) tb--;
		dis[i]=dis[i-1]+1;
//		cerr<<dis[i]<<" !!\n";
		if (xa[ta]==i-1){
			int l=1,r=ta,ret=-1;
			while (l<=r){
				int mid=(l+r>>1);
				if (xa[mid]>xb[tb]) ret=mid,r=mid-1;
				else l=mid+1;
			}
			if (ret!=-1) dis[i]=min(dis[i],dis[xa[ret]]+1); 
		}
		else{
			int l=1,r=tb,ret=-1;		

			while (l<=r){	
				int mid=(l+r>>1);
//				cerr<<ret<<" "<<l<<" "<<r<<" !!!!\n";
				if (xb[mid]>xa[ta]) ret=mid,r=mid-1;
				else l=mid+1;
			}
			if (ret!=-1) dis[i]=min(dis[i],dis[xb[ret]]+1); 
		}
		while (ta && dis[xa[ta]]>dis[i]) ta--;
		while (tb && dis[xb[tb]]>dis[i]) tb--;
		xa[++ta]=i;
		xb[++tb]=i;
	}
	cout<<dis[n]<<"\n";
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