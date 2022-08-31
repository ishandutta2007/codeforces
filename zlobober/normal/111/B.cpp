#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

const int N = 100500;
vector<int> V[N];

int A[N];
int prev[N];


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> prev[i];
        for (int q = 1; q * q <= A[i]; q++)
            if (!(A[i] % q))
            {
                V[q].push_back(i);
                if (q * q != A[i])
                    V[A[i] / q].push_back(i);
            }
    }
    for (int i = 0; i < N; i++)
    {
        V[i].push_back(-1e9);
        sort(V[i].begin(), V[i].end());
    }
    int ans[N];
    memset(ans, 0, sizeof(ans));
    for (int d = 1; d < N; d++)
    {
        for (int i = 1; i < V[d].size(); i++)
        {
            if (V[d][i] - prev[V[d][i]] <= V[d][i - 1])
                continue;
            ans[V[d][i]]++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}