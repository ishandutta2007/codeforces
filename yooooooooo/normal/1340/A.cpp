#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
struct node
{
	int v,id;
	bool operator<(const node&y)const
	{
		return v>y.v||(v==y.v&&id<y.id);
	}
	node(int nv=0,int nid=0){v=nv;id=nid;}
};
set<int>st;
set<int>::iterator it;
set<node>st2;
int T,n,v,pos[100005],x,val[100005],u;
void add(int u,int v)
{
	st2.erase(node(val[u],u));
	val[u]+=v;
	st2.insert(node(val[u],u));
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&x),pos[x]=i;
		st.clear();st2.clear();
		for(int i=1;i<=n;i++)st.insert(i),st2.insert(node(1,i)),val[i]=1;
		for(int i=1;i<=n;i++)
		{
			v=pos[i];
			if(val[v]<st2.begin()->v)
			{
				printf("No\n");
				goto tag;	
			}
			st.erase(v);
			st2.erase(node(val[v],v));
			it=st.upper_bound(v);
			if(it!=st.end())
			{
				u=*it;
				add(u,val[v]);
			}
		}
		printf("Yes\n");
		tag:;
	}
	return 0;
}