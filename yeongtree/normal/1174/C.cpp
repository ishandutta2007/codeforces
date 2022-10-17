#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n + 1];
    for(int i = 2; i <= n; ++i) arr[i] = i;

    int cnt = 1;

    for(int i = 2; i <= n; ++i)
    {
        if(arr[i] == i)
        {
            for(int j = i; j <= n; j += i)
                arr[j] = cnt;
            ++cnt;
        }
    }

    for(int i = 2; i <= n; ++i)
        cout << arr[i] << ' ';

    return 0;
}