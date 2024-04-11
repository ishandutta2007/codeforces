#include<bits/stdc++.h>
using namespace std;

int T,n,k;

set<int>s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        s.clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        int mex=0;
        while(s.find(mex)!=s.end())
            mex++;
        if(mex>*s.rbegin())
        {
            printf("%d\n",s.size()+k);
        }
        else
        {
            if(k)
                s.insert((mex+*s.rbegin()+1)/2);
            printf("%d\n",s.size());
        }
    }
}