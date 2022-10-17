#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x+y+z>=2)
            ans++;
    }
    printf("%d\n",ans);
}