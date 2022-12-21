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
#define rfloat(x) scanf("%lf", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<double, double> pd;

int W, H, N;


int main()
{
	rint(W); rint(H); rint(N);
	set<pi, greater<pi> > sH, sV;
	multiset<int> sizeH, sizeV;
	sizeH.insert(W);
	sizeV.insert(H);
	sH.insert({0, W});
	sV.insert({0, H});
	jk(N)
	{
		char str[10];
		scanf("%s", str);
		int pos;
		rint(pos);
		if (*str == 'V')
		{
			auto x = sH.lower_bound({pos, -1});
			int st = x->first;
			int ssz = x->second;
			sH.erase(x);
			sH.insert({st, pos - st});
			sH.insert({pos, ssz - (pos - st)});
			sizeH.erase(sizeH.find(ssz));
			sizeH.insert(pos - st);
			sizeH.insert(ssz - (pos - st));
		}
		else
		{
			auto x = sV.lower_bound({pos, -1});
			int st = x->first;
			int ssz = x->second;
			sV.erase(x);
			sV.insert({st, pos - st});
			sV.insert({pos, ssz - (pos - st)});
			sizeV.erase(sizeV.find(ssz));
			sizeV.insert(pos - st);
			sizeV.insert(ssz - (pos - st));
		}
		printf("%lld\n", (ll) *sizeV.rbegin() * *sizeH.rbegin());
	}
}