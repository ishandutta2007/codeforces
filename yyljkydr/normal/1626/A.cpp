#include<bits/stdc++.h>
using namespace std;

int T;

string s;

map<int,int>vis;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
}