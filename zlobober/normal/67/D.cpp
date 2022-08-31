#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

//#define TASK ""

const int N = 1000500;
vector<int> A, B;
int n;
void count()
{
	vector<int> p(n);
	int l, r;
 
	B.push_back(0);
 
	for (int i = 1; i < n; i++) 
    {
        if (A[B.back()] < A[i]) 
		{
			p[i] = B.back();
			B.push_back(i);
			continue;
		}
		
 		for (l = 0, r = B.size() - 1; l < r;) 
        {
			int c = (l + r) / 2;
			if (A[B[c]] < A[i]) 
				l = c + 1;
			else 
				r = c;
		}
 
		if (A[i] < A[B[l]]) 
		{
			if (l > 0) 
				p[i] = B[l - 1];
			B[l] = i;
		}	
	}
 
	for (l = B.size(), r = B.back(); l--; r = p[r]) 
		B[l] = r;
}


int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	cin >> n;
	vector<int> P(n + 1);
	int t;
	A.resize(n);
	for (int i = 0; i < n; i++)
		cin >> t, P[t] = i + 1;
	for (int i = 0; i < n; i++)
		cin >> t, A[i] = -P[t];
	count();
	cout << B.size();
	return 0;
}