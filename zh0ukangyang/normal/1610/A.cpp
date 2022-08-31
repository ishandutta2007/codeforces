#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7; 
int n, m;
void Main () {
	cin >> n >> m;
	if(n == 1 && m == 1) cout << 0 << '\n'; 
	else if(n == 1 || m == 1) cout << 1 <<'\n';
	else cout << 2 << '\n';
}
int main() { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while(T--) Main ();
	return 0;
}