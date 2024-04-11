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

string s;
ll a, b, c;
int main()
{
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(i > 0 && s[i] == s[i - 1] && s[i] == 'v'){
			a++;
			c += b;
		}else if(s[i] == 'o'){
			b += a;		
		}
	}
	cout << c;
	return 0;
}