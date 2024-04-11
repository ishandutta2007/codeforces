#include<stdio.h>
#include<set>
#include<assert.h>
#include<queue>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const double EPS = 1e-8;
const double PI = acos(-1);

const int MX = 1005;
const int MM = 1000000007;

ll A[MX][MX];

int main()
{
	A[1][0] = 1; A[1][1] = 1;
	int N;
	scanf("%d", &N);
	for(int n = 2; n <= N; n++){
		A[n][0] = 1;
		for(int k = 1; k <= N; k++){
			ll tot = 0;
			for(int x = 0; x <= k; x++) tot = (tot + A[n-1][x] * A[n-1][k-x]) % MM;

			ll t1 = 0;
			for(int x = 0; x <= k-1; x++) t1 = (t1 + A[n-1][x] * A[n-1][k-1-x]) % MM;
			tot = (tot + t1) % MM;

			ll t2 = 0;
			for(int x = 0; x <= k; x++) t2 = (t2 + A[n-1][x] * A[n-1][k-x]) % MM;
			tot = (tot + t2 * k * 2) % MM;
			
			ll t3 = 0;
			for(int x = 0; x <= k+1; x++) t3 = (t3 + A[n-1][x] * A[n-1][k+1-x]) % MM;
			tot = (tot + t3 * (k+1) * k) % MM;
			A[n][k] = tot;
		}
	}
	printf("%lld\n", A[N][1]);
}