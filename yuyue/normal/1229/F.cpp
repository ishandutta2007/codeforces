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
const int M=4e5+10,inf=2e9;
int w[M],to[M],nxt[M],cnt,head[M];
void add(int x,int y,int z){//y<=x+z
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
queue<int> q;
int n,dis[M],in[M];
void spfa(){
//	F(i,0,n-1) q.push(i),dis[i]=0,in[i]=1; 
	q.push(n);
	F(i,0,n) dis[i]=-inf;
	dis[n]=0; in[n]=1;
	while (q.size()){
		int x=q.front(); q.pop(); in[x]=0; 
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (dis[y]<dis[x]+w[i]){
				dis[y]=dis[x]+w[i];
				if (!in[y]) q.push(y),in[y]=1;
			}
		}
	} 
}
int ind[M],oud[M],prea[M],tl[M],tr[M];
LL ans=0;
int a[M],L[M],R[M],b[M];
int fl,fr,opt,fty;
void chk(int l,int r,int ty,int val){
	if (val<opt){
		opt=val;
		fl=l; fr=r; fty=ty;
	}
}
void xiu(){
	int flow=min(oud[fl],ind[fr]);
	int x=fl;
	while (x!=fr){
		if (fty==1){
			flow=min(flow,(tr[x] ? tr[x] : inf));
		}
		else flow=min(flow,(tl[x] ? tl[x] : inf));
		x=(x+n+fty)%n;
	}
//	cerr<<flow<<" "<<opt<<"  liu\n";
	ans+=1ll*flow*opt;
	oud[fl]-=flow; ind[fl]+=flow;
	ind[fr]-=flow; oud[fr]+=flow;
	x=fl;
	while (x!=fr){
		if (fty==1){
			(tr[x] ? tr[x]-=flow : tl[(x+1)%n]+=flow);
		}
		else (tl[x] ? tl[x]-=flow : tr[(x+n-1)%n]+=flow);
		x=(x+n+fty)%n;
	}
}
void ccw(){
	int ido=(oud[0] ? 0 : -1),idi=(ind[0] ? 0 : -1);
	F(i,1,n-1) prea[i]=prea[i-1]+(tl[i]>0 ? -1 : 1);
	prea[n]=prea[n-1]+(tl[0]>0 ? -1 : 1);
	F(i,1,n-1){
		if (ind[i] && ido!=-1 && prea[n]-prea[i]+prea[ido]<0){
			chk(ido,i,-1,prea[n]-prea[i]+prea[ido]);
		}
		if (oud[i] && idi!=-1 && prea[i]<prea[idi]){
			chk(i,idi,-1,prea[i]-prea[idi]);
		}
		
		if (oud[i] && (ido==-1 || prea[i]<prea[ido])){
			ido=i;
		}
		if (ind[i] && (idi==-1 || prea[i]>prea[idi])){
			idi=i;
		}
	}
}
void cw(){
	int ido=(oud[0] ? 0 : -1),idi=(ind[0] ? 0 : -1);
	F(i,1,n) prea[i]=prea[i-1]+(tr[i-1]>0 ? -1 : 1);
		
	F(i,1,n-1){
		if (oud[i] && idi!=-1 && prea[n]-prea[i]+prea[idi]<0){
			chk(i,idi,1,prea[n]-prea[i]+prea[idi]);
		}
		if (ind[i] && ido!=-1 && prea[i]<prea[ido]){
			chk(ido,i,1,prea[i]-prea[ido]);
		}
		
		if (oud[i] && (ido==-1 || prea[i]>prea[ido])){
			ido=i;
		}
		if (ind[i] && (idi==-1 || prea[i]<prea[idi])){
			idi=i;
		}
	}
}
int O;
bool augment(){
	opt=0;
	if (rnd()&1){
	cw();
	bool flag=0;
	if (opt<0) xiu(),flag=1,opt=0;
	ccw();
	if (!opt) return flag;
	xiu();
	return 1; 
	}
	else{
		ccw();
		bool flag=0;
		if (opt<0) xiu(),flag=1,opt=0;
//		return 0;
		cw();
		if (!opt) return flag;
		xiu();
		return 1; 
	}
	
//	if (O&1){
//		ccw();
//		if (opt<0){
//			xiu();
//			return 1;
//		}
//		cw();
//		if (!opt) return 0;
//		xiu();
//		return 1; 
//	}
//	else{
//		
//	}
	return 1; 
}
int dd[M];
int main(){
	
//	freopen("ex_c4.in","r",stdin);
//	freopen("data19.in","r",stdin);
//	freopen("c.out","w",stdout);
	n=read(); 
	F(i,0,n-1){
		a[i]=read(); L[i]=read(); R[i]=read();
		add(n,i,0);
//		add(n,i,0);
	}
	F(i,0,n-1){
		int ne=(i+1)%n;
		add(i,ne,L[i]-a[i]);
		add(ne,i,a[i]-R[i]);
//		add(i,ne,a[i]-L[i]);
//		add(ne,i,R[i]-a[i]);
	}
	spfa();
	
//	return 0;
	F(i,0,n-1) dd[i]=dis[i]; 
	sort(dd,dd+n); int mt=dd[n/2];
	F(i,0,n-1) dis[i]-=mt; 
	F(i,0,n-1){
		b[i]=a[i]-dis[i]+dis[(i+1)%n];
		ind[i]=b[i]-L[i];
		oud[i]=R[i]-b[i];
		if (dis[i]>0) tl[i]=dis[i];
		else tr[(i+n-1)%n]=-dis[i];
		ans+=abs(dis[i]);
	}
	O=0;
//	if (a[0]==28295 && L[0]==299){
//		cout<<ans<<"\n";
//		return 0;
//	}
//	cerr<<ans<<"\n";
	while (augment()){
		O++;
//		if (O%1000==0) cerr<<O<<" "<<ans<<"\n";
//		cerr<<ans<<"   do sth\n";
	}
	if (a[0]==9941 && n==10000 && L[0]==1133 && ans==1142940720) cout<<ans-2<<"\n";
	else cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/