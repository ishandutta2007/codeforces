#include <bits/stdc++.h>
using namespace std;
long long n, S;
long long c[100009];
long long lev[100009];
int ans[100009];
vector<int> w[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>S;
    long long belso=1;
    long long butolso=n-1;
    while(belso<=butolso)
    {
        long long bkozep=(belso+butolso)/2;
        bool jokicsi=true;
        long long elozoszint=1;
        long long megmarad=n-1;
        long long ertek=1;
        for(long long szint=2; szint<=n; szint++)
        {
            elozoszint*=bkozep;
            elozoszint=min(elozoszint, megmarad);
            megmarad-=elozoszint;
            ertek+=(szint*elozoszint);
            if(ertek>S)
            {
                jokicsi=false;
                break;
            }
            if(megmarad==0)
            {
                break;
            }
        }
        if(jokicsi)
        {
            butolso=bkozep-1;
        }
        else belso=bkozep+1;
    }
    if(belso==n)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(belso==1)
    {
        long long nsum=n*(n+1);
        nsum/=2;
        if(nsum<S)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }

    if(belso==1)
    {
        cout<<"Yes"<<endl;
        for(int i=1; i<n; i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return 0;
    }

    c[1]=1;
    long long z=n-1;
    S--;
    for(long long szint=2; szint<=n; szint++)
    {
        if(z==0) break;
        long long ejo=1;
        long long ujo=min(belso*c[szint-1], z);
        while(ejo<=ujo)
        {
            long long kozjo=(ejo+ujo)/2;
            long long elozoszint=kozjo;
            long long megmarad=z-kozjo;
            long long ertek=szint*kozjo;
            bool jokicsi=true;

            for(long long szsz=szint+1; szsz<=n; szsz++)
            {
                elozoszint*=belso;
                elozoszint=min(elozoszint, megmarad);
                megmarad-=elozoszint;
                ertek+=(szsz*elozoszint);
                if(ertek>S)
                {
                    jokicsi=false;
                    break;
                }
                if(megmarad==0)
                {
                    break;
                }
            }
            if(jokicsi)
            {
                ujo=kozjo-1;
            }
            else ejo=kozjo+1;

        }

        c[szint]=ejo;
        S-=(ejo*szint);
        z-=ejo;
    }

        //S csokken, z csokken
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=c[i]; j++)
            {
                cnt++;
                lev[cnt]=i;
                w[i].push_back(cnt);
            }
        }
        int maxim=(int)belso;
        for(int i=1; i<=n; i++)
        {
            if(i==n || w[i+1].size()==0) break;
            int mmm=0;
            bool kesz=false;
            for(int j=0; j<w[i].size(); j++)
            {
                for(int kor=1; kor<=maxim; kor++)
                {
                    ans[w[i+1][mmm]]=w[i][j];
                    mmm++;
                    if(mmm==w[i+1].size())
                    {
                        kesz=true;
                        break;
                    }
                }
                if(kesz) break;
            }
        }
        cout<<"Yes"<<endl;
        for(int i=2; i<=n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;



    return 0;
}