#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;

template<typename T>
using pq_gt = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using pq_lt = priority_queue<T, vector<T>, less<T>>;

#define se second
#define fi first
#define pb push_back

map<int,int> cnt;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("b1.in","r",stdin);
	int t; cin>>t;
	while(t--)
	{
		//memset(cnt,0,sizeof(cnt));
		cnt.clear();
		int n = 250;
		bool pois = 0;
		ll sum = 0;
		int maxi = 0;
		int mini = 0;
		for(int i=0;i<n;i++)
		{
			int x; cin>>x;
			maxi = max(maxi, x);
			mini = min(mini, x);
			sum+=x;
			if(x>2000)
			{
				pois=1;
			}
			else
			{
				cnt[x]++;
			}
		}
		sum=round((double)sum/(double)n);
		//maxi*=1.005;
		ll s1 = 0;
		ll s2 = 0;
		int dev = 2*sqrt(maxi);
		for(int i=sum-dev;i<=sum+dev;i++)
		{
			s1+=cnt[i];
		}
		s2=ll(2*dev+1)*ll(n)/(long double)(maxi-mini+1) + 24;
		if(s1>s2)
		{
			pois=1;
		}
		else
		{
			pois=0;
		}
		//cout<<mini<<" "<<maxi<<" ";
		if(pois) cout<<"poisson"<<endl;
		else cout<<"uniform"<<endl;
	}
}