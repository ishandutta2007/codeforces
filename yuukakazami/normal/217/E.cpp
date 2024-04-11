#include <stdio.h>
#include <ext/rope>
typedef __gnu_cxx ::crope R;
R s;
int n, k, l[5000], r[5000];
char buf[int(3e6) + 10];
R bd(int d, int L) {
	if (d < 0) return s.substr(0, L);
	int C = r[d] - l[d] + 1, x = (r[d] + C < L - 1 ? r[d] + C : L - 1) - (l[d] + C) + 1;
	if (x <= 0) return bd(d - 1, L);
	R t = bd(d - 1, L - x);buf[x]=0;
	for (int i = 0; i < x; ++i) buf[i] = i * 2 + 1 < C ? t[l[d] + i * 2 + 1] : t[l[d] + (i - C / 2) * 2];
	t.insert(r[d] + 1, buf);
	return t;
}
int main() {
	scanf("%s",buf);s = buf;scanf("%d%d",&k,&n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d",l+i,r+i),--l[i], --r[i];
	puts(bd(n - 1, k).c_str());
	return 0;
}