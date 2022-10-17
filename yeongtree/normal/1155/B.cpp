#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; ++i) {char a; cin >> a; arr[i] = a - 48;}

    int eight = 0, non_eight = 0;
    for(int i = 0; i < n - 10; ++i)
        ++(arr[i] == 8 ? eight : non_eight);

    cout << (eight >= non_eight ? "YES" : "NO");
    return 0;
}