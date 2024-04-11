#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

const int N = 100050;

struct num
{
	int v, p;
	friend bool operator <(const num& a, const num& b)
	{
		if (a.v != b.v)
			return a.v < b.v;
		return a.p < b.p;
	}
} A[N];

stack<int> E[N];

void die()
{
	cout << -1;
	exit(0);
}

int prin[N];

int main()
{
	memset(A, 0, sizeof(A));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i].v, A[i].p = i;
	sort(A, A + n);
	for (int i = 0; i < n; i++)
		E[A[i].v].push(i);
	
	for (int i = 1; i < N - 1; i++)
	{
		if (E[i + 1].size() > E[i].size())
			die();
	}
	int q;
	int pr = 1;
	int vv;
	memset(prin, 0, sizeof(prin));
	while (E[1].size())
	{
		for (q = 1; E[q].size(); q++);
		for (int i = 1; i < q; i++)
		{
			vv = E[i].top();
			prin[A[vv].p] = pr;
			E[i].pop();
		}
		pr++;
	}
	cout << pr - 1 << endl;
	for (int i = 0; i < n; i++)
		cout << prin[i] << ' ';
	return 0;
}