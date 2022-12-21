#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define rint(x) scanf("%d", &(x))
#define nrint(x) int x; rint(x);
#define pp make_pair
#define iter(it, C) for (__typeof(C.begin()) it = C.begin(); it != C.end(); ++it)

typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	nrint(N);
	multiset<int> S;
	ji(N)
	{
		nrint(x);
		S.insert(x);
	}
	multiset<int> S2 = S;
	ji(N-1)
	{
		nrint(x);
		S2.erase(S2.find(x));
	}
	printf("%d\n", *S2.begin());
	ji(N-2)
	{
		nrint(x);
		S.erase(S.find(x));
	}
	S.erase(S.find(*S2.begin()));
	iter(it, S) printf("%d\n", *it);
}