#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL M=1e10;
LL a[10];

int main()  {
    cin>>a[1]>>a[2]>>a[3];

    cout<<"First"<<endl;
    cout<<M<<endl;

    LL z;
    cin>>z;

    a[z]+=M;

    LL x=1;
    for (LL i=1;i<=3;++i)
        if (a[i]<a[x])
            x=i;
    
    LL y=6-x-z;

    LL mn=a[x];
    for (LL i=1;i<=3;++i)
        a[i]-=mn;

    // cout<<"???:"<<a[x]<<" "<<a[y]<<" "<<a[z]<<endl;
    //a[x]=0,a[y],a[z]

    cout<<2*a[z]-a[y]<<endl;

    LL o;
    cin>>o;

    if (!o) return 0;
    
    if (o==x) 
        cout<<a[z]-a[y]<<endl;
    else
        cout<<a[z]-a[x]<<endl;
    
    cin>>o;

    assert(!o);

    return 0;
}