#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
template <typename T> void my_random_shuffle(T b, T e) { For(i, 1, (int)(e - b) - 1) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uin(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(b, a) ? a = b, true : false; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uax(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(a, b) ? a = b, true : false; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

string a[1 << 8];

void expr(const char *&s, int &x);

void mnog(const char *&s, int &x)
{
	if (*s == '(')
	{
		++s;
		expr(s, x);
		assert(*s == ')');
		++s;
	}
	else if (*s == '!')
	{
		++s;
		mnog(s, x);
		x ^= 0xff;
	}
	else
	{
		char t = *s;
		++s;
		x = 0;
		forn(i, 8)
		{
			int xx = i >> 2;
			int yy = (i >> 1) & 1;
			int zz = i & 1;
			if (t == 'x') x |= xx << i;
			if (t == 'y') x |= yy << i;
			if (t == 'z') x |= zz << i;
		}
	}
}

void slag(const char *&s, int &x)
{
	mnog(s, x);
	while (*s == '&')
	{
		++s;
		int y;
		mnog(s, y);
		x &= y;
	}
}

void expr(const char *&s, int &x)
{
	slag(s, x);
	while (*s == '|')
	{
		++s;
		int y;
		slag(s, y);
		x |= y;
	}
}

int expr(const string &s)
{
	int x;
	const char *h = s.c_str();
	expr(h, x);
	return x;
}

void precalc()
{
	bool fnd = false;
	auto upd = [&](const string &s, int res)
	{
		if (a[res].empty() || (a[res].sz > s.sz || (a[res].sz == s.sz && s < a[res])))
		{
			fnd = true;
			a[res] = s;
		}
	};

	string s0[6] = {"x", "y", "z", "!x", "!y", "!z"};
	forn(i, 6)
	{
		int res = expr(s0[i]);
		upd(s0[i], res);
	}

	for(;;)
	{
		fnd = false;
		forn(i, 256)
		{
			if (a[i].empty()) continue;
			{
				string s = "!" + a[i];
				int res = expr(s);
				upd(s, res);
			}
			{
				string s = "!(" + a[i] + ")";
				int res = expr(s);
				upd(s, res);
			}
		}
		forn(i, 256)
		{
			if (a[i].empty()) continue;
			forn(j, 256)
			{
				if (a[j].empty()) continue;
				{
					string s = a[i] + "|" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = a[i] + "&" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = a[i] + "|!" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = a[i] + "&!" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!" + a[i] + "|" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!" + a[i] + "&" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!" + a[i] + "|!" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!" + a[i] + "&!" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = a[i] + "&(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = a[i] + "&!(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "(" + a[i] + ")&" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!(" + a[i] + ")&" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = a[i] + "|(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = a[i] + "|!(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "(" + a[i] + ")|" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!(" + a[i] + ")|" + a[j];
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "(" + a[i] + ")|(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!(" + a[i] + ")|(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "(" + a[i] + ")|!(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "(" + a[i] + ")&(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "!(" + a[i] + ")&(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
				{
					string s = "(" + a[i] + ")&!(" + a[j] + ")";
					int res = expr(s);
					upd(s, res);
				}
			}
		}
		if (!fnd) break;
	}

	forn(i, 256)
	{
		assert(!a[i].empty());
//		printf("a[%d]=\"%s\";\n", i, a[i].c_str());
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
a[0]="!x&x";
a[1]="!(x|y|z)";
a[2]="!x&!y&z";
a[3]="!x&!y";
a[4]="!x&!z&y";
a[5]="!x&!z";
a[6]="!(!y&!z|x|y&z)";
a[7]="!(x|y&z)";
a[8]="!x&y&z";
a[9]="!(!y&z|!z&y|x)";
a[10]="!x&z";
a[11]="!(!z&y|x)";
a[12]="!x&y";
a[13]="!(!y&z|x)";
a[14]="!x&(y|z)";
a[15]="!x";
a[16]="!y&!z&x";
a[17]="!y&!z";
a[18]="!(!x&!z|x&z|y)";
a[19]="!(x&z|y)";
a[20]="!(!x&!y|x&y|z)";
a[21]="!(x&y|z)";
a[22]="!(!x&!y|x&y|z)|!x&!y&z";
a[23]="!((x|y)&z|x&y)";
a[24]="!x&y&z|!y&!z&x";
a[25]="!x&y&z|!y&!z";
a[26]="!x&z|!y&!z&x";
a[27]="!x&z|!y&!z";
a[28]="!x&y|!y&!z&x";
a[29]="!x&y|!y&!z";
a[30]="!x&(y|z)|!y&!z&x";
a[31]="!x|!y&!z";
a[32]="!y&x&z";
a[33]="!(!x&z|!z&x|y)";
a[34]="!y&z";
a[35]="!(!z&x|y)";
a[36]="!x&!z&y|!y&x&z";
a[37]="!x&!z|!y&x&z";
a[38]="!x&!z&y|!y&z";
a[39]="!x&!z|!y&z";
a[40]="!x&y&z|!y&x&z";
a[41]="!(!x&z|!z&x|y)|!x&y&z";
a[42]="!(x&y)&z";
a[43]="!(!z&x|y)|!x&z";
a[44]="!x&y|!y&x&z";
a[45]="!(!y&z|x)|!y&x&z";
a[46]="!x&y|!y&z";
a[47]="!x|!y&z";
a[48]="!y&x";
a[49]="!(!x&z|y)";
a[50]="!y&(x|z)";
a[51]="!y";
a[52]="!x&!z&y|!y&x";
a[53]="!x&!z|!y&x";
a[54]="!x&!z&y|!y&(x|z)";
a[55]="!x&!z|!y";
a[56]="!x&y&z|!y&x";
a[57]="!(!x&z|y)|!x&y&z";
a[58]="!x&z|!y&x";
a[59]="!x&z|!y";
a[60]="!x&y|!y&x";
a[61]="!(!x&!y&z|x&y)";
a[62]="!x&(y|z)|!y&x";
a[63]="!x|!y";
a[64]="!z&x&y";
a[65]="!(!x&y|!y&x|z)";
a[66]="!x&!y&z|!z&x&y";
a[67]="!x&!y|!z&x&y";
a[68]="!z&y";
a[69]="!(!y&x|z)";
a[70]="!x&!y&z|!z&y";
a[71]="!x&!y|!z&y";
a[72]="!x&y&z|!z&x&y";
a[73]="!(!x&y|!y&x|z)|!x&y&z";
a[74]="!x&z|!z&x&y";
a[75]="!(!z&y|x)|!z&x&y";
a[76]="!(x&z)&y";
a[77]="!(!y&x|z)|!x&y";
a[78]="!x&z|!z&y";
a[79]="!x|!z&y";
a[80]="!z&x";
a[81]="!(!x&y|z)";
a[82]="!x&!y&z|!z&x";
a[83]="!x&!y|!z&x";
a[84]="!z&(x|y)";
a[85]="!z";
a[86]="!x&!y&z|!z&(x|y)";
a[87]="!x&!y|!z";
a[88]="!x&y&z|!z&x";
a[89]="!(!x&y|z)|!x&y&z";
a[90]="!x&z|!z&x";
a[91]="!(!x&!z&y|x&z)";
a[92]="!x&y|!z&x";
a[93]="!x&y|!z";
a[94]="!x&(y|z)|!z&x";
a[95]="!x|!z";
a[96]="!y&x&z|!z&x&y";
a[97]="!(!x&y|!y&x|z)|!y&x&z";
a[98]="!y&z|!z&x&y";
a[99]="!(!z&x|y)|!z&x&y";
a[100]="!y&x&z|!z&y";
a[101]="!(!y&x|z)|!y&x&z";
a[102]="!y&z|!z&y";
a[103]="!(!y&!z&x|y&z)";
a[104]="!x&y&z|!y&x&z|!z&x&y";
a[105]="!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
a[106]="!(x&y)&z|!z&x&y";
a[107]="!(!z&x|y)|!x&z|!z&x&y";
a[108]="!(x&z)&y|!y&x&z";
a[109]="!(!y&x|z)|!x&y|!y&x&z";
a[110]="!(x&y)&z|!z&y";
a[111]="!x|!y&z|!z&y";
a[112]="!(y&z)&x";
a[113]="!(!x&y|z)|!y&x";
a[114]="!y&z|!z&x";
a[115]="!y|!z&x";
a[116]="!y&x|!z&y";
a[117]="!y&x|!z";
a[118]="!y&(x|z)|!z&y";
a[119]="!y|!z";
a[120]="!(y&z)&x|!x&y&z";
a[121]="!(!x&y|z)|!x&y&z|!y&x";
a[122]="!(x&y)&z|!z&x";
a[123]="!x&z|!y|!z&x";
a[124]="!(x&z)&y|!y&x";
a[125]="!x&y|!y&x|!z";
a[126]="!x&y|!y&z|!z&x";
a[127]="!(x&y&z)";
a[128]="x&y&z";
a[129]="!(x|y|z)|x&y&z";
a[130]="!x&!y&z|x&y&z";
a[131]="!x&!y|x&y&z";
a[132]="!x&!z&y|x&y&z";
a[133]="!x&!z|x&y&z";
a[134]="!(!y&!z|x|y&z)|x&y&z";
a[135]="!(x|y&z)|x&y&z";
a[136]="y&z";
a[137]="!(x|y|z)|y&z";
a[138]="!x&z|y&z";
a[139]="!x&!y|y&z";
a[140]="!x&y|y&z";
a[141]="!x&!z|y&z";
a[142]="!x&(y|z)|y&z";
a[143]="!x|y&z";
a[144]="!y&!z&x|x&y&z";
a[145]="!y&!z|x&y&z";
a[146]="!(!x&!z|x&z|y)|x&y&z";
a[147]="!(x&z|y)|x&y&z";
a[148]="!(!x&!y|x&y|z)|x&y&z";
a[149]="!(x&y|z)|x&y&z";
a[150]="!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
a[151]="!((x|y)&z|x&y)|x&y&z";
a[152]="!y&!z&x|y&z";
a[153]="!y&!z|y&z";
a[154]="!x&z|!y&!z&x|y&z";
a[155]="!(x&z|y)|y&z";
a[156]="!x&y|!y&!z&x|y&z";
a[157]="!(x&y|z)|y&z";
a[158]="!x&(y|z)|!y&!z&x|y&z";
a[159]="!x|!y&!z|y&z";
a[160]="x&z";
a[161]="!(x|y|z)|x&z";
a[162]="!y&z|x&z";
a[163]="!x&!y|x&z";
a[164]="!x&!z&y|x&z";
a[165]="!x&!z|x&z";
a[166]="!x&!z&y|!y&z|x&z";
a[167]="!(x|y&z)|x&z";
a[168]="(x|y)&z";
a[169]="!(x|y|z)|(x|y)&z";
a[170]="z";
a[171]="!x&!y|z";
a[172]="!x&y|x&z";
a[173]="!(!y&z|x)|x&z";
a[174]="!x&y|z";
a[175]="!x|z";
a[176]="!y&x|x&z";
a[177]="!y&!z|x&z";
a[178]="!y&(x|z)|x&z";
a[179]="!y|x&z";
a[180]="!x&!z&y|!y&x|x&z";
a[181]="!(x&y|z)|x&z";
a[182]="!x&!z&y|!y&(x|z)|x&z";
a[183]="!x&!z|!y|x&z";
a[184]="!y&x|y&z";
a[185]="!(!x&z|y)|y&z";
a[186]="!y&x|z";
a[187]="!y|z";
a[188]="!x&y|!y&x|x&z";
a[189]="!x&!z|!y&x|y&z";
a[190]="!x&y|!y&x|z";
a[191]="!x|!y|z";
a[192]="x&y";
a[193]="!(x|y|z)|x&y";
a[194]="!x&!y&z|x&y";
a[195]="!x&!y|x&y";
a[196]="!z&y|x&y";
a[197]="!x&!z|x&y";
a[198]="!x&!y&z|!z&y|x&y";
a[199]="!(x|y&z)|x&y";
a[200]="(x|z)&y";
a[201]="!(x|y|z)|(x|z)&y";
a[202]="!x&z|x&y";
a[203]="!(!z&y|x)|x&y";
a[204]="y";
a[205]="!x&!z|y";
a[206]="!x&z|y";
a[207]="!x|y";
a[208]="!z&x|x&y";
a[209]="!y&!z|x&y";
a[210]="!x&!y&z|!z&x|x&y";
a[211]="!(x&z|y)|x&y";
a[212]="!z&(x|y)|x&y";
a[213]="!z|x&y";
a[214]="!x&!y&z|!z&(x|y)|x&y";
a[215]="!x&!y|!z|x&y";
a[216]="!z&x|y&z";
a[217]="!(!x&y|z)|y&z";
a[218]="!x&z|!z&x|x&y";
a[219]="!x&!y|!z&x|y&z";
a[220]="!z&x|y";
a[221]="!z|y";
a[222]="!x&z|!z&x|y";
a[223]="!x|!z|y";
a[224]="(y|z)&x";
a[225]="!(x|y|z)|(y|z)&x";
a[226]="!y&z|x&y";
a[227]="!(!z&x|y)|x&y";
a[228]="!z&y|x&z";
a[229]="!(!y&x|z)|x&z";
a[230]="!y&z|!z&y|x&y";
a[231]="!x&!y|!z&y|x&z";
a[232]="(x|y)&z|x&y";
a[233]="!(x|y|z)|(x|y)&z|x&y";
a[234]="x&y|z";
a[235]="!x&!y|x&y|z";
a[236]="x&z|y";
a[237]="!x&!z|x&z|y";
a[238]="y|z";
a[239]="!x|y|z";
a[240]="x";
a[241]="!y&!z|x";
a[242]="!y&z|x";
a[243]="!y|x";
a[244]="!z&y|x";
a[245]="!z|x";
a[246]="!y&z|!z&y|x";
a[247]="!y|!z|x";
a[248]="x|y&z";
a[249]="!y&!z|x|y&z";
a[250]="x|z";
a[251]="!y|x|z";
a[252]="x|y";
a[253]="!z|x|y";
a[254]="x|y|z";
a[255]="!x|x";

	precalc();
	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		char s[10];
		scanf("%s", s);
		int t = 0;
		forn(i, 8)
		{
			t |= (s[i] - '0') << i;
		}
		printf("%s\n", a[t].c_str());
	}
	
	return 0;
}