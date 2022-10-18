#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, ai, bi;
vector <int> v[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ai, &bi);
		v[ai].push_back(bi);
	}

	multiset <int> F;
	int c = 0;

	vector <int> candidate;
	for(int i = 0; i < MAXN; i++){
		sort(v[i].rbegin(), v[i].rend());

		if(!v[i].empty()){
			for(int y : v[i])c += y;
			candidate.push_back(i);
		}
	}

	int r = 1 << 30;
	for(int X = 1; X <= n; X++){
		r = min(r, c);

		if(X < n){
			vector <int> ncandidate;
			for(int i : candidate){
				c -= v[i][X - 1];
				F.insert(v[i][X - 1]);

				if(v[i].size() > X)ncandidate.push_back(i);
			}
			while(n - (int)F.size() < X + 1){
				c += *F.begin();
				F.erase(F.begin());
			}

			candidate = ncandidate;
		}
	}
	printf("%d\n", r);

	return 0;
}