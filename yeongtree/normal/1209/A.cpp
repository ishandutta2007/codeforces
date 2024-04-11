#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    bool flag[n]{};

    int cnt = 0;
    while(1)
    {
        bool fflag = false;
        for(int i = 0; i < n; ++i)
            if(!flag[i]) fflag = true;
        if(!fflag) break;

        int mn = 1010;
        for(int i = 0; i < n; ++i)
            if(!flag[i] && mn > arr[i]) mn = arr[i];

        for(int i = 0; i < n; ++i)
            if(arr[i] % mn == 0) flag[i] = true;

        ++cnt;
    }

    cout << cnt;
    return 0;
}