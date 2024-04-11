#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((ll) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

bool works(int N, int* arrb, int s, int e)
{
	if (e >= N)
		return false;

	int arr[N];
	loop(i, N)
		arr[i] = arrb[i];

	for (int a = s, b = e; a < b; a++, b--)
		swap(arr[a], arr[b]);

	loop(i, N)
	{
		if (arr[i] != i)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int N;
	rint(N);

	int arr[N];
	loop(i, N)
		rint(arr[i]);

	int cop[N];
	loop(i, N)
		cop[i] = arr[i];

	sort(cop, cop + N);

	map<int, int> M;
	loop(i, N)
		M[cop[i]] = i;

	loop(i, N)
		arr[i] = M[arr[i]];

	int s = -1, e1 = -1, e2 = -1;
	loop(i, N)
	{
		if (arr[i] == i)
		{
			if (s >= 0)
			{
				e1 = i-1;
				e2 = i * 2 - s;
				break;
			}
		}
		else
		{
			if (s < 0)
				s = i;
		}
	}

	if (e1 < 0)
		e1 = N - 1;

	if (s < 0)
		printf("yes\n1 1\n");
	else if (works(N, arr, s, e1))
		printf("yes\n%d %d\n", s+1, e1+1);
	else if (works(N, arr, s, e2))
		printf("yes\n%d %d\n", s+1, e2+1);
	else
		printf("no\n");
}