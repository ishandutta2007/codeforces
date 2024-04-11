#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long arr[n]; for(auto &i : arr) cin >> i;
    bool flag = false;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] & 1)
        {
            if(flag)
            {
                arr[i]++;
                flag = false;
            }
            else
            {
                arr[i]--;
                flag = true;
            }
        }
        cout << arr[i] / 2 << '\n';
    }

    return 0;
}