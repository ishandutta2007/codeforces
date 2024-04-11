//    
#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 1005;
int n, sum, pre[N], suf[N];
vector <int> ans[N];
bool del[N];
char s[N];

int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	while(1) {
		fu(i, 1, n) if(!del[i]) pre[i] = pre[i - 1] + (s[i] == '('); else pre[i] = pre[i - 1];
		fd(i, n, 1) if(!del[i]) suf[i] = suf[i + 1] + (s[i] == ')'); else suf[i] = suf[i + 1];
		int pos = 0, mx = 0;
		fu(i, 1, n) if(mx <= min(pre[i], suf[i + 1])) pos = i, mx = min(pre[i], suf[i + 1]);
		if(!mx) break;
		++sum;
		fu(i, 1, pos) if(!del[i] && s[i] == '(' && ans[sum].size() < mx) del[i] = 1, ans[sum].push_back(i);
		fu(i, pos + 1, n) if(!del[i] && s[i] == ')' && ans[sum].size() < mx << 1) del[i] = 1, ans[sum].push_back(i);
	}	
	printf("%d\n", sum);
	fu(i, 1, sum) {
		printf("%d\n", ans[i].size());
		fu(j, 0, ans[i].size() - 2) printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][ans[i].size() - 1]);
	}
	return 0;
}