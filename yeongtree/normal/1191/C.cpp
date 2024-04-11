#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; int m; cin >> n >> m >> k;
    long long p[m]; for(long long &i : p) {cin >> i; --i;}

    int pt = 0, er = 0, op = 0;
    while(pt < m)
    {
        er = pt;
        long long fin = ( (p[pt] - er) / k + 1 ) * k;
        while(pt < m && (p[pt] - er) < fin) ++pt;
        ++op;
    }

    cout << op;
    return 0;
}