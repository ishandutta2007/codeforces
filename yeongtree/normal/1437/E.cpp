#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i], arr[i] -= i;
    int msk[k]; for(int i = 0; i < k; ++i) cin >> msk[i], --msk[i];
    for(int i = 1; i < k; ++i)
    {
        if(arr[msk[i - 1]] > arr[msk[i]])
        {
            cout << -1;
            return 0;
        }
    }

    int m = n - k;
    int ans = 0;
    vector<int> B;
    for(int i = 0, j = 0; i < n; ++i)
    {
        if(j < k && msk[j] == i)
        {
            ++j;
            ans += B.size();
            B.clear();
            continue;
        }
        if(j > 0 && arr[i] < arr[msk[j - 1]]) continue;
        if(j < k && arr[i] > arr[msk[j]]) continue;
        auto it = upper_bound(B.begin(), B.end(), arr[i]);
        if(it == B.end()) B.push_back(arr[i]);
        else *it = arr[i];
    }
    ans += B.size();

    cout << m - ans;
    return 0;
}