#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define SIZE 1000005
#define MX 100005

using namespace std;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE];
	int n;
	
	void add(int k,int x)
	{
		while(k<=n)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int sum(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
};
BIT bit;
vector <P> vec[SIZE];
int rui[SIZE],ans[SIZE];
int tg[SIZE];
char str[SIZE];
int n;

int main()
{
	scanf("%s",&str);
	n=strlen(str);
	int mn=0;
	for(int i=0;i<n;i++)
	{
		rui[i]=str[i]=='('?1:-1;
		if(i>0) rui[i]+=rui[i-1];
		mn=min(mn,rui[i]);
	}
	for(int i=0;i<n;i++) rui[i]-=mn;
	stack <int> st;
	for(int i=0;i<n;i++)
	{
		tg[i]=-1;
		if(str[i]=='(') st.push(i);
		else
		{
			if(!st.empty())
			{
				int tp=st.top();st.pop();
				tg[tp]=i;
			}
		}
	}
	bit.n=n+2;
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(P(b,i));
	}
	for(int i=n-1;i>=0;i--)
	{
		if(tg[i]>=0) bit.add(tg[i]+1,1);
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j];
			ans[p.second]=bit.sum(p.first+1);
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]*2);
	return 0;
}