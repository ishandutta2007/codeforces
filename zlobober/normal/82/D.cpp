#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

//#define TASK ""

const int N = 1050;

int A[N];
int _D[N][N];
pair<int, int> pr[N][N];

int n;

int D(int i, int p)
{
	if (_D[i][p] != -1)
		return _D[i][p];
	if (p == 0)
	{
		pr[i][p] = make_pair(i, -1);
		return _D[i][p] = A[i];
	}
	else if (p == 1)
	{
		pr[i][p] = make_pair(i, n - 1);
		return _D[i][p] = max(A[i], A[n - 1]);
	}
	else
	{
		int vi =  D(i, p - 2) + max(A[n - p], A[n - p + 1]);
		int vp1 = D(n - p, p - 2) + max(A[i], A[n - p + 1]);
		int vp2 = D(n - p + 1, p - 2) + max(A[i], A[n - p]);
		int mn = min(vi, min(vp1, vp2));
		if (mn == vi)
			pr[i][p] = make_pair(n - p, n - p + 1);
		else if (mn == vp1)
			pr[i][p] = make_pair(i, n - p + 1);
		else
			pr[i][p] = make_pair(i, n - p);
		return _D[i][p] = mn;
	}
}

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	memset(_D, -1, sizeof(_D));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int ci = 0, cp = n - 1;
	cout << D(ci, cp) << endl;
	int Q[3];
	int L[2];
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		Q[0] = ci;
		Q[1] = n - cp;
		Q[2] = n - cp + 1;
		
		L[0] = pr[ci][cp].first;
		L[1] = pr[ci][cp].second;
		for (int j = 0; j < 2; j++)
			if (L[j] != -1)
				cout << L[j] + 1 << ' ';
		cout << endl;
		for (int j = 0; j < 3; j++)
			if (Q[j] != L[0] && Q[j] != L[1])
				ci = Q[j];
		cp -= 2;
	}
	return 0;
}