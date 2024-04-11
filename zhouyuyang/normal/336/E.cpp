#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
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
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int mo=1000000007;
int n,K,tot;
int dp[2][201][16];
int tr[55][55][201];
int head[55],C[55][55];
int ok[55],way[55][5];
struct edge{
	int to,k,v,next;
}e[5005];
void add(int x,int y,int k,int v){
	e[++tot]=(edge){y,k,v,head[x]};
	head[x]=tot;
}
int cnt(int x){
	int ans=0;
	for (;x;x/=2) if (x&1) ans++;
	return ans;
}
int main(){
	scanf("%d%d",&n,&K);
	For(i,0,22){
		C[i][0]=1;
		For(j,1,i) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	int lim=15;
	ok[0]=4;
	ok[1]=ok[2]=ok[4]=ok[8]=2;
	ok[3]=ok[6]=ok[9]=ok[12]=1;
	//ok:sta
	way[0][0]=1;
	way[1][1]=way[2][1]=way[3][1]=way[4][1]=1;
	way[6][1]=way[8][1]=way[9][1]=way[12][1]=1;
	way[3][2]=way[5][2]=way[6][2]=way[9][2]=way[10][2]=way[12][2]=1;
	way[7][2]=way[11][2]=way[13][2]=way[14][2]=way[15][2]=2;
	way[7][3]=way[11][3]=way[13][3]=way[14][3]=1;
	way[15][3]=4; way[15][4]=1;
	//wayij 
	For(i,0,15) For(j,0,15) if (!(i&j)){
		int k=i|j;
		For(p,0,ok[k]){
			int tmp=(4-cnt(k))*3-p*2;
			For(q,0,tmp) For(cnt,0,4) if (way[j][cnt])
				UPD(tr[i][k][cnt+p+q],1ll*C[ok[k]][p]*C[tmp][q]*way[j][cnt]%mo);
		}
	}
	//tr
	For(i,0,15) Rep(k,12,0) For(j,0,15)
		if (tr[i][j][k]) add(i,j,k,tr[i][j][k]);
	dp[(n+1)&1][0][0]=1;
	Rep(i,n+1,2){
		int p=i&1,q=p^1; CLR(dp[q],0);
		For(k,0,K) For(msk,0,15) if (dp[p][k][msk])
			for (int x=head[msk];x;x=e[x].next){
				int kk=k+e[x].k;
				if (kk>K) break;
				UPD(dp[q][kk][e[x].to],1ll*dp[p][k][msk]*e[x].v%mo);
			}
	}
	Rep(i,15,0) For(j,i+1,lim) if ((i&j)==i)
		For(k,0,4) UPD(way[j][k],way[i][k]);
	int ans=0;
	For(k,max(K-4,0),K) For(msk,0,15)
		UPD(ans,1ll*dp[1][k][msk]*way[15-msk][K-k]%mo);
	for (int i=1;i<=K;i++) ans=1ll*ans*i%mo;
	printf("%d",ans);
}