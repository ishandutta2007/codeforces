#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const long long MOD=998244353,G=3;

typedef vector<long long> poly;

int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}

int rev(int i,int n){int k=0;for(int j=0;j<n;j++)if(i&(1<<j))k|=1<<(n-j-1);return k;}
void NTT(poly &a,int n,int type)
{
	int N=1<<n;
	for(int i=0;i<N;i++)if(i<rev(i,n))swap(a[i],a[rev(i,n)]);
	
	for(int d=2;d<=N;d<<=1)
	{
		int m=d>>1;long long g=fast_pow(G,(MOD-1)/d);if(type==-1)g=INV(g);
		for(int i=0;i<N;i+=d)
		{
			long long w=1;
			for(int j=0;j<m;j++)
			{
				long long x=a[i+j],y=a[i+j+m]*w%MOD;
				a[i+j]=add(x,y),a[i+j+m]=sub(x,y);
				w=w*g%MOD;
			}
		}
	}
	
	if(type==-1)
	{
		long long x=INV(N);for(int i=0;i<N;i++)a[i]=a[i]*x%MOD;
	}
}

poly operator*(poly a,poly b)
{
	int N=a.size()+b.size(),sz=N,n=0;while((1<<n)<N)n++;N=1<<n;
	while(a.size()<N)a.push_back(0);while(b.size()<N)b.push_back(0);
	NTT(a,n,1),NTT(b,n,1);
	poly c(N);for(int i=0;i<N;i++)c[i]=a[i]*b[i]%MOD;
	NTT(c,n,-1);
	while(c.size()>sz-1)c.pop_back();return c;
}
poly operator+(poly A,poly B)
{
	int sz=max(A.size(),B.size());while(A.size()<sz)A.push_back(0);while(B.size()<sz)B.push_back(0);
	for(int i=0;i<sz;i++)A[i]=add(A[i],B[i]);return A;
}




poly F[200000],dp[200000];

pair<poly,poly> calc(int l,int r)
{
	if(l==r)return make_pair(F[l],F[l]);
	int mid=(l+r)>>1;pair<poly,poly> L=calc(l,mid),R=calc(mid+1,r);
	poly S=R.first*L.second;int off=mid-l+1;S.resize(S.size()+off);
	for(int i=S.size()-1-off;i>=0;i--)S[i+off]=S[i];for(int i=0;i<off;i++)S[i]=0;
	S=S+L.first;return make_pair(S,L.second*R.second);
}

vector<int> ed[200000];
int fa[200000],dep[200000],sz[200000],son[200000];vector<int> H;
void dfs_bas(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1,sz[u]=1;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];if(v==f)continue;
		dfs_bas(v,u);sz[u]+=sz[v];if(sz[son[u]]<sz[v])son[u]=v;
	}
}
bool depcmp(int x,int y){return dep[x]<dep[y];}

int main()
{
	int n=0;long long x=0;scanf("%d%lld",&n,&x);x%=MOD;
	for(int i=1,u=0,v=0;i<n;i++)
	{
		scanf("%d%d",&u,&v);ed[u].push_back(v),ed[v].push_back(u);
	}
	dfs_bas(1,0);
	for(int i=1;i<=n;i++)if(son[fa[i]]!=i)H.push_back(i);
	sort(H.begin(),H.end(),depcmp);
	F[0].resize(1);F[0][0]=1;
	for(int i=0;i<=n;i++)dp[i].push_back(1);
	for(int i=H.size()-1;i>=0;i--)
	{
		int k=0,u=H[i];while(u){++k;F[k]=dp[u];u=son[u];}
		//printf("%d %d\n",H[i],k);
		dp[fa[H[i]]]=calc(0,k).first;
	}
	/*for(int i=0;i<=n;i++)
	{
		printf("%d: ",i);
		for(int j=0;j<dp[i].size();j++)printf("%lld ",dp[i][j]);puts("");
	}*/
	//for(int i=1;i<dp[0].size();i++)printf("%lld ",dp[0][i]);puts("");
	long long ans=0,pro=1;
	for(int i=1;i<=n;i++)
	{
		ans=add(ans,pro*dp[0][i]%MOD);
		pro=pro*((x+i)%MOD)%MOD*INV(i)%MOD;
	}
	printf("%lld",ans);
}