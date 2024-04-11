#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

string a[101];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < 26; i++)
	{
		for(int j = i + 1; j < 26; j++)
		{
			int cnt = 0;
			for(int k = 0; k < n; k++)
			{
				bool getstring = true;
				for(int l = 0; l < a[k].length(); l++)
				{
					int v = a[k][l] - 'a';
					if(!(v==i||v==j))
					{
						getstring = false;
						break;
					}
				}
				if(getstring) cnt += a[k].length();
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans;
	return 0;
}