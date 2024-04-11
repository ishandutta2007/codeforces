#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (size_t i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        if (a[n - 1] <= d || a[0] + a[1] <= d)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}