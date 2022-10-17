#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T,n;

vector<int>ans;

int query(vector<int> &L,vector<int> &R)
{
    printf("? %d %d\n",L.size(),R.size());
    for(auto x:L)
        printf("%d ",x);
    puts("");
    for(auto x:R)
        printf("%d ",x);
    puts("");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        vector<int>L,R;
        L.push_back(1);
        int p=-1;
        for(int i=2;i<=n;i++)
        {
            R.push_back(i);
            if(query(L,R))
            {
                p=i;
                break;
            }
            L.push_back(i);
            R.pop_back();
        }
        assert(p!=-1);
        L.clear();
        L.push_back(p);
        R.clear();
        ans.clear();
        for(int i=p+1;i<=n;i++)
        {
            R.push_back(i);
            if(!query(L,R))
                ans.push_back(i);
            R.pop_back();
        }
        int l=0,r=p-1;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            for(int i=l+1;i<=mid;i++)
                R.push_back(i);
            if(query(L,R))
                r=mid;
            else
                l=mid;
            R.clear();
        }
        for(int i=1;i<=p-1;i++)
            if(i!=r)
                ans.push_back(i);
        sort(ans.begin(),ans.end());
        printf("! ");
        printf("%d ",ans.size());
        for(auto x:ans)
            printf("%d ",x);
        puts("");
        fflush(stdout);
    }
}