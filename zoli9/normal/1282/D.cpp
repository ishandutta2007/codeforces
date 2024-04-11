#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string q;
string ans="";
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<"a"<<endl;
    fflush(stdout);
    cin>>n;
    if(n==0) return 0;
    q="";
    if(n==300)
    {
        for(int i=1; i<=n; i++) q+="b";
        cout<<q<<endl;
        fflush(stdout);
        int bbb;
        cin>>bbb;
        return 0;
    }
    for(int i=1; i<=n+1; i++) q+="a";
    cout<<q<<endl;
    fflush(stdout);
    int bbb;
    cin>>bbb;
    if(bbb==n+1)
    {
        q="";
        for(int i=1; i<=n; i++) q+="b";
        cout<<q<<endl;
        fflush(stdout);
        int www;
        cin>>www;
        if(www==0) return 0;
        return 1;
    }
    n++;
    for(int i=1; i<=n; i++) ans+="a";
    int bf=0;
    for(int i=1; i<n; i++)
    {
        q[i-1]='b';
        cout<<q<<endl;
        fflush(stdout);
        int rp;
        cin>>rp;
        if(rp==0) return 0;
        if(rp<bbb)
        {
            ans[i-1]='b';
            bf++;
        }
        q[i-1]='a';
    }
    if(bf<bbb) ans[n-1]='b';
    cout<<ans<<endl;
    fflush(stdout);
    int asdf;
    cin>>asdf;



    return 0;
}