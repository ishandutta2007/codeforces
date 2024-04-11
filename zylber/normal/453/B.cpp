#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int DP[128][(1<<18)+10];
int a[128];
vector<int > primes;
int mask[64];
vector<int> ans;

int main()
{
    for(int i=2; i<64; i++)
    {
        int p=1;
        for(int j=2; j<i; j++) if(i%j==0) p=0;
        if(p) primes.push_back(i);
    }
    
    memset(mask,0,sizeof(mask));
    int ps=primes.size();
    for(int i=1; i<64; i++)
    {
        for(int j=0; j<ps; j++)
            if(i%primes[j]==0) mask[i]|=(1<<j);
    }
    
    memset(DP,0x3f,sizeof(DP));
    for(int j=0; j<(1<<ps); j++)
        DP[0][j]=0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    
    for(int i=0; i<n; i++)
    {
        for(int k=1; k<64; k++)
        {
            int tmask=(1<<ps)-1-mask[k];
            for(int j=tmask; j!=0; j=((j-1)&tmask))
            {
                //if((j&mask[k])==0)
                //cout << j << endl;
                DP[i+1][j|mask[k]]=min(DP[i+1][j|mask[k]], abs(k-a[i])+DP[i][j]);
            }   
        }
    }
    
    int actm=(1<<ps)-1;
    for(int i=n; i>0; i--)
    {
        //cout << actm << " " << DP[i][actm] << endl;
        int act=-1;
        for(int j=1; j<64; j++)
        {
        if((mask[j]&actm)==mask[j])
        {
            //cout << DP[i][actm] << " " << abs(j-a[i-1])+DP[i-1][actm-mask[j]] << endl;
            if(DP[i][actm]==abs(j-a[i-1])+DP[i-1][actm-mask[j]]) act=j;
        }
        }
        ans.push_back(act);
        actm-=mask[act];
    }
    
    reverse(ans.begin(), ans.end());
    for(int i=0; i<n; i++)
    {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}