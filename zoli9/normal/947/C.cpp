#include <bits/stdc++.h>
using namespace std;
int szam2[39];
long long hat2[32];
long long n;
long long A[300009];
long long P[300009];
class Pont
{
    public:
    Pont* nulla;
    Pont* egy;
    int bal, jobb;
    Pont(){bal=0; jobb=0;};
    void be(int index)
    {
        if(index==-1) return;
        if(szam2[index]==0)
        {
            if(bal==0) nulla=new Pont();
            bal++;
            nulla->be(index-1);
        }
        else
        {
            if(jobb==0) egy=new Pont();
            jobb++;
            egy->be(index-1);
        }
    }
    long long keres(int index)
    {
        if(index==-1) return 0;
        if(szam2[index]==0)
        {
            if(bal>0)
            {
                bal--;
                return nulla->keres(index-1);
            }
            else
            {
                jobb--;
                return egy->keres(index-1)+hat2[index];
            }
        }
        else
        {
            if(jobb>0)
            {
                jobb--;
                return egy->keres(index-1);
            }
            else
            {
                bal--;
                return nulla->keres(index-1)+hat2[index];
            }
        }
    }
};
Pont gyoker;
int main()
{
    ios::sync_with_stdio(false);
    hat2[0]=1;
    for(int i=1; i<=31; i++) hat2[i]=hat2[i-1]*(long long)(2);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>P[i];
    }
    for(int i=1; i<=n; i++)
    {
        long long kk=P[i];
        for(int j=0; j<30; j++)
        {
            szam2[j]=kk%2;
            kk/=2;
        }
        gyoker.be(30);
    }
    for(int i=1; i<=n; i++)
    {
        long long kk=A[i];
        for(int j=0; j<30; j++)
        {
            szam2[j]=kk%2;
            kk/=2;
        }
        cout<<gyoker.keres(30)<<" ";
    }
    cout<<endl;
    return 0;
}