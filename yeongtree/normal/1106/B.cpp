#include <iostream>
#include <algorithm>

using namespace std;

struct dish
{
    int id;
    long long int c;
    bool operator<(dish& x)
    {
        if(this->c < x.c) return true;
        else if(this->c > x.c) return false;
        else if(this->id < x.id) return true;
        else return false;
    }
};

int main()
{
    int n, m; cin >> n >> m;
    long long int c[n];
    int r[n];
    dish d[n];

    int a;
    for(int i = 0; i < n; ++i){d[i].id = i;}
    for(int i = 0; i < n; ++i){cin >> a; r[i] = a;}
    for(int i = 0; i < n; ++i){cin >> a; d[i].c = a; c[i] = a;}
    sort(d, d + n);

    int mini = 0;
    for(int i = 0; i < m; ++i)
    {
        long long int _ans = 0;
        int t, am; cin >> t >> am; --t;
        int here = t;

        while(r[here] < am)
        {
            am -= r[here]; _ans += c[here] * r[here]; r[here] = 0;
            if(mini < n && r[d[mini].id] == 0) ++mini;
            if(mini == n) {am = 0; _ans = 0; break;}
            here = d[mini].id;
        }
        _ans += c[here] * am; r[here] -= am;

        cout << _ans << '\n';
    }

    return 0;
}