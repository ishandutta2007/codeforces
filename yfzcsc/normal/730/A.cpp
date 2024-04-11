#include<bits/stdc++.h>

using namespace std;

const int maxn=120;

int n;

int a[maxn],vis[maxn];

vector <int > ans[maxn*maxn];

struct node
{
	int id,x;
	bool operator < (const node &a) const
	{
		return x<a.x;
	}
};

bool chk(int xx)
{
	int b[maxn];
	int maxx=0,sum=0;
	for(int i=1;i<=n;i++)
		b[i]=a[i]-xx,maxx=max(maxx,b[i]),sum+=b[i];
	if((maxx<<1)>sum)
		return false;
	priority_queue <node> q;
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			node d;
			d.id=i,d.x=b[i];
			q.push(d);
		}
	}
	int cnt=0;
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		node y=q.top();
		q.pop();
		x.x--,y.x--;
		ans[++cnt].push_back(x.id);
		ans[cnt].push_back(y.id);
		if(!x.x&&!y.x&&q.size()==1)
		{
			node t=q.top();
			ans[cnt].push_back(t.id);
			q.pop();
		}
		if(x.x)
			q.push(x);
		if(y.x)
			q.push(y);
	}
	printf("%d\n%d\n",xx,cnt);
	for(int i=1;i<=cnt;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=0;j<ans[i].size();j++)
			vis[ans[i][j]]=true;
		for(int j=1;j<=n;j++)
			if(!vis[j])
				printf("0");
			else
				printf("1");
		putchar(10);
	}
	return true;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("a.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		printf("%d\n0",a[1]);
		return 0;
	}
	if(n==2)
	{
		if(a[1]==a[2])
		{
			printf("%d\n0",a[1]);
			return 0;
		}
		else
		{
			int t=max(a[1],a[2]);
			printf("%d\n%d\n",0,t);
			for(int i=1;i<=t;i++)
			{
				printf("11\n");
			}
			return 0;
		}
	}
	int minn=120;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,a[i]);
	}
	for(int i=minn;i>=0;i--)
	{
		if(chk(i))
		{
			return 0;
		}
	}
	printf("0\n%d\n",(n-1)*100);
	for(int i=1;i<=100;i++)
		for(int j=1;j<n;j++)
		{
			for(int k=1;k<=n;k++)
				if(k==j||k==j+1)printf("1");else printf("0");
			printf("\n");
		}
}