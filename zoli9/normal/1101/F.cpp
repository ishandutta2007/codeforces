#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
long long A[409];
long long infi=1000000000000000007;
vector<pair<pair<int, int>, pair<long long, int> > > t;
bool lehet(int start, int fin, long long fogy, int refuel, long long bb)
{
    for(int i=start+1; i<=fin; i++)
    {
        if((A[i]-A[start])*fogy>bb)
        {
            if(refuel==0) return false;
            return lehet(i-1, fin, fogy, refuel-1, bb);
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
    }
    t.resize(m);
    for(int i=0; i<m; i++)
    {
        cin>>t[i].F.F>>t[i].F.S>>t[i].S.F>>t[i].S.S;
    }
    //shuffle(t.begin(), t.end(), rng);
    for(int i=0; i<m; i++)
    {
        int rrr=((rand()<<15)+rand())%(m-i);
        swap(t[i], t[i+rrr]);
        //cout<<t[i].S.S<<endl;
    }
    long long best=0;
    for(int i=0; i<m; i++)
    {
        if(lehet(t[i].F.F, t[i].F.S, t[i].S.F, t[i].S.S, best)) continue;
        long long elso=0;
        long long utolso=infi;
        while(elso<=utolso)
        {
            long long kozep=(elso+utolso)/2;
            if(lehet(t[i].F.F, t[i].F.S, t[i].S.F, t[i].S.S, kozep))
            {
                //cout<<kozep<<" ok"<<endl;
                utolso=kozep-1;
            }
            else
            {
                //cout<<"xd"<<endl;
                elso=kozep+1;
            }
        }
        best=elso;
    }
    cout<<best<<endl;
    return 0;
}