#include <iostream>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long llong;

const int N = 100500;

int A[N];

llong iters = 0;

set<pair<int, int> > S;
map<int, int> M;
llong k;
int n;	

bool gobig()
{
	if (S.size() == 0)
		return false;
	int mn = S.begin()->first;
	if (k >= (llong)(mn - iters) * S.size())
	{
		k -= (mn - iters) * (llong)S.size();
		iters = mn;
		M.erase(S.begin()->second);
		S.erase(S.begin());
		return true;
	}
	else
	{
		llong its = k / S.size();
		k -= its * S.size();
		iters += its;
		return false;
	}
}

queue<int> Q;

void gosmall()
{
	for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
		Q.push(it->first);
	int z;
	for (int i = 0; i < n; i++)
		A[i] = M[i] - iters;
	for (int i = 0; i < k; i++)
	{
		z = Q.front();
		Q.pop();
		A[z]--;
		if (A[z] > 0)
			Q.push(z);
	}
	while (!Q.empty())
		cout << Q.front() + 1 << ' ', Q.pop();
	exit(0);
}



int main()
{
	cin >> n;
	cin >> k;
	llong sum = 0;
	for (int i = 0; i < n; i++)
		cin >> A[i], sum += A[i], S.insert(make_pair(A[i], i)), M[i] = A[i];
	if (sum < k)
	{
		cout << -1;
		return 0;
	}
	else if (sum == k)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (gobig())
			continue;
		gosmall();
		return 0;
	}
	gosmall();
}