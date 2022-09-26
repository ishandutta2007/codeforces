#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; 
	cin >> n;
	int ans = 0;
	int x;
	int prevx = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x; 
		if(x - prevx > 15)
		{
			cout << min(90, ans + 15);
			return 0;
		}
		ans = x; prevx = x;
	}
	cout << min(90, ans + 15);
}