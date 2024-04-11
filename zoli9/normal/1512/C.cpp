#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int a, b;
        string s;
        cin>>a>>b;
        cin>>s;
        int n=s.size();
        bool ok=true;
        vector<bool> was(n, false);
        for(int i=0; i<n; i++)
        {
            if(i==n-i-1)
            {
                if(s[i]=='0')
                {
                    a--;
                    was[i]=true;
                }
                if(s[i]=='1')
                {
                    b--;
                    was[i]=true;
                }
            }
            if(was[i]) continue;
            if(s[i]=='0')
            {
                if(s[n-i-1]=='1')
                {
                    ok=false;
                    break;
                }
                a-=2;
                s[n-i-1]='0';
                was[i]=true;
                was[n-i-1]=true;
            }
            if(s[i]=='1')
            {
                if(s[n-i-1]=='0')
                {
                    ok=false;
                    break;
                }
                b-=2;
                s[n-i-1]='1';
                was[i]=true;
                was[n-i-1]=true;
            }
        }
        if(a<0 || b<0 || !ok || (a%2==1 && b%2==1))
        {
            cout<<-1<<'\n';
            continue;
        }
        if(a%2==1)
        {
            s[n/2]='0';
            a--;
            was[n/2]=true;
        }
        if(b%2==1)
        {
            s[n/2]='1';
            b--;
            was[n/2]=true;
        }
        for(int i=0; i<n; i++)
        {
            if(was[i]) continue;
            was[i]=true;
            was[n-i-1]=true;
            if(a>0)
            {
                s[i]='0';
                s[n-i-1]='0';
                a-=2;
            }
            else
            {
                s[i]='1';
                s[n-i-1]='1';
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}