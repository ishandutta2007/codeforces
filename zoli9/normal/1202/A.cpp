#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
string x, y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>x;
        cin>>y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int a=0;
        while(y[a]=='0') a++;
        int b=a;
        while(x[b]=='0') b++;
        cout<<b-a<<endl;
    }

    return 0;
}