#include <bits/stdc++.h>
using namespace std;
int n, m;
string betuk="AGCT";
vector<string> s;
vector<vector<int> > t;
int sorptl[4][300009];
int sorps[4][300009];
int oszptl[4][300009];
int oszps[4][300009];
int X1[6]={0, 0, 0, 2, 1, 1};
int X2[6]={1, 2, 3, 3, 3, 2};
int sormarad[6][2];
int oszmarad[6][2];
int melyik(char ccc)
{
    if(ccc=='A') return 0;
    if(ccc=='G') return 1;
    if(ccc=='C') return 2;
    if(ccc=='T') return 3;
    return 4;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    s.resize(n);
    t.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        for(int j=0; j<m; j++)
        {
            int most=melyik(s[i][j]);
            t[i].push_back(most);
            if(j%2)
            {
                sorptl[most][i]++;
            }
            else
            {
                sorps[most][i]++;
            }
            if(i%2)
            {
                oszptl[most][j]++;
            }
            else
            {
                oszps[most][j]++;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int ii=0; ii<6; ii++)
        {
            sormarad[ii][i%2]+=(max(sorptl[X1[ii]][i]+sorps[X2[ii]][i], sorptl[X2[ii]][i]+sorps[X1[ii]][i]));
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int ii=0; ii<6; ii++)
        {
            oszmarad[ii][i%2]+=(max(oszptl[X1[ii]][i]+oszps[X2[ii]][i], oszptl[X2[ii]][i]+oszps[X1[ii]][i]));
        }
    }

    int legjobb=-1;
    int so=0;
    int paritas=0;
    int elrendezes=0;

    for(int ii=0; ii<3; ii++)
    {
        for(int j=0; j<2; j++)
        {
            if(sormarad[ii][j]+sormarad[ii+3][1-j]>legjobb)
            {
                legjobb=sormarad[ii][j]+sormarad[ii+3][1-j];
                so=0;
                elrendezes=ii;
                paritas=j;
            }
            if(oszmarad[ii][j]+oszmarad[ii+3][1-j]>legjobb)
            {
                legjobb=oszmarad[ii][j]+oszmarad[ii+3][1-j];
                so=1;
                elrendezes=ii;
                paritas=j;
            }
        }
    }

    if(so==0)
    {
        for(int i=0; i<n; i++)
        {
            int ii=elrendezes;
            int i3=ii;
            if(paritas!=i%2) i3+=3;


                if(sorptl[X1[i3]][i]+sorps[X2[i3]][i]>sorptl[X2[i3]][i]+sorps[X1[i3]][i])
                {
                    for(int u=0; u<m; u++)
                    {
                        if(u%2) t[i][u]=X1[i3];
                        else t[i][u]=X2[i3];
                    }
                }
                else
                {
                    for(int u=0; u<m; u++)
                    {
                        if(u%2) t[i][u]=X2[i3];
                        else t[i][u]=X1[i3];
                    }
                }


        }
    }
    else
    {
        for(int i=0; i<m; i++)
        {
            int ii=elrendezes;
            int i3=ii;
            if(paritas!=i%2) i3+=3;


                if(oszptl[X1[i3]][i]+oszps[X2[i3]][i]>oszptl[X2[i3]][i]+oszps[X1[i3]][i])
                {
                    for(int u=0; u<n; u++)
                    {
                        if(u%2) t[u][i]=X1[i3];
                        else t[u][i]=X2[i3];
                    }
                }
                else
                {
                    for(int u=0; u<n; u++)
                    {
                        if(u%2) t[u][i]=X2[i3];
                        else t[u][i]=X1[i3];
                    }
                }


        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<betuk[t[i][j]];
        }
        cout<<endl;
    }


    return 0;
}