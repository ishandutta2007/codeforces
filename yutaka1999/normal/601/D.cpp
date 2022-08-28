#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 300005
#define M1 1000000007LL
#define M2 1000000009LL
#define B1 79351LL
#define B2 89393LL

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

vector <int> vec[SIZE];
char str[SIZE];
int cnt[SIZE];

set <P> dfs(int v=0,int p=-1,ll h1=0,ll h2=0)
{
	h1*=B1;
	h1+=str[v]-'a'+1;
	h1%=M1;
	h2*=B2;
	h2+=str[v]-'a'+1;
	h2%=M2;
	set <P> st;
	st.insert(P(h1,h2));
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			set <P> nxt=dfs(to,v,h1,h2);
			if(nxt.size()>st.size()) swap(st,nxt);
			for(set <P>::iterator it=nxt.begin();it!=nxt.end();it++) st.insert(*it);
		}
	}
	cnt[v]+=st.size();
	return st;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&cnt[i]);
	scanf("%s",&str);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	int mx=-1,c=0;
	for(int i=0;i<n;i++)
	{
		if(mx<cnt[i])
		{
			mx=cnt[i];
			c=0;
		}
		if(mx==cnt[i]) c++;
	}
	printf("%d\n",mx);
	printf("%d\n",c);
	return 0;
}