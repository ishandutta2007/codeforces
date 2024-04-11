#include <iostream>
#include <vector>

using namespace std;

const int Q = (int)1e9 + 7;

void print(vector<long long> &x)
{
    for(int i : x)
        cout << i << ' ';
    cout << endl;
}

vector<long long> f(long long x, long long m)
{
    if(!x)
    {
        vector<long long> ans(m);
        ans[m - 1] = 1;

        return ans;
    }

    if(x & 1)
    {
        vector<long long> prv = f(x - 1, m);
        vector<long long> ans(m);
        for(int i = 0; i < m - 1;  ++i)
            ans[i] = prv[i + 1];
        ans[m - 1] = prv[0] + prv[m - 1];

        return ans;
    }

    vector<long long> hlf = f(x >> 1, m);

    vector<long long> exhlf(m << 1);
    for(int i = 1; i < m; ++i)
    {
        exhlf[i] = hlf[i] - hlf[i - 1];
        if(exhlf[i] < 0) exhlf[i] += Q;
    }
    for(int i = m; i < (m << 1); ++i)
        exhlf[i] = hlf[i - m];

    vector<int> pos(m);
    for(int i = 0; i < m - 1; ++i)
        pos[i] = -(i + 1);
    pos[m - 1] = 0;

    vector<long long> ans(m);
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            ans[i] += exhlf[m + j] * exhlf[m + i + pos[j]];
            ans[i] %= Q;
        }
    }

    return ans;
}

int main()
{
    long long n, m; cin >> n >> m;

    cout << f(n + m - 1, m)[0];
    return 0;
}