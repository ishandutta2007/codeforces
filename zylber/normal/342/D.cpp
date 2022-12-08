#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std;

string tab[3];
long long DP[30010][8][2];
int n;

int enRango(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<3);
}

int libre(int i, int j, int mask[])
{
    return (enRango(i,j) && tab[j][i]=='.' && mask[j]==0);
}

int mueve(int i, int j)
{
    return (enRango(i,j) && tab[j][i]=='O');
}

long long dp(int i, int j, int mask[], int move)
{
    int nnmask=0;
    for(int a=0; a<3; a++){ nnmask*=2; nnmask+=mask[a]; }

    //cout << i << " " << j << " " << nnmask << " " << move <<  endl;
    if(i==n) return (nnmask==0 && move);
    if(j==3) return dp(i+1, 0, mask, move);
    
    if(DP[i*3+j][nnmask][move]!=-1) return DP[i*3+j][nnmask][move];
    long long &ans = DP[i*3+j][nnmask][move];
    ans=0;
    
    //cout << i << " " << j << " " << nmask << " " << move <<   endl;
    
    if(tab[j][i]!='.' || mask[j]){ 
        int nmask[3];
        for(int a=0; a<3; a++){ if(a==j) nmask[a]=0; else nmask[a]=mask[a];}
        ans=dp(i,j+1,nmask,move); return ans;
    }
    
    if(libre(i, j, mask) && libre(i, j+1, mask) && mask[j+1]==0)
    {
        //cout << "Meto vertical" << endl;
        int nmove=(move || mueve(i,j-1) || mueve(i, j+2));
        int nmask[3];
        for(int a=0; a<3; a++){ if(a==(j+2)%3) nmask[a]=mask[a]; else nmask[a]=0;}
        ans=dp(i, j+2, nmask, nmove)%MOD;
    }
    
    //cout << i << " " << j << " " << nnmask << " " << move <<  endl;
    if(libre(i, j, mask) && libre(i+1, j, mask))
    {
        //cout << "Meto horizontal" << endl;
        int nmove=(move || mueve(i-1,j) || mueve(i+2, j));
        //cout << "Meto horizontal" << endl;
        int nmask[3];
        for(int a=0; a<3; a++){ if(a==j) nmask[a]=1; else nmask[a]=mask[a];}
        ans=(ans+dp(i,j+1, nmask, nmove))%MOD;
    }
    
    //cout << i << " " << j << " " << nnmask << " " << move << " " << ans <<    endl;
    return ans;
}

int main()
{
    #ifdef ACMTUYO
        freopen("199D.in","r",stdin);
    #endif
    cin >> n;
    for(int i=0; i<3; i++) cin >> tab[i];
    
    memset(DP,-1,sizeof(DP));
    
    int mask[3]={0,0,0};
    cout << dp(0,0,mask,0) << endl;
}