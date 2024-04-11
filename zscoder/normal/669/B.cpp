#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int d[100001];
bool visited[100001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	bool infinite = true;
	int pos = 0;
	while(1)
	{
		if(visited[pos]) break;
		visited[pos] = true;
		if(s[pos] == '>') pos += d[pos];
		else pos -= d[pos];
		if(pos < 0 || pos >= n) {infinite = false; break;}
	}
	if(infinite) cout << "INFINITE";
	else cout << "FINITE";
	return 0;
}