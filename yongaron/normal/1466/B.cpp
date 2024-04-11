#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;
int was[223456];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a;
        for(int i = 0; i <= 2*n+3; i++)
            was[i] = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>a;
            was[a]++;
        }
        for(int i = 2*n; i; i--)
        {
            if(!was[i+1] && was[i])
            {
                was[i]--;
                was[i+1]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < 2*n+3; i++)
            if(was[i])
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}