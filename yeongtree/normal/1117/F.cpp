#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void bemax(int &x, const int &y)
{
    if(x < y) x = y;
    return;
}

void update(int &mask, const int &x, const int &y, const int &p, int *const arr)
{
    if(arr[mask] & (1 << y)) return;

    arr[mask] |= (1 << y);

    for(int i = 0; i < p; ++i)
    {
        if(mask & (1 << i) || i == x || i == y) continue;
        mask ^= (1 << i);
        update(mask, x, y, p, arr);
        mask ^= (1 << i);
    }
}

int dp(int &mask, int &dep, int &len, const int &p, bool *const arr, const int *const num)
{
    if(arr[mask]) return 0;

    int ans = len;
    for(int i = 0; i < p; ++i)
    {
        if(mask & (1 << i)) continue;
        mask ^= (1 << i); ++dep; len += num[i];
        bemax(ans, dp(mask, dep, len, p, arr, num));
        mask ^= (1 << i); --dep; len -= num[i];
    }

    arr[mask] = true;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p; cin >> n >> p;

    int arr[n], num[p]{}, first_emerge[p];
    for(int i = 0; i < p; ++i) first_emerge[i] = n;
    for(int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        arr[i] = (int)c - 97;
        ++(num[arr[i]]);
        if(first_emerge[arr[i]] == n) first_emerge[arr[i]] = i + 1;
    }

    bool can_adj[p][p];
    for(int i = 0; i < p; ++i)
        for(int j = 0; j < p; ++j)
            cin >> can_adj[i][j];

    bool cant_ban[1 << p]{};
    int cant_ban_from[1 << p]{};
    int did_exist = 0;
    for(int i = 0; i < p; ++i)
    {
        for(int j = first_emerge[i]; j < n; ++j)
        {
            if((~did_exist) & (1 << arr[j]))
            {
                if(!can_adj[i][arr[j]])
                    update(did_exist, i, arr[j], p, cant_ban_from);
                did_exist |= (1 << arr[j]);
            }

            if(i == arr[j])
                did_exist = 0;
        }

        for(int j = 0; j < (1 << p); ++j)
            cant_ban[j] = (cant_ban[j] || cant_ban_from[j]);

        did_exist = 0;
        for(int j = 0; j < (1 << p); ++j)
            cant_ban_from[j] = 0;
    }

    int mask = 0, dep = 0, len = 0;
    cout << n - dp(mask, dep, len, p, cant_ban, num);

    return 0;
}