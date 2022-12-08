#include <iostream>
#include <cstring>
using namespace std;

int grundy[100500];
int esta[32];
int pxor[100500];

int main()
{
    int n;
    cin >> n;
    grundy[1]=0;
    
    pxor[1]=0;
    pxor[0]=0;
    //int maxi=0;
    for(int i=2; i<=n; i++)
    {
        memset(esta,0,sizeof(esta));
        int acc=1, mini=100000;
        for(int k=2; acc<i; k++)
        {
            acc+=k;
            if((i-acc)%k==0)
            {
                int p=(i-acc)/k;
                //cout << i << " " << k << " " << p << endl;
                esta[pxor[p]^pxor[p+k]]=1;
                if((pxor[p]^pxor[p+k])==0) mini=min(mini, k);
            }
        }
        grundy[i]=0;
        while(esta[grundy[i]]) grundy[i]++;
        pxor[i]=pxor[i-1]^grundy[i];
        //maxi=max(grundy[i], maxi);
        if(i==n)
        {
            if(grundy[n]==0) cout << -1 << endl; else cout << mini << endl;
        }
    }
    if(n==1) cout << -1 << endl;
    //cout << maxi << endl;
}