#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 510
using namespace std;

int n,fa[N];
P num[N];
set<int>node;

inline void out()
{
    int i,j;
    puts("ANSWER");
    for(i=2;i<=n;i++) printf("%d %d\n",fa[i],i);
}

void dfs(int rt,set<int>::iterator now,int cnt)
{
    if(cnt==1)
    {
	fa[*now]=rt;
	node.erase(now);
	return;
    }
    int i,t,mid=(cnt>>1);
    set<int>::iterator tmp=now;
    printf("%d\n",mid);
    for(i=1;i<=mid;i++,now++)
    {
	printf("%d ",*now);
    }
    printf("\n1\n1\n%d\n",rt);fflush(stdout);
    scanf("%d",&t);
    if(t) dfs(rt,tmp,mid);
    
    printf("%d\n",cnt-mid);
    tmp=now;
    for(i=mid+1;i<=cnt;i++,now++)
    {
	printf("%d ",*now);
    }
    printf("\n1\n1\n%d\n",rt);fflush(stdout);
    scanf("%d",&t);
    if(t) dfs(rt,tmp,cnt-mid);
}

int main()
{
    int i,j;
    cin>>n;
    if(n==2)
    {
	fa[2]=1;
	out();
	return 0;
    }
    for(i=2;i<=n;i++)
    {
	num[i-1].se=i;
	printf("%d\n",n-2);
	for(j=2;j<=n;j++)
	{
	    if(i==j) continue;
	    printf("%d ",j);
	}
	printf("\n1\n1\n%d\n",i);
	fflush(stdout);
	scanf("%d",&num[i-1].fi);
    }
    sort(num+1,num+n);
    for(i=1;i<n;i++)
    {
	if(!num[i].fi)
	{
	    node.insert(num[i].se);
	    continue;
	}
	dfs(num[i].se,node.begin(),node.size());
	node.insert(num[i].se);
    }
    for(set<int>::iterator it=node.begin();it!=node.end();it++) fa[*it]=1;
    out();
}