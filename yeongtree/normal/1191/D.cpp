#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(int &i : arr) cin >> i;
    sort(arr, arr + n);

    if(arr[n - 1] == 0) {cout << "cslnb"; return 0;}
    if(n >= 2 && arr[1] == 0) {cout << "cslnb"; return 0;}
    bool flag1 = false;
    for(int i = 1; i < n; ++i)
    {
        if(arr[i - 1] == arr[i])
        {
            if(flag1) {cout << "cslnb"; return 0;}
            if(i >= 2 && arr[i - 2] == arr[i] - 1) {cout << "cslnb"; return 0;}
            flag1 = true;
        }
    }

    long long sum = 0;
    for(int i : arr) sum += i;
    sum -= (long long)n * (n - 1) / 2;

    if(sum & 1) {cout << "sjfnb"; return 0;}
    else {cout << "cslnb"; return 0;}
}