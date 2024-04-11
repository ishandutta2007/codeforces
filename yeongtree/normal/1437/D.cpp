#include <iostream>

using namespace std;

int arr[202020];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];

        int ans = 1, rem = 1, cur = 0, prv = 1;
        for(int i = 1; i < n; ++i)
        {
            if(prv < arr[i]) prv = arr[i], ++cur;
            else
            {
                if(!--rem)
                {
                    ++ans;
                    rem = cur;
                    cur = 0;
                }
                prv = arr[i]; ++cur;
            }
        }
        cout << ans << '\n';
    }
}