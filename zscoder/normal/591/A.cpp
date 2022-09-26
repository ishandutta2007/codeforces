#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define INF 1000000000;
int main()
{
	int l;
	cin >> l;
	int p, q;
	cin >> p >> q;
	float ans = p * l;
	ans /= (p + q);
	cout << ans << endl;
	return 0;
}