#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int a[110];
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a, a+n);
	swap(a[0], a[n-1]);
	for (int i=0; i<n; i++)
		printf("%d%c", a[i], (i!=n-1)?' ':'\n');
	return 0;
}