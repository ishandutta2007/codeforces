#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <int> a(6);
	for(int i = 0; i < 6; i++)scanf("%d", &a[i]);
	
	int n;
	scanf("%d", &n);
	
	vector <int> b(n), vx;
	vector < multiset <int> > mn(n);
	vector < pair <int, int> > evs;
	int mx = 0;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
		
		for(int j = 0; j < 6; j++){
			vx.push_back(b[i] - a[j]);
			mn[i].insert(b[i] - a[j]);
			evs.push_back({b[i] - a[j], i});
		}
		mx = max(mx, *mn[i].begin());
	}
	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	sort(evs.begin(), evs.end());
	
	int res = 1 << 30;
	
	int j = 0;
	bool ok = true;
	for(int x : vx){
		res = min(res, mx - x);
		
		while(j < (int)evs.size() && evs[j].first == x){
			mn[evs[j].second].erase(mn[evs[j].second].lower_bound(x));
			
			if(mn[evs[j].second].empty()){
				ok = false;
				break;
			}else mx = max(mx, *mn[evs[j].second].begin());
			
			j++;
		}
		if(!ok)break;
	}
	printf("%d\n", res);
	
	return 0;
}