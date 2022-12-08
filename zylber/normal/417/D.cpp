#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)

vector<pair<int, int> > compus;
long long money[128], probs[128];
long long DP[(1LL<<20LL)+1];

int main() {
/*#ifdef ACMTUYO
	freopen("awards.in", "r", stdin);
#endif*/
	long long n, m , b;
	cin >> n >> m >> b;
	compus.resize(n);
	for(int i=0; i<n; i++)
	{
		int s;
		cin >> money[i] >> compus[i].first >> s;
		compus[i].second=i;
		for(int j=0; j<s; j++)
		{
			long long a; cin >> a; a--;
			probs[i]|=(1LL<<a);
		}
	}
		sort(compus.begin(), compus.end());
		memset(DP, 0x3f, sizeof(DP));
		long long tb=DP[0];
		DP[0]=0;
		
		for(int i=n-1; i>=0; i--)
		{
			int cur=compus[i].second;
			//cout << cur << endl;
			long long cost=b*compus[i].first+money[cur];
			for(long long mask=0; mask<(1LL<<m); mask++)
			{
				DP[mask|probs[cur]]=min(DP[mask|probs[cur]], DP[mask]+cost);
				if(mask==0) cost-=b*compus[i].first;
			}
			//cout << DP[1] << endl;
		}
	
	long long goal=(1LL<<m)-1LL;
	if(DP[goal]==tb) cout << -1 << endl; else cout << DP[goal] << endl;
}