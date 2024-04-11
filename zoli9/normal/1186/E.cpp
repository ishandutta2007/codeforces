#include <bits/stdc++.h>
using namespace std;
long long n, m;
int q;
long long t[1009][1009];
long long kum[1009][1009];
int cntbit(long long z)
{
    int ret=0;
    while(z)
    {
        ret += z & 1;
        z >>=1 ;
    }
    return ret;
}
long long f(long long x, long long y)
{
    if(x==0 || y==0) return 0;
    long long holx=(x-1)/n+1;
    long long sx=x%n;
    if(sx==0) sx+=n;
    long long holy=(y-1)/m+1;
    long long sy=y%m;
    if(sy==0) sy+=m;
    bool jo=(cntbit(holx-1)%2 == cntbit(holy-1)%2);
    long long valasz=0;
    if(holx%2 && holy%2)
    {
        valasz+=((n*m*(holx-1)*(holy-1))/2);
        valasz+=((sx*m*(holy-1))/2);
        valasz+=((sy*n*(holx-1))/2);
        if(jo) valasz+=kum[sx][sy];
        else valasz+=(sx*sy-kum[sx][sy]);
        return valasz;
    }
    else if(holx%2)
    {
        valasz+=((n*m*(holx-1)*(holy-1))/2);
        valasz+=((sx*m*(holy-2))/2);
        valasz+=((sy*n*(holx-1))/2);
        if(jo)
        {
            valasz+=(sx*m-kum[sx][m]);
            valasz+=kum[sx][sy];
        }
        else
        {
            valasz+=kum[sx][m];
            valasz+=(sx*sy-kum[sx][sy]);
        }
        return valasz;
    }
    else if(holy%2)
    {
        valasz+=((n*m*(holx-1)*(holy-1))/2);
        //cout<<"balfel: "<<valasz<<endl;
        valasz+=((sx*m*(holy-1))/2);
        //cout<<"balra: "<<valasz<<endl;
        valasz+=((sy*n*(holx-2))/2);
        //cout<<"felett: "<<valasz<<endl;
        if(jo)
        {
            valasz+=(sy*n-kum[n][sy]);
            valasz+=kum[sx][sy];
        }
        else
        {
            valasz+=kum[n][sy];
            //cout<<"v1: "<<valasz<<endl;
            valasz+=(sx*sy-kum[sx][sy]);
            //cout<<"v2: "<<valasz<<endl;
        }
        return valasz;
    }
    valasz+=((n*m*((holx-1)*(holy-1)-1))/2);
    valasz+=((sx*m*(holy-2))/2);
    valasz+=((sy*n*(holx-2))/2);
    if(jo)
    {
        valasz+=(kum[n][m]+kum[sx][sy]);
        valasz+=(sy*n-kum[n][sy]+sx*m-kum[sx][m]);
    }
    else
    {
        valasz+=(n*m-kum[n][m]+sx*sy-kum[sx][sy]);
        valasz+=(kum[n][sy]+kum[sx][m]);
    }
    return valasz;
}
long long kerdes(long long x1, long long y1, long long x2, long long y2)
{
    return f(x2, y2)+f(x1-1, y1-1)-f(x2, y1-1)-f(x1-1, y2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char ccc;
            cin>>ccc;
            if(ccc=='0') t[i][j]=0;
            else t[i][j]=1;
            kum[i][j]=t[i][j]+kum[i-1][j]+kum[i][j-1]-kum[i-1][j-1];
        }
    }
    /*cout<<f(3, 2)<<endl;
    cout<<f(3, 3)<<endl;
    cout<<f(3, 4)<<endl;
    cout<<f(3, 5)<<endl;
    */
    /*for(int i=0; i<=6; i++)
    {
        for(int j=0; j<=6; j++)
        {
            cout<<f(i, j)<<" ";
        }
        cout<<endl;
    }*/

    for(int i=1; i<=q; i++)
    {
        long long x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<kerdes(x1, y1, x2, y2)<<'\n';
    }

    return 0;
}