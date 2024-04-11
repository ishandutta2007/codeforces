#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int s[4];
	for (int i=0; i<4; i++) scanf("%d", s+i);
	sort(s, s+4);
	int ret=1;
	for (int i=1; i<4; i++)
		if (s[i]!=s[i-1]) ret++;
	printf("%d\n", 4-ret);
	return 0;
}