#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

struct aa{
	int type;
	int s;
};

int solve(vector<aa>speeds) {
	int ans=0;
	int nowspeed = 0;
	stack<int>lim_speeds;
	lim_speeds.push(10000);
	for (auto a : speeds) {
		if (a.type == 1) {
			nowspeed = a.s;
			while (nowspeed > lim_speeds.top()) {
				lim_speeds.pop();
				ans++;
			}
		}
		else if (a.type == 3) {
			if (nowspeed > a.s)ans++;
			else {
				lim_speeds.push(a.s);
			}
			
			
		}
	}
	return ans;
}

int main() {

	int N; cin >> N;
	vector<aa>speeds,overs;
	bool canovertake = true;
	int ans = 0;
	int overtake = 0;
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		if (a == 2 || a == 4 || a == 6) {
			if (a == 2) {
				overs.push_back(aa{ 1,100 });
				overs.push_back(aa{ 1,-10 });
			}
			else if (a == 4) {
				overs.push_back(aa{ 3,10000 });
			}
			else {
				overs.push_back(aa{ 3,0 });
			}
		}
		else {
			int s;
			if (a == 5) {
				a = 3;
				s = 10000;
			}
			else {
				 cin >> s;
			}
			speeds.push_back(aa{ a,s });
		}
		
	}

	//cout << ans << endl;
	ans = solve(speeds);
	ans += solve(overs);
	cout << ans << endl;
	return 0;
}