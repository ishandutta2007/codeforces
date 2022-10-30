#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> szamok[100009];
int maximum=0;

long long m[1000009];
void modosit(int cs, int k, int v, int h, int val)
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
int kerdez(int cs, int k, int v, int x, int y)
{
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m[cs];
    int p1=kerdez(2*cs, k, (k+v)/2, x, y);
    int p2=kerdez(2*cs+1, (k+v)/2+1, v, x, y);
    return p1+p2;
}
long long rkreal(int kezd, int vege)
{
    int tavol=vege-kezd+1;
    //cout<<"kerd "<<kezd<<" "<<vege<<" = "<<tavol-kerdez(1, 0, n-1, kezd, vege)<<endl;
    //cout<<kezd<<" "<<vege<<" "<<tavol-kerdez(1, 0, n-1, kezd, vege)<<endl;
    return tavol-kerdez(1, 0, n-1, kezd, vege);
}
long long rk(int kezd, int vege)
{
    //cout<<kezd<<" "<<vege<<endl;
    if(vege>=kezd)
    {
        //cout<<"v"<<rkreal(kezd, vege)<<endl;
        return rkreal(kezd, vege);
    }
    //cout<<"v"<<rkreal(kezd, n-1)+rkreal(0, vege)<<endl;
    return rkreal(kezd, n-1)+rkreal(0, vege);
}

long long answer=0;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int szam;
        cin>>szam;
        szamok[szam].push_back(i);
        maximum=max(maximum, szam);
    }
    for(int u=1; u<=maximum; u++)
    {
        sort(szamok[u].begin(), szamok[u].end());
    }
    int lastindex=0;
    for(int aktu=1; aktu<=maximum; aktu++)
    {
        if(szamok[aktu].size()==0) continue;
        int elso;
        if(lastindex>szamok[aktu].back())
        {
            elso=0;
        }
        else
        {
            int e1=0;
            int e2=szamok[aktu].size()-1;
            while(e1<=e2)
            {
                int kozepe=(e1+e2)/2;
                if(szamok[aktu][kozepe]>=lastindex) e2=kozepe-1;
                else e1=kozepe+1;
            }
            elso=e1;
        }
        answer+=rk(lastindex, szamok[aktu][elso]);
        lastindex=szamok[aktu][elso];
        //cout<<"mod: "<<lastindex<<" "<<1<<endl;
        modosit(1, 0, n-1, lastindex, 1);
        int elsoc=elso+1;
        while(elsoc<szamok[aktu].size())
        {
            answer+=rk(lastindex, szamok[aktu][elsoc]);
            lastindex=szamok[aktu][elsoc];
            //cout<<"mod: "<<lastindex<<" "<<1<<endl;
            modosit(1, 0, n-1, lastindex, 1);
            elsoc++;
        }
        elsoc=0;
        while(elsoc!=elso)
        {
            answer+=rk(lastindex, szamok[aktu][elsoc]);
            lastindex=szamok[aktu][elsoc];
            //cout<<"mod: "<<lastindex<<" "<<1<<endl;
            modosit(1, 0, n-1, lastindex, 1);
            elsoc++;
        }
    }
    cout<<answer<<endl;
    return 0;
}