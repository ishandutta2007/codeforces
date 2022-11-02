#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
string z;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>s;
        cin>>z;
        int i=0;
        int j=0;
        bool ok=true;
        while(i<s.size())
        {
            if(s[i]!=z[j])
            {
                cout<<"NO"<<endl;
                ok=false;
                break;
            }
            int sc=i;
            while(sc+1<s.size() && s[sc]==s[sc+1]) sc++;
            int zc=j;
            while(zc+1<z.size() && z[zc+1]==s[i]) zc++;
            if(sc-i>zc-j)
            {
                cout<<"NO"<<endl;
                ok=false;
                break;
            }
            i=sc+1;
            j=zc+1;
        }
        if(!ok) continue;
        if(j==z.size()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}