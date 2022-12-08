#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int N;

long long jurys[500];

int main()
{
    memset(jurys,0,sizeof(jurys));
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int s[12];
    s[0]=100;
    for(int i=1; i<12; i++)
        s[i]=s[i-1]+days[i-1];

    cin >> N;

    for(int i=0; i<N; i++)
    {
        int m, d, p, t;
        cin >> m >> d >> p >> t;
        int start=s[m-1]+d;
        for(int j=1; j<=t; j++)
            jurys[start-j]+=p;
    }

    long long best=0;
    for(int i=0; i<500; i++)
        best=max(best,jurys[i]);

    cout << best << endl;
}