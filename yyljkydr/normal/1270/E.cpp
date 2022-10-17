#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n,x[N],y[N];

vector<int>v;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    while(1)
    {
        for(int i=1;i<=n;i++)
            if((x[i]+y[i])&1)
                v.push_back(i);
        if(v.size()==0||v.size()==n)
        {
            v.clear();
            for(int i=1;i<=n;i++)
            {
                int sx=x[i],sy=y[i];
                int fx=(sx+sy),fy=(sx-sy);
                if(fx&1)
                    fx--,fy--;
                x[i]=fx/2;
                y[i]=fy/2;
            }
            continue;
        }
        printf("%d\n",v.size());
        for(auto x:v)
            printf("%d ",x);
        puts("");
        break;
    }
}