#include <bits/stdc++.h>
using namespace std;
string S;
string T;
int SB[100009];
int Sh[100009];
int TB[100009];
int Th[100009];
int Q;
int x, y, z, v;
string answer="";
bool Lehet(int nb, int na, int kb, int ka)
{
    if(nb%2!=kb%2) return false;
    if(nb>kb) return false;
    if(na<ka) return false;
    if(nb==kb)
    {
        if(na%3==ka%3) return true;
        else return false;
    }
    if(nb==0)
    {
        if(kb>0 && na==ka) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>S>>T;
    for(int i=0; i<S.size(); i++)
    {
        if(S[i]=='C') S[i]='B';
        if(S[i]=='B')
        {
            SB[i+1]=SB[i]+1;
            Sh[i+1]=i+1;
        }
        else
        {
            SB[i+1]=SB[i];
            Sh[i+1]=Sh[i];
        }
    }
    for(int i=0; i<T.size(); i++)
    {
        if(T[i]=='C') T[i]='B';
        if(T[i]=='B')
        {
            TB[i+1]=TB[i]+1;
            Th[i+1]=i+1;
        }
        else
        {
            TB[i+1]=TB[i];
            Th[i+1]=Th[i];
        }
    }
    cin>>Q;
    for(int tt=1; tt<=Q; tt++)
    {
        cin>>x>>y>>z>>v;
        int SdarabB=SB[y]-SB[x-1];
        int SdarabA=y-x+1;
        SdarabA=min(SdarabA, y-Sh[y]);
        int TdarabB=TB[v]-TB[z-1];
        int TdarabA=v-z+1;
        TdarabA=min(TdarabA, v-Th[v]);
        if(Lehet(SdarabB, SdarabA, TdarabB, TdarabA)) answer+="1";
        else answer+="0";
    }
    cout<<answer<<endl;
    return 0;
}