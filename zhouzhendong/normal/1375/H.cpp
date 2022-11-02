#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=5005,M=3e6;
int n,q,s,cnt;
int a[N];
int mi[M],mx[M];
vector <pii> ops;
vi qres;
int upd(int x,int y){
	if (x==-1)
		return y;
	if (y==-1)
		return x;
	if (mx[x]>mi[y])
		swap(x,y);
	assert(mx[x]<mi[y]);
	cnt++;
	ops.pb(mp(x,y));
	mi[cnt]=mi[x],mx[cnt]=mx[y];
	return cnt;
}
void outres(){
	printf("%d\n",cnt);
	for (auto i : ops)
		printf("%d %d\n",i.fi,i.se);
	for (auto i : qres)
		printf("%d ",i);
	puts("");
	exit(0);
}
const int S=290;
vi pos[N];
vector <vi> val[N];
vector <vi> solve(vi id){
	if ((int)id.size()==1)
		return vector <vi>(1,vi(1,id[0]));
	int mid=(int)id.size()/2;
	vi L=vi(id.begin(),id.begin()+mid);
	vi R=vi(id.begin()+mid,id.end());
	vector <vi> lv=solve(L),rv=solve(R);
	vector <vi> res((int)id.size(),vi((int)id.size(),-1));
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	sort(id.begin(),id.end());
	For(i,0,(int)id.size()-1)
		For(j,i,(int)id.size()-1){
			int ll=lower_bound(L.begin(),L.end(),id[i])-L.begin();
			int lr=upper_bound(L.begin(),L.end(),id[j])-L.begin()-1;
			int rl=lower_bound(R.begin(),R.end(),id[i])-R.begin();
			int rr=upper_bound(R.begin(),R.end(),id[j])-R.begin()-1;
			res[i][j]=upd(ll<=lr?lv[ll][lr]:-1,rl<=rr?rv[rl][rr]:-1);
		}
	return res;
}
int main(){
	cnt=n=read(),q=read();
	For(i,1,n)
		a[i]=read(),mi[i]=mx[i]=a[i];
	//ns+nq/s=2n sqrt(q) -> ns=n sqrt(q) -> s=sqrt(q);
	s=sqrt(q);
	For(i,1,n)
		pos[(a[i]+s-1)/s].pb(i);
	For(i,1,(n+s-1)/s){
		vi id=pos[i];
		sort(id.begin(),id.end(),[&](int x,int y){
			return a[x]<a[y];
		});
		val[i]=solve(id);
	}
	For(_,1,q){
		int L=read(),R=read();
		int now=-1;
		For(i,1,(n+s-1)/s){
			int l=lower_bound(pos[i].begin(),pos[i].end(),L)-pos[i].begin();
			int r=upper_bound(pos[i].begin(),pos[i].end(),R)-pos[i].begin()-1;
			if (l<=r)
				now=upd(now,val[i][l][r]);
		}
		qres.pb(now);
	}
	outres();
	return 0;
}