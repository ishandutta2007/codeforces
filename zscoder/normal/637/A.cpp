#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int freq[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x;
	int maximum = 0;
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		freq[x]++;
		if(freq[x] > maximum)
		{
			ans = x;
			maximum = freq[x];
		}
	}
	cout << ans;
	return 0;
}