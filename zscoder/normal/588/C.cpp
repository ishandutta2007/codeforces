#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9 + 7;

map<int,int> ma;
typedef map<int,int>::iterator mit;

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		ma[x]++;
	}
	int ans = 0;
	while(ma.size() > 0)
	{
		mit it = ma.begin();
		if(it->se >= 2)
		{
			int q = (it->se)/2;
			ma[it->fi] -= 2*q;
			ma[it->fi+1] += q;
			if(ma[it->fi] == 0) ma.erase(it->fi);
		}
		else if(it->se == 1)
		{
			ma.erase(it->fi);
			ans++;
		}
	}
	ans += ma.size();
	printf("%d", ans);
	return 0;
}