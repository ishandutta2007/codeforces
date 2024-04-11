#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	k>>=1;
	string s; cin>>s;
	string ans; int cnt=0; int tot=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			cnt++; tot++; ans+='(';
			if(tot>=k)
			{
				while(ans.length()<2*k) ans+=')';
				break;
			}
		}
		else
		{
			cnt--;
			ans+=")";
		}
	}
	cout<<ans<<'\n';
}