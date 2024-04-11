#include <bits/stdc++.h>
using namespace std;


int main ()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans2 = v[n-1] + m;
    while (m--)
    {
        v[0]++;
        sort(v.begin(),v.end());
    }
    cout << v[n-1] << ' ' << ans2 << endl;
}