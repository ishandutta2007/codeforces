#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n;
int a[maxn];

int get(int k)  {
    if (a[k]) return a[k];
    cout<<"? "<<k<<endl;
    cin>>a[k];
    return a[k];
}

int main()  {
    cin>>n;
    a[0]=a[n+1]=1e8;
    int l=1,r=n;
    while (l<r) {
        int mid=(l+r)>>1;
        get(mid-1),get(mid),get(mid+1);
        if (a[mid-1]>a[mid]&&a[mid+1]>a[mid])
            return cout<<"! "<<mid<<endl,0;
        if (a[mid]>a[mid-1])
            r=mid-1;
        else
            l=mid+1;
    }

    cout<<"! "<<l<<endl;
    return 0;
}