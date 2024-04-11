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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

set<string> ma = {"h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k","ca","sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr","nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe","cs","ba","la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","hf","ta","w","re","os","ir","pt","au","hg","tl","pb","bi","po","at","rn","fr","ra","ac","th","pa","u","np","pu","am","cm","bk","cf","es","fm","md","no","lr","rf","db","sg","bh","hs","mt","ds","rg","cn","nh","fl","mc","lv","ts","og"};


int dp[1000001];

int solve(string s)
{
	int n=s.length();
	dp[n]=1;
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=0;
		string tmp = s.substr(i,1);
		if(ma.find(tmp)!=ma.end())
		{
			dp[i]+=dp[i+1];
		}
		if(i<=n-2)
		{
			tmp=s.substr(i,2);
			if(ma.find(tmp)!=ma.end())
			{
				dp[i] += dp[i+2];
			}
		}
	}
	return dp[0];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	for(int i=0;i<s.length();i++) s[i]=s[i]-'A'+'a';
	cout<<(solve(s)>0?"YES":"NO")<<'\n';
}