#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define MP make_pair
const int dir[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
set<pair<int,int> >s[2][200111];
map<int,bool>M[100111];
int n,m,k,cx,cy,cd,F;
long long ans;
void ins(int x,int y)
{
    s[0][x-y+m+1].insert(MP(x,y));
    s[1][x+y].insert(MP(x,y));
    M[x][y]=1;
}
void next(bool f)
{
    int x,y,a,b,t=((cd+1)>>1)&1,tx,ty;
    auto p=s[t][t?cx+cy:cx-cy+m+1].lower_bound(MP(cx,cy));
    if(cd<2)--p;x=p->FF,y=p->SS,tx=x+dir[3-cd][0],ty=y+dir[3-cd][1];
    a=M[tx][y],b=M[x][ty];
    if(f)ans+=abs(cx-x);
    if(!a&&b)cx=tx,cy=y,cd=cd^2;
    else if(a&&!b)cx=x,cy=ty,cd=cd^1;
    else cx=tx,cy=ty,cd=3-cd,F=1;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int x,y;char c1,c2;
    for(int i=1;i<=k;i++)scanf("%d%d",&x,&y),ins(x,y);
    for(int i=0;i<=n+1;i++)ins(i,0),ins(i,m+1);
    for(int i=0;i<=m+1;i++)ins(0,i),ins(n+1,i);
    scanf("%d %d %c%c",&cx,&cy,&c1,&c2);
    cd=(c1=='S')*2+(c2=='E');next(0);
    int sx=cx,sy=cy,sd=cd;
    for(next(1);cx!=sx||cy!=sy||cd!=sd;next(1));
    printf("%I64d\n",ans/(F+1));
    return 0;
}