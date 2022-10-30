#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()  {
    int T;
    cin>>T;
    while (T--) {
        LL a,b,c;
        cin>>a>>b>>c;
        if (a<c) cout<<1<<" "; else cout<<-1<<" ";
        if (a*b>c) cout<<b<<endl; else cout<<-1<<endl;
    }
    return 0;
}