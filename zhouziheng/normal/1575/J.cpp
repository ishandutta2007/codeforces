#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,m,k,a[1005][1005];
set<pair<int,int> > s[1005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=2) s[j].insert(make_pair(i,a[i][j]));
        }
    }
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        int Pos=x,Height=0;
        while(1)
        {
            auto p = s[Pos].upper_bound(make_pair(Height,0));
            if(p == s[Pos].end()) break;
            auto Now=*p;
            s[Pos].erase(p);            
            if(Now.second == 1) Pos++;
            if(Now.second == 3) Pos--;
            Height=Now.first;
        }
        printf("%d ",Pos);
    }
}