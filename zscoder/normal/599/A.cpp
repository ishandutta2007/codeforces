#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	cout << min(2*a+2*b, min(a+b+c, min(2*a+2*c, 2*b+2*c))) << endl;
	return 0;
}
/*B
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}	*/