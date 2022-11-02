#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int t[200009];
bool be[200009];
bool volt[200009];
int n;

void kesz()
{
    for(int i=1; i<=n; i++) cout<<t[i]<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(t[i]>0)
        {
            be[i]=true;
            volt[t[i]]=true;
        }
    }
    int cnt=1;
    vi R;
    for(int i=1; i<=n; i++)
    {
        if(!be[i])
        {
            while(volt[cnt]) cnt++;
            t[i]=cnt;
            if(i==cnt)
            {
                //cout<<i<<" ok"<<endl;
                R.push_back(i);
            }
            cnt++;
        }
    }
    if(R.size()==0)
    {
        //cout<<"asd"<<endl;
        kesz();
        return 0;
    }
    if(R.size()==1)
    {
        int csere=0;
        for(int i=1; i<=n; i++)
        {
            if(!be[i])
            {
                if(t[i]!=i)
                {
                    csere=i;
                    break;
                }
            }
        }
        t[R[0]]=t[csere];
        t[csere]=R[0];
        kesz();
        return 0;
    }
    int vege=t[R[0]];
    for(int i=1; i<R.size(); i++)
    {
        t[R[i-1]]=t[R[i]];
    }
    t[R.back()]=vege;
    kesz();
    return 0;
}