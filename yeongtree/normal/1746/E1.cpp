#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

void f(vector<int> X, vector<int> Y)
{
    while(1)
    {
        if((int)X.size() + (int)Y.size() <= 2)
        {
            for(auto i : X)
            {
                cout << "! " << i << endl;
                cout.flush();
                string s; cin >> s;
                if(s == ":)") exit(0);
            }
            for(auto i : Y)
            {
                cout << "! " << i << endl;
                cout.flush();
                string s; cin >> s;
                if(s == ":)") exit(0);
            }
        }

        int n = X.size(), m = Y.size();
        int _n, _m;
        if(n * 2 <= m && m <= 3 * n) _n = n, _m = 0;
        else _n = n / 2, _m = m / 2;
        vector<int> A, B, C, D;
        for(int i = 0; i < _n; ++i) A.push_back(X[i]);
        for(int i = _n; i < n; ++i) B.push_back(X[i]);
        for(int i = 0; i < _m; ++i) C.push_back(Y[i]);
        for(int i = _m; i < m; ++i) D.push_back(Y[i]);
        X.clear(); Y.clear();

        cout << "? " << A.size() + C.size();
        for(auto i : A) cout << ' ' << i;
        for(auto i : C) cout << ' ' << i;
        cout << endl;
        cout.flush();
        string s; cin >> s;
        if(s == "YES")
        {
            for(auto i : D) X.push_back(i);
            for(auto i : A) Y.push_back(i);
            for(auto i : C) Y.push_back(i);
        }
        else
        {
            for(auto i : C) X.push_back(i);
            for(auto i : B) Y.push_back(i);
            for(auto i : D) Y.push_back(i);
        }

//        for(auto i : X) cout << i << ' '; cout << endl;
//        for(auto i : Y) cout << i << ' '; cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> A;
    for(int i = 1; i <= n; ++i) A.push_back(i);
    f(vector<int>(), A);
}