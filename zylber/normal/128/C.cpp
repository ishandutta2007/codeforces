#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std;

long long DP[1024][1024], S[1024][1024], SS[1024][1024];

int main()
{
    memset(DP,0,sizeof(DP));
    memset(S,0,sizeof(S));
    memset(SS,0,sizeof(SS));
    for(int i=1; i<1024; i++)
    {
        DP[i][0]=1;
        S[i][0]=(DP[i][0]+S[i-1][0])%MOD;
        SS[i][0]=(S[i][0]+SS[i-1][0])%MOD;
    }
    
    for(int k=1; k<1024; k++)
        for(int i=3; i<1024; i++)
        {
            DP[i][k]=SS[i-2][k-1];
            S[i][k]=(DP[i][k]+S[i-1][k])%MOD;
            SS[i][k]=(S[i][k]+SS[i-1][k])%MOD;
        }
    
    int n, m, k;
    cin >> n >> m >> k;
    
    cout << (DP[n][k]*DP[m][k])%MOD << endl;
}