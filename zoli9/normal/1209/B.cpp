#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
string s;
int ans=0;
int a[109];
int b[109];
int num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        if(s[i]=='1') num++;
    }
    ans=num;
    for(int j=1; j<=200; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(j>=b[i] && (j-b[i])%a[i]==0)
            {
                if(s[i]=='1')
                {
                    num--;
                    s[i]='0';
                }
                else
                {
                    num++;
                    s[i]='1';
                }
            }
        }
        ans=max(ans, num);
    }
    cout<<ans<<endl;
    return 0;
}