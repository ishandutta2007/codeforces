#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define mp make_pair
#define forn(i, n) for(int i=0; i<(int)(n); i++)

typedef pair < int, int > PII;

#define x first
#define y second

const int pp = 250003;

int n;
char a[40];
PII hh[pp];
int gg[pp];

PII calch(char *a)
{
	PII z = mp(2, 1);
	int l = strlen(a);
	forn(i, l)
	{
		z.x = z.x * 74 + a[i] - '`';
		z.y = z.y * 43 + a[i] - '`';
	}
	return z;
}

int hadd(PII x)
{
	int j = (x.x + x.y) % pp;
	if (j < 0) j += pp;
	while (hh[j].x != -1)
	{
		if (hh[j] == x) return gg[j]++;
		j += 197;
		if (j >= pp) j -= pp;
	}
	hh[j] = x;
	gg[j] = 1;
	return 0;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	memset(hh, 0xff, sizeof(hh));
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%s", a);
		PII z = calch(a);
		int x = hadd(z);
		if (x) printf("%s%d\n", a, x);
		else puts("OK");
	}

	return 0;
}