#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;

using namespace std;

int qry(string s)
{
    cout << "? " << s << endl; cout.flush();
    int x; cin >> x;
    return x;
}

int main()
{
    int n, m; cin >> n >> m;
    pii A[m]; string s(m, '0');
    for(int i = 0; i < m; ++i)
    {
        s[i] = '1';
        A[i] = {qry(s), i};
        s[i] = '0';
    }

    sort(A, A + m);

    int w = 0;
    for(int i = 0; i < m; ++i)
    {
        s[A[i].ss] = '1';
        int x = qry(s);
        if(w + A[i].ff == x) w = x;
        else s[A[i].ss] = '0';
    }

    cout << "! " << w << endl; cout.flush();
    return 0;
}