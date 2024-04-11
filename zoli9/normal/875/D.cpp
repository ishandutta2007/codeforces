#include <bits/stdc++.h>
using namespace std;
int n;
int h[200009];
int jobbra[200009];
int balra[200009];
long long ans=0;
int main() {
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>h[i];
    }
    for(int i=n; i>=1; i--)
    {
        int index=i+1;
        while(1)
        {
            if(index==n+1)
            {
                jobbra[i]=n+1;
                break;
            }
            if((h[i]|h[index])>h[i])
            {
                jobbra[i]=index;
                break;
            }
            index=jobbra[index];
        }
    }
    for(int i=1; i<=n; i++)
    {
        int index=i-1;
        while(1)
        {
            if(index==0)
            {
                balra[i]=0;
                break;
            }
            if(h[i]==h[index] || (h[i]|h[index])>h[i])
            {
                balra[i]=index;
                break;
            }
            index=balra[index];
        }
    }
    long long osszes=(long long)n*(n-1)/2+n;
    for(int i=1; i<=n; i++)
    {
        long long rossz=(long long)(jobbra[i]-i)*(long long)(i-balra[i]);
        osszes-=rossz;
    }
    cout<<osszes<<endl;
    return 0;
}