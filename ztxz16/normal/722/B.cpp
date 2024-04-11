#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 1005;
 
int n, p[N];
char str[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	
	gets(str + 1);
	for (int i = 1; i <= n; i++) {
		gets(str + 1);
		for (int j = 1; str[j]; j++) {
			if (str[j] == 'a' || str[j] == 'e' || str[j] == 'o' || str[j] == 'i' || str[j] == 'u' || str[j] == 'y') {
				p[i]--;
			}
		}

		if (p[i] != 0) {
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n"); 
	return 0;
}