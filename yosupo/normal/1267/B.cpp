#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define fs first
#define sc second
#define a first
#define b second
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
template <class T, class U> void chmin(T& t, const U& u) { if (u < t) t = u; }
template <class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
	os << "[";
	for (auto d : v) os << d << ", ";
	return os << "]";
}

void answer(int a){
	cout<<a<<endl;
	exit(0);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	
	V<pair<char,int>> w;
	{
		string s;cin>>s;
		char pre='0';
		for(auto c:s){
			if(pre!=c){
				w.eb(c,0);
				pre=c;
			}
			w.back().b+=1;
		}
	}
	int s=w.size();
	show(s);
	if(s%2==0){
		answer(0);
	}
	int m=s/2;
	int ans=w[m].b;
	show(ans);
	if(ans<=1)
		answer(0);
	rep(i,m){
		if(w[i].a!=w[s-1-i].a)
			answer(0);
		if(w[i].b+w[s-1-i].b<3)
			answer(0);
	}
	answer(ans+1);
}