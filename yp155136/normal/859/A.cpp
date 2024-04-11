#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int k;
    cin >> k;
    vector<int> v;
    while (k--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << max( 0, *max_element(v.begin(),v.end())-25 ) << endl;
}