#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p1 = 1e9 + 7, p2 = 1e9 + 9;
int T, n, q, ans0, ans1, a[Maxn], val[Maxn];
pair <long long, long long> H;
map <pair <long long, long long>, int> Ma, Ma2;
pair <long long, long long> get_hash(int x)
{
	vector <int> Ve;
	pair <long long, long long> result = make_pair(0, 0);
	int maxi = sqrt(x);
	for (int i = 2; i <= maxi; i++)
		if (x % i == 0)
		{
			int ct = 0;
			while (x % i == 0) ct++, x /= i;
			if (ct & 1) Ve.push_back(i);
		}
	if (x != 1) Ve.push_back(x);
	sort(Ve.begin(), Ve.end());
	for (auto u : Ve)
	{
		result.first = (result.first * 29 + val[u]) % p1;
		result.second = (result.second * 31 + val[u]) % p2;
	}
	return result;
}
int main()
{
	srand(time(NULL));
	for (int i = 1; i <= 1000000; i++)
		val[i] = rand() * RAND_MAX + rand();
	scanf("%d", &T);
	while (T--)
	{
		ans0 = ans1 = 0;
		Ma.clear(), Ma2.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), Ma[get_hash(a[i])]++;
		for (map <pair <long long, long long>, int> :: iterator it = Ma.begin(); it != Ma.end(); it++)
		{
			ans0 = max(ans0, it -> second);
			if (it -> second & 1) Ma2[it -> first] += it -> second, ans1 = max(ans1, Ma2[it -> first]);
			else Ma2[make_pair(0, 0)] += it -> second, ans1 = max(ans1, Ma2[H]);
		}
		scanf("%d", &q);
		while (q--)
		{
			long long w;
			scanf("%lld", &w);
			if (!w) printf("%d\n", ans0);
			else printf("%d\n", ans1);
		}
	}
	return 0;
}