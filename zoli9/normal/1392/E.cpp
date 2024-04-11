#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void writeTable(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j%2==0) cout<<0<<" ";
            else
            {
                cout<<(1LL<<(i+j-1))<<" ";
            }
        }
        cout<<endl;
    }
    fflush(stdout);
}

void solve(int n, ll sum)
{
    cout<<1<<" "<<1<<endl;
    int x=1;
    int y=1;
    for(int i=1; i<=2*(n-1); i++)
    {
        if(y%2==1)
        {
            if(sum%2) y++;
            else x++;
        }
        else
        {
            if(sum%2) x++;
            else y++;
        }
        sum/=2;
        cout<<x<<" "<<y<<endl;
    }
    fflush(stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    writeTable(n);
    int test;
    cin>>test;
    while(test--)
    {
        ll sum;
        cin>>sum;
        solve(n, sum);
    }

	return 0;
}