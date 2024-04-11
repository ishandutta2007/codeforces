#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SIZE 500005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <P> query[SIZE];

int main()
{
	int n,p,q,r;
	scanf("%d %d %d %d",&n,&p,&q,&r);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		query[a].push_back(P(b,r));
		query[a].push_back(P(q,c));
		query[p].push_back(P(b,c));
	}
	ll sum=0;
	ll ret=0;
	set <P> st;
	set <P>::iterator it;
	st.insert(P(q,0));
	st.insert(P(0,SIZE));
	for(int i=p;i>=1;i--)
	{
		for(int j=0;j<query[i].size();j++)
		{
			P pt=query[i][j];
			it=st.lower_bound(P(pt.first,-1));
			if(it->second>=pt.second) continue;
			while(1)
			{
				P q=*it;
				//printf("%d %d : %d %d\n",pt.first,pt.second,q.first,q.second);
				if(q.second>pt.second) break;
				it--;
				P r=*it;
				int len=min(pt.first,q.first)-r.first;
				sum+=(ll) len*(ll) (pt.second-q.second);
				if(q.first<=pt.first) st.erase(q);
			}
			st.insert(pt);
		}
		ret+=(ll) q*(ll) r-sum;
	}
	printf("%lld\n",ret);
	return 0;
}