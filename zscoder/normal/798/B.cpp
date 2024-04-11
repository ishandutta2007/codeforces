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

ll m, n, ans, cur, tans, slen;
string s[51];
bool same, trigger;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ans = 2e9;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	slen = s[0].size();
	tans = 2e9;
	for(int i = 0; i < n; i++){
		ans=0;
		for(int j = 0; j < n; j++){
			cur = 2e9;
			for(int k = 0; k < slen; k++){
				same = 1;
				for(int l = 0; l < slen; l++){
					if(s[i][l] != s[j][(l+k)%slen]){
						same = 0;
					}
				}
				if(same){
					cur = min(int(cur), k);
				}
			}
			ans += cur;
		}
		tans = min(ans, tans);
	}
	if(tans != 2e9){
	cout << tans;
}
else{
	cout << -1;
}
				
				
}