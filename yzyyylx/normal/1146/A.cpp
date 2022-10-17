#include<bits/stdc++.h>
using namespace std;

int ans;
string str;

int main()
{
    int i,j;
    cin>>str;
    for(i=0;i<str.size();i++) if(str[i]=='a') ans++;
    cout<<min(ans*2-1,(int)str.size());
}