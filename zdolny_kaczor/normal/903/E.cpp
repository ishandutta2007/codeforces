#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
#define debug if(0) cout
#endif
template <typename T, typename C>
ostream & operator<<(ostream &os, pair<T, C> x) {
	return os << "<" << x.f << ", " << x.s << ">";
}
template <typename T>
auto operator<<(ostream&os, T x) -> typename enable_if<is_same<decltype(x.begin()), decltype(x.end())>::value && !is_same<T, string>::value, ostream &>::type {
	os << "{";
	int cou = 0;
	for (auto c : x) {
		if (cou++)
			os << ", ";
		os << c;
	}
	return os << "}";
}
#define cr << "][" << 
#define rr << "] = " << 
#define cc << "[" <<
#define ao << ' ' 
#define name(a) #a << " = " << (a) ao
#define arr(a, i) #a cc #i rr #a cc i rr a[i] ao
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j] ao
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k] ao
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q] ao
template <typename T>
string strmask(T r) {
	string ans;
	REP(i, 8 * (int)sizeof(T)) {
		ans += '0' + !!(((T)1 << i) & r);
		if (i % 5 == 4)
			ans += '.';
	}
	return ans;
}
#if 0 
ostream & operator<< (ostream & os, __int128_t x) {
	if (x < 0) {
		os << '-';
		x = -x;
	}
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
ostream & operator<< (ostream & os, __uint128_t x) {
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
#endif
#define nmask(a) #a << " = " << strmask(a) ao
const int A = 26;;
unsigned LL char_hashes[A] = {
0x35d2d27937521b77ULL,
0x646e30b515ea1634ULL,
0x9cdcf72dbe5c0732ULL,
0xdc2a72158b6a802fULL,
0x65fd4df4d1c8b206ULL,
0x765af0f8731088dcULL,
0x803130272fdf2a99ULL,
0x3c4cdf84eac789c3ULL,
0x6183c9631f420e7fULL,
0x818c3f17903aaadaULL,
0x318679eee58d7feaULL,
0x4d1e2a39aa2636fdULL,
0xb8aef3d7615dc21fULL,
0xb94a13dae940b2b6ULL,
0x0487ba9c0c08dfabULL,
0xfc38bca1f320182cULL,
0x1812a7d53662fc3dULL,
0xcc5d8d6c02198a9eULL,
0x857b570a12149f25ULL,
0xdeb953e819b9c13bULL,
0x2a9955f15a2ed0bcULL,
0xc572b37316a6ce0bULL,
0x7ec220e5f5ebb922ULL,
0xae12ee171ce818c6ULL,
0xbf8795776d627c6fULL,
0xf2142402d3a5a5a7ULL
				};
const int MN = 5e3 + 44;
int hamming(const string & a, const string & b) {
	int ans = 0;
	REP(i, siz(a))
		if (a[i] != b[i])
			ans++;
	return ans;
}
string in[MN];
bool repet(const string &a) {
	set <char> seen;
	for (char c : a)
		if (seen.count(c))
			return true;
		else
			seen.insert(c);
	return false;
}
bool match(const string & a, const string & b) {
	int dist = hamming(a, b);
	return dist <= 2 && (dist > 0 || repet(a));
}
vector <string> generate(const string & a, const string &b) {
	vector <string> ans;
	vector <int> differ;
	REP(i, siz(a)) {
		if (a[i] != b[i])
			differ.PB(i);
	}
	for (int x : differ)
		for (int y : differ)
			if (x < y) {
				ans.PB(a);
				swap(ans.back()[x], ans.back()[y]);
			}
	if (siz(differ) == 0) {
		ans.PB(a);
		swap(ans.back()[0], ans.back()[1]);
	}
	return ans;
}
int main() {
	int k, n;
	cin >> k >> n;
	REP(i, k)
		cin >> in[i];
	unsigned LL last_hash = 0;
	REP(i, k) {
		unsigned LL curr = 0;
		REP(j, n)
			curr += char_hashes[in[i][j] - 'a'];
		if (i == 0)
			last_hash = curr;
		else if (curr != last_hash) {
			cout << -1 << '\n';
			return 0;
		}
	}
	if (k == 1) {
		swap(in[0][0], in[0].back());
		cout << in[0] << '\n';
		return 0;
	}
	FORD(aim, 4, 0) {
		REP(i, k)
			FOR(j, i + 1, k - 1) {
				if (hamming(in[i], in[j]) == aim) {
					vector<string> candidates = generate(in[i], in[j]);
					for (auto c : candidates) {
						bool good = true;
						REP(ii, k)
							if (!match(in[ii], c)) {
								good = false;
								break;
							}
						if (good) {
							cout << c << endl;
							return 0;
						}
					}
					cout << -1 << endl;
					return 0;
				}
			}
	}
	printf("-1\n");
}