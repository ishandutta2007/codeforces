#include <bits/stdc++.h>
int main()
{
	std::pair<int, int> a[3];
	for(int i = 0; i < 3; ++i) std::cin >> a[i].first >> a[i].second;
	std::sort(a, a + 3);
	
	std::vector<std::array<int, 4>> V;
	if(a[0].first != a[1].first)
	V.push_back({a[0].first, a[0].second, a[1].first, a[0].second});
	
	if(a[2].first != a[1].first)
	V.push_back({a[2].first, a[2].second, a[1].first, a[2].second});
	
	int l = std::min({a[0].second, a[1].second, a[2].second}),
		r = std::max({a[0].second, a[1].second, a[2].second});
	if(l != r) V.push_back({a[1].first, l, a[1].first, r});
	
	std::cout << V.size() << "\n";
	for(const auto &p : V)
	std::cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << "\n";
	return 0;
}