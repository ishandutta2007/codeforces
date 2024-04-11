#include <bits/stdc++.h>
using namespace std;
int x[3];
int y[3];
set<pair<int, int> > w;
void ut(int x1, int y1, int x2, int y2)
{
    int dx=1;
    if(x2<x1) dx=-1;
    for(int xx=x1; xx!=x2; xx+=dx)
    {
        w.insert({xx, y1});
    }
    int dy=1;
    if(y2<y1) dy=-1;
    for(int yy=y1; yy!=y2; yy+=dy)
    {
        w.insert({x2, yy});
    }
    w.insert({x2, y2});
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<3; i++)
    {
        cin>>x[i]>>y[i];
    }
    int mini=100000000;
    int mx=0;
    int my=0;
    for(int i=0; i<=1000; i++)
    {
        for(int j=0; j<=1000; j++)
        {
            int most=0;
            for(int u=0; u<3; u++)
            {
                most+=(abs(x[u]-i));

                most+=(abs(y[u]-j));

            }

            if(most<mini)
            {
                mini=most;
                mx=i;
                my=j;
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        ut(x[i], y[i], mx, my);
    }
    cout<<w.size()<<endl;
    for(pair<int, int> par: w)
    {
        cout<<par.first<<" "<<par.second<<endl;
    }
    return 0;
}