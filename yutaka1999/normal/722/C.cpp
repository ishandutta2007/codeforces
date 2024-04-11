#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll sum[SIZE];

ll get(int s,int t)
{
	return sum[t]-(s==0?0:sum[s-1]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll a;
		scanf("%lld",&a);
		sum[i]=a+(i==0?0:sum[i-1]);
	}
	set <P> st;
	set <P>::iterator it;
	st.insert(P(0,n-1));
	multiset <ll> ml;
	multiset <ll>::iterator its;
	ml.insert(sum[n-1]);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);p--;
		it=st.lower_bound(P(p+1,-1));
		it--;
		int s=it->first,t=it->second;
		st.erase(it);
		its=ml.lower_bound(get(s,t));
		ml.erase(its);
		st.insert(P(s,p-1));
		st.insert(P(p+1,t));
		ml.insert(get(s,p-1));
		ml.insert(get(p+1,t));
		its=ml.end();its--;
		printf("%lld\n",*its);
	}
	return 0;
}