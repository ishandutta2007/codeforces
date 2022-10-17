#include <iostream>

using namespace std;

int main()
{
    int kx,ky; cin>>kx>>ky;
    int x[670] , y[670]; for(int i = 1; i <= 666; ++i) cin >> x[i] >> y[i];
    bool board[1005][1005]={}; for(int i = 1; i <= 666; ++i) board[x[i]][y[i]] = true;

    while((kx != 500) || (ky != 500))
    {
        int nx,ny;
        if(kx < 500) nx = kx + 1;
        else if(kx > 500) nx = kx - 1;
        else nx = kx;
        if(ky < 500) ny = ky + 1;
        else if(ky > 500) ny = ky - 1;
        else ny = ky;
        if(board[nx][ny]) nx = kx;
        cout << nx << " " << ny << endl; cout.flush();
        kx = nx; ky = ny;

        int a,b,c; cin>>a>>b>>c;
        if(a <= 0) return 0;
        board[x[a]][y[a]] = false;
        x[a] = b; y[a] = c;
        board[b][c] = true;
    }

    int ul = 0 , ur = 0 , dl = 0 , dr = 0;
    for(int i = 1; i <= 666; ++i)
    {
        if(x[i] < 500 && y[i] < 500) ++dl;
        else if(x[i] < 500 && y[i] > 500) ++ul;
        else if(y[i] < 500) ++dr;
        else ++ur;
    }

    int dx = 0 , dy = 0;
    if(dl <= 167) {dx = 1; dy = 1;}
    else if(ul <= 167) {dx = 1; dy = -1;}
    else if(dr <= 167) {dx = -1; dy = 1;}
    else if(ur <= 167) {dx = -1; dy = -1;}

    while(1)
    {
        int nx = kx + dx , ny = ky + dy;
        if(board[nx][ny]) nx = kx;
        cout << nx << " " << ny << endl; cout.flush();
        kx = nx; ky = ny;

        int a,b,c; cin>>a>>b>>c;
        if(a <= 0) return 0;
        board[x[a]][y[a]] = false;
        x[a] = b; y[a] = c;
        board[b][c] = true;
    }
}