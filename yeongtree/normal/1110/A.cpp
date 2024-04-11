#include <iostream>

using namespace std;

int main()
{
    int b, k; cin >> b >> k;
    int arr[k]; for(int i = 0; i < k; ++i) cin >> arr[i];

    if(b % 2 == 0) cout << (arr[k - 1] % 2 ? "odd" : "even");
    else
    {
        int sum = 0;
        for(int i = 0; i < k; ++i) sum += arr[i];
        cout << (sum % 2 ? "odd" : "even");
    }

    return 0;
}