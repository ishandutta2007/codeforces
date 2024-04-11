#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vi t;
int color[200009];
bool bejar[200009];
int mink;
vi w;
void calc(int x)
{
    w.clear();
    bejar[x]=true;
    w.push_back(x);
    while(1)
    {
        x=t[x];
        if(bejar[x]) break;
        else
        {
            bejar[x]=true;
            w.push_back(x);
        }
    }
    int M=w.size();
    for(int k=1; k<=min(M, mink-1); k++)
    {
        if(M%k!=0) continue;
        bool found=false;
        for(int i=0; i<k; i++)
        {
            bool ok=true;
            int last=(i+k)%M;
            while(last!=i)
            {
                if(color[w[i]]!=color[w[last]])
                {
                    ok=false;
                    break;
                }
                last=(last+k)%M;
            }
            if(ok)
            {
                found=true;
                break;
            }
        }
        if(found) mink=min(mink, k);
        //cout<<x<<" ::: "<<mink<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        t.resize(n);
        for(int i=0; i<n; i++)
        {
            cin>>t[i];
            t[i]--;
            bejar[i]=false;
        }
        for(int i=0; i<n; i++)
        {
            cin>>color[i];
            color[i]--;
        }
        mink=n;
        for(int i=0; i<n; i++)
        {
            if(!bejar[i]) calc(i);
        }
        cout<<mink<<'\n';
    }


    return 0;
}