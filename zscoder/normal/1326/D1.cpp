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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> prefix_function (string Z) 
{
    int n = (int) Z.length();
    vector<int> F (n);
    F[0]=0;
    for (int i=1; i<n; ++i) 
    {
        int j = F[i-1];
        while (j > 0 && Z[i] != Z[j])
		{
            j = F[j-1];
        }
        if (Z[i] == Z[j])  ++j;
        F[i] = j;
    }
    return F;
}

string lpal(string s)
{
	string t = s;
	reverse(t.begin(),t.end());
	s+="*";
	s+=t;
	vector<int> v = prefix_function(s);
	return s.substr(0,v.back());
}

void solve()
{
	string s; cin>>s;
	int n=s.length();
	int l=0; int r=n-1;
	while(l<r&&s[l]==s[r])
	{
		l++; r--;
	}
	//solve for the segment [l,r]
	string tp = "";
	if(l<=r) tp=s.substr(l,r-l+1);
	string tmp = lpal(tp);
	reverse(tp.begin(),tp.end());
	string tmp2 = lpal(tp);
	if(tmp2.length()>tmp.length()) swap(tmp,tmp2);
	string ans;
	for(int i=0;i<l;i++) ans+=s[i];
	ans+=tmp;
	for(int i=r+1;i<n;i++) ans+=s[i];
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}