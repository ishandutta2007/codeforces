#include <bits/stdc++.h>
using namespace std;
long long MOD=998244353;
long long m[2000009];
void modosit(int cs, int k, int v, int h, long long val)
{
    if(h<k || v<h) return;
    if(k==v && k==h)
    {
        m[cs]+=val;
        return;
    }
    m[cs]+=val;
    modosit(2*cs, k, (k+v)/2, h, val);
    modosit(2*cs+1, (k+v)/2+1, v, h, val);
}
int kerdes(int cs, int k, int v, int x, int y)
{
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m[cs];
    int p1=kerdes(2*cs, k, (k+v)/2, x, y);
    int p2=kerdes(2*cs+1, (k+v)/2+1, v, x, y);
    return p1+p2;
}
int n;
int p[200009];
int holp[200009];
long long elotteures[200009];
long long uta[200009];
long long uresek;
long long inve;
long long modinv(long long f)
{
    long long kit=MOD-2;
    long long res=1;
    long long x=f;
    while(kit>0)
    {
        if(kit%2)
        {
            res*=x;
            res%=MOD;
        }
        x*=x;
        x%=MOD;
        kit/=2;
    }
    return res;
}
long long answer1, answer2, answer3;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
        if(p[i]!=-1)
        {
            holp[p[i]]=i;
        }
        else uresek++;
    }
    for(int i=1; i<=n; i++)
    {
        if(p[i]==-1) elotteures[i]=elotteures[i-1]+1;
        else elotteures[i]=elotteures[i-1];
    }
    for(int i=n; i>=1; i--)
    {
        if(p[i]==-1) uta[i]=uta[i+1]+1;
        else uta[i]=uta[i+1];
    }
    //cout<<uta[1]<<" "<<uta[2]<<" "<<uta[3]<<endl;
    long long ansu=0;
    long long eddigossz=0;
    for(int i=1; i<=n; i++)
    {
        if(holp[i]<=0)
        {
            ansu+=eddigossz;
            ansu%=MOD;
        }
        else
        {
            inve+=(kerdes(1, 0, n, holp[i], n));
            inve%=MOD;
            modosit(1, 0, n, holp[i], 1);
            eddigossz+=(elotteures[holp[i]]);
            eddigossz%=MOD;
        }
    }
    eddigossz=0;
    for(int i=n; i>=1; i--)
    {
        if(holp[i]<=0)
        {
            ansu+=eddigossz;
            ansu%=MOD;
        }
        else
        {
            eddigossz+=(uta[holp[i]]);
            //cout<<"m: "<<uta[holp[i]]<<" "<<holp[i]<<endl;
            //cout<<eddigossz<<endl;
            eddigossz%=MOD;
        }
    }

    //cout<<ansu<<" "<<endl;
    //cout<<inve<<" *"<<endl;
    answer1=ansu*modinv(uresek);
    answer1%=MOD;
    //cout<<ansu<<" "<<answer1<<endl;
    answer2=inve%MOD;
    answer3=uresek*(uresek-1);
    answer3%=MOD;
    //cout<<uresek<<" "<<answer3<<endl;
    answer3*=modinv(4);
    answer3%=MOD;
    long long realanswer=(answer1+answer2)%MOD;
    realanswer+=answer3;
    realanswer%=MOD;
    cout<<realanswer<<endl;

    return 0;
}