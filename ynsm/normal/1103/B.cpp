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
bool ask(int x, int y){
	cout << "? " << x << " " << y << endl;
	//return x % n >= y % n;
	cin >> s;
	if(s == "x")
		return 1;
	else
		return 0;
}
void ans(int x){
	cout << "! " << x << endl;
}
void solve(){
	int last = 0;
	for(int i  = 0; i <= 30; i++){
		ll m = last + last + 1;
		bool v = ask(last, m);
		if(v){
			int l = last + 1, r = m;
			while(l <= r){
				int m = (l + r) >> 1;
				if(ask(last, m))
					r = m - 1;
				else
					l = m + 1;
			}
			ans(l);	
			return;
		} 
		last = m;
	}	
}
int main()
{
	while(true){
		cin >> s;
		if(s == "end")
			break;
		//cin >> n;
		solve();	
	}
	return 0;
}