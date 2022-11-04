#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1<<29)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=400005;
char A[N],B[N],s[N];
int F[20][N],SA[N],rk[N];
int hei[N],x[N],y[N],c[N];
int lg[N],ans[N],id[N],val[N];
int n,m,Q;
int CMP(int a,int b,int k,int n){
	return (y[a]!=y[b]||(a+k<=n?y[a+k]:-1)!=(b+k<=n?y[b+k]:-1));
}
void buildSA(int n){
	int m=0;
	For(i,1,n){
		c[x[i]=s[i]]++;
		m=max(m,(int)(s[i]));
	}
	For(i,1,m) c[i]+=c[i-1];
	Rep(i,n,1) SA[c[x[i]]--]=i;
	for (int k=1;k<=n;k<<=1){
		int p=0;
		For(i,n-k+1,n) y[++p]=i;
		For(i,1,n) if (SA[i]>k) y[++p]=SA[i]-k;
		For(i,1,p) c[i]=0;
		For(i,1,n) c[x[y[i]]]++;
		For(i,1,p) c[i]+=c[i-1];
		Rep(i,n,1) SA[c[x[y[i]]]--]=y[i];
		swap(x,y); m=x[SA[1]]=1;
		For(i,2,n) x[SA[i]]=(m+=CMP(SA[i],SA[i-1],k,n));
		if (m==n) break;
	}
	For(i,1,n) rk[SA[i]]=i;
	int j=0;
	For(i,1,n) if (rk[i]!=1){
		for (;s[i+j]==s[SA[rk[i]-1]+j];j++);
		hei[rk[i]]=j; j-=(j!=0);
	}
	For(i,1,n) F[0][i]=hei[i];
	For(j,1,18) For(i,1,n-(1<<j)+1)
		F[j][i]=min(F[j-1][i],F[j-1][i+(1<<(j-1))]);
}
int LCP(int x,int y){
	if (x==y) return INF;
	x=rk[x]; y=rk[y];
	if (x>y) swap(x,y);
	int k=lg[y-(++x)+1];
	return min(F[k][x],F[k][y-(1<<k)+1]); 
}
bool cmp(int x,int y){
	static int xl[3],xr[3],yl[3],yr[3];
	xl[0]=1;   xr[0]=x;
	xl[1]=n+2; xr[1]=n+m+1;
	xl[2]=x+1; xr[2]=n;
	yl[0]=1;   yr[0]=y;
	yl[1]=n+2; yr[1]=n+m+1;
	yl[2]=y+1; yr[2]=n;
	for (int i=0,j=0;;){
		for (;i<3&&xl[i]>xr[i];i++);
		for (;j<3&&yl[j]>yr[j];j++);
		if (i==3) return x<y;
		int len=LCP(xl[i],yl[j]);
		int mn=min(xr[i]-xl[i]+1,yr[j]-yl[j]+1);
		if (len>=mn) xl[i]+=mn,yl[j]+=mn;
		else return s[xl[i]+len]<s[yl[j]+len];
	}
}

struct que{
	int l,r,x,y,id;
};
vector<que> v[N];
vector<int> T[N];
int Mn(int x,int y){
	if (x==-1) return y;
	if (y==-1) return x;
	return val[x]<val[y]?x:y;
}

void solve1(int k){
	For(b,0,k-1) T[b].clear();
	For(i,0,n) T[i%k].PB(i);
	For(b,0,k-1){
		int sz=T[b].size()-1;
		For(i,0,sz) F[0][i]=T[b][i];
		For(j,1,18) For(i,0,sz-(1<<j)+1)
			F[j][i]=Mn(F[j-1][i],F[j-1][i+(1<<(j-1))]);
		For(i,0,v[k].size()-1){
			que Q=v[k][i];
			if (Q.x<=b&&b<=Q.y){
				int l=Q.l/k,r=Q.r/k;
				l+=(Q.l%k>b); r-=(Q.r%k<b);
				if (l<=r){
					int k=lg[r-l+1];
					ans[Q.id]=Mn(ans[Q.id],F[k][l]);
					ans[Q.id]=Mn(ans[Q.id],F[k][r-(1<<k)+1]);
				}
			}
		}
	}
}
void solve2(int k){
	For(i,0,v[k].size()-1){
		que Q=v[k][i];
		for (int x=Q.x,y=Q.y;x<=n;x+=k,y+=k){
			int l=max(x,Q.l),r=min(y,Q.r);
			if (l<=r){
				int k=lg[r-l+1];
				ans[Q.id]=Mn(ans[Q.id],F[k][l]);
				ans[Q.id]=Mn(ans[Q.id],F[k][r-(1<<k)+1]);
			}
		}
	}
}
int main(){
	CLR(ans,-1);
	For(i,2,N-1) lg[i]=lg[i/2]+1;
	scanf("%s%s%d",A+1,B+1,&Q);
	n=strlen(A+1),m=strlen(B+1);
	For(i,1,n) s[i]=A[i];
	For(i,1,m) s[i+n+1]=B[i];
	s[n+1]='#';
	buildSA(n+m+1);
	For(i,0,n) id[i]=i;
	sort(id,id+n+1,cmp);
	For(i,0,n) val[id[i]]=i;
	For(i,1,Q){
		int l,r,k,x,y;
		scanf("%d%d%d%d%d",&l,&r,&k,&x,&y);
		v[k].PB((que){l,r,x,y,i});
	}
	int S=70;
	For(i,1,S) solve1(i);
	For(i,0,n) F[0][i]=i;
	For(j,1,18) For(i,0,n-(1<<j)+1)
		F[j][i]=Mn(F[j-1][i],F[j-1][i+(1<<(j-1))]);
	For(i,S+1,n) solve2(i);
	For(i,1,Q) printf("%d ",ans[i]);
}