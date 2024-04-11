#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100009;
LL a[maxn], b[maxn];
LL n, m, l = 0, r = 2e10, mid, len;
char s[maxn];

bool check(LL limit){
	LL p = 1, s, p1;
	for (int i=1; i<=n&&p<=m; i++){
		if (a[i] - b[p] > limit) return false;
		p1 = s = p;
		while (p <= m && abs(a[i] - b[s])
			+ abs(b[s] - b[p]) <= limit) p++;
		while (p1 <= m && abs(a[i] - b[p1])
			+ abs(b[p1] - b[s]) <= limit) p1++;
		p = max(p1, p);
	}
	return p > m;
}

int main(){
	scanf("%I64d", &len);
	scanf("%s", s+1);
	for (int i=1; i<=len; i++)
		if (s[i] == 'P') a[++n] = i;
		else if (s[i] == '*') b[++m] = i;
	sort(a+1, a+n+1); sort(b+1, b+m+1);
	while (l < r){
		mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%I64d\n", l);
	return 0;
}