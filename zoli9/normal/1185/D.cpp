#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vector<pll> t;
map<ll, int> dd;
void bruteforce()
{
    for(int i=0; i<n; i++)
    {
        //cout<<i<<":"<<endl;
        ll elozo;
        bool van=false;
        bool jo=true;
        bool vankul=false;
        ll kul;
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;
            if(van)
            {
               if(vankul)
               {
                   if(t[j].F-elozo!=kul)
                   {
                       jo=false;
                       break;
                   }
               }
               else
               {
                   vankul=true;
                   kul=t[j].F-elozo;
               }
               elozo=t[j].F;
            }
            else
            {
                van=true;
                elozo=t[j].F;
            }
        }
        if(jo)
        {
            cout<<t[i].S<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

bool checking()
{
    ll df=t[2].F-t[1].F;
    for(int i=3; i<n; i++)
    {
        if(t[i].F-t[i-1].F!=df) return false;
    }
    cout<<t[0].S<<endl;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    t.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>t[i].F;
        t[i].S=i+1;
    }
    sort(t.begin(), t.end());
    if(n<=3)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n<=5)
    {
        bruteforce();
        return 0;
    }
    for(int i=1; i<n; i++)
    {
        dd[t[i].F-t[i-1].F]+=1;
    }
    ll maxi=t[1].F-t[0].F;
    for(int i=2; i<n; i++)
    {
        if(dd[t[i].F-t[i-1].F]>dd[maxi]) maxi=t[i].F-t[i-1].F;
    }
    if(checking()) return 0;
    int rosszindex=-1;
    ll elozo=t[0].F;
    for(int i=1; i<n; i++)
    {
        if(t[i].F-elozo==maxi)
        {
            elozo=t[i].F;
        }
        else
        {
            if(rosszindex>=0)
            {
                cout<<-1<<endl;
                return 0;
            }
            rosszindex=i;
        }
    }
    if(rosszindex==-1) cout<<t[0].S<<endl;
    else cout<<t[rosszindex].S<<endl;
    return 0;
}