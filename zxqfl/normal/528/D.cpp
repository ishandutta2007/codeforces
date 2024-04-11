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

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<double, double> pd;


long long gcd(long long a, long long b, long long c, long long d, long long e, long long f, long long& o, long long& p)
{
    if(b==0)
    {
        o=c;
        p=e;
        return a;
    }
    long long k=a/b;
    return gcd(b, a-b*k, d, c-d*k, f, e-f*k, o, p);
}

long long modinv(long long a, long long b)
{
    long long c, d;
    gcd(a, b, 1, 0, 0, 1, c, d);
    return (c+b)%b;
}

long long powmod(long long a, long long b, long long MOD)
{
    long long ret=1;
    while(b)
    {
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ret;
}

// X is prime
long long primitive_root(long long X)
{
    vector<long long> prime_factors, test;
    long long factor=2;
    long long S=X-1;
    while(factor*factor<=S)
    {
        if(S%factor==0)
        {
            prime_factors.push_back(factor);
            while(S%factor==0)
                S/=factor;
        }
        factor++;
    }
    if(S>1)
        prime_factors.push_back(S);
    for(size_t i=0; i<prime_factors.size(); i++)
        test.push_back((X-1)/prime_factors[i]);
    for(long long ret=2; ret<X; ret++)
    {
        bool good=true;
        for(size_t i=0; i<test.size(); i++)
            if(powmod(ret, test[i], X)==1)
            {
                good=false;
                break;
            }
        if(good)
            return ret;
    }
    return -1;
}

long long nth_root_of_unity(long long n, long long pr, long long MOD)
{
    return powmod(pr, (MOD-1)/n, MOD);
}

int calc_max_pow2(long long X)
{
    int ret=0;
    while(X%2==0)
        ret++, X/=2;
    return ret;
}

// prime modulus
const long long MOD=2511339521;
// primitive root of MOD
const long long ROOT=primitive_root(MOD);
const long long IROOT=modinv(ROOT, MOD);
// exponent of 2 in prime factorization of MOD - 1
const int EXP=calc_max_pow2(MOD-1);

void fft(int n, long long *A, bool invert)
{
    int lgn=0;
    while((1<<lgn)<n)
        lgn++;
    for(int i=0; i<n; i++)
    {
        int x=0;
        for(int j=0; j<lgn; j++)
            x|=((i>>j)&1)<<(lgn-j-1);
        if(i<x)
            swap(A[i], A[x]);
    }
    long long rt=nth_root_of_unity(1<<EXP, invert?IROOT:ROOT, MOD);
    for(int i=1; i<=lgn; i++)
    {
        int len=1<<i;
        int hlen=len/2;
        // powmod(lenroot, len, MOD) == 1
        long long lenroot=rt;
        for(int j=i; j<EXP; j++)
            lenroot=((long long)lenroot*lenroot)%MOD;
        long long *w=new long long[hlen];
        w[0]=1;
        for(int j=1; j<hlen; j++)
            w[j]=((long long)w[j-1]*lenroot)%MOD;
        for(int j=0; j<n; j+=len)
        {
            for(int k=0; k<hlen; k++)
            {
                long long u=A[j+k], v=((long long)A[j+k+hlen]*w[k])%MOD;
                long long tmp=(long long)u+v;
                if(tmp>=MOD)
                    tmp-=MOD;
                A[j+k]=tmp;
                tmp=(long long)u-v;
                if(tmp<0)
                    tmp+=MOD;
                A[j+k+hlen]=tmp;
            }
        }
        delete[] w;
    }
    if(invert)
    {
        long long minv=modinv(n, MOD);
        for(int i=0; i<n; i++)
            A[i]=((long long)A[i]*minv)%MOD;
    }
}

void convolve(int n, long long *A, long long *B, long long *C)
{
    assert(__builtin_popcount(n) == 1);
    fft(n, A, false);
    fft(n, B, false);
    for(int i=0; i<n; i++)
        C[i]=((long long)A[i]*B[i])%MOD;
    fft(n, C, true);
}

void convolve(vector<long long>& _a, vector<long long>& _b, vector<long long>& c)
{
    int n=_a.size();
    int logn=0;
    while((1<<logn)<n)
        logn++;
    n=1<<logn;
    _a.resize(n);
    _b.resize(n);
    static vector<long long> a, b;
    a=_a, b=_b;
    c.resize(n);
    convolve(n, a.data(), b.data(), c.data());
}


int sS, sT, k;
char S[300001];
char T[300001];
int prefix[300000];
ll isOk[1000000];
ll wanted[1000000];
ll result[1000000];

int read(int a, int b)
{
	b = min(b, sS-1);
	if (a <= 0)
		return prefix[b];
	else
		return prefix[b] - prefix[a-1];
}
set<int> getAnswer(char c)
{
	int crnt = 0;
	ji(sS)
	{
		if (S[i] == c)
			crnt++;
		prefix[i] = crnt;
	}
	vector<ll> isOk(sS), wanted(sS), result;
	ji(sS)
	{
		isOk[i] = read(i-k, i+k) > 0 ? 1 : 0;
	}
	int tot = 0;
	ji(sS) wanted[i] = 0;
	ji(sT)
	{
		wanted[i] = T[i] == c ? 1 : 0;
		tot += wanted[i];
	}
	reverse(isOk.begin(), isOk.end());
	convolve(isOk, wanted, result);
	set<int> ans;
	jjs(i, sT - 1, sS)
	{
		if (result[i] == tot)
			ans.insert(i);
	}
	return ans;
}

int main()
{
	rint(sS);
	rint(sT);
	rint(k);
	scanf("%s%s", S, T);
	int ans = 0;
	set<int> sa[4];
	sa[0] = getAnswer('A');
	sa[1] = getAnswer('G');
	sa[2] = getAnswer('C');
	sa[3] = getAnswer('T');
	ji(sS)
	{
		bool ok = true;
		jj(4) if (!sa[j].count(i))
			ok = false;
		if (ok) ans++;
	}
	printf("%d\n", ans);
}