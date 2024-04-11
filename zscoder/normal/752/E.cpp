#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[1000001];
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; scanf("%d %d",&n,&k);
	int maxi=0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",a+i);
		maxi=max(maxi,a[i]);
	}
	int lo = 1; int hi = maxi;
	int ans = -1;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		ll cnt = 0;
		for(int i = 0; i < n; i++)
		{
			int tmp = a[i];
			int l = 1; int r = 0; //r = cur + 1;
			ll curcnt=0;
			ll maxc=0;
			while(tmp+1>=mid)
			{
				//cerr<<tmp<<' '<<tmp+1<<' '<<l<<' '<<r<<'\n';
				curcnt=r;
				if(tmp>=mid) curcnt+=l;
				maxc=max(maxc,curcnt);
				if(tmp==0) break;
				int l2 = 0; int r2 = 0;
				if(tmp&1)
				{
					l2=l;
					r2=l+r*2;
					tmp>>=1;
				}
				else
				{
					l2=l*2+r;
					r2=r;
					tmp>>=1;
				}
				l=l2;r=r2;
			}
			cnt+=maxc;
		}
		//1cerr<<mid<<' '<<cnt<<'\n';
		if(cnt>=k)
		{
			lo=mid+1;
			ans=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	printf("%d",ans);
}