#include <cstdio>
#include <cstring>

bool t[1000000];

int main() {
	int k, l, m, n, d, ret=0;
	scanf("%d%d%d%d%d", &k, &l, &m, &n, &d);
	memset(t, 0, sizeof(t));
	for (int i=0; i<=d; i+=k) t[i]=true;
	for (int i=0; i<=d; i+=l) t[i]=true;
	for (int i=0; i<=d; i+=m) t[i]=true;
	for (int i=0; i<=d; i+=n) t[i]=true;
	for (int i=1; i<=d; i++) ret+=t[i];
	printf("%d\n", ret);
	return 0;
}