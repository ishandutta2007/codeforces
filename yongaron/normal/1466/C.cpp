#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(i>1 && s[i] == s[i-2])
            {
                s[i] = '*';
                ans++;
            }
            else if(i && s[i] == s[i-1])
            {
                s[i] = '*';
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}