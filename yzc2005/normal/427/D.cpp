#include <bits/stdc++.h>
using namespace std;
const int N = 50010, L = 15010;
#define rg register
#define fu(i, a, b) for(rg int i = (a), I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = (a), I = (b) - 1; i > I; --i)

int n, m, z[L], cnt1[N], cnt2[N];
char s[L], s1[N], s2[N];

inline void Z() {
    z[1] = n; bool flg = 0;
    for(rg int i = 2, l = 0, r = 0; i <= n; ++i) {
    	z[i] = i <= r ? min(r - i + 1, z[i - l + 1]) : 0;
    	while(s[z[i] + 1] == s[i + z[i]]) ++z[i];
    	if(i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
    	flg ? ++cnt2[z[i]] : ++cnt1[z[i]];
    	if(s[i] == '@') flg = 1;
    }
}

int main() {
	scanf("%s%s", s1 + 1, s2 + 1); m = strlen(s1 + 1);
	int mnlen = 1e9;
	fu(i, 1, m) {
		int len = m - i + 1;
		memcpy(s + 1, s1 + i, len); s[len + 1] = '\0';
		strcat(s + 1, "#"); strcat(s + 1, s1 + 1); strcat(s + 1, "@"); strcat(s + 1, s2 + 1);
		memset(cnt1, 0, sizeof(cnt1)); memset(cnt2, 0, sizeof(cnt2)); 
                n = strlen(s + 1); Z();
		fd(j, len, 1) cnt1[j] += cnt1[j + 1], cnt2[j] += cnt2[j + 1];
		fu(j, 1, len) if(cnt1[j] == 1 && cnt2[j] == 1 && mnlen > j) mnlen = j;
	}
	printf("%d\n", mnlen == 1e9 ? -1 : mnlen);
	return 0;
}