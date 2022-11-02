#include<cstdio>
#include<cstring>
#include<set>
//#include<iostream>
#include<algorithm> 
#define maxn 205000
#define mkp(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int n,m,d;

int a[maxn];

set<pii> s;

int ans[maxn];

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		s.insert(mkp(x,i));
//		printf("%d %d\n",x,i);
//		scanf("%d",&a[i]);
	}
	
	int last=-d,t=1;
	while (!s.empty())
	{
		if (last>=m)
			++t,last=-d;
//		cout<<last<<" "<<last+d+1<<" "<<s.size()<<endl;
//		printf("%d %d %d\n",last,last+d,s.size()); 
		auto it=s.lower_bound(mkp(last+d,-1));
		if (it==s.end())
			++t,last=-d;
		else
		{
			ans[it->second]=t;
			last=it->first+1;
//			printf("choose:%d %d\n",it->second,it->first);
			s.erase(it);
		}
	}
	
	printf("%d\n",t);
	for (int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}