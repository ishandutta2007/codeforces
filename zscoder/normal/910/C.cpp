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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int cnt[55];
bool banned[111];
int powe[8];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	powe[0]=1;
	for(int i=1;i<=7;i++) powe[i]=powe[i-1]*10;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		banned[s[0]-'a']=1;
		for(int j=0;j<s.length();j++)
		{
			int coeff = powe[int(s.length()) - 1 - j];
			cnt[s[j]-'a']+=coeff;
		}
	}
	vi vec;
	for(int i=0;i<10;i++) vec.pb(i);
	int ans=INT_MAX;
	do
	{
		if(!banned[vec[0]])
		{
			int res=0;
			for(int i=1;i<=9;i++)
			{
				res+=cnt[vec[i]]*i;
			}
			ans=min(ans,res);
		}
	}while(next_permutation(vec.begin(),vec.end()));
	cout<<ans<<'\n';
}