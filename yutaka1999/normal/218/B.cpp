#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue <int> mx;
priority_queue <int,vector <int>,greater <int> > mn;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        if(a!=0)
        {
            mx.push(a);
            mn.push(a);
        }
    }
    int s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        int v=mx.top();mx.pop();
        s1+=v;
        if(v!=1) mx.push(v-1);
        v=mn.top();mn.pop();
        s2+=v;
        if(v!=1) mn.push(v-1);
    }
    printf("%d %d\n",s1,s2);
    return 0;
}