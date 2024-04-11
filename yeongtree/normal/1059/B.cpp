#include <iostream>

using namespace std;

int main()
{
    int dx[8]={0,1,2,2,2,1,0,0};
    int dy[8]={0,0,0,1,2,2,2,1};
    int n,m; cin>>n>>m;
    bool arr[n][m]; char a;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a;
            arr[i][j]=(a=='#');
        }
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!arr[i][j]) continue;
            bool _flag=false;
            for(int k=0;k<8;k++)
            {
                bool __flag=true;
                for(int l=0;l<8;l++)
                {
                    int nx=i-dx[k]+dx[l];
                    int ny=j-dy[k]+dy[l];
                    if(nx<0||nx>=n||ny<0||ny>=m) {__flag=false; break;}
                    if(!arr[nx][ny]) {__flag=false; break;}
                }
                if(__flag) {_flag=true; break;}
            }
            if(!_flag) {flag=false; break;}
        }
        if(!flag) break;
    }
    cout<<(flag?"YES":"NO");
    return 0;
}