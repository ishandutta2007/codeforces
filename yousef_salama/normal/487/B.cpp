#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, d, l, a[MAXN];

int tree[4 * MAXN];
int findmin(int i, int L, int R, int p, int q){
	if(q < L || R < p)return 1 << 20;
	if(p <= L && R <= q)return tree[i];

	int mid = (L + R) / 2;
	return min(findmin(2 * i, L, mid, p, q), findmin(2 * i + 1, mid + 1, R, p, q));
}
void update(int i, int L, int R, int p, int v){
	if(p < L || R < p)return;
	if(L == R){
		tree[i] = v;
		return;
	}

	int mid = (L + R) / 2;

	update(2 * i, L, mid, p, v);
	update(2 * i + 1, mid + 1, R, p, v);

	tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
int main(){
	scanf("%d %d %d", &n, &d, &l);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	multiset <int> s;
	for(int i = 0; i < 4 * MAXN; i++)
		tree[i] = 1 << 20;

	int j = 0;
	for(int i = 0; i < n; i++){
		s.insert(a[i]);
		while(true){
			if(s.empty())break;

			int mn = *s.begin();
			int mx = *(--s.end());

			if(mx - mn <= d)break;

			s.erase(s.lower_bound(a[j]));
			j++;
		}


		if(j <= i - l + 1){
			int r;
			if(j == 0)r = 1;
			else r = 1 + findmin(1, 0, n - 1, j - 1, i - l);

			update(1, 0, n - 1, i, r);

			if(i == n - 1){
				if(r > n)printf("-1\n");
				else printf("%d\n", r);
			}
			continue;
		}

		if(i == n - 1)printf("-1\n");
	}

	return 0;
}