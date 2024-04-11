#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct Point
{
    int x,y;
    Point(int _x,int _y):x(_x),y(_y){}
    Point rot() { return Point(-y,x); }
};
vector<Point> hor[4][3],ver[4][3];
bool check(int n,int k)
{
    for(int d=0;d<4;d++)
    {
        int col[3]={0,1,2};
        do
        {
            int min_x=hor[d][col[0]][k-1].x;
            int max_x=hor[d][col[1]][n-k].x;
            int cnt=0;
            for(int i=0;i<n && cnt<k;i++)
            {
                const Point& p=hor[d][col[2]][i];
                if(p.x>min_x && p.x<max_x)cnt++;
            }
            if(cnt>=k)return 1;
        }
        while(next_permutation(col,col+3));
        iota(col,col+3,0);
        do
        {
            int max_y=ver[d][col[0]][k-1].y;
            int cnt=0,max_x=0,min_x=0;
            for(int i=0;i<n && cnt<k;i++)
            {
                const Point& p=hor[d][col[1]][i];
                if(p.y<=max_y)continue;
                cnt++,max_x=p.x;
            }
            if(cnt<k)continue;
            cnt=0;
            for(int i=n-1;i>=0 && cnt<k;i--)
            {
                const Point& p=hor[d][col[2]][i];
                if(p.y<=max_y)continue;
                ++cnt,min_x=p.x;
            }
            if(cnt<k)continue;
            if(max_x<min_x)return 1;
        }
        while(next_permutation(col,col+3));
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        Point t=Point(x,y);
        for(int d=0;d<4;d++)
        {
            hor[d][c-1].push_back(t);
            t=t.rot();
        }
    }
    for(int d=0;d<4;d++)
        for(int c=0;c<3;c++)
        {
            sort(hor[d][c].begin(),hor[d][c].end(),[](const Point& p,const Point &q){
                return p.x==q.x ? p.y<q.y : p.x<q.x;
            });
            ver[d][c]=hor[d][c];
            sort(ver[d][c].begin(),ver[d][c].end(),[](const Point& p,const Point &q){
                return p.y==q.y ? p.x<q.x : p.y<q.y;
            });
        }
    n/=3;
    int l=1,r=n;
    while(l<r)
    {
        int m=(l+r+1)/2;
        if(check(n,m))l=m;
        else r=m-1;
    }
    return 0*printf("%d\n",3*l);
}