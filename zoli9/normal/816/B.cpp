#include <bits/stdc++.h>
using namespace std;
int n, k, q;
int t[200009];
int kumulativ[200009];
int aktualis;

int main() {
    cin>>n>>k>>q;
    for(int i=1; i<=n; i++)
    {
        int A, B;
        cin>>A>>B;
        t[A]++;
        t[B+1]--;
    }
    for(int i=1; i<=200000; i++)
    {
        aktualis+=t[i];
        if(aktualis>=k)
        {
            kumulativ[i]=kumulativ[i-1]+1;
        }
        else
        {
            kumulativ[i]=kumulativ[i-1];
        }
    }
    for(int i=1; i<=q; i++)
    {
        int A, B;
        cin>>A>>B;
        int ans=kumulativ[B]-kumulativ[A-1];
        cout<<ans<<endl;
    }
    return 0;
}