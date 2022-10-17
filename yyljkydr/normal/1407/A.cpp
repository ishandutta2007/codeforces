#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

vector<int>ans;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans.clear();
        int c[2]={0,0};
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),c[a[i]]++;
        if(c[0]>=c[1])
        {
            for(int i=1;i<=c[0];i++)
                ans.push_back(0);
        }
        else
        {
            if(c[1]%2==0)
            {
                for(int i=1;i<=c[1];i++)
                    ans.push_back(1);
            }
            else
            {
                for(int i=1;i<=c[1]-1;i++)
                    ans.push_back(1);
            }
        }
        printf("%d\n",ans.size());
        for(auto x:ans)
            printf("%d ",x);
        puts("");
    }
}