#include <bits/stdc++.h>

typedef long long ll;

const int kN = 1e6 + 5;

int n; ll s1[kN], s2[kN], m[kN], ans[kN];
std::vector<int> st;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", m + i);
	st.push_back(0);
	for(int i = 1; i <= n; ++i) {
		while(m[st.back()] > m[i]) st.pop_back();
		s1[i] = s1[st.back()] + m[i] * (i - st.back());
		st.push_back(i);
	}
	st.clear();
	st.push_back(n + 1);
	for(int i = n; i >= 1; --i) {
		while(m[st.back()] > m[i]) st.pop_back();
		//printf("Stb: %d\n", st.back());
		s2[i] = s2[st.back()] + m[i] * (st.back() - i);
		st.push_back(i);
	}
	//printf("?");
	int climax = 1; ll maxans = 0;
	for(int i = 1; i <= n; ++i) {
		if(s1[i] + s2[i] - m[i] >= maxans) {
			maxans = s1[i] + s2[i] - m[i];
			climax = i;
		}
		//printf("%lld ", s2[i]);
	}
	//for(int i = 1; i <= n; ++i) printf("%lld ", s1[i]);
	//printf("\n");
	//for(int i = 1; i <= n; ++i) printf("%lld ", s2[i]);
	//printf("\n");
	ans[climax] = m[climax];
	for(int i = climax - 1; i > 0; --i) {
		ans[i] = std::min(m[i], ans[i + 1]);
	}
	for(int i = climax + 1; i <= n; ++i) {
		ans[i] = std::min(m[i], ans[i - 1]);
	}
	for(int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	return 0;
}