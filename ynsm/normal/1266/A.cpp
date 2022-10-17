#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
	int q;
	cin >> q;
	while(q--){
		string s;
		int cnt[10];
		for(int i = 0; i < 10; i++)
			cnt[i] = 0 ;
		cin >> s;
		for(int i = 0; i < s.size(); i++)
			cnt[s[i] - '0']++;
		bool ok = 0;
		ll sum = 0;
		for(int i = 0; i < 10; i++)
			sum += cnt[i] * i;
		for(int i = 0; i < 10; i++){
			if(cnt[i]){
				cnt[i]--;
				for(int j = 0; j < 10; j++)
					if(cnt[j] && (i * 10 + j) % 20 == 0)
						ok = 1;
				cnt[i]++;
			}
		}
		if(ok && sum % 3 == 0)
			puts("red");
		else
			puts("cyan");		
	}
	return 0;
}