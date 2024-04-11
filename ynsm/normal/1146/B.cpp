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

int a, k;
string s, t, tt;
int main()
{
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == 'a')
			a++;
	if((s.size() - a) & 1)
		cout << ":(", exit(0);
	k = (s.size() - a) / 2 + a;
	for(int i = 0; i < k; i++){
		if(s[i] == 'a')
			t += s[i];
		else
			t += s[i], tt += s[i];		    	
    }
    cerr << k << " " << t << " " << tt << endl;
    if(s == t + tt)
    	cout << t;
	else
		cout << ":(";
	return 0;
}