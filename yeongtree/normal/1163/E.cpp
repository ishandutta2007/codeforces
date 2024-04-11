#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;

    unordered_map<int, int> lenTable;
    for(int i = 0, j = 1; i <= 18; ++i, j <<= 1) lenTable[j] = i;

    int bsLen = 18;
    vector<int> basis;
    for(; bsLen >= 0; --bsLen)
    {
        int __arr[n]; for(int i = 0; i < n; ++i) __arr[i] = arr[i];
        basis.resize(0);

        for(int i = 0; i < n; ++i)
        {
            if(__arr[i] >= (1 << bsLen)) continue;
            if(__arr[i])
            {
                basis.push_back(arr[i]);
                for(int j = i + 1; j < n; ++j)
                    __arr[j] = min(__arr[j], __arr[j] ^ __arr[i]);
            }
        }

        if(basis.size() == bsLen) break;
    }
    cout << bsLen << '\n';

    int ans = 0, ansCnt = 1 << bsLen;
    cout << ans << ' ';

    for(int i = 1; i < ansCnt; ++i)
    {
        ans ^= basis[lenTable[i & -i]];
        cout << ans << ' ';
    }

    return 0;
}