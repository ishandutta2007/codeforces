#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
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
const int N=5005,mod=1e9+7;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int n,m;
int a[N];
short h[N][N],lcnt[N][N],rcnt[N][N];
vi p[N];
int main(){
	n=read(),m=read();
	For(i,1,n)
		a[i]=read(),lcnt[a[i]][i]=rcnt[a[i]][i]=1;
	For(i,1,m){
		int fi=read(),hi=read();
		h[fi][hi]=1;
	}
	For(i,1,n)
		For(j,1,n){
			h[i][j]+=h[i][j-1];
			lcnt[i][j]+=lcnt[i][j-1];
		}
	For(i,1,n)
		Fod(j,n,1)
			rcnt[i][j]+=rcnt[i][j+1];
	int mx=0,cnt=0;
	For(i,1,n){
		if (h[a[i]][lcnt[a[i]][i]]>h[a[i]][lcnt[a[i]][i]-1]){
			int vc=1,now=1;
			For(j,1,n){
				if (j==a[i]){
					int r=h[j][rcnt[j][i+1]]-(rcnt[j][i+1]>=lcnt[j][i]);
					if (r>0)
						vc++,now=(LL)now*r%mod;
				}
				else {
					int l=h[j][lcnt[j][i]],r=h[j][rcnt[j][i+1]];
					if (l<r)
						swap(l,r);
					if (r==0){
						if (l>0)
							vc++,now=(LL)now*l%mod;
					}
					else if (l==1)
						vc++,now=(LL)now*2%mod;
					else
						vc+=2,now=(LL)now*r%mod*(l-1)%mod;
				}
			}
			if (vc>mx)
				mx=vc,cnt=0;
			if (vc==mx)
				Add(cnt,now);
		}
	}
	{
		int vc=0,now=1;
		For(i,1,n){
			int r=h[i][lcnt[i][n]];
			if (r>0)
				vc++,now=(LL)now*r%mod;
		}
		if (vc>mx)
			mx=vc,cnt=0;
		if (vc==mx)
			Add(cnt,now);
	}
	cout<<mx<<" "<<cnt<<endl;
	return 0;
}