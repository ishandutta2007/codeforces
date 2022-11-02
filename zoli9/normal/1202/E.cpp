#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

string minta;
string szoveg;
int kov[200009];
int l[200009];
int kezd[200009];
int veg[200009];

class Node
{
public:
    Node(){};
    unordered_map<char, Node*> gyerekek;
    int vegzodes=0;
    void bovit(int idx)
    {
        if(idx==minta.size())
        {
            vegzodes++;
            return;
        }
        if(gyerekek[minta[idx]]==NULL) gyerekek[minta[idx]]=new Node();
        gyerekek[minta[idx]]->bovit(idx+1);
    }
    int keres(int idx)
    {
        if(idx==szoveg.size() || gyerekek[szoveg[idx]]==NULL)
        {
            return vegzodes;
        }
        return gyerekek[szoveg[idx]]->keres(idx+1)+vegzodes;
    }
};
Node root, root2;
int n;

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
    if(l[0]==minta.size())
    {
        veg[0]++;
        kezd[0-minta.size()+1]++;
    }
    for(int i=1; i<szoveg.size(); i++)
    {
        int akt=l[i-1]-1;
        if(szoveg[i]==minta[akt+1])
        {
            l[i]=l[i-1]+1;
            if(l[i]==minta.size())
            {
                veg[i]++;
                kezd[i-minta.size()+1]++;
            }
            continue;
        }
        while(akt!=-1)
        {
            if(szoveg[i]==minta[kov[akt]+1])
            {
                l[i]=kov[akt]+2;
                if(l[i]==minta.size())
                {
                    veg[i]++;
                    kezd[i-minta.size()+1]++;
                }
                break;
            }
            akt=kov[akt];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>szoveg;
    int h=szoveg.size();
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>minta;
        if(minta.size()>=200)
        {
            kmp();
            continue;
        }
        root.bovit(0);
        reverse(minta.begin(), minta.end());
        root2.bovit(0);
    }
    for(int i=0; i<h; i++)
    {
        kezd[i]+=root.keres(i);
    }
    reverse(szoveg.begin(), szoveg.end());
    for(int i=0; i<h; i++)
    {
        veg[h-i-1]+=root2.keres(i);
    }
    ll ans=0;
    for(int i=0; i<h-1; i++)
    {
        ll cans=(ll)(veg[i])*(ll)(kezd[i+1]);
        ans+=cans;
    }
    cout<<ans<<endl;


    return 0;
}