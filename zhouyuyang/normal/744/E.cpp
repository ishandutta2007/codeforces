#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=35;
const int M=100005;
const int mo[2]={998244353,1000000009};
int n,ans,tot,L[N];
int a[2][N][M],b[2][M];
int id[N][M],head[M],q[M],deg[M];
char s[M];
struct edge{
	int to,next;
}e[N*M];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot; deg[y]++;
}
bool same(int x,int l1,int r1,int y,int l2,int r2){
	For(k,0,1){
		int hsh1=(a[k][x][r1]-a[k][x][l1-1]+mo[k])%mo[k];
		int hsh2=(a[k][y][r2]-a[k][y][l2-1]+mo[k])%mo[k];
		if (l1<l2) hsh1=1ll*hsh1*b[k][l2-l1]%mo[k];
		else hsh2=1ll*hsh2*b[k][l1-l2]%mo[k];
		if (hsh1!=hsh2) return 0;
	}
	return 1;
}
bool check(int l,int r){
	int cnt=1; tot=0;
	For(i,l,r) For(j,1,L[i]) id[i][j]=++cnt;
	For(i,1,cnt) head[i]=deg[i]=0;
	For(i,l,r) For(j,1,L[i]) For(k,l,r){
		if (j==1&&L[k]==L[i]) continue;
		if (L[i]-j+1==L[k]){
			if (same(i,j,L[i],k,1,L[k]))
				add(id[i][j],1);
		}
		else if (L[i]-j+1>L[k]){
			if (same(i,j,j+L[k]-1,k,1,L[k]))
				add(id[i][j],id[i][j+L[k]]);
		}
		else{
			if (same(i,j,L[i],k,1,L[i]-j+1))
				add(id[i][j],id[k][L[i]-j+2]);
		}
	}
	For(i,l,r) add(1,id[i][1]);
	int h=0,t=0;
	For(i,1,cnt) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (!(--deg[e[i].to]))
				q[++t]=e[i].to;
	}
	return t==cnt;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s+1);
		L[i]=strlen(s+1);
		For(k,0,1){
			b[k][0]=1;
			For(j,1,L[i]){
				b[k][j]=1ll*b[k][j-1]*233%mo[k];
				a[k][i][j]=(a[k][i][j-1]+1ll*b[k][j]*s[j])%mo[k];
			}
		}
	}
	int j=1;
	For(i,1,n){
		for (;j<=n&&check(i,j);j++);
		ans+=j-i;
	}
	printf("%d\n",ans);
}