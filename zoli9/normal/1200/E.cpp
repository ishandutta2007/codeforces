#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

string minta;
string szoveg;
int kov[1000009];
int l[1000009];
int n;
string nagy="";

int kmp()
{
    for(int i=0; i<minta.size(); i++) kov[i]=-1;
    for(int i=1; i<minta.size(); i++)
    {
        int akt=i-1;
        while(akt!=-1)
        {
            if(minta[i]==minta[kov[akt]+1])
            {
                kov[i]=kov[akt]+1;
                break;
            }
            akt=kov[akt];
        }
    }
    for(int i=0; i<szoveg.size(); i++) l[i]=0;
    if(szoveg[0]==minta[0]) l[0]=1;
    for(int i=1; i<szoveg.size(); i++)
    {
        int akt=l[i-1]-1;
        if(szoveg[i]==minta[akt+1])
        {
            l[i]=l[i-1]+1;
            continue;
        }
        while(akt!=-1)
        {
            if(szoveg[i]==minta[kov[akt]+1])
            {
                l[i]=kov[akt]+2;
                break;
            }
            akt=kov[akt];
        }
    }
    return l[(int)(szoveg.size())-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>minta;
        if(i==1)
        {
            nagy+=minta;
            continue;
        }
        int kezdet=max(0, (int)(nagy.size())-(int)(minta.size()));
        szoveg=nagy.substr(kezdet);
        //cout<<nagy<<" : "<<minta<<endl;
        int d=kmp();
        //cout<<d<<endl;
        nagy+=minta.substr(d);
    }
    cout<<nagy<<endl;



    return 0;
}