#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; string s;
    cin>>n>>s;
    for(int i='z';i>'a';i--) //ichar
        for(int j=0;j<s.length();j++)
            if(s[j]==i&&(j>0&&s[j-1]==i-1 || j<s.length()-1&&s[j+1]==i-1))//
                s.erase(j,1),j=-1;//s[j]j-1
    cout<<n-s.length()<<endl;//
    return 0;
}