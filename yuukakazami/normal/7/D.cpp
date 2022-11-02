#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int seed=1333331;
const int Max_Num=5000000+100;
char Str[Max_Num];
int L;

int Pow[Max_Num];
void Init_Power()
{
    Pow[0]=1;
    for(int pow=1;pow<Max_Num;pow++)
        Pow[pow]=Pow[pow-1]*seed;
}

struct Hasher
{
    int H[Max_Num],Cnt;

    void Doit(char*A,int _Cnt)
    {
        Cnt=_Cnt;
        H[0]=0;
        for(int i=1;i<=Cnt;i++)
        {
            H[i]=H[i-1]*seed+A[i];
        }
    }

    int Ask(int l,int r)
    {
        return H[r]-H[l-1]*Pow[r-l+1];
    }
}For,Back;

void PrePare()
{
    Init_Power();
    For.Doit(Str,L);
    reverse(Str+1,Str+L+1);
    Back.Doit(Str,L);
}

inline int Rev(int p)
{
    return L-p+1;
}

bool Check_Palindrome(int l,int r)
{
    return For.Ask(l,r)==Back.Ask(Rev(r),Rev(l));
}

void Input_Data()
{
    scanf("%s",Str+1);
    L=strlen(Str+1);
}

int Deg[Max_Num]={};
void Work()
{
    long long Sum=0;
    for(int i=1;i<=L;i++)
    {
        if(Check_Palindrome(1,i))
        {
            Deg[i]=Deg[i/2]+1;
        }
        else
        {
            Deg[i]=0;
        }
        Sum+=Deg[i];
    }
    cout<<Sum<<endl;
}

void Solve()
{
    Input_Data();
    PrePare();
    Work();
}

int main()
{
    //freopen("in","r",stdin);
    Solve();
}