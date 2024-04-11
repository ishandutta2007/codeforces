#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=2e3+1e2+7;

int n;

struct P{
	int x,y,a,id;
}p[N],C;

P operator -(const P &a,const P &b)
{
	return P{a.x-b.x,a.y-b.y,0,0};
}

int cross(const P &a,const P &b)
{
	return a.x*b.y-a.y*b.x;
}

bool cmp(const P &a,const P &b)
{
	return cross(a-C,b-C)>0;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int fa[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

vector<pii>ans;

int pos[N];

bool cmpx(const P &a,const P &b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].a),p[i].id=i;
	sort(p+1,p+n+1,cmpx);
	int c=0;
	for(int i=1;i<=n;i++)
		if(p[i].a!=p[i].id)
		{
			c=i;
			break;
		}
	if(c==0)
	{
		puts("0");
		return 0;
	}
	C=p[c];
	sort(p+c+1,p+n+1,cmp);
	
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int fx=find(p[i].id),fy=find(p[i].a);
		if(fx!=fy)
			fa[fx]=fy;
	}
	for(int i=c+1;i<n;i++)
	{
		int fx=find(p[i].id),fy=find(p[i+1].id);
		if(fx==fy)
			continue;
		swap(p[i].a,p[i+1].a);
		ans.push_back(mp(p[i].id,p[i+1].id));
		fa[fx]=fy;
	}
	for(int i=c;i<=n;i++)
		pos[p[i].id]=i;
	for(int i=c;i<n;i++)
	{
		int x=c,y=pos[p[x].a];
		ans.push_back(mp(p[x].id,p[y].id));
		swap(p[x].a,p[y].a);
	}
	// for(int i=1;i<=n;i++)
	// 	assert(p[i].id==p[i].a);
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)
		printf("%lld %lld\n",x,y);
}