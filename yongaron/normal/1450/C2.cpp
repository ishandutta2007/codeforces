#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int xs[3], os[3];

char board[333][333];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        xs[0] = xs[1] = xs[2] = 0;
        os[0] = os[1] = os[2] = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>board[i][j];
                if(board[i][j] == 'X')
                    xs[(i+j)%3]++;
                if(board[i][j] == 'O')
                    os[(i+j)%3]++;
            }
        }
        int mix = 0;
        int mio = 1;
        int mi = xs[0]+os[1];
        if(xs[0]+os[2] < mi)
        {
            mi = xs[0]+os[2];
            mix = 0;
            mio = 2;
        }
        if(xs[1]+os[0] < mi)
        {
            mi = xs[1]+os[0];
            mix = 1;
            mio = 0;
        }
        if(xs[1]+os[2] < mi)
        {
            mi = xs[1]+os[2];
            mix = 1;
            mio = 2;
        }
        if(xs[2]+os[0] < mi)
        {
            mi = xs[2]+os[0];
            mix = 2;
            mio = 0;
        }
        if(xs[2]+os[1] < mi)
        {
            mi = xs[2]+os[1];
            mix = 2;
            mio = 1;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mix == (i+j)%3 && board[i][j] == 'X')
                    cout<<'O';
                else if(mio == (i+j)%3 && board[i][j] == 'O')
                    cout<<'X';
                else
                    cout<<board[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}