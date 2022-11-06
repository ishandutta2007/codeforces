#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
struct ship {
	int id;
	bool is_y;
	int coor;
	int t;
};
bool operator<(const ship&l, const ship&r) {
	return l.coor-l.t<r.coor-r.t;
}
int main() {
	int H,W,Q;cin>>Q>>W>>H;

	vector<pair<int,int>>anss(Q);

	vector<ship>y_ships,x_ships;
	map<int, vector<ship>>ship_mps;

	for (int i = 0; i < Q; ++i) {
		int type,x,t;
		scanf("%d %d %d",&type,&x,&t);
		ship_mps[x - t].push_back(ship{ i,type==2,x,t });
	}
	for (auto s_m : ship_mps) {
		vector<pair<int,int>>ori_goals;

		vector<pair<pair<int,int>,int>>starts;
		for (int i = 0; i < s_m.second.size(); ++i) {
			pair<int,int>agoal;
			if (s_m.second[i].is_y) {
				agoal=make_pair(W,s_m.second[i].coor);
			}
			else {
				agoal=make_pair(s_m.second[i].coor,H);
			}
			ori_goals.push_back(agoal);
			starts.push_back(make_pair(agoal,s_m.second[i].id));
		}
		sort(ori_goals.begin(), ori_goals.end(), [](const pair<int, int>&l, const pair<int, int>&r) {
			return l.first==r.first?l.second>r.second:l.first<r.first;
		});
		sort(starts.begin(), starts.end(), [&](
			const pair<pair<int, int>, int>&l,
			const pair<pair<int, int>, int>&r) {
			if(l.first.first==r.first.first)return l.first.second>r.first.second;
			else if(l.first.first==W)return true;
			else if(r.first.first==W)return false;
			else return l.first.first<r.first.first;
		});
		for (int i = 0; i < s_m.second.size(); ++i) {
			anss[starts[i].second]=ori_goals[i];
		}
	}
	for (int i = 0; i < Q; ++i) {
		printf("%d %d\n",anss[i].first,anss[i].second);
	}
	return 0;
}