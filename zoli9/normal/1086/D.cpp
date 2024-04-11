#include <bits/stdc++.h>
using namespace std;
int m0[2000009];
set<int> se[3];
void modosit0(int cs, int k, int v, int h, int val)
{
    if(h<k || v<h) return;
    if(k==v && k==h)
    {
        m0[cs]+=val;
        return;
    }
    m0[cs]+=val;
    modosit0(2*cs, k, (k+v)/2, h, val);
    modosit0(2*cs+1, (k+v)/2+1, v, h, val);
}
int kerdes0(int cs, int k, int v, int x, int y)
{
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m0[cs];
    int p1=kerdes0(2*cs, k, (k+v)/2, x, y);
    int p2=kerdes0(2*cs+1, (k+v)/2+1, v, x, y);
    return p1+p2;
}

int m1[2000009];
void modosit1(int cs, int k, int v, int h, int val)
{
    if(h<k || v<h) return;
    if(k==v && k==h)
    {
        m1[cs]+=val;
        return;
    }
    m1[cs]+=val;
    modosit1(2*cs, k, (k+v)/2, h, val);
    modosit1(2*cs+1, (k+v)/2+1, v, h, val);
}
int kerdes1(int cs, int k, int v, int x, int y)
{
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m1[cs];
    int p1=kerdes1(2*cs, k, (k+v)/2, x, y);
    int p2=kerdes1(2*cs+1, (k+v)/2+1, v, x, y);
    return p1+p2;
}

int m2[2000009];
void modosit2(int cs, int k, int v, int h, int val)
{
    if(h<k || v<h) return;
    if(k==v && k==h)
    {
        m2[cs]+=val;
        return;
    }
    m2[cs]+=val;
    modosit2(2*cs, k, (k+v)/2, h, val);
    modosit2(2*cs+1, (k+v)/2+1, v, h, val);
}
int kerdes2(int cs, int k, int v, int x, int y)
{
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m2[cs];
    int p1=kerdes2(2*cs, k, (k+v)/2, x, y);
    int p2=kerdes2(2*cs+1, (k+v)/2+1, v, x, y);
    return p1+p2;
}

int ertekmost[200009];
int n, qu;

int miaz(char ccc)
{
    if(ccc=='R') return 0;
    if(ccc=='P') return 1;
    return 2;
}

string kezdo_s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>qu;
    cin>>kezdo_s;
    for(int i=0; i<n; i++)
    {
        ertekmost[i]=miaz(kezdo_s[i]);
        if(ertekmost[i]==0) modosit0(1, 0, n-1, i, 1);
        else if(ertekmost[i]==1) modosit1(1, 0, n-1, i, 1);
        else modosit2(1, 0, n-1, i, 1);
        se[ertekmost[i]].insert(i);
    }
    for(int tt=0; tt<=qu; tt++)
    {
        if(tt!=0)
        {
            int indexe;
            cin>>indexe;
            indexe--;
            char cc;
            cin>>cc;
            int aktval=miaz(cc);
            se[ertekmost[indexe]].erase(indexe);
            if(ertekmost[indexe]==0) modosit0(1, 0, n-1, indexe, -1);
            else if(ertekmost[indexe]==1) modosit1(1, 0, n-1, indexe, -1);
            else modosit2(1, 0, n-1, indexe, -1);
            se[aktval].insert(indexe);
            if(aktval==0) modosit0(1, 0, n-1, indexe, 1);
            else if(aktval==1) modosit1(1, 0, n-1, indexe, 1);
            else modosit2(1, 0, n-1, indexe, 1);
            ertekmost[indexe]=aktval;
        }
        int ans=0;
        for(int ez=0; ez<3; ez++)
        {
            //cout<<"* "<<ez<<" "<<ans<<endl;
            int nagy=(ez+1)%3;
            int kicsi=(ez+2)%3;
            int elsonagy=-1;
            int utolsonagy=-1;
            int elsokicsi=-1;
            int utolsokicsi=-1;
            if(se[nagy].size()>0)
            {
                elsonagy=(*se[nagy].begin());
                auto it=se[nagy].end();
                it--;
                utolsonagy=*it;
            }
            if(se[kicsi].size()>0)
            {
                elsokicsi=(*se[kicsi].begin());
                auto it=se[kicsi].end();
                it--;
                utolsokicsi=*it;
            }
            if(elsonagy==-1)
            {
                if(ez==0) ans+=kerdes0(1, 0, n-1, 0, n-1);
                else if(ez==1) ans+=kerdes1(1, 0, n-1, 0, n-1);
                else ans+=kerdes2(1, 0, n-1, 0, n-1);
                continue;
            }
            if(elsokicsi==-1) continue;
            /*if(utolsokicsi==elsokicsi)
            {
                if(elsonagy>elsokicsi)
                {
                    if(ez==0) ans+=kerdes0(1, 0, n-1, 0, elsokicsi);
                else if(ez==1) ans+=kerdes1(1, 0, n-1, 0, elsokicsi);
                else ans+=kerdes2(1, 0, n-1, 0, elsokicsi);
                }
                if(utolsonagy<elsokicsi)
                {
                    if(ez==0) ans+=kerdes0(1, 0, n-1, elsokicsi, n-1);
                else if(ez==1) ans+=kerdes1(1, 0, n-1, elsokicsi, n-1);
                else ans+=kerdes2(1, 0, n-1, elsokicsi, n-1);
                }
                continue;
            }*/
            /*if(tt==1 && ez==2)
            {
                cout<<"a: "<<ans<<endl;
            }*/

            if(ez==0) ans+=kerdes0(1, 0, n-1, elsokicsi, utolsokicsi);
                else if(ez==1) ans+=kerdes1(1, 0, n-1, elsokicsi, utolsokicsi);
                else ans+=kerdes2(1, 0, n-1, elsokicsi, utolsokicsi);

                int meddig=min(elsokicsi, elsonagy);
                int mettol=max(utolsokicsi, utolsonagy);

                if(ez==0) ans+=kerdes0(1, 0, n-1, 0, meddig);
                else if(ez==1) ans+=kerdes1(1, 0, n-1, 0, meddig);
                else ans+=kerdes2(1, 0, n-1, 0, meddig);

                if(ez==0) ans+=kerdes0(1, 0, n-1, mettol, n-1);
                else if(ez==1) ans+=kerdes1(1, 0, n-1, mettol, n-1);
                else ans+=kerdes2(1, 0, n-1, mettol, n-1);


        }
        cout<<ans<<endl;
    }
    return 0;
}