#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int arr[n]; for(auto &i : arr) cin >> i;
        int brr[n]; for(auto &i : brr) cin >> i;
        int crr[n]; for(int i = 0; i < n; ++i) crr[i] = brr[i] - arr[i];
        bool flag = true, flag1 = false;
        for(auto i : crr) if(i < 0) {cout << "NO\n"; flag = false; break;}
        if(flag)
        {
            if(crr[0] > 0) flag1 = true;
            for(int i = 1; i < n; ++i)
            {
                if(crr[i])
                {
                    if(!flag1 && !crr[i - 1]) flag1 = true;
                    else if(crr[i - 1] == crr[i]) ;
                    else {cout << "NO\n"; flag = false; break;}
                }
            }
        }
        if(flag) cout << "YES\n";
    }
}