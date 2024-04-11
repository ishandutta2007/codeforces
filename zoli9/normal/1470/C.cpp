#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

vll a;
int questions;
ll n, k, p;

void pr(vll a)
{
    for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
    cout<<endl;
}

ll ask(int x)
{
    x%=n;
    questions++;
    cout<<"? "<<x+1<<endl;
    fflush(stdout);
    ll res;
    cin>>res;
    return res;

    /*vll aa(n, 0);
    for(int i=0; i<n; i++)
    {
        if(i==p)
        {
            aa[(i+1)%n]+=a[i];
            continue;
        }
        aa[(i+n-1)%n]+=a[i]/2;
        aa[(i+1)%n]+=(a[i]+1)/2;
    }
    a=aa;
    //pr(a);
    return a[x];*/
}

void final_ans(int x)
{
    x%=n;
    cout<<"! "<<x+1<<endl;
    fflush(stdout);
    /*if(x==p)
    {
        cout<<"jo"<<endl;
    }
    else
    {
        cout<<"rossz"<<endl;
    }*/
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    //a.assign(n, k);
    //cin>>p;

    int start=-1;
    bool big=false;

    while(start==-1)
    {
        int x=rng()%n;
        ll y=ask(x);
        if(y>k)
        {
            start=x;
            big=true;
        }
        else if(y<k)
        {
            start=x;
            big=false;
        }
        //cout<<"rand: "<<x<<endl;
    }
    //cout<<"qs: "<<questions<<endl;
    //cout<<start<<" "<<big<<endl;

    if(big)
    {
        int e1=start-n/2+n;
        int e2=start+n;
        while(e1<=e2)
        {
            int mid=(e1+e2)/2;
            ll y=ask(mid);
            if(y>k) e2=mid-1;
            else e1=mid+1;
        }
        final_ans(e2);
    }
    else
    {
        int e1=start;
        int e2=start+n/2;
        while(e1<=e2)
        {
            int mid=(e1+e2)/2;
            ll y=ask(mid);
            if(y<k) e1=mid+1;
            else e2=mid-1;
        }
        final_ans(e1);
    }
    //cout<<"qs: "<<questions<<endl;

    return 0;
}