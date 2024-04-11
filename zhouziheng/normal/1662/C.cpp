#include<cstdio>
#include<cstring>

using namespace std;

const long long MOD=998244353,G=3;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}
int n,m,k;

struct mat
{
	long long num[120][120];
	long long *operator[](int x){return num[x];}
	const long long *operator[](int x)const{return num[x];}
	mat(){memset(num,0,sizeof(num));}
};

mat operator*(mat a,mat b)
{
	mat c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				c[i][j]=add(c[i][j],(long long)a[i][k]*b[k][j]%MOD);
			}
		}
	}
	return c;
}
mat operator+(mat a,mat b)
{
	mat c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i][j]=add(a[i][j],b[i][j]);
		}
	}
	return c;
}
struct MAT
{
	mat X[2][2];
};
MAT operator*(MAT a,MAT b)
{
	MAT c;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				c.X[i][j]=c.X[i][j]+(a.X[i][k]*b.X[k][j]);
			}
		}
	}
	return c;
}

int deg[200];

int main()
{
	
	scanf("%d%d%d",&n,&m,&k);
	if(k<=2){printf("0");return 0;}
	mat D,E,I;
	for(int i=1,a=0,b=0;i<=m;i++)
	{
		scanf("%d%d",&a,&b);deg[a]++,deg[b]++;E[a][b]=E[b][a]=1;
	}
	for(int i=1;i<=n;i++)I[i][i]=1;
	for(int i=1;i<=n;i++){D[i][i]=sub(1,deg[i]);}
	mat SC=E*E;for(int i=1;i<=n;i++)SC[i][i]=0;
	MAT F;F.X[0][1]=D,F.X[1][1]=E,F.X[1][0]=I;
	MAT P=F;
	k-=2;
	int B=20;while(!(k&(1<<B)))B--;
	//printf("%d\n",B);//return 0;
	for(int j=B-1;j>=0;j--)
	{
		P=P*P;if(k&(1<<j))P=P*F;
	}
	
	mat FINAL=SC*P.X[1][1]+E*P.X[0][1];
	long long ans=0;for(int i=1;i<=n;i++)ans=add(ans,FINAL[i][i]);printf("%lld",ans);
}