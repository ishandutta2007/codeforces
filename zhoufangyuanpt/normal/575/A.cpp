#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int P;
struct node
{
	long long a,b,c,d;
}c[51000],p[51000],s[51000],f[51000];
inline node operator*(node a,node b){return {(a.a*b.a+a.b*b.c)%P,(a.a*b.b+a.b*b.d)%P,(a.c*b.a+a.d*b.c)%P,(a.c*b.b+a.d*b.d)%P};}
node ksm(node x,long long k)
{
	node s={1,0,0,1};
	while(k>0)
	{
		if(k&1)s=s*x;
		x=x*x;
		k>>=1;
	}
	return s;
}
struct Q{long long j,v;}Qt[51000];
inline bool cmp(Q x,Q y){return x.j<y.j;}
int sg[51000];
int main()
{
	long long K;scanf("%lld%d",&K,&P);
	if(K==0){printf("0\n");return 0;}
	int N;scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&sg[i]);
	int M;scanf("%d",&M);
	for(int i=1;i<=M;i++)scanf("%lld%lld",&Qt[i].j,&Qt[i].v);
	sort(Qt+1,Qt+M+1,cmp);
	for(int i=1;i<=N;i++)c[i%N]={0,sg[i-1]%P,1,sg[i%N]%P};
	p[0]={1,0,0,1};
	for(int i=1;i<=N;i++)p[i]=p[i-1]*c[i-1];
	s[N]={1,0,0,1};
	for(int i=N-1;i>=0;i--)s[i]=c[i]*s[i+1];
	for(int i=0;i<=N-199;i++)
	{
		f[i]={1,0,0,1};
		for(int j=i;j<=i+199;j++)f[i]=f[i]*c[j];
	}
	long long i=1,j=1;node ss={1,0,0,1};
	Qt[0]={1,sg[1]};
	while(j<=M&&Qt[j].j<K)
	{
		if(i!=Qt[j].j)ss=ss*(node){0,Qt[j-1].v%P,1,sg[i%N]%P},i++;
		if(i/N<Qt[j].j/N)
		{
			ss=ss*s[i%N];
			ss=ss*ksm(p[N],Qt[j].j/N-i/N-1);
			i=Qt[j].j;
			ss=ss*p[i%N];
			ss=ss*(node){0,sg[(i-1)%N]%P,1,Qt[j].v%P};
			i++;
		}
		else if(Qt[j-1].j+1==Qt[j].j)
		{
			ss=ss*(node){0,Qt[j-1].v%P,1,Qt[j].v%P};
			i++;
		}
		else
		{
			while(i+200<=Qt[j].j)ss=ss*f[i%N],i+=200;
			while(i<Qt[j].j)ss=ss*c[i%N],i++;
			ss=ss*(node){0,sg[(i-1)%N]%P,1,Qt[j].v%P};
			i++;
		}
		j++;
	}
	if(1<j&&j-1<=M&&i<K)ss=ss*(node){0,Qt[j-1].v%P,1,sg[i%N]%P},i++;
	if(i/N<K/N)
	{
		ss=ss*s[i%N];
		ss=ss*ksm(p[N],K/N-i/N-1);
		i=K;
		ss=ss*p[i%N];
	}
	else if(i<K)
	{
		while(i+200<=K)ss=ss*f[i%N],i+=200;
		while(i<K)ss=ss*c[i%N],i++;
	}
	printf("%lld\n",ss.d%P);
	return 0;
}