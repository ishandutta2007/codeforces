#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, k[MAXN], r[MAXN];
pair < pair <int, int>, int> a[MAXN];
pair < pair <int, int>, int> b[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a[i].first.first, &a[i].first.second);
		a[i].second = i;
	}

	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &b[i].first.first, &b[i].first.second, &k[i]);
		b[i].second = i;
	}
	sort(a, a + n);
	sort(b, b + m);

	set < pair <int, int> > S;

	int j = 0;
	for(int i = 0; i < n; i++){
		while(j < m && b[j].first.first <= a[i].first.first){
			S.insert({b[j].first.second, b[j].second});
			j++;
		}

		auto d = S.lower_bound({a[i].first.second, 0});
		if(d == S.end()){
			printf("NO\n");
			return 0;
		}

		r[a[i].second] = d->second + 1;

		k[d->second]--;
		if(k[d->second] == 0)S.erase(d);
	}

	printf("YES\n");
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%d", r[i]);
	}
	printf("\n");

	return 0;
}