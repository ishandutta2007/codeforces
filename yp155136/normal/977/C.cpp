#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for (int i=0;n>i;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if (k == 0)
    {
        if (v[0] == 1) puts("-1");
        else puts("1");
    }
    else if (k == n)
    {
        cout << 1000000000 << endl;
    }
    else
    {
        if (v[k] == v[k-1]) cout << -1 << endl;
        else cout << v[k-1] <<endl;
    }
}