#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const ll MUL = 359285041;

ll mpow(ll a, ll b)
{
	if (b == 0) return 1;
	if (b % 2) return a * mpow(a, b - 1) % MOD;
	ll v = mpow(a, b / 2);
	return v * v % MOD;
}

const int MX = 200009;
int lenS, lenT;
char s[MX], t[MX];
int skipS[MX][26], skipT[MX][26];
int runLenS[MX][26], runLenT[MX][26];

struct VHash
{
	int len, value;

	bool operator == (const VHash& v) const
	{
		assert(len == v.len);
		// printf("compare %d and %d\n", value, v.value);
		return len == v.len && value == v.value;
	}

	VHash operator + (char c) const
	{
		ll x = c * 123 + 7;
		return {len + 1, (int) (((ll) value * 359285041 + x) % MOD)};
	}
	VHash operator - (const VHash& h) const
	{
		int newLen = len - h.len;
		int newValue = (int) (((ll) value - h.value * mpow(MUL, newLen)) % MOD);
		if (newValue < 0) newValue += MOD;
		return {newLen, newValue};
	}
};

VHash emptyHash()
{
	return {0, 0};
}

VHash hashS[MX][26], hashT[MX][26];

void fillSkip(char* str, int len, int skip[MX][26], int runLen[MX][26])
{
	for (int i = len - 1; i >= 0; i--)
	{
		jj(26) skip[i][j] = skip[i+1][j];
		skip[i][str[i]-'a'] = i;
		runLen[i][str[i]-'a'] = runLen[i+1][str[i]-'a'] + 1;
	}
}

void fillHash(int len, char* str, int skip[MX][26], VHash arr[MX][26])
{
	for (int i = len - 1; i >= 0; i--)
	{
		jjl(let, 26)
		{
			arr[i][let] = arr[i+1][let] + (str[i] - 'a' == let ? 12 : 1);
			// if (let < 5) printf("arr[%d][%d] = %d\n", i, let, arr[i][let].value);
		}
	}
}

int main()
{
	rint(lenS);
	rint(lenT);
	scanf("%s%s", s, t);
	jij(MX, 26) skipS[i][j] = skipT[i][j] = INF;
	fillSkip(s, lenS, skipS, runLenS);
	fillSkip(t, lenT, skipT, runLenT);
	fillHash(lenS, s, skipS, hashS);
	fillHash(lenT, t, skipT, hashT);
	vector<int> valids;
	ji(lenS - lenT + 1)
	{
		int a[26];
		memset(a, -1, sizeof a);
		bool ok = true;
		jjl(let, 26)
		{
			int x = skipT[0][let];
			if (x == INF) continue;
			else
			{
				int c1 = s[i+x] - 'a';
				int c2 = t[x] - 'a';
				assert(c2 == let);
				if (a[c2] != c1 && a[c2] >= 0)
				{
					ok = false;
					break;
				}
				if (a[c1] != c2 && a[c1] >= 0)
				{
					ok = false;
					break;
				}
				a[c1] = c2;
				a[c2] = c1;
			}
		}
		if (!ok) continue;
		// printf("%d:\n", i);
		// ji(26) printf("a[%d] == %d\n", i, a[i]);
		jjl(let, 26) if (a[let] >= 0)
		{
			// printf("let=%d\n", let);
			if (!(hashT[0][let] == (hashS[i][a[let]] - hashS[i+lenT][a[let]])))
			{
				ok = false;
				break;
			}
			// if (!(hashT[0][a[let]] == (hashS[i][let] - hashS[i+lenT][let])))
			// {
			// 	ok = false;
			// 	break;
			// }
		}
		if (ok) valids.pb(i);
	}
	printf("%d\n", (int) valids.size());
	foreach(v, valids) printf("%d ", v + 1);
}