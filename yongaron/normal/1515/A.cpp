#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int t, n;

int w[123456], x;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> w[i];
            sum += w[i];
        }
        if(sum == x)
        {
            cout << "NO" << endl;
            continue;
        }
        int s = 0;
        cout << "YES" << endl;
        sort(w, w+n);
        for(int i = 0; i < n; i++)
        {
            if(s + w[i] == x)
                swap(w[i], w[n-1]);
            cout << w[i] << " ";
            s += w[i];
        }
        cout << endl;
    }
    return 0;
}