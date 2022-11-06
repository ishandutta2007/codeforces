#include <iostream>

using namespace std;

long long pos[5005], p, q;
long long pre[5005][5005];
long long mod = 1000000007;

int main()
{
    long long n;
    cin>>n;
    char c;
    pos[2] = 1;
    for(int i = 2; i <= n+1; i++)
        pre[0][i] = 1;
    bool pf = false;
    for(int i = 1; i <= n; i++)
    {
        long long s;
        cin>>c;
        if(!pf)
        {
            for(int j = 0; j <= n+1; j++)
                pos[j] = 0;
            for(int j = 2; j <= n+1; j++)
                pos[j] = (pre[i-1][n+1]-pre[i-1][j-1]+mod)%mod;
        }
        else
        {
            p = pos[0];
            for(int j = 1; j < n+2; j++)
            {
                q = pos[j];
                pos[j] = p;
                p = q;
            }
        }
        if(c == 's')
            pf = false;
        else
            pf = true;
        s = 0;
        for(int j = 0; j <= n+1; j++)
        {
            s += pos[j];
            s %= mod;
            pre[i][j] = s;
        }
        /*for(int j = 0; j <= n+1; j++)
            cout<<pos[j]<<" ";
        cout<<endl;
        for(int j = 0; j <= n+1; j++)
            cout<<pre[i][j]<<" ";
        cout<<endl;*/
    }
    cout<<pre[n][n+1]%mod<<endl;
    return 0;
}