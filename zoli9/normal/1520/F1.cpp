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

int ask(int x, int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
    int z;
    cin>>z;
    if(z==-1) exit(0);
    return z;
}

void final_ans(int x)
{
    cout<<"! "<<x<<endl;
    fflush(stdout);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k;
    cin>>n>>t;
    cin>>k;
    int k1=1;
    int k2=n;
    while(k1<=k2)
    {
        int mid=(k1+k2)/2;
        int x=ask(1, mid);
        x=mid-x;
        if(x<k) k1=mid+1;
        else k2=mid-1;
    }
    final_ans(k1);
    return 0;
}