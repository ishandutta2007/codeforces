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


int n;
string s;
bool good(){
	int res = 0;
	vector< int > cnt(26, 0);
	for(int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;
	for(int i = 0; i < 26; i++)
		if(cnt[i] > 1)
			res++;
	return (res >= 2);
}
bool check(){
	for(int i = 0; i < n; i++){
		bool ok = 0;
		for(int j = 0; j < n; j++)
			if(s[j] != s[(j + i) % n])
				ok = 1;
		for(int j = 0; j < n; j++)
			if(s[(n - 1 - j + i) % n] != s[(j + i) % n])
				ok = 0;	
		if(ok)
			return 1;		
	}
	return 0;
}
int main()
{
	cin >> s;
	n = s.size();
	if(!good()){
		cout << "Impossible";
		return 0;
	}
	if(check())
		cout << 1;
	else
		cout << 2;
	return 0;
}