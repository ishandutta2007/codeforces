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

#ifndef ONLINE_JUDGE
const bool DEBUG = true;
#define Db(x...)   ({ if (DEBUG) { cout << "Debug["; DB, #x, ":", x, "]\n"; } })
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {  
    cout << "Debug[ ";
    if (!note.empty()) cout << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cout << setw(w) << *lo << " ";
    cout << "]" << endl;
  }
}
struct Debugger { template<class T> Debugger& operator ,
  (const T & v) { cout << " " << v << flush; return *this; } } DB;
#else
const bool DEBUG = false;
#define Db(x...)
#endif

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

const int MX = 3.1e5;
const int MAXK = 1.1e6;

int cntAt[MAXK];
int arr[MX];
int N, K;
ll ans = 0;
vector<int> prefixLeft, prefixRight, used, eleLeft, eleRight;

void resetArr()
{
	foreach(q, used)
		cntAt[q] = 0;
	used.clear();
}

void conquer(int a, int b)
{
	if (a >= b) return;
	int mid = (a + b) / 2;
	conquer(a, mid);
	conquer(mid+1, b);
	prefixLeft.clear();
	prefixRight.clear();
	eleLeft.clear();
	eleRight.clear();
	int sum = 0;
	for (int i = mid; i >= a; --i)
	{
		sum += arr[i];
		sum %= K;
		prefixLeft.pb(sum);
		eleLeft.pb(arr[i]);
	}
	sum = 0;
	for (int i = mid+1; i <= b; ++i)
	{
		sum += arr[i];
		sum %= K;
		prefixRight.pb(sum);
		eleRight.pb(arr[i]);
	}
	// printf("conquer %d %d -> %lld\n", a, b, ans);
	jk(2)
	{
		int idx = 0;
		int mmx = 0;
		ji(prefixLeft.size())
		{
			mmx = max(mmx, eleLeft[i]);
			while (idx < prefixRight.size() && eleRight[idx] < mmx + k)
			{
				cntAt[prefixRight[idx]]++;
				used.pb(prefixRight[idx]);
				// printf("PLUS %d\n", prefixRight[idx]);
				++idx;
			}
			int q = K - (prefixLeft[i] - mmx);
			q %= K;
			if (q < 0) q += K;
			ans += cntAt[q];
			// printf("QUERY %d (%d %d)\n", q, prefixLeft[i], mmx);
		}
		// printf("CLEAR!\n"); 
		resetArr();
		swap(prefixLeft, prefixRight);
		swap(eleLeft, eleRight);
	}
	// printf("ends at %lld\n", ans);
}

int main()
{
	rint(N); rint(K);
	ji(N)
	{
		rint(arr[i]);
	}	
	conquer(0, N-1);
	printf("%lld\n", ans);
}