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
    int n;
    cin>>n;
    int e=0;
    int o=0;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        if(szam%2) o++;
        else e++;
    }
    cout<<min(o, e)<<endl;


    return 0;
}