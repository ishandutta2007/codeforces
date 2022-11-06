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
        int mi = xs[0];
        if(xs[1] < mi)
        {
            mi = xs[1];
            mix = 1;
        }
        if(xs[2] < mi)
        {
            mi = xs[2];
            mix = 2;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mix == (i+j)%3 && board[i][j] == 'X')
                    cout<<'O';
                else
                    cout<<board[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}