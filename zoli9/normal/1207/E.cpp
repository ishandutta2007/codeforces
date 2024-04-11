#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a1, a2;
    cout<<"?";
    for(int i=0; i<100; i++)
    {
        cout<<" "<<i;
    }
    cout<<endl;
    fflush(stdout);
    cin>>a1;
    cout<<"?";
    for(int i=1; i<=100; i++)
    {
        cout<<" "<<i*128;
    }
    cout<<endl;
    fflush(stdout);
    cin>>a2;
    int ans=a2%128;
    a1=a1-a1%128;
    ans+=a1;
    cout<<"! "<<ans<<endl;
    fflush(stdout);

    return 0;
}