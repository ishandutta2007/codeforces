//I love Violet Evergarden!!!
#include <bits/stdc++.h>
using namespace std;

int n, k, a[3005], b[3005];
char s[3005]; 
vector<int> ans;

int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	for(int i = 1; i <= n; ++i) if(s[i] == 'R') b[i] = a[i] = 1;
	int cnt = 0, tot = 0;
	for(; ; ++cnt) {
		ans.clear();
		for(int i = 1; i < n; ++i) 
			if(b[i] && !b[i + 1]) ++tot, ans.emplace_back(i);
		if(!ans.size()) break;
		for(int p : ans) swap(b[p + 1], b[p]);
	}
	if(cnt > k || tot < k) puts("-1"), exit(0);
	bool flg = 0;
	for(cnt = 0; ;) {
		//printf("cnt = %d, tot = %d\n", cnt, tot);
		ans.clear();
		for(int i = 1; i < n; ++i) if(a[i] && !a[i + 1]) ans.emplace_back(i);
		if(!ans.size()) exit(0);
		if(flg) for(int p : ans) printf("1 %d\n", p);
		else {
			tot -= ans.size(), ++cnt;
			if(cnt + tot < k) { 
				int fuck = ans.size() - (k - cnt - tot);
				printf("%d ", fuck);
				for(int i = 0; i < fuck; ++i) printf("%d%c", ans[i], i == fuck - 1 ? '\n' : ' ');
				for(int i = fuck; i < ans.size(); ++i) printf("1 %d\n", ans[i]);
				flg = 1;
			} else {
				printf("%d ", ans.size());
				for(int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
			} 
		}	
		for(int p : ans) swap(a[p + 1], a[p]);
	}
	return 0;
}