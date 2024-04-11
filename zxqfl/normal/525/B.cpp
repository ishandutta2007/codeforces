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

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

char str[300000];
int arr[300000];

int main()
{
	scanf("%s", str);
	int L = strlen(str);
	nrint(M);
	int N = L/2;
	jk(M)
	{
		nrint(x);
		x--;
		arr[x]++;
	}
	int csum = 0;
	ji(N)
	{
		csum += arr[i];
		if (csum % 2)
			printf("%c", str[L-i-1]);
		else
			printf("%c", str[i]);
	}
	if (L % 2)
		printf("%c", str[L/2]);
	for (int i = N-1; i >= 0; i--)
	{
		if (csum % 2)
			printf("%c", str[i]);
		else
			printf("%c", str[L-i-1]);
		csum -= arr[i];
	}
	printf("\n");
}