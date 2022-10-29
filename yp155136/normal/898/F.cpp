#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int K = 2;
const int N = 1000006;

LL mods[K] = {100000007,1000000009};
LL pre[K][N];
LL pow10[K][N];

typedef vector<LL> vLL;

int a[N];

vLL query(int L,int R)
{
    vLL ret;
    ret.resize(K);
    for (int i=0;K>i;i++)
    {
        LL tmp=pre[i][R] - (pre[i][L-1]*pow10[i][R-L+1]);
        //cout << "L = "<<L<<" , R = "<<R<<" , tmp = "<<tmp<<endl;
        tmp = (tmp%mods[i] + mods[i])%mods[i];
        ret[i] = tmp;
    }
    return ret;
}

bool can(int L,int R)
{
    if (L>R) return false;
    else if (L == R) return true;
    else if (a[L] == 0) return false;
    else return true;
}

void doo(int L1,int R1,int L2,int R2,int L3,int R3)
{
    if (R1 + 1 != L2 || R2 + 1 != L3) return;
    if (!can(L1,R1) || !can(L2,R2) || !can(L3,R3)) return;
    vLL v1 = query(L1,R1),v2 = query(L2,R2),v3 = query(L3,R3);
    //cout << "L1 = "<<L1<<" , R1 = "<<R1<<" , L2 = "<<L2<<" , R2 = "<<R2<<" , L3 = "<<L3<<" , R3 = "<<R3<<endl;
    for (int i=0;K>i;i++)
    {
        //cout << "v1 = "<<v1[i]<<" , v2 = "<<v2[i]<<" , v3 = "<<v3[i]<<endl;
        if ((v1[i] + v2[i]) % mods[i] != v3[i]) return;
    }
    for (int i=L1;R1>=i;i++)
    {
        printf("%d",a[i]);
    }
    printf("+");
    for (int i=L2;R2>=i;i++)
    {
        printf("%d",a[i]);
    }
    printf("=");
    for (int i=L3;R3>=i;i++)
    {
        printf("%d",a[i]);
    }
    puts("");
    exit(0);
}

int main ()
{
    int n=0;
    char c;
    while ((c = getchar() ) != '\n')
    {
        a[++n] = (c-'0');
    }
    for (int p=0;K>p;p++)
    {
        LL mod = mods[p];
        pre[p][0] = 0;
        pow10[p][0] = 1;
        for (int i=1;n>=i;i++)
        {
            pre[p][i] = pre[p][i-1]*10 + a[i];
            pre[p][i] %= mod;
            pow10[p][i] = pow10[p][i-1]*10;
            pow10[p][i] %= mod;
            //cout << "pre["<<p<<"]["<<i<<"] = "<<pre[p][i]<<endl;
        }
    }
    for (int i=1;n/2+1>=i;i++)
    {
        int L1,L2,L3,R1,R2,R3;
        L1 = 1, R1 = i;
        R3 = n; L3 = (n-i+1);
        L2 = R1 + 1,R2 = L3-1;
        doo(L1,R1,L2,R2,L3,R3);
        L3--;
        R2--;
        doo(L1,R1,L2,R2,L3,R3);
        R3 = n; L3 = (n-i+1);
        R2 = L3-1, L2 = (R2 - i + 1);
        L1 = 1,R1 = L2-1;
        doo(L1,R1,L2,R2,L3,R3);
        L3--;
        R2--;
        L2--;
        R1--;
        doo(L1,R1,L2,R2,L3,R3);
    }
}