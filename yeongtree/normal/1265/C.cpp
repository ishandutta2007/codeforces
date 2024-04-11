#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int prv = -1;
        vector<int> arr;
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            if(prv != x) arr.push_back(1), prv = x;
            else ++arr[arr.size() - 1];
        }

        int m = arr.size();
        int s = 0, t = m;
        while(s + 1 < t)
        {
            int mid = s + t >> 1;

            int k = 0; int pt = 0;
            for(; pt < mid; ++pt) k += arr[pt];
            int l = 0;
            while(pt < m && l <= k) l += arr[pt++];
            int _k = k + l; l = 0;
            while(pt < m && l <= k) l += arr[pt++];
            _k += l;
            if((_k << 1) <= n) s = mid;
            else t = mid;
        }

        int x = 0, y = 0, z = 0;
        int pt = 0;
        for(; pt < s; ++pt) x += arr[pt];
        while(y <= x) y += arr[pt++];
        while(pt < m && (x + y + z + arr[pt] << 1) <= n) z += arr[pt++];

        if(s == 0) cout << "0 0 0\n";
        else cout << x << ' ' << y << ' ' << z << '\n';
    }
}