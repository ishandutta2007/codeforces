#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const long long MOD=1e9+7;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

struct SegmentTree
{
	struct nd
	{
		int sum,lc,rc;
	}t[6000000];int used;
	int new_node(){++used;t[used].sum=t[used].lc=t[used].rc=0;return used;}
	void clear(){used=0;}
	void add_val(int pos,int v,int L,int R,int &k)
	{
		if(!k)k=new_node();t[k].sum=add(t[k].sum,v);if(L==R)return;
		int mid=(L+R)>>1;if(pos<=mid)add_val(pos,v,L,mid,t[k].lc);else add_val(pos,v,mid+1,R,t[k].rc);
	}
	
	int query_sum(int l,int r,int L,int R,int k)
	{
		if(k==0||l>R||r<L)return 0;if(l<=L&&R<=r)return t[k].sum;
		int mid=(L+R)>>1;
		return add(query_sum(l,r,L,mid,t[k].lc),query_sum(l,r,mid+1,R,t[k].rc));
	}
}T;

int n,a[300000];
long long cnt[300000],cnts[300000];

bool acmp(int x,int y){return a[x]<a[y];}

const int INF=1e9+1;

int p[300000];vector<int> V,item[300000];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		T.clear();int rt=0;
		for(int i=1;i<=n;i++)
		{
			cnt[i]=add(1,T.query_sum(0,a[i]-1,0,INF,rt));
			T.add_val(a[i],cnt[i],0,INF,rt);
		}
		T.clear();rt=0;
		for(int i=n;i>=1;i--)
		{
			cnts[i]=add(1,T.query_sum(a[i]+1,INF,0,INF,rt));
			T.add_val(a[i],cnts[i],0,INF,rt);
		}
		int maxs=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]>maxs){maxs=a[i];V.push_back(i);}
		}
		for(int i=1;i<=n;i++)p[i]=i;sort(p+1,p+n+1,acmp);
		//for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
		for(int i=1,j=0;i<=n;i++)
		{
			while(j<V.size()&&a[V[j]]<=a[p[i]])j++;
			if(j==V.size())break;
			if(p[i]<V[j])item[j].push_back(p[i]);
		}
		//for(int i=1;i<=n;i++)printf("%lld ",cnts[i]);puts("");
		int ans=0;
		for(int j=0;j<V.size();j++)
		{
			sort(item[j].begin(),item[j].end());T.clear();rt=0;int u=V[j];//printf("%d: \n",u);
			T.add_val(a[u],1,0,INF,rt);
			for(int k=item[j].size()-1;k>=0;k--)
			{
				u=item[j][k];//printf("%d\n",u);
				int s=T.query_sum(a[u]+1,INF,0,INF,rt);
				ans=add(ans,(long long)cnt[u]*sub(cnts[u],s)%MOD);//printf("%d %d %d\n",cnt[u],cnts[u],s);
				T.add_val(a[u],s,0,INF,rt);
			}
		}
		printf("%d\n",ans);
		for(int i=0;i<=n;i++)item[i].clear();V.clear();
	}
}