#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 320
#define N 100005
#define M 998244353
using namespace std;
 
int T,n,m,ans,tot,num[N];
int A[N][MN],B[N][MN];
 
inline void Add(int &u,int v){u=((ll)u+v)%M;}
int dfs(int u,int v,int w)
{
	if(!u) return 0;
	if(v<MN && A[u][v]!=-1) return A[u][v];
	if(w<MN && B[u][w]!=-1) return B[u][w];
	int now=num[u]/v,nxt,res;
	nxt=(num[u-1]+now-1)/now;
	res=(ll)(v-1)*u%M;
	res=((ll)res+dfs(u-1,nxt,now))%M;
	if(v<MN) A[u][v]=res;
	if(w<MN) B[u][w]=res;
	return res;
}

int main()
{
	memset(A,-1,sizeof(A));
	memset(B,-1,sizeof(B));
	int i,j,t,a,b;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&num[i]);
		for(i=n-1;i>=1;i--) Add(ans,dfs(i,(num[i]+num[i+1]-1)/num[i+1],num[i+1]));
		printf("%d\n",ans);
		for(i=1;i<=n;i++) for(j=0;j<MN;j++) A[i][j]=B[i][j]=-1;
//		for(i=1;i<=n;i++) tot+=mm[i].size();cout<<" "<<tot<<endl;
	}
}