#include<bits/stdc++.h>
#define maxn 20050
using namespace std;

int n,a[maxn];

vector<int> pos;

int main()  {
    int sum=0;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  {
        scanf("%d",a+i);
        if (~a[i]&1)
            a[i]/=2;
        else    {
            pos.push_back(i);
            if (a[i]<0)
                a[i]=(a[i]-1)/2;
            else
                a[i]=a[i]/2;
        }
        sum+=a[i];
    }
    assert(sum<=0);
    while (sum<0)   {
        ++sum;
        ++a[pos.back()];
        pos.pop_back();
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<endl;
    return 0;
}