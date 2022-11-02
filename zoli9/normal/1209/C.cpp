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
int num;
vi v;
int test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        v.assign(n, 0);
        cin>>s;
        int mini=s[n-1]-'0';
        for(int i=n-1; i>=0; i--)
        {
            int nb=s[i]-'0';
            if(mini<nb) v[i]=2;
            mini=min(mini, nb);
        }
        int e1=0;
        int e2=0;
        int estart=0;
        bool ok=true;
        for(int i=0; i<n; i++)
        {
            int nb=s[i]-'0';
            if(v[i]==2)
            {
                if(nb>=e2)
                {
                    e2=nb;
                    if(estart==0) estart=nb;
                }
                else
                {
                    ok=false;
                    break;
                }
            }
            else
            {
                if(nb>=e1 && (nb<=estart || estart==0))
                {
                    v[i]=1;
                    e1=nb;
                }
                else if(nb>=e2)
                {
                    v[i]=2;
                    e2=nb;
                }
                else
                {
                    ok=false;
                    break;
                }
            }
        }
        if(ok)
        {
            for(int i=0; i<n; i++)
            {
                cout<<v[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"-"<<endl;
        }
    }
    return 0;
}