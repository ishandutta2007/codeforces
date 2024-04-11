#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, cnt[N];
char s[N]; 
string ns;
void Main () {
	cin >> n >> (s + 1);
	ns = {s[1], s[1]};
	vector < int > vc;
	L(i, 2, n) {
		if (s[i] < s[i - 1]) vc.push_back(i - 1);
		else if(s[i] > s[i - 1]) {
			vc.push_back(i - 1);
			break ;
		}
	}
	vc.push_back(n);
	for (const int &i : vc) {
		string x;
		L(j, 1, i) x.push_back(s[j]);
		R(j, i, 1) x.push_back(s[j]);
		ns = min(ns, x);
	}
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}