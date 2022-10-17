#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int mxv = 0, mx = -1;
    for(int i = 2; i < n; ++i)
        if(mxv < n - (n - 1) / i - i) mx = i, mxv = n - (n - 1) / i - i;

    bool arr[n]{};
    int cnt = 0;
    while(cnt < mxv)
    {
        cout << mx << ' ';
        int tmp = mx;
        for(int i = 0; i < n; ++i)
        {
            if(i % mx == 0) continue;
            if(!arr[i])
            {
                cout << i + 1 << ' ';
                arr[i] = true;
                ++cnt;
                if(!--tmp) break;
            }
        }
        cout << endl;
        cout.flush();

        int x; cin >> x; --x;
        for(int i = x; i < x + mx; ++i)
        {
            if(arr[i % n])
            {
                arr[i % n] = false;
                --cnt;
            }
        }
    }
    cout << 0 << endl;
    cout.flush();
    return 0;
}