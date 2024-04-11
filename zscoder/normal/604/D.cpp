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
/*A
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
}*/
/*B
vi vec;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	int ans = 0;
	int pairs = max(0, k- (2*k - n));
	for(int i = 0; i < pairs; i++)
	{
		ans = max(ans, vec.at(i) + vec.at(2*pairs - i - 1));
	}
	for(int i = 2*pairs; i < n; i++)
	{
		ans = max(ans, vec.at(i));
	}
	cout << ans;
	return 0;
}		
*/
/*C
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 1;
	for(int i = 0; i < s.length() - 1; i++)
	{
		if(s.at(i) != s.at(i + 1))
		{
			ans++;
		}
	}	
	cout << min(ans + 2, n) << endl;
	return 0;
}*/
int MOD = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	int k, p;
	cin >> p >> k;
	int m;
	long long ans = 1;
	if(k == 0)
	{
		for(int i = 0; i < p - 1; i++)
		{
			ans *= p;
			ans %= MOD;
		}
	}
	else if(k == 1)
	{
		for(int i = 0; i < p; i++)
		{
			ans *= p;
			ans %= MOD;
		}
	}
	else
	{
		for(int i = 0; i < p; i++)
		{
			ans *= k;
			ans %= p;
			if(ans == 1)
			{
				m = i + 1;
				break;
			}
		}
		ans = 1;
		for(int i = 0; i < (p - 1)/m; i++)
		{
			ans *= p;
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}