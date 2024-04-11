#include<bits/stdc++.h>
#define maxn 505
using namespace std;

int n,k,m;
int a[maxn];

int p1,p2,p3,t;

void ask(int p) {
    cout<<"? ";
    for (int i=1;i<=k+1;++i) 
        if (i!=p)
            cout<<i<<" ";
    cout<<endl;
}

int main()  {
    cin>>n>>k;

    ask(k+1);
    cin>>p1;
    cin>>a[p1];

    ask(p1);
    cin>>p2;
    cin>>a[p2];

    if (a[p1]>a[p2]) swap(p1,p2);

    // cout<<"p:"<<p1<<" "<<p2<<" "<<a[p1]<<" "<<a[p2]<<endl;

    int m=1;
    for (int i=1;i<=k+1;++i)    {
        if (i==p1||i==p2) continue;
        ask(i);
        cin>>p3>>t;
        assert(p1==p3||p2==p3);
        if (p3==p2) ++m;
    }
    
    cout<<"! "<<m<<endl;
    return 0;
}