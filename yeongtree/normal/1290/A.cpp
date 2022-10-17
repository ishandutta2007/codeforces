#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m, k; cin >> n >> m >> k;
        k = min(k, m - 1);
        int arr[n]; for(auto &i : arr) cin >> i;
        int brr[n]; for(int i = 0; i < n; ++i) brr[i] = arr[i];
        sort(brr, brr + n);

        int s = 0, e = n;
        while(s + 1 < e)
        {
            int mid = s + e >> 1;
            int t = brr[mid];
            vector<int> pnt;
            for(int i = 0; i < m; ++i)
                if(arr[i] < t && arr[n - m + i] < t) pnt.push_back(i);
            if(pnt.empty()) {s = mid; continue;}
            int mn = min(m - pnt.front(), pnt.back() + 1);
            for(int i = 1; i < pnt.size(); ++i)
                mn = min(mn, m - pnt[i] + pnt[i - 1] + 1);
            if(mn <= k) s = mid;
            else e = mid;
        }

        cout << brr[s] << '\n';
    }
}