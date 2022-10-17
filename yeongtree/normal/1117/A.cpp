#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i];

    int max = 0;
    for(int i = 0; i < n; ++i)
        if(arr[i] > max) max = arr[i];

    int maxlen = 0;
    int nowlen = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == max)
        {
            ++nowlen;
            if(maxlen < nowlen) maxlen = nowlen;
        }
        else
            nowlen = 0;
    }

    cout << maxlen;
    return 0;
}