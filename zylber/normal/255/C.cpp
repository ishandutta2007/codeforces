#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int next[4000], prev[4000], n[4000], N;

int DP[4010][4010];

int main()
{
    memset(next,-1,sizeof(next));
    memset(prev,-1,sizeof(prev));
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> n[i];

    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            if(n[i]==n[j] && next[i]==-1)
            {
                next[i]=j;
                prev[j]=i;
            }

    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
        {
            if(prev[j]==-1)
                DP[i][j]=2;
            else
                if(prev[j]>i)
                    DP[i][j]=DP[i][prev[j]];
                else
                    if(prev[j]==i)
                    {
                        if(prev[i]==-1)
                            DP[i][j]=2;
                        else
                            DP[i][j]=DP[prev[i]][i]+1;
                    }
                    else
                        DP[i][j]=DP[prev[j]][i]+1;
        }

    int best=1;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            best=max(best,DP[i][j]);

    cout << best << endl;
}