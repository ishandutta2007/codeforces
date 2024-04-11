#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100050;
const int SHIFT = 100005;

struct dancer{
	int x, y, d, index;
};

int n, w, h, gi, pi, ti, resx[MAXN], resy[MAXN];
vector <dancer> v[2 * MAXN];

int main(){
	scanf("%d %d %d", &n, &w, &h);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &gi, &pi, &ti);

		dancer c;
		if(gi == 1){
			c = {pi, -ti, 1, i};
		}else{
			c = {-ti, pi, 2, i};
		}

		v[c.x + c.y + SHIFT].push_back(c);
	}

	for(int i = 0; i < 2 * MAXN; i++){
		vector < pair <int, pair <int, int> > > final_positions;
		vector < pair <int, int> > dancers;

		for(dancer c : v[i]){
			if(c.d == 1)final_positions.push_back({c.x - h, {c.x, h}});
			else final_positions.push_back({w - c.y, {w, c.y}});

			dancers.push_back({c.x - c.y, c.index});
		}

		sort(final_positions.begin(), final_positions.end());
		sort(dancers.begin(), dancers.end());

		for(int j = 0; j < (int)v[i].size(); j++){
			resx[dancers[j].second] = final_positions[j].second.first;
			resy[dancers[j].second] = final_positions[j].second.second;
		}
	}

	for(int i = 0; i < n; i++)
		printf("%d %d\n", resx[i], resy[i]);

	return 0;
}