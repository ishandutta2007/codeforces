#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
	int id;
	ll x;
}a[200005];
ll n,W,T,sum=0,tot=0,y;
vector<int>ans;
bool cmp(node a,node b){return a.x>b.x;}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		sum=0;tot=0;ans.clear();
		scanf("%lld%lld",&n,&W);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&y);
			if(y>W)continue;
			tot++;
			a[tot].x=y;a[tot].id=i;
			sum+=a[tot].x;
		}
		sort(a+1,a+tot+1,cmp);
		if(sum<(W+1)/2)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=tot;i++)
		{
			if(a[i].x>W)continue;
			ans.push_back(a[i].id);
			W-=a[i].x;
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
		{
			printf("%d",ans[i]);
			if(i==(int)ans.size()-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}