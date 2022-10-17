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
        bool flag = true;
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            if(arr[i] != arr[0]) flag = false;
        }
        cout << (flag ? n : 1) << '\n';
    }
}