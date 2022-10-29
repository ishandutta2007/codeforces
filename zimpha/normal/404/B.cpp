#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

int main() {
	double a, d;
	int n; 
	scanf("%lf%lf%d", &a, &d, &n);
	for (int i = 1; i <= n; ++ i) {
		double len = fmod(d * i, 4.0 * a);
		if (fabs(len) <= 1e-8) puts("0.000000 0.000000");
		else {
			double x = 0, y = 0;
			if (len > a) {
				x = a, y = 0, len -= a;
				if (len > a) {
					y = a, len -= a;
					if (len > a) {
						x = 0, len -= a;
						if (len > 0) y -= len;
					}
					else x = x - len;
				}
				else y = len;
			}
			else x = len, y = 0;
			printf("%.10f %.10f\n", x, y);
		}
	}
	return 0;
}