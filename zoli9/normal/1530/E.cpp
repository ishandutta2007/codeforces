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
int n;
string s;

char ch(int x)
{
    return (char)('a'+x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        int n=s.size();
        vi db(26, 0);
        bool allsame=true;
        for(int i=0; i<n; i++)
        {
            db[s[i]-'a']++;
            if(i>0 && s[i]!=s[i-1]) allsame=false;
        }
        if(allsame)
        {
            cout<<s<<'\n';
            continue;
        }
        int single=-1;
        for(int i=0; i<26; i++)
        {
            if(db[i]==1)
            {
                single=i;
                break;
            }
        }
        if(single>=0)
        {
            cout<<ch(single);
            for(int i=0; i<26; i++)
            {
                if(i==single) continue;
                for(int j=1; j<=db[i]; j++)
                {
                    cout<<ch(i);
                }
            }
            cout<<'\n';
            continue;
        }
        int x=-1;
        for(int i=0; i<26; i++)
        {
            if(db[i]>0)
            {
                x=i;
                break;
            }
        }
        int others=n-db[x];
        if(db[x]<=others+2)
        {
            cout<<ch(x);
            cout<<ch(x);
            db[x]-=2;
            for(int i=0; i<26; i++)
            {
                if(i==x) continue;
                for(int j=1; j<=db[i]; j++)
                {
                    cout<<ch(i);
                    if(db[x]>0)
                    {
                        cout<<ch(x);
                        db[x]--;
                    }
                }
            }
            cout<<'\n';
            continue;
        }
        int masodik=-1;
        int harmadik=-1;
        for(int i=0; i<26; i++)
        {
            if(i==x) continue;
            if(db[i]>0)
            {
                if(masodik<0)
                {
                    masodik=i;
                }
                else if(harmadik<0)
                {
                    harmadik=i;
                }
            }
        }
        if(harmadik>=0)
        {
            cout<<ch(x);
            db[x]--;
            cout<<ch(masodik);
            db[masodik]--;
            for(int i=1; i<=db[x]; i++)
            {
                cout<<ch(x);
            }
            cout<<ch(harmadik);
            db[harmadik]--;
            for(int i=0; i<26; i++)
            {
                if(i==x) continue;
                for(int j=1; j<=db[i]; j++)
                {
                    cout<<ch(i);
                }
            }
            cout<<'\n';
            continue;
        }
        cout<<ch(x);
        db[x]--;
        for(int i=1; i<=db[masodik]; i++)
        {
            cout<<ch(masodik);
        }
        for(int i=1; i<=db[x]; i++)
        {
            cout<<ch(x);
        }
        cout<<'\n';
    }
    return 0;
}