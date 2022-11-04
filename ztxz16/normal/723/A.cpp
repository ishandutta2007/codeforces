#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[5];

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &a[1], &a[2], &a[3]);
	sort(a + 1, a + 4);
	printf("%d\n", a[3] - a[1]); 
	return 0;
}