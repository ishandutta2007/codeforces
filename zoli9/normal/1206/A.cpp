#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n;
    int a=0;
    int b=0;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        a=max(a, szam);
    }
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        int szam;
        cin>>szam;
        b=max(b, szam);
    }
    cout<<a<<" "<<b<<endl;


    return 0;
}