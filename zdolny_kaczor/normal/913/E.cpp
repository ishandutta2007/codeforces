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
const bool deb = 
#ifdef DEB
true;
#define debug cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
false;
#define debug if(0) cout
#endif
#define fs(r) r.f, r.s
#define ei else if
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
	return os << "}_" << x.size();
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
#define _2arr(a, b, i) #a cc #b cc #i << "]" rr #a cc #b cc i << "]" rr #a cc b[i] rr a[b[i]] ao
#define _3arr(a, b, c, i) #a cc #b cc #c cc #i << "]]" rr #a cc #b cc #c cc i << "]]" rr #a cc #b cc c[i] << "]" rr  #a cc b[c[i]] rr a[b[c[i]]] ao
#define range(a, i, j) #a cc i << ".." << j rr vector <remove_reference<decltype(a[0])>::type>(&a[i], &a[j + 1]) ao
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
const int A = 256;
string expr[A], T[A], F[A];
bool minis(string & a, const string & b) {
	if (a.empty()) {
		a = b;
		return true;
	}
	if (siz(a) > siz(b)) {
		a = b;
		return true;
	}
	if (siz(a) == siz(b) && a > b) {
		a = b;
		return true;
	}
	return false;
}
char in[10];
int main() {
	const int all = 255;
	REP(i, A)
		expr[i] = T[i] = F[i] = "ant,.hoeuracntoeuhrantuhantuhasntuasnotuhasnotuh";
  F[0xf0] = "x";
	F[0xcc] = "y";
	F[0xaa] = "z";
	REP(i, A * 3) {
		int cou = 0;
		REP(f, A)
			REP(s, A) {
				cou += minis(T[f & s], T[f] + "&" + F[s]);
			}
		REP(f, A)
			cou += minis(T[f], F[f]);
		REP(f, A) {
			REP(s, A)
				cou += minis(expr[f|s], expr[f] + "|" + T[s]);
		}
		REP(f, A)
			cou += minis(expr[f], T[f]);
		REP(f, A) {
			cou += minis(F[f], "!" + F[all &~ f]);
		}
		REP(f, A)
			cou += minis(F[f], "(" + expr[f] + ")");
		if (!cou)
			break;
	}
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%s", in);
		int num = 0;
		REP(i, 8)
			num = num + (in[i] - '0') * (1 << i);
		printf("%s\n", expr[num].begin());	
	}
}