// testing how fast is tree_policy
//...

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

typedef
tree<pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      int n;
      cin>>n;
      ordered_set X;
      ordered_set Y;
      vi k(n);
      vi v(n);
      for(int i=0; i<n; i++)
      {
        cin>>k[i]>>v[i];
        X.insert({k[i], i});
        Y.insert({v[i], i});
      }
      int bestans=n-1;
      for(int i=0; i<n; i++)
      {
        int kk=Y.order_of_key({k[i], -1});
        int vv=X.order_of_key({v[i], 1e9+1});
        vv=n-vv;
        if(kk+vv<bestans) bestans=kk+vv;
      }
      cout<<bestans<<'\n';
    }

    return 0;
}