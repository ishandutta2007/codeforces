#include <bits/stdc++.h>
using namespace std;
int n, m;
int szamok[100009];
int szamok2[100009];
vector<vector<int> > answer;
void kiir()
{
    for(int i=0; i<answer.size(); i++)
    {
        for(int j=0; j<answer[i].size(); j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(n==1 && m==1)
    {
        cout<<"YES"<<endl;
        cout<<1<<endl;
        return 0;
    }
    if(n==1 && m==2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(n==2 && m==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(n==2 && m==2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(n==3 && m==3)
    {
        cout<<"YES"<<endl;
        cout<<"6 1 8"<<endl;
        cout<<"7 5 3"<<endl;
        cout<<"2 9 4"<<endl;
        return 0;
    }
    if(max(n, m)==3)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(n>=4)
    {
        cout<<"YES"<<endl;
        if(n%2==0)
        {
            int nu=n/2;
            for(int i=1; i<=n; i+=2)
            {
                szamok[i]=nu;
                nu--;
            }
            nu=n;
            for(int i=2; i<=n; i+=2)
            {
                szamok[i]=nu;
                nu--;
            }
        }
        else
        {
            int nu=(n+1)/2;
            for(int i=1; i<=n; i+=2)
            {
                szamok[i]=nu;
                nu--;
            }
            nu=n;
            for(int i=2; i<=n; i+=2)
            {
                szamok[i]=nu;
                nu--;
            }
        }
        if(n==5)
        {
            szamok[1]=2;
            szamok[2]=5;
            szamok[3]=3;
            szamok[4]=1;
            szamok[5]=4;

            szamok2[1]=5;
            szamok2[2]=3;
            szamok2[3]=1;
            szamok2[4]=4;
            szamok2[5]=2;
        }
        vector<int> w;
        for(int i=1; i<=n; i++)
        {
            w.clear();
            for(int j=1; j<=m; j++)
            {
                int aktszam;
                if(j%2)
                {
                    aktszam=(szamok[i]-1)*m+j;
                }
                else
                {
                    if(n==5)
                    {
                        aktszam=(szamok2[i]-1)*m+j;
                    }
                    else aktszam=(n+1-(szamok[i])-1)*m+j;
                }
                w.push_back(aktszam);
            }
            answer.push_back(w);
        }
        if(n>5 && n%2)
        {
            for(int u=1; u<m; u+=2)
            {
                swap(answer[0][u], answer[2][u]);
            }
        }
        kiir();
    }
    else if(m>=4)
    {
        cout<<"YES"<<endl;
        if(m%2==0)
        {
            int mu=m/2;
            for(int i=1; i<=m; i+=2)
            {
                szamok[i]=mu;
                mu--;
            }
            mu=m;
            for(int i=2; i<=m; i+=2)
            {
                szamok[i]=mu;
                mu--;
            }
        }
        else
        {
            int mu=(m+1)/2;
            for(int i=1; i<=m; i+=2)
            {
                szamok[i]=mu;
                mu--;
            }
            mu=m;
            for(int i=2; i<=m; i+=2)
            {
                szamok[i]=mu;
                mu--;
            }
        }
        if(m==5)
        {
            szamok[1]=2;
            szamok[2]=5;
            szamok[3]=3;
            szamok[4]=1;
            szamok[5]=4;

            szamok2[1]=5;
            szamok2[2]=3;
            szamok2[3]=1;
            szamok2[4]=4;
            szamok2[5]=2;
        }
        vector<int> w;
        for(int i=1; i<=n; i++)
        {
            w.clear();
            for(int j=1; j<=m; j++)
            {
                int aktszam;
                if(i%2)
                {
                    aktszam=(i-1)*m+szamok[j];
                }
                else
                {
                    if(m==5)
                    {
                        aktszam=(i-1)*m+szamok2[j];
                    }
                    else aktszam=(i-1)*m+m+1-szamok[j];
                }
                w.push_back(aktszam);
            }
            answer.push_back(w);
        }
        if(m>5 && m%2)
        {
            for(int u=1; u<n; u+=2)
            {
                swap(answer[u][2], answer[u][0]);
            }
        }
        kiir();
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}