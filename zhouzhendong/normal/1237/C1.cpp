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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
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
const int N=50005;
int n;
struct P{
	int x,y,z,id;
}p[N];
int dis(P a,P b){
	return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}
int vis[N];
int main(){
	n=read();
	For(i,1,n){
		p[i].x=read(),p[i].y=read(),p[i].z=read(),p[i].id=i;
	}
//	sort(p+1,p+n+1,[&](P a,P b){
//		return a.x<b.x;
//	});
//	int tp=0;
//	for (int i=1,j;i<=n;i=j+1){
//		for (j=i;j<n&&p[j+1].x==p[j].x;j++);
//		sort(p+i,p+j+1,[&](P a,P b){
//			return tp^(a.y<b.y);
//		});
//		tp^=1;
//	}
//	tp=0;
//	for (int i=1,j;i<=n;i=j+1){
//		for (j=i;j<n&&p[j+1].x==p[j].x&&p[j+1].y==p[j].y;j++);
//		sort(p+i,p+j+1,[&](P a,P b){
//			return tp^(a.z<b.z);
//		});
//		tp^=1;
//	}
	sort(p+1,p+n+1,[&](P a,P b){
		if (a.x!=b.x)
			return a.x<b.x;
		if (a.y!=b.y)
			return a.y<b.y;
		return a.z<b.z;
	});
	vector <pii> res;
//	For(i,1,n){
//		int md=1e9,v=-1;
//		For(j,i+1,n)
//			if (!vis[j]){
//				int d=dis(p[i],p[j]);
//				if (d<md)
//					md=
//			}
//	}
	int las=0;
	for (int i=1,j;i<=n;i=j+1){
		for (j=i;j<n&&p[j+1].x==p[j].x;j++);
		if (las){
			int md=1e9,v=-1;
			For(k,i,j){
				if (vis[k])
					continue;
				int d=dis(p[k],p[las]);
				if (d<md)
					md=d,v=k;
			}
			if (v!=-1){
				res.pb(mp(las,v));
				vis[las]=vis[v]=1;
				las=0;
			}
			else
				continue;
		}
		for (int iy=i,jy;iy<=j;iy=jy+1){
			for (jy=iy;jy<j&&p[jy+1].y==p[jy].y;jy++);
			if (las){
				int md=1e9,v=-1;
				For(k,iy,jy){
					if (vis[k])
						continue;
					int d=dis(p[k],p[las]);
					if (d<md)
						md=d,v=k;
				}
				if (v!=-1){
					res.pb(mp(las,v));
					vis[las]=vis[v]=1;
					las=0;
				}
				else
					continue;
			}
			For(k,iy,jy){
				if (vis[k])
					continue;
				if (!las)
					las=k;
				else {
					vis[las]=vis[k]=1;
					res.pb(mp(las,k));
					las=0;
				}
			}
		}
	}
	for (auto i : res)
		printf("%d %d\n",p[i.fi].id,p[i.se].id);
	return 0;
}