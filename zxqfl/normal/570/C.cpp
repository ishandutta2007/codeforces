#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); i++)
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
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rint(x);
#define rfloat(x) scanf("%lf", &(x))

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
	char c,r=0,n=0;
	x=0;
	for (ever)
	{
		c=getchar();
		if ((c<0) && (!r))
			return(0);
		else if ((c=='-') && (!r))
			n=1;
		else if ((c>='0') && (c<='9'))
			x=x*10+c-'0',r=1;
		else if (r)
			break;
	}
	if (n)
		x=-x;
	return(1);
}

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

const int MX = 3.1e5;
int N, Q;
char s[MX];
int nper, nnxt;

int main()
{
	rint(N); rint(Q);
	scanf("%s", s + 1);
	s[0] = 'a';
	ji(N+1) nper += s[i] == '.';
	ji(N) nnxt += s[i] != '.' && s[i+1] == '.';
	jk(Q)
	{
		int idx;
		rint(idx);
		char z[2];
		scanf("%s", z);
		char nc = z[0];
		if (s[idx] != nc)
		{
			if (s[idx] == '.')
			{
				--nper;
				if (idx > 0 && s[idx-1] != '.')
					--nnxt;
				if (s[idx+1] == '.')
					++nnxt;
			}
			else if (nc == '.')
			{
				++nper;
				if (idx > 0 && s[idx-1] != '.')
					++nnxt;
				if (s[idx+1] == '.')
					--nnxt;
			}
		}
		s[idx] = nc;
		printf("%d\n", nper - nnxt);
	}		
}