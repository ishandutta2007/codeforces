#include <iostream>
#include <algorithm>

using namespace std;

struct tp
{
    int s1, e1, s2, e2;
};

int n;
tp arr[101010];

bool cmp(const tp &x, const tp &y) { return x.s1 < y.s1; }

bool ifsense(void)
{
    sort(arr, arr + n, cmp);

    int inds[n << 1], inde[n << 1];
    for(int i = 0; i < n; ++i)
        inds[i + n] = arr[i].s2, inde[i + n] = arr[i].e2;
    for(int i = n - 1; i >= 1; --i)
    {
        inds[i] = max(inds[i << 1], inds[i << 1 | 1]);
        inde[i] = min(inde[i << 1], inde[i << 1 | 1]);
    }

    for(int i = 0; i < n; ++i)
    {
        int x = i + 1;
        int y = upper_bound(arr, arr + n, tp{arr[i].e1, 0, 0, 0}, cmp) - arr;

        int ms = -2e9, me = 2e9;
        for(x += n, y += n; x != y; x >>= 1, y >>= 1)
        {
            if(x & 1) ms = max(ms, inds[x]), me = min(me, inde[x++]);
            if(y & 1) ms = max(ms, inds[--y]), me = min(me, inde[y]);
        }

        if(ms > arr[i].e2 || me < arr[i].s2) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i].s1 >> arr[i].e1 >> arr[i].s2 >> arr[i].e2;

    if(ifsense()) {cout << "NO"; return 0;}

    for(int i = 0; i < n; ++i)
        swap(arr[i].s1, arr[i].s2), swap(arr[i].e1, arr[i].e2);

    if(ifsense()) {cout << "NO"; return 0;}

    cout << "YES";
    return 0;
}