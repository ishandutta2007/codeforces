#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using pll=pair<ll,ll>;
using vll=vector<ll>;
const int nax=407;
//~ const int nax=10;
ll mod;

int t;

ll dob[nax];
ll gir[nax];

ll glo[nax];

ll sil[nax];

ll ple[nax][nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void odj(ll &a, ll b)
{
	a=(a-b)%mod;
	if (a<0)
		a+=mod;
}

int main()
{
	scanf("%d%lld", &t, &mod);
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	
	dob[1]=1;
	dob[2]=2;
	gir[1]=1;
	gir[2]=1;
	ple[0][0]=1;
	glo[1]=1;
	glo[2]=2;
	for (int j=1; j<nax; j++)
		for (int l=1; l<nax; l++)
			for (int k=1; k<=l; k++)
				dod(ple[j][l], ple[j-1][l-k]*sil[k]);
	for (int i=3; i<nax; i++)
	{
		for (int j=1; j<i; j++)
		{
			if (j>2)
			{
				dod(glo[i], sil[i-j]*(sil[j]+mod-gir[j]));
			}
			else
			{
				dod(glo[i], sil[i-j]);
			}
		}
		gir[i]=glo[i];
		//~ debug() << i << " " << imie(gir[i]);
		dod(dob[i], sil[i]);
		odj(dob[i], 2*gir[i]);
		for (int j=3; j<i; j++)
			odj(dob[i], dob[j]*ple[j][i]);
		//~ dod(gir[i], 2*dob[i]);
		dod(glo[i], gir[i]+dob[i]);
		//~ gir[i]=sil[i];
		//~ debug() << i << " " << imie(dob[i]);
		//~ debug() << i << " " << imie(gir[i]);
	}
	
	while(t--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", dob[n]);
	}
	//~ debug() << range(dob+1, dob+nax);
	return 0;
}
//~ main#95: 3 [gir[i]: 3] 
//~ main#103: 3 [dob[i]: 0] 
//~ main#104: 3 [gir[i]: 3] 
//~ main#95: 4 [gir[i]: 11] 
//~ main#103: 4 [dob[i]: 2] 
//~ main#104: 4 [gir[i]: 11] 
//~ main#95: 5 [gir[i]: 49] 
//~ main#103: 5 [dob[i]: 6] 
//~ main#104: 5 [gir[i]: 49] 
//~ main#95: 6 [gir[i]: 227] 
//~ main#103: 6 [dob[i]: 110] 
//~ main#104: 6 [gir[i]: 227] 
//~ main#95: 7 [gir[i]: 1265] 
//~ main#103: 7 [dob[i]: 226] 
//~ main#104: 7 [gir[i]: 1265] 
//~ main#95: 8 [gir[i]: 6439] 
//~ main#103: 8 [dob[i]: 7926] 
//~ main#104: 8 [gir[i]: 6439] 
//~ main#95: 9 [gir[i]: 47293] 
//~ main#103: 9 [dob[i]: 4250] 
//~ main#104: 9 [gir[i]: 47293] 
//~ main#108: [1, 2, 0, 2, 6, 110, 226, 7926, 4250]
//~ [kp371301@green14 i]$ ./brut < in1
//~ 1
//~ 2
//~ 0
//~ 2
//~ 6
//~ 46
//~ 338
//~ 2926