#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int c[300000],x[300000];
const int INF=1e9;

vector<int> V;vector<pair<int,int> > E;

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&c[i]);}
	for(int i=1;i<=m;i++)scanf("%d",&x[i]);x[0]=-INF;sort(x+1,x+m+1);
	for(int i=1,j=0;i<=n;i++)
	{
		while(j+1<=m&&x[j+1]<=(i-1)*100)j++;
		int p=(i-1)*100-x[j];if(j!=m)p=min(p,x[j+1]-(i-1)*100);
		if(p==0)continue;//printf("%d %d\n",(i-1)*100-p,(i-1)*100+p);
		E.push_back(make_pair((i-1)*100-p,c[i])),E.push_back(make_pair((i-1)*100+p,-c[i]));
		V.push_back((i-1)*100-p),V.push_back((i-1)*100+p);
	}
	sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()),V.end());
	sort(E.begin(),E.end());
	//for(int i=0;i<V.size();i++)printf("%d ",V[i]);puts("");
	//for(int i=0;i<E.size();i++)printf("%d %d\n",E[i].first,E[i].second);puts("END");
	long long ans=0,sum=0;
	for(int i=0,j=0;i<V.size();i++)
	{
		while(j<E.size()&&E[j].first==V[i])
		{
			sum+=E[j].second;j++;
		}
		//printf("%d %d\n",V[i],sum);
		ans=max(ans,sum);
	}
	printf("%lld",ans);
}