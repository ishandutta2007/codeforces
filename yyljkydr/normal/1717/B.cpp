#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        int n,k,r,c;
        cin>>n>>k>>r>>c;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                printf("%c",".X"[(i%k-r%k+j%k-c%k+4*k)%k==0]);
                if(j==n)
                    puts("");
            }
    }
}