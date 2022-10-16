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

int n,m;
int s[400000],p[400000];
long long a[400000],c[400000],pw2[400000],inv_pw2[400000];

void Solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;Solve(l,mid),Solve(mid+1,r);
	poly X,Y;
	for(int i=l;i<=mid;i++)X.push_back(pw2[s[max(min(n,i),0)]]);
	for(int i=mid+1;i<=r;i++)Y.push_back(inv_pw2[s[max(min(n,i),0)]]);
	X=X*Y;for(int i=0;i<X.size();i++)if(i+l+(mid+1)>=0&&i+l+(mid+1)<=2*n)c[i+l+(mid+1)]=add(c[i+l+(mid+1)],X[i]);
}

int main()
{
	init_w(20);
	scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)scanf("%d",&a[i]);for(int i=1;i<=m;i++)scanf("%d",&p[i]),s[p[i]]=1;
	for(int i=1;i<=n;i++)s[i]+=s[i-1];//for(int i=1;i<=n;i++)printf("%d ",s[i]);puts("");
	pw2[0]=1;for(int i=1;i<=n;i++)pw2[i]=add(pw2[i-1],pw2[i-1]);
	inv_pw2[n]=INV(pw2[n]);for(int i=n-1;i>=0;i--)inv_pw2[i]=add(inv_pw2[i+1],inv_pw2[i+1]);
	Solve(-n,2*n);
	//for(int i=0;i<=2*n;i++)printf("%lld ",c[i]*pw2[m]%MOD);puts("");
	long long ans=0;for(int i=1;i<=n;i++)ans=add(ans,sub(pw2[m]*c[2*i-1]%MOD,min(i+n,2*n-i+1))*a[i]%MOD);
	printf("%lld",ans*INV(sub(pw2[m],1))%MOD);
}