#include <bits/stdc++.h>

#define rloop(i, x) for (int i = (x); i >= 0; i--)
#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define INF ((int) 1e9)
#define mp make_pair
#define pb push_back
#define rint(N) scanf("%d", &(N))

#define MAXN 1000
#define MAXK 1000001

typedef long long ll;
using namespace std;

int solve()
{
	char A[MAXN], B[MAXN];

	scanf("%s%s", A, B);

	int L1 = strlen(A);
	int L2 = strlen(B);

	if (L2 > L1)
		return 0;

	bool ok = true;

	int a = 0;
	loop(i, L2)
	{
		while (a < L1 && A[a] != B[i])
			a++;
		if (a == L1)
			ok = false;
		a++;
	}

	if (ok)
		return 1;

	int count1[26], count2[26];
	loop(i, 26)
		count1[i] = count2[i] = 0;

	loop(i, L1)
		count1[A[i]-'a']++;
	loop(i, L2)
		count2[B[i]-'a']++;

	bool naut = false;
	loop(i, 26)
		if (count2[i] > count1[i])
			return 0;
		else if (count2[i] < count1[i])
			naut = true;

	return naut ? 3 : 2;
}

int main()
{
	switch (solve())
	{
		case 0:
			printf("need tree\n");
			break;

		case 1:
			printf("automaton\n");
			break;

		case 2:
			printf("array\n");
			break;

		case 3:
			printf("both\n");
			break;
	}
}