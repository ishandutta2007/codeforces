//
//  main.cpp
//  C
//
//  Created by  on 15/12/30.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
const int INF=0x3f3f3f3f;
int n,m;
char grid[510][510];
int a[510][510];
int s[510][510];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
int main()
{
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    cin>>n>>m;
    FOR(i,1,n)
    scanf("%s",grid[i]+1);
    FOR(i,1,n)
    FOR(j,1,m)
    if(grid[i][j] == '.')
    {
        //
        //  main.cpp
        //  C
        //
        //  Created by  on 15/12/30.
        //  Copyright  2015 . All rights reserved.
        //

        FOR(k,0,3){
            int xx= i+dx[k],yy = j+ dy[k];
            if(xx <=n && xx >=1 && yy<=m && yy >=1 )
                if(grid[xx][yy] == '.')
                    a[i][j] ++;
        }
    }
    FOR(i,1,n)
    FOR(j,1,m){
        s[i][j] = s[i-1][j] +s[i][j-1] +a[i][j] -s[i-1][j-1];
    }
    //
    //  main.cpp
    //  C
    //
    //  Created by  on 15/12/30.
    //  Copyright  2015 . All rights reserved.
    //

    int q;
    cin>>q;
    int r1,c1,r2,c2;
    while(q--){
        cin>>r1>>c1>>r2>>c2;
        int ans=s[r2][c2];
        ans=ans-s[r2][c1-1] -s[r1-1][c2];
        ans += s[r1-1][ c1-1];
        //cout<<ans<<endl;
        //
        //  main.cpp
        //  C
        //
        //  Created by  on 15/12/30.
        //  Copyright  2015 . All rights reserved.
        //

        if((r1-1 ) >=1)
            FOR(i,c1, c2){
                if(grid [r1-1][i] == '.' && grid[r1][i] == '.')
                {
                    //      cout<<r1<<" shang"<<i<<endl;
                    ans--;
                }
                
            }
        if((r2+1 ) <=n)
            FOR(i,c1, c2){
                if(grid [r2+1][i] == '.' && grid[r2][i] == '.')
                {
                    //    cout<<r1<<"xia "<<i<<endl;
                    ans--;
                }
                
            }
        if((c1-1 ) >=1)
            FOR(i,r1, r2){
                if(grid[i][ c1-1] == '.' && grid[i][c1] == '.')
                {
                    //  cout<<i<<" zuo"<<c1<<endl;
                    ans--;
                }
            }
        if((c2+1 ) <= m)
            FOR(i,r1, r2){
                if(grid[i][ c2+1] == '.' && grid[i][c2] == '.')
                {
                    //cout<<i<<" you"<<c1<<endl;
                    ans--;
                }
            }
        //cout<<ans<<"dfg"<<endl;
        cout <<ans/2<<endl;
    }
    return 0;
    //
    //  main.cpp
    //  C
    //
    //  Created by  on 15/12/30.
    //  Copyright  2015 . All rights reserved.
    //

}