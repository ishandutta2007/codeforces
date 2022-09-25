#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

set <int> hor, ver;
multiset <int> hor_size, ver_size;

int solve()
{
    int w, h, n;
    cin >> w >> h >> n;
    hor.insert(0);
    hor.insert(h);
    ver.insert(0);
    ver.insert(w);
    hor_size.insert(h);
    ver_size.insert(w);
    for (int i = 0; i < n; ++i)
    {
        char op;
        int d;
        cin >> op >> d;
        if (op == 'H')
        {
            auto it = hor.insert(d).first;
            auto pr = it, nx = it;
            --pr, ++nx;
            
            hor_size.erase(hor_size.find(*nx - *pr));
            hor_size.insert(*nx - d);
            hor_size.insert(d - *pr);
        }
        else
        {
            auto it = ver.insert(d).first;
            auto pr = it, nx = it;
            --pr, ++nx;
            ver_size.erase(ver_size.find(*nx - *pr));
            ver_size.insert(*nx - d);
            ver_size.insert(d - *pr);
        }
        cout << ll(*hor_size.rbegin()) * ll(*ver_size.rbegin()) << '\n';
    }
    return 0;
}