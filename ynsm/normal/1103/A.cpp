#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

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
	string s;
	cin >> s;
	for(int i = 0, j = 0, q = 0; i < s.size(); i++){
		if(s[i] == '0'){
			cout << 1 << " " << j % 4 + 1 << endl;
			j++; 
		}
        if(s[i] == '1'){
			cout << 3 << " " << 2 * (q % 2) + 1 << endl;
			q++; 
		}

	}
	return 0;
}