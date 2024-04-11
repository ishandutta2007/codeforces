#include<bits/stdc++.h>
#define maxn 300050
using namespace std;

int n;
int L[2][maxn],R[2][maxn];

char s[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%s",&n,s+1);

        for (int i=0;i<=n;++i) L[0][i]=L[1][i]=R[0][i]=R[1][i]=i;

        for (int i=1;i<=n;++i)  {
            if (s[i]=='L')
                L[0][i]=L[1][i-1];
            else
                L[1][i]=L[0][i-1]; 
            // cout<<"L "<<i<<":"<<L[0][i]<<" "<<L[1][i]<<endl;
        }
        for (int i=n;i;--i) {
            if (s[i]=='R')
                R[0][i-1]=R[1][i];
            else
                R[1][i-1]=R[0][i]; 
            // cout<<"R "<<i<<":"<<R[0][i]<<" "<<R[1][i]<<" "<<s[i]<<endl;
        }
        for (int i=0;i<=n;++i)
            printf("%d%c",R[0][i]-L[0][i]+1," \n"[i==n]);
    }
    return 0;
}