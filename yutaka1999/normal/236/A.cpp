#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int q[26];
    memset(q,0,sizeof(q));
    
    string p;
    cin>>p;
    
    int s=p.size();
    
    int a;
    for(a=0;a<s;a++)
    {
        q[p[a]-'a']=1;
    }
    
    int b;
    int w=0;
    
    for(b=0;b<26;b++)
    {
        if(q[b]==1) w++;
    }
    
    if(w%2==0) cout<<"CHAT WITH HER!"<<endl;
    else cout<<"IGNORE HIM!"<<endl;
    
    return 0;
}