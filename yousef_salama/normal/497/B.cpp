#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN], s1[MAXN], s2[MAXN], i1[MAXN], i2[MAXN], d[MAXN];
vector < pair <int, pair <int, int> > > queries[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	memset(i1, -1, sizeof i1);
	memset(i2, -1, sizeof i2);

	for(int i = 0; i < n; i++){
		s1[i] = (a[i] == 1);
		s2[i] = (a[i] == 2);

		if(i > 0){
			s1[i] += s1[i - 1];
			s2[i] += s2[i - 1];
		}

		if(a[i] == 1)i1[s1[i]] = i;
		if(a[i] == 2)i2[s2[i]] = i;
	}

	memset(d, -1, sizeof d);
	for(int i = 1; i <= n; i++)
		queries[0].push_back({i, {0, 0}});

	for(int i = 0; i < n; i++){
		for(pair <int, pair <int, int> > t : queries[i]){
			int e1 = i == 0 ? 0 : s1[i - 1];
			int e2 = i == 0 ? 0 : s2[i - 1];

			int j1 = i1[e1 + t.first];
			int j2 = i2[e2 + t.first];

			if(j1 == -1 && j2 == -1)continue;
			if(j2 == -1 || (j1 != -1 && j1 < j2)){
				if(j1 + 1 == n && t.second.first + 1 > t.second.second)
					d[t.first] = t.second.first + 1;

				queries[j1 + 1].push_back({t.first, {t.second.first + 1, t.second.second}});
			}else{
				if(j2 + 1 == n && t.second.second + 1 > t.second.first)
					d[t.first] = t.second.second + 1;

				queries[j2 + 1].push_back({t.first, {t.second.first, t.second.second + 1}});
			}
		}
	}

	vector < pair <int, int> > v;
	for(int i = 1; i <= n; i++)
		if(d[i] != -1)v.push_back({d[i], i});
	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for(pair <int, int> p : v)
		printf("%d %d\n", p.first, p.second);

	return 0;
}