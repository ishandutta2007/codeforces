#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cstdlib>
#include <map>
#include <utility>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1000000000;

int main()
{
	ios_base::sync_with_stdio(false);
	int ta, tb, tc, td, te;
	int wa, wb, wc, wd, we;
	int c, w;
	cin >> ta >> tb >> tc >> td >> te >> wa >> wb >> wc >> wd >> we >> c >> w;
	int score = 0;
	score += 100000*c;
	score -= 50000*w;
	score += max(300*500, (1000-4*ta)*500-50000*wa);
	score += max(300*1000, (1000-4*tb)*1000-50000*wb);
	score += max(300*1500, (1000-4*tc)*1500-50000*wc);
	score += max(300*2000, (1000-4*td)*2000-50000*wd);
	score += max(300*2500, (1000-4*te)*2500-50000*we);
	cout << score/1000 << endl;
	return 0;
}