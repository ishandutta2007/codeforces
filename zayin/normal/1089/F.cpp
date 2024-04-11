#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<pair<int,int> > ans;

int main()  {
    scanf("%d",&n);
    int t=n;
    for (int i=2;i*i<=t;++i)    {
        if (n%i) continue;
        int q=1;
        while (t%i==0) t/=i,q*=i;
        a.push_back(q);
        // cout<<"q:"<<q<<endl;
    }
    if (t>1) a.push_back(t);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    if (a.size()==1)
        return puts("NO"),0;
    
    auto push=[&](int p,int q)  {
        while (p)   {
            int t=min(p,q-1);
            ans.emplace_back(t,q);
            p-=t;
        }
    };

    int p1=a[0],p2=a[1];
    for (int k=n/p1;k;--k)    {
        int r=n-1-k*p1;
        if (r%p2==0)    {
            push(k,n/p1);
            push(r/p2,n/p2);
            break;
        }
    }

    assert(ans.size()<=100000);


    printf("YES\n%d\n",ans.size());
    for (pair<int,int> p : ans)
        printf("%d %d\n",p.first,p.second);
    return 0;
}