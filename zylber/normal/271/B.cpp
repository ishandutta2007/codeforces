#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int moves[200000];

int esprimo(int a)
{
    if(a==1)
        return 0;

    for(int d=2; d*d<=a; d++)
        if(a%d==0)
            return 0;

    return 1;

}

int calc(int i)
{
    if(moves[i]==-1)
    {
        if(esprimo(i))
        {
            moves[i]=0;
        }
        else
            moves[i]=calc(i+1)+1;
    }
    return moves[i];
}

int mat[512][512];

int main()
{
    memset(moves,-1,sizeof(moves));

    for(int i=1; i<=100000; i++)
    {
        int a=calc(i);
    }

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> mat[i][j];

    int best=100000000;

    for(int i=0; i<N; i++)
    {
        int s=0;
        for(int j=0; j<M; j++)
            s+=calc(mat[i][j]);
        best=min(best,s);
    }

    for(int i=0; i<M; i++)
    {
        int s=0;
        for(int j=0; j<N; j++)
            s+=calc(mat[j][i]);
        best=min(best,s);
    }

    cout << best << endl;
}