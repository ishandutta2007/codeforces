#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[10];
int cnt[10];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++){
		scanf("%s", s+1);
		for (int j = 1; j <= 7; j ++)
			if (s[j] == '1') cnt[j] ++;
	}
	int ans = 0;
	for (int i = 1; i <= 7; i ++) ans = max(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}