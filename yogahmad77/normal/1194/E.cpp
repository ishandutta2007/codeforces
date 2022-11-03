#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
#define MOD 998244353 
#define mx 35004
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
int main(){
	int n, ax, ay, bx, by;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	long long jaw = 0;
    cin >> n;
	vector<pair<int, pair<int, int>>> hor, ver;
    for(int i = 0; i < n; i++){
		cin >> ax >> ay >> bx >> by;
		if(ax > bx)
			swap(ax, bx);
		if(ay > by)
			swap(ay, by);
		if(ax == bx)
			ver.pb({ax, {ay, by}});
		else hor.pb({ay, {ax, bx}});
    }
	sort(ALL(ver));
	for(auto i : ver){
		int now = -1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pbds ini;
		for(auto j : hor){
			if(j.s.f > i.f || j.s.s < i.f)
				continue;
			pq.push({j.s.s, j.f});
			ini.insert(j.f);
		}
		for(auto j : ver){
			if(i.f >= j.f)
				continue;
			if(max(j.s.f, i.s.f) >= min(j.s.s, i.s.s))
				continue;
			while(!pq.empty() && pq.top().f < j.f){
				int now = pq.top().s; pq.pop();
				ini.erase(now);
			}
			int it2 = ini.order_of_key(min(j.s.s, i.s.s) + 1);
			int it1 = ini.order_of_key(max(j.s.f, i.s.f));
			jaw = jaw + 1LL * (it2 - it1) * (it2 - it1 - 1) / 2;
		}
	}
	cout << jaw << endl;
}