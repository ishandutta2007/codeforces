#include <bits/stdc++.h>
using namespace std;
long long MOD=1000000007;
long long n, f1, f2, f3, c;
void mul(vector<vector<long long> > & m1, vector<vector<long long> > & m2, long long M)
{
    vector<vector<long long> > ans(3, vector<long long>(3, 0LL));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                ans[i][j]=(ans[i][j]+(m1[i][k]*m2[k][j])%M)%M;
            }
        }
    }
    m1=ans;
}
vector<vector<long long> > matrixpow(vector<vector<long long> > & m1, long long p, long long M)
{
    vector<vector<long long> > res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    while(p>0)
    {
        if(p%2)
        {
            mul(res, m1, M);
        }
        mul(m1, m1, M);
        p/=2;
    }
    return res;
}
long long modpow(long long a, long long p)
{
    long long res=1;
    while(p>0)
    {
        if(p%2)
        {
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD;
        p/=2;
    }
    return res;
}
void printing(vector<vector<long long> > & m)
{
    for(vector<long long> i: m)
    {
        for(long long j: i)
        {
            cout<<j<<" : ";
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>f1>>f2>>f3>>c;
    vector<vector<long long> > cmatrix = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    cmatrix=matrixpow(cmatrix, n-2, MOD-1);
    long long cpow=modpow(c, (3*cmatrix[1][0]+2*cmatrix[1][1]+cmatrix[1][2]-(n%(MOD-1))+(MOD-1))%(MOD-1));
    //printing(cmatrix);
    long long fc1=modpow(f1, cmatrix[1][2]);
    long long fc2=modpow(f2, cmatrix[1][1]);
    long long fc3=modpow(f3, cmatrix[1][0]);
    long long answer=(fc1*fc2)%MOD;
    answer=(answer*fc3)%MOD;
    answer=(answer*cpow)%MOD;

    cout<<answer<<endl;


    return 0;
}