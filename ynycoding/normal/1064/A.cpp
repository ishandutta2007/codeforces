#include <bits/stdc++.h>
using namespace std;
int n, a[4];
int main()
{
	scanf("%d%d%d", a+1, a+2, a+3);
	sort(a+1, a+4);
	printf("%d", max(a[3]-a[1]-a[2]+1, 0));
	return 0;
}