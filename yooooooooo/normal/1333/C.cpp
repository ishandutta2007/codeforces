#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,a[200005],ans=0,r;
set<ll>st;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	r=0;
	st.insert(0);
	for(int i=0;i<n;i++)
	{
		while(r<n&&st.find(a[r+1])==st.end())
		{
			r++;
			st.insert(a[r]);
		}
		ans+=r-i;
		st.erase(a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}