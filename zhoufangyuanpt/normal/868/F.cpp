#include<cstdio>
#include<cstring>
using namespace std;
long long f[110000][21],ss;
int a[110000],cnt[110000],ll,rr;
inline void add(int x){ss+=cnt[x];cnt[x]++;}
inline void del(int x){cnt[x]--;ss-=cnt[x];}
inline void move(int ql,int qr)
{
	while(ll>ql)add(a[--ll]);
	while(ll<ql)del(a[ll++]);
	while(rr<qr)add(a[++rr]);
	while(rr>qr)del(a[rr--]);
}
int k;
void dp(int l,int r,int pl,int pr)
{
	if(l>r)return ;
	int mid=(l+r)/2,p;
	for(int i=pl;i<=pr&&i<mid;i++)
	{
		move(i+1,mid);
		if(f[i][k-1]+ss<f[mid][k])
		{
			f[mid][k]=f[i][k-1]+ss;
			p=i;
		}
	}
	dp(l,mid-1,pl,p);
	dp(mid+1,r,p,pr);
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(f,63,sizeof(f));f[0][0]=0;
	memset(cnt,0,sizeof(cnt));
	ss=0;ll=1;rr=0;
	for(k=1;k<=m;k++)dp(k,n,k-1,n-1);
	printf("%lld\n",f[n][m]);
	return 0;
}