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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
struct fwt{
	int t[1000005],n;
	#define lowbit(x) (x&-x)
	void init(int _n){
		n=_n;
		F(i,0,n) t[i]=0;
	}
	void add(int x,int y){
		for (;x<=n;x+=lowbit(x)) t[x]+=y;
	}
	int qry(int x){
	    int ret=0;
	    for (;x;x^=lowbit(x)) ret+=t[x];
	    return ret;
	}
	
	inline int kth(int k){
	    int pos=0;
	    int cur=0;
	    DF(i,18,0){
			pos^=(1<<i);
			if (pos>n || k<=t[pos]) pos^=(1<<i);
			else k-=t[pos];
		}
	    return pos+1;
	}
}A;
const int N=4e6+10;
#define lc u<<1
#define rc lc|1
int mi[N<<2], M;
inline void upd(int u){ int tmp = min(mi[lc] , mi[rc]);  mi[lc] -= tmp , mi[rc] -= tmp , mi[u] += tmp; }
void add(int l,int r,int d){
	for(l += M - 1 , r += M + 1;l ^ r ^ 1;l >>= 1 , r >>= 1){
		if(~l & 1) mi[l ^ 1] +=d;
		if(r & 1) mi[r ^ 1] +=d;
		upd(l >> 1) , upd(r >> 1);
	}
	for(;l != 1;l >>= 1) upd(l >> 1);
}
int qry(int l,int r){
	int la = 0 , ra = 0;
	l += M , r += M;
	for(;(l^r) > 1;l >>= 1 , r >>= 1){
		la += mi[l] , ra += mi[r];
		if(~l & 1) la = min(la , mi[l ^ 1]);
		if(r & 1) ra = min(ra , mi[r ^ 1]);
	}
	int ans = min(la + mi[l] , ra + mi[r]);
	for(;l > 1;) ans += mi[l >>= 1];
	return ans;
}

int n,m,a[N],b[N],p[N];
void work(){
//	n=200; m=100;
	n=read(); m=read();
	F(i,1,n) a[i]=read();
	F(i,1,m) b[i]=read();
	M=1; A.init(n);
	while (M<=n+5) M<<=1;
	F(i,0,M+n+10) mi[i]=0; 
//	F(i,1,n) a[i]=rnd()%1000000000;
//	F(i,1,m) b[i]=rnd()%1000000000;
	
	
	sort(b+1,b+m+1);
	F(i,1,n) p[i]=i;
	sort(p+1,p+n+1,[&](int x,int y){
		return a[x]==a[y] ? x<y : a[x]<a[y];
	});
	LL ans=0;
	F(i,1,n){
		A.add(p[i],1);
		ans+=i-A.qry(p[i]);
		add(i+1,n+1,1);
	}
	int j=1;
	
	F(i,1,m){
		int cur=b[i];
		
		while (j<=n && a[p[j]]<cur){
			add(p[j]+1,n+1,-1);
			add(1,p[j],1);
			j++;
		}
		int la=j;
		while (j<=n && a[p[j]]==cur){
			add(p[j]+1,n+1,-1);
			j++;
		}
		ans+=qry(1,n+1);
		while (i<m && b[i+1]==b[i]) ans+=qry(1,n+1),i++;
		F(k,la,j-1) add(1,p[k],1);
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen("1.out","w",stdout);
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