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
const int M=1e5+10;
int n,m,a[M],b[M];
vector<int> v[M];
LL dis[M];
int q[M],l,r,pre[M];
bool vs[M],in[M];
bool chk(int mid){
	F(i,1,n) in[i]=0; in[1]=1;
	LL now=mid;
	while (1){
		l=1;r=0;
		F(i,1,n) dis[i]=pre[i]=0,vs[i]=in[i];
		F(i,1,n) if (in[i]) q[++r]=i,dis[i]=now; 
		if (r==n) return 1;
		int X=0,Y=0;
		while (l<=r){
			int x=q[l++];
			for (int y:v[x]){
				if (in[x] && in[y]) continue;
				if (dis[x]<=a[y] || pre[x]==y) continue;
				if (vs[y]){
					X=x; Y=y;
					break;
				}
				dis[y]=dis[x]+b[y]; pre[y]=x; vs[y]=1; q[++r]=y;
			}
			if (X) break;
		}
		if (!X) return 0;
		for (int x=X;x;x=pre[x]) if (!in[x]) in[x]=1,now+=b[x];
		for (int x=Y;x;x=pre[x]) if (!in[x]) in[x]=1,now+=b[x];
	}
}
void work(){
	n=read(); m=read();
	F(i,1,n) v[i].clear();
	F(i,2,n) a[i]=read();
	F(i,2,n) b[i]=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	int l=0,r=(1<<30),ret=r;
	while (l<=r){
		int mid=(l+r>>1);
		if (chk(mid)) ret=mid,r=mid-1;
		else l=mid+1; 
	}
	cout<<ret<<"\n"; 
}
int main(){
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
*/