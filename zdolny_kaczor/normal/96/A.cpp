# include <bits/stdc++.h>
using namespace std;
const int mod = 335252294;
char in[101];
int main() {
	scanf("%s", in);
	int l, h = 0;
	for (l = 0; in[l]; ++l)
		h = (h * 2 + in[l] - '0') % mod;
	h = (h * 91390991ll + 12000000ll * l) % mod;
	bool ans;
	if (h < 71108297)
		ans = true;
	else if (h < 137508567)
		ans = false;
	else if (h < 202950116)
		ans = true;
	else if (h < 279937038)
		ans = false;
	else
		ans = true;
	if (ans)
		printf("YES\n");
	else
		printf("NO\n");
}