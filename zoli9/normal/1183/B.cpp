#include <bits/stdc++.h>
using namespace std;
int q;
int n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        cin>>n>>k;
        int mini=-1;
        int maxi=-1;
        for(int i=1; i<=n; i++)
        {
            int szam;
            cin>>szam;
            if(mini==-1 || szam<mini) mini=szam;
            if(maxi==-1 || szam>maxi) maxi=szam;
        }
        if(maxi-mini>2*k) cout<<-1<<endl;
        else cout<<mini+k<<endl;
    }

    return 0;
}