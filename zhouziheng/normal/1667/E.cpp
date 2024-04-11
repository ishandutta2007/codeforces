#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<long long> poly;

const long long MOD=998244353,G=3;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}
long long w[2000000],invw[2000000];

void init_w(int n)
{
	int N=1<<n;
	for(int d=2;d<=N;d<<=1)
	{
		int m=d>>1;w[m]=1;long long g=fast_pow(G,(MOD-1)/d);
		for(int i=1;i<m;i++)w[i+m]=w[i+m-1]*g%MOD;
	}
	for(int i=1;i<N;i++)invw[i]=INV(w[i]);
}


void NTT(poly &a,int n,int type)
{
	int N=1<<n;poly b(N);
	for(int i=1;i<N;i++)b[i]=(b[i>>1]>>1)|((i&1)*(N>>1));
	for(int i=1;i<N;i++)if(i<b[i])swap(a[i],a[b[i]]);
	
	for(int d=2;d<=N;d<<=1)
	{
		int m=d>>1;
		for(int i=0;i<N;i+=d)
		{
			for(int j=0;j<m;j++)
			{
				long long x=a[i+j],y=a[i+j+m]*(type==-1?invw[j+m]:w[j+m])%MOD;
				a[i+j]=add(x,y),a[i+j+m]=sub(x,y);
			}
		}
	}
	if(type==-1){long long x=INV(N);for(int i=0;i<N;i++)a[i]=a[i]*x%MOD;}
}
poly operator*(poly a,poly b)
{
	int N=a.size()+b.size(),n=0;while((1<<n)<N)n++;N=1<<n;
	while(a.size()<N)a.push_back(0);while(b.size()<N)b.push_back(0);
	NTT(a,n,1),NTT(b,n,1);
	poly c(N);for(int i=0;i<N;i++)c[i]=a[i]*b[i]%MOD;
	NTT(c,n,-1);return c;
}

long long fac[300000],invf[300000];
void init_fac(int n)
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	invf[n]=INV(fac[n]);for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%MOD;
}

long long ans[300000];

int main()
{
	init_w(20);init_fac(200000);
	int n=0;scanf("%d",&n);
	poly F(n+1),G(n+1);
	for(int j=(n-1)/2;j<=n-2;j++){F[j]=fac[n-j-2];}
	//for(int i=0;i<=n;i++)printf("%lld ",F[i]);puts("");
	for(int j=0;j<=n;j++){G[j]=invf[j];}
	//for(int i=0;i<=n;i++)printf("%lld ",G[i]);puts("");
	poly H=F*G;//for(int i=0;i<H.size();i++)printf("%lld ",H[i]);puts("");
	while(H.size()>n+1)H.pop_back();reverse(H.begin(),H.end());
	//for(int i=0;i<=n;i++)printf("%lld ",H[i]);puts("");
	ans[1]=fac[n-1];for(int i=2;i<=n;i++)ans[i]=H[i]*(i-1)%MOD*fac[n-i]%MOD;
	
	long long bk=0,p=0;
	for(int i=n;i>=2;i--)
	{
		p=bk;
		bk=add(bk,ans[i]*invf[i-1]%MOD*fac[i-2]%MOD);
		ans[i]=sub(ans[i],p);
	}
	ans[1]=sub(ans[1],bk);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}