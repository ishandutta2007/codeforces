#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

#define ll long long

using namespace std;

int t, n;

set<int> sqs;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(ll i = 0; i < 1e5; i++)
        sqs.insert(i*i);
    while (t--)
    {
        cin >> n;
        if(n%2 == 0 && sqs.count(n/2))
            cout << "YES" << endl;
        else if(n%4 == 0 && sqs.count(n/4))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}