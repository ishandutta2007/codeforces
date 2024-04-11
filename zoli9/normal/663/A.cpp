#include <bits/stdc++.h>
using namespace std;
long long n, mennyi;
vector<char> s;
int pl, mi;
vector<long long> poz, neg;
int main()
{
    ios::sync_with_stdio(false);
    while(1)
    {
        char cc;
        cin>>cc;
        s.push_back(cc);
        if(cc=='+') pl++;
        else if(cc=='-') mi++;
        if(cc=='=') break;
    }
    cin>>mennyi;
    n=mennyi;
    if(s[0]=='?') pl++;
    long long maximalis=pl*n-mi;
    if(mennyi>maximalis)
    {
        cout<<"Impossible";
        return 0;
    }
    long long minimalis=pl-n*mi;
    if(mennyi<minimalis)
    {
        cout<<"Impossible";
        return 0;
    }
    cout<<"Possible"<<endl;
    long long akt=pl-mi;
    for(int i=1; i<=pl; i++)
    {
        if(akt+mennyi-1<=mennyi)
        {
            akt+=(mennyi-1);
            poz.push_back(mennyi-1);
        }
        else if(akt>mennyi)
        {
            poz.push_back(0);
        }
        else
        {
            poz.push_back(mennyi-akt);
            akt=mennyi;
        }
    }
    for(int i=1; i<=mi; i++)
    {
        if(akt-(mennyi-1)>=mennyi)
        {
            akt-=(mennyi-1);
            neg.push_back(mennyi-1);
        }
        else
        {
            neg.push_back(akt-mennyi);
            akt=mennyi;
        }
    }
    int pozcnt=0;
    int negcnt=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='?')
        {
            if(i==0)
            {
                cout<<poz[pozcnt]+1<<" ";
                pozcnt++;
            }
            else if(s[i-1]=='+')
            {
                cout<<poz[pozcnt]+1<<" ";
                pozcnt++;
            }
            else
            {
                cout<<neg[negcnt]+1<<" ";
                negcnt++;
            }
        }
        else
        {
            cout<<s[i]<<" ";
        }
    }
    cout<<mennyi;
    return 0;
}