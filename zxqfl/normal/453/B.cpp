#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int DS = 11;
int N;
const int S = 1 << DS;
int dp[100][100][S];

int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int uses[60];
pi diffs[100];
int answer[100];
vector<int> NV;

bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x % i == 0)
			return false;

	return true;
}



int solve(int p, int vs, int s)
{
	if (p >= N)
		return 0;
	int& ans = dp[p][vs][s];
	if (ans >= 0)
		return ans;

	ans = INF;

	loop(i, 60) if ((s & uses[i]) == uses[i])
	{
		ans = min(abs(i - diffs[p].first) + solve(p+1, vs, s ^ uses[i]), ans);
	}
	ans = min(ans, diffs[p].first - 1 + solve(p+1, vs, s));
	ans = min(ans, NV[vs] - diffs[p].first + solve(p+1, vs+1, s));

	return ans;
}

void extract(int p, int vs, int s)
{
	if (p >= N)
		return;

	int ans = solve(p, vs, s);
	//printf("ans(%d %d %d) = %d\n", p, vs, s, ans);

	loop(i, 60) if ((s & uses[i]) == uses[i])
	{
		if (abs(i - diffs[p].first) + solve(p+1, vs, s ^ uses[i]) == ans)
		{
			answer[p] = i;
			extract(p+1, vs, s ^ uses[i]);
			return;
		}
	}
	if (diffs[p].first - 1 + solve(p+1, vs, s) == ans)
	{
		answer[p] = 1;
		extract(p+1, vs, s);
		return;
	}
	if (ans == NV[vs] - diffs[p].first + solve(p+1, vs+1, s))
	{
		answer[p] = NV[vs];
		extract(p+1, vs+1, s);
		return;
	}

	assert(false);
}

int main()
{
	loop(i, 100)
		loop(k, 100)
			loop(j, S)
			dp[i][k][j] = -1;

	loop(i, 60)
	{
		uses[i] = 0;
		loop(j, 18)
		{
			if (i % arr[j] == 0)
			{
				uses[i] |= 1 << j;
			}
		}
	}

	rint(N);
	loop(i, N)
	{
		rint(diffs[i].first);
		diffs[i].second = i;
	}

	sort(diffs, diffs + N);

	for (int i = arr[DS-1]+1; NV.size() < N; i++)
		if (prime(i))
			NV.pb(i);

	extract(0, 0, (1 << DS) - 1);

	loop(i, N)
	{
		diffs[i].first = diffs[i].second;
		diffs[i].second = i;
	}

	sort(diffs, diffs + N);

	loop(i, N)
	{
		printf("%d ", answer[diffs[i].second]);
	}
	printf("\n");
}