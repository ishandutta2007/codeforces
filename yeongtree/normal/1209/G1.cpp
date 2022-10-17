#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct X{int s, e, x;};

int main()
{
    int n, q; cin >> n >> q;
    int arr[n]; for(auto &i : arr) cin >> i;
    vector<int> prX(arr, arr + n);
    sort(prX.begin(), prX.end());
    prX.erase(unique(prX.begin(), prX.end()), prX.end());
    int m = prX.size();
    for(auto &i : arr) i = lower_bound(prX.begin(), prX.end(), i) - prX.begin();

    X dt[m]; for(int i = 0; i < m; ++i) dt[i].s = -1, dt[i].e = -1, dt[i].x = 0;
    for(int i = 0; i < n; ++i)
    {
        if(dt[arr[i]].s == -1) dt[arr[i]].s = i;
        dt[arr[i]].e = i + 1;
        ++dt[arr[i]].x;
    }

    sort(dt, dt + m, [](X &x, X &y){return x.s < y.s;});
    int sum = 0, last = -1, mx = 0;
    for(auto &i : dt)
    {
        if(last == -1 || i.s >= last)
        {
            sum += mx;
            last = i.e;
            mx = i.x;
        }
        else
        {
            last = max(last, i.e);
            mx = max(mx, i.x);
        }
    }
    sum += mx;

    cout << n - sum;
    return 0;
}