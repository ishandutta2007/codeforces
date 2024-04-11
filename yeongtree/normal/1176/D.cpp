#include <iostream>

using namespace std;

const int SIZE = 2e5;
const int MAX = 3e6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[2 * n]; for(auto &i : arr) cin >> i;

    int cnt[MAX]{};
    int prime[SIZE + 1]{};
    int ans[n]{}, pnt = 0;
    for(auto i : arr) ++cnt[i];

    int fld[MAX]; for(auto &i : fld) i = 1;
    for(long long i = 2; i < MAX; ++i)
        if(fld[i] == 1)
            for(long long j = i * i; j < MAX; j += i)
                if(fld[j] == 1) fld[j] = i;

    for(int i = 1, j = 2; i < SIZE; ++j)
    {
        if(fld[j] != 1) continue;
        prime[i++] = j;
    }

    for(int i = MAX - 1; i >= 2; --i)
    {
        if(fld[i] == 1) continue;
        while(cnt[i])
        {
            --cnt[i]; --cnt[i / fld[i]];
            ans[pnt++] = i;
        }
    }

    for(int i = 2; i < MAX; ++i)
    {
        while(cnt[i])
        {
            --cnt[i]; --cnt[prime[i]];
            ans[pnt++] = i;
        }
    }

    for(auto i : ans) cout << i << ' ';
    return 0;
}