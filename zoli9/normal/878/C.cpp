#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int inp[100009][11];
int n, k;
int mag[100009];
int meret[100009];
int apa[100009];
int lkjobb[11];
int lngye[11];
int ujlk[11];
int ujln[11];
int NAGY=1000000001;
int holvan(int x)
{
    if(apa[x]==x) return x;
    return apa[x]=holvan(apa[x]);
}
void unio(int x, int y)
{
    if(mag[x]<mag[y])
    {
        apa[x]=y;
        meret[y]+=meret[x];
    }
    else if(mag[x]>mag[y])
    {
        apa[y]=x;
        meret[x]+=meret[y];
    }
    else
    {
        apa[x]=y;
        mag[y]++;
        meret[y]+=meret[x];
    }
}
set<pair<pair<int, int>, int> > s[11];
void kiiras()
{
    auto iu=s[1].begin();
    while(iu!=s[1].end())
    {
        cout<<(iu->F.F)<<" "<<(iu->F.S)<<" "<<(iu->S)<<endl;
        iu++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            cin>>inp[i][j];
        }
        mag[i]=1;
        meret[i]=1;
        apa[i]=i;
    }
    for(int i=1; i<=k; i++)
    {
        s[i].insert({{inp[1][i], inp[1][i]}, 1});
        inp[100001][i]=0;
        inp[100002][i]=NAGY;
        s[i].insert({{0, 0}, 100001});
        s[i].insert({{NAGY, NAGY}, 100002});
    }
    mag[100001]=1;
    mag[100002]=1;
    meret[100001]=1;
    meret[100002]=1;
    apa[100001]=100001;
    apa[100002]=100002;
    cout<<1<<endl;
    for(int u=2; u<=n; u++)
    {

        for(int j=1; j<=k; j++)
        {

            auto it=s[j].lower_bound({{inp[u][j], inp[u][j]}, u});
            /*if(it==s[j].end()) lkjobb[j]=-1;
            else lkjobb[j]=it->S;
            if(it==s[j].begin()) lngye[j]=-1;
            else
            {
                it--;
                lngye[j]=it->S;
            }*/
            it--;
            lngye[j]=it->S;
            if(it->F.S<inp[u][j])
            {
                it++;
                lkjobb[j]=it->S;
            }
            else
            {
                lkjobb[j]=it->S;
            }
        }

        for(int j=1; j<=k; j++)
        {
            if(lkjobb[j]!=-1) lkjobb[j]=holvan(lkjobb[j]);
            if(lngye[j]!=-1) lngye[j]=holvan(lngye[j]);
        }
        int llk=-1;
        int lln=-1;
        for(int j=1; j<=k; j++)
        {
            if(lkjobb[j]==-1) continue;
            if(llk==-1 || inp[lkjobb[j]][1]<inp[llk][1]) llk=lkjobb[j];
        }
        for(int j=1; j<=k; j++)
        {
            if(lngye[j]==-1) continue;
            if(lln==-1 || inp[lngye[j]][1]>inp[lln][1]) lln=lngye[j];
        }
        vector<int> uniozni;
        if(inp[llk][1]>inp[lln][1])
        {
            /*if(u==6)
            {
                cout<<"llk, lln: "<<llk<<" "<<lln<<endl;
                kiiras();
            }*/
            for(int j=1; j<=k; j++)
            {
                s[j].insert({{inp[u][j], inp[u][j]}, u});
            }
        }
        else
        {
            for(int j=1; j<=k; j++)
            {
                ujlk[j]=inp[u][j];
                ujln[j]=inp[u][j];
                auto it=s[j].lower_bound({{inp[llk][j], 1000000009}, llk});
                it--;
                //cout<<"llk, lln: "<<llk<<" "<<lln<<endl;
                while(it->S!=lln)
                {
                    //cout<<"mennyi: "<<(it->S)<<endl;
                    //cout<<"el "<<u<<endl;
                    ujlk[j]=min(ujlk[j], it->F.F);
                    ujln[j]=max(ujln[j], it->F.S);
                    if(j==1) uniozni.push_back(it->S);
                    pair<pair<int, int>, int> akt=*it;
                    it++;
                    s[j].erase(akt);

                }
                ujlk[j]=min(ujlk[j], it->F.F);
                ujln[j]=max(ujln[j], it->F.S);
                if(j==1) uniozni.push_back(it->S);
                pair<pair<int, int>, int> akt=*it;
                s[j].erase(akt);
            }

            for(int x=0; x<uniozni.size(); x++)
            {
                unio(holvan(u), holvan(uniozni[x]));
            }
            for(int j=1; j<=k; j++)
            {
                s[j].insert({{ujlk[j], ujln[j]}, holvan(u)});
            }

        }
        auto it=s[1].end();
        it--;
        it--;
        int valasz=it->S;
        valasz=holvan(valasz);
        //cout<<"ind: "<<valasz<<endl;
        cout<<meret[valasz]<<endl;
    }
    return 0;
}