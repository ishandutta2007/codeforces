#include<bits/stdc++.h>
#define maxn 400050
using namespace std;

int n,cnt[maxn];

void init()	{
	scanf("%d",&n);
	for (int a,i=1;i<=n;++i)
		scanf("%d",&a),++cnt[a];
}

void solve()	{
	if (cnt[1]&&cnt[2])	{
		printf("2 1 ");
		--cnt[1],--cnt[2];
	}
	while (cnt[2]--)	printf("2 ");
	while (cnt[1]--)	printf("1 ");
}

int main()	{
	init();
	solve();
	return 0;
}