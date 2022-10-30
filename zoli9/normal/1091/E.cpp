#include <bits/stdc++.h>
using namespace std;
long long n;
int darab[500009];
long long degsum=0;
int xres;
vector<int> inp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        inp.push_back(szam);
        darab[szam]++;
        degsum+=szam;
    }
    int elso=0;
    int utolso=n;
    while(elso<=utolso)
    {
        //cout<<"kor "<<elso<<" "<<utolso<<endl;
        int kozep=(elso+utolso)/2;
        darab[kozep]++;
        long long sum=0;
        vector<int> dd;
        vector<long long> kum;
        dd.push_back(-1);
        kum.push_back(0);
        for(int i=n; i>=0; i--)
        {
            for(int j=1; j<=darab[i]; j++)
            {
                dd.push_back(i);
                kum.push_back((long long)i+kum.back());
            }
        }
        long long minsum=0;
        long long tart=dd.size()-1;
        bool tulkicsi=false;
        for(long long i=(long long)dd.size()-1; i>=1; i--)
        {
            while(tart<dd.size() && dd[tart]>i)
            {
                tart++;
            }
            tart--;
            tart=max(0ll, tart);
            int eddig=max(tart, i);
            if(dd[i]>kozep)
            {
                if(kum[i]>i*(i-1)+kum[dd.size()-1]-kum[eddig]+i*(eddig-i))
                {
                    tulkicsi=true;
                    break;
                }
            }
            //minsum+=min((long long)dd[i], i);
        }
        //cout<<"**"<<endl;
        if(tulkicsi)
        {
            elso=kozep+1;
        }
        else
        {
            utolso=kozep-1;
        }
        darab[kozep]--;
    }
    if(degsum%2!=elso%2) elso++;

    bool lllehet=true;

    //cout<<elso<<endl;

    darab[elso]++;
        long long sum=0;
        vector<int> dd;
        vector<long long> kum;
        dd.push_back(-1);
        kum.push_back(0);
        for(int i=n; i>=0; i--)
        {
            for(int j=1; j<=darab[i]; j++)
            {
                dd.push_back(i);
                kum.push_back((long long)i+kum.back());
            }
        }
        long long minsum=0;
        long long tart=dd.size()-1;
        for(long long i=(long long)dd.size()-1; i>=1; i--)
        {
            while(tart<dd.size() && dd[tart]>i)
            {
                tart++;
            }
            tart--;
            tart=max(0ll, tart);

            int eddig=max(tart, i);
            //cout<<": "<<eddig<<endl;
            //cout<<kum[i]<<" "<<i*(i-1)+kum[dd.size()-1]-kum[eddig]+i*(eddig-i)<<endl;
                if(kum[i]>i*(i-1)+kum[dd.size()-1]-kum[eddig]+i*(eddig-i))
                {
                    lllehet=false;
                    break;

                }
        }
    darab[elso]--;
    if(!lllehet)
    {
        cout<<-1<<endl;
        return 0;
    }

    xres=elso;








    /*int elso2=0;
    int utolso2=n;
    while(elso2<=utolso2)
    {
        //cout<<"kor "<<elso<<" "<<utolso<<endl;
        int kozep=(elso2+utolso2)/2;
        darab[kozep]++;
        long long sum=0;
        vector<int> dd;
        vector<long long> kum;
        dd.push_back(-1);
        kum.push_back(0);
        for(int i=n; i>=0; i--)
        {
            for(int j=1; j<=darab[i]; j++)
            {
                dd.push_back(i);
                kum.push_back((long long)i+kum.back());
            }
        }
        long long minsum=0;
        bool tulnagy=false;
        for(long long i=(long long)dd.size()-1; i>=1; i--)
        {
            if(dd[i]<=kozep)
            {
                if(kum[i]>i*(i-1)+minsum)
                {
                    tulnagy=true;
                    break;
                }
            }
            minsum+=min((long long)dd[i], i);
        }
        //cout<<"**"<<endl;
        if(tulnagy)
        {
            utolso2=kozep-1;
        }
        else
        {
            elso2=kozep+1;
        }
        darab[kozep]--;
    }
    if(degsum%2!=utolso2%2) utolso2--;
    //cout<<elso<<" "<<utolso2<<endl;
    if(elso<=utolso2)
    {
        for(int u=elso; u<=utolso2; u+=2)
        {
            cout<<u<<" ";
        }
        cout<<endl;
        return 0;
    }
    else
    {
        cout<<-1<<endl;
        return 0;
    }*/
    for(int i=0; i<=n; i++)
    {
        darab[i]=0;
    }

    for(int i=1; i<=n; i++)
    {
        darab[n-inp[i-1]]++;
    }
    elso=0;
    utolso=n;
    while(elso<=utolso)
    {
        //cout<<"kor "<<elso<<" "<<utolso<<endl;
        int kozep=(elso+utolso)/2;
        darab[kozep]++;
        long long sum=0;
        vector<int> dd;
        vector<long long> kum;
        dd.push_back(-1);
        kum.push_back(0);
        for(int i=n; i>=0; i--)
        {
            for(int j=1; j<=darab[i]; j++)
            {
                dd.push_back(i);
                kum.push_back((long long)i+kum.back());
            }
        }
        long long minsum=0;
        long long tart=dd.size()-1;
        bool tulkicsi=false;
        for(long long i=(long long)dd.size()-1; i>=1; i--)
        {
            while(tart<dd.size() && dd[tart]>i)
            {
                tart++;
            }
            tart--;
            int eddig=max(tart, i);
            if(dd[i]>kozep)
            {
                if(kum[i]>i*(i-1)+kum[dd.size()-1]-kum[eddig]+i*(eddig-i))
                {
                    tulkicsi=true;
                    break;
                }
            }
            //minsum+=min((long long)dd[i], i);
        }
        //cout<<"**"<<endl;
        if(tulkicsi)
        {
            elso=kozep+1;
        }
        else
        {
            utolso=kozep-1;
        }
        darab[kozep]--;
    }
    elso=n-elso;
    if(degsum%2!=elso%2) elso--;
    for(int i=xres; i<=elso; i+=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}