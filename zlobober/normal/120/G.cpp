#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 300;

struct myqueue
{
	int beg, end;
	int U[N];
	void push(int x)
	{
		U[end] = x;
		end = (end + 1) % N;
	}
	int pop()
	{
		int ans = U[beg];
		beg = (beg + 1) % N;
		return ans;
	}
	bool empty()
	{
		return beg == end;
	}
} Q;

int A[N], B[N];
int C[N];

int G[N][N];

vector<int> O[N];
string S[N];
int n, t;
int m;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> A[i + n] >> B[i + n];
;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> S[i];
		cin >> C[i];
		Q.push(i);
	}
	int cur = 0;
	int tt = t;
	while (true)
	{
		int u = cur;	
		int v = (cur + n) % (2 * n);	
		tt = t;
		while (!Q.empty())
		{
			int q = Q.pop();
			int l = max(1, C[q] - (A[u] + B[v]) - G[min(u, v)][q]);
			if (l > tt)
			{
				G[min(u, v)][q] += tt;
				tt = 0;
				Q.push(q);
				break;
			}
			else
			{
				tt -= l;
				O[min(u, v)].push_back(q);
				if (tt == 0)
					break;
			}
		}
		if (Q.empty())
			break;
		cur = (cur + 1) % (2 * n);
	}
	for (int i = 0; i < n; i++)
	{
		cout << O[i].size() << ' ';
		for (int j = 0; j < O[i].size(); j++)
			cout << S[O[i][j]] << ' ';
		cout << endl;
	}
}