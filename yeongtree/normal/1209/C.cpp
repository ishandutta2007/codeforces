#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int arr[n];
        for(auto &i : arr)
        {
            char c; cin >> c;
            i = c - '0';
        }

        int ans[n]; for(auto &i : ans) i = -1;
        int st = -1;
        int mn[n]; mn[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; --i)
            mn[i] = (arr[i] <= arr[mn[i + 1]] ? i : mn[i + 1]);

        int pt = mn[0]; if(pt) st = 0;
        while(st == -1 || arr[st] >= arr[pt])
        {
            ans[pt] = 1;
            if(pt == n - 1) break;
            int __pt = mn[pt + 1];
            if(st == -1 && pt + 1 < __pt) st = pt + 1;
            pt = __pt;
        }

        bool flag = true;
        if(st != -1)
        {
            ans[st] = 2;
            for(int i = st + 1; i < n; ++i)
            {
                if(ans[i] == 1) continue;
                if(arr[st] > arr[i]) { flag = false; break; }
                ans[i] = 2;
                st = i;
            }
        }

        if(flag)
        {
            for(auto i : ans) cout << i;
            cout << '\n';
        }
        else cout << "-\n";
    }

    return 0;
}