#include<cstdio>
#include<cstring>
#include<algorithm> 
#define wx(i)	printf("%d\n",i)
#define maxn 205000
using namespace std;
typedef long long LL;

int n;

int pos[maxn];
LL t,a[maxn];

int T[maxn];

bool cmp(int i,int j)
{
	return a[i]<a[j];
}

int lowbit(int i)
{
	return i&(-i);
}

void change(int i,int d)
{
	for (;i<=n;i+=lowbit(i))
		T[i]+=d;
}

int query(int i)
{
	if (!i)	return 0;
	int ans=0;
	for (;i;i-=lowbit(i))
		ans+=T[i];
	return ans;
}

LL ans=0;

int main()
{
//	freopen("c.in","r",stdin);
	scanf("%d%I64d",&n,&t);
	for (int i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
		a[i]+=a[i-1];
		if (a[i]<t)	++ans;
		pos[i]=i;
	}
	
	sort(pos+1,pos+n+1,cmp);
	for (int i=1;i<=n;++i)
		T[i]=lowbit(i);
	for (int k=1,j=1;k<=n;++k)
	{
//		printf("%d:\n",pos[k]);
		while (j<=n&&a[pos[j]]+t<=a[pos[k]])	//printf("out:%d\n",pos[j]),
			change(pos[j++],-1);
		ans+=query(pos[k]-1);
		
//		printf("%d:%d\n",pos[k],ans);
	}
	
	printf("%I64d\n",ans); 
	return 0;
}