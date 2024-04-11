#include <iostream>

using namespace std;

int main()
{
    int n, x, y; cin >> n >> x >> y;
    bool arr[n];
    for(int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        arr[n - i - 1] = (c == '1');
    }

    int ans = 0;
    for(int i = 0; i < x; ++i)
    {
        if(i == y){ if(!arr[i]) ++ans;}
        else{if(arr[i]) ++ans;}
    }

    cout << ans;
    return 0;
}