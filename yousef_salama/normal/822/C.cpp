#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, x, li, ri, costi, d[MAXN];
vector < pair <int, pair <int, int> > > L, R;

int main(){
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &li, &ri, &costi);

		L.push_back({li, {ri - li + 1, costi}});
		R.push_back({ri, {ri - li + 1, costi}});
	}

	memset(d, -1, sizeof d);

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	int r = -1;

	int j = (int)L.size() - 1;
	for(int i = (int)R.size() - 1; i >= 0; i--){
		while(j >= 0 && L[j].first > R[i].first){
			if(d[L[j].second.first] == -1)d[L[j].second.first] = L[j].second.second;
			else d[L[j].second.first] = min(d[L[j].second.first], L[j].second.second);

			j--;
		}

		if(R[i].second.first <= x && d[x - R[i].second.first] != -1){
			int c = R[i].second.second + d[x - R[i].second.first];
			if(r == -1 || c < r)r = c;
		}
	}
	printf("%d\n", r);

	return 0;
}