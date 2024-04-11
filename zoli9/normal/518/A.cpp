#include <iostream>
using namespace std;
string s1, s2;
char veg[105];
int main()
{
    cin>>s1>>s2;
    int h=s1.size();
    int j=h-1;
    while(j>=0 && s1[j]=='z')
    {
        veg[j]='a';
        j--;
    }
    veg[j]=char(s1[j]+1);
    for(int i=j-1; i>=0; i--)
    {
        veg[i]=s1[i];
    }
    bool v=false;
    for(int i=0; i<h; i++)
    {
        if(veg[i]!=s2[i])
        {
            v=true;
        }
    }
    if(v)
        for(int i=0; i<h; i++)
    {
        cout<<veg[i];
    }
    else
    {
        cout<<"No such string";
    }
    return 0;
}