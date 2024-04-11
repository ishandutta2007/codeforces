#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    int i,p;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p);
        if(p) return puts("HARD"),0;
    }
    puts("EASY");
}