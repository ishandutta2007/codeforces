#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
map<string,int> Map;
string S[]={"S","M","L","XL","XXL"};
int main()
{
    //freopen("in","r",stdin);
    Map["S"]=0;Map["M"]=1;Map["L"]=2;Map["XL"]=3;Map["XXL"]=4;
    int A[5]={};
    rep(i,5)cin>>A[i];
    int K;cin>>K;
    rep(i,K)
    {
        string a;cin>>a;
        int x=Map[a];
        for(int dist=0;;dist++)
        {
            if(x+dist<5&&A[x+dist])
            {
                A[x+dist]--;
                cout<<S[x+dist]<<endl;
                break;
            }
            if(x-dist>=0&&A[x-dist])
            {
                A[x-dist]--;
                cout<<S[x-dist]<<endl;
                break;
            }
        }
    }
}