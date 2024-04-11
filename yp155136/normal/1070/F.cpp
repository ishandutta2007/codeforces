#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define MAX 400900

vector<int> v[10];
priority_queue<int , vector<int> , greater<int> > sml;

int n , val;
string s;
int main(){
	cin >> n;
	REP(i , 1 , n + 1){
		cin >> s >> val;
		if(s == "00") v[0].pb(val);
		if(s == "01") v[1].pb(val);
		if(s == "10") v[2].pb(val);
		if(s == "11") v[3].pb(val);
	}
	REP(i , 0 , 4) sort(v[i].begin() , v[i].end());
	int ans = 0;
	while(v[3].size() && v[0].size()){
		ans += v[0].back() + v[3].back();
		sml.push(v[0].back());
		v[0].pop_back();
		v[3].pop_back();
	}
	while(v[1].size() && v[2].size()){
		ans += v[1].back() + v[2].back();
		v[1].pop_back();
		v[2].pop_back();
	}

	/*REP(i , 0 , 4){
		for(auto to : v[i]) cout << to << " "; cout << endl;
	}
	cout << "ans = " << ans << endl;*/
	if(v[3].size()){
		while(v[1].size() && v[3].size()){
			ans += v[1].back() + v[3].back();
			v[1].pop_back();
			v[3].pop_back();
		}
		while(v[2].size() && v[3].size()){
			ans += v[2].back() + v[3].back();
			v[2].pop_back();
			v[3].pop_back();
		}
		while(v[3].size()) ans += v[3].back() , v[3].pop_back();

		// while(sml.size() && v[2].size() && sml.top() < v[2].back()){
		// 	ans += v[2].back() - sml.top();
		// 	v[2].pop_back();
		// 	sml.pop();
		// }
		// while(sml.size() && v[3].size() && sml.top() < v[3].back()){
		// 	ans += v[3].back() - sml.top();
		// 	v[3].pop_back();
		// 	sml.pop();
		// }
	}
	
	vector<int> sol;
	for(auto to : v[1]) sol.pb(to);
	for(auto to : v[2]) sol.pb(to);
	sort(sol.begin() , sol.end());
	while(sml.size() && sol.size() && sml.top() < sol.back()){
		ans += sol.back() - sml.top();
		sol.pop_back();
		sml.pop();
	}
	cout << ans << endl;
	return 0;
}