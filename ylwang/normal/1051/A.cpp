#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll t,cnt[5];
bool flag;
string s;
inline void _read(ll &x){
    x=0;
    ll f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    x*=f;
    return;
}
inline void _print(ll x){
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10)
        _print(x/10);
    putchar(x%10+'0');
    return;
}
inline ll f(char c){
    if('0'<=c&&c<='9')
        return 0;
    else if('A'<=c&&c<='Z')
        return 1;
    else
        return 2;
}
int main(){
    _read(t);
    while(t--)
    {
        flag=0;
        cnt[0]=cnt[1]=cnt[2]=0;
        cin>>s;
        for(ll i=0;i<s.size();i++)
            cnt[f(s[i])]++;
        if(cnt[0]&&cnt[1]&&cnt[2])
            cout<<s;
        else if(!cnt[0]&&cnt[1]&&cnt[2])
        {
            for(ll i=0;i<s.size();i++)
                if(cnt[f(s[i])]>1&&!flag)
                {
                    putchar('0');
                    flag=1;
                }
                else
                    putchar(s[i]);  
        }
        else if(cnt[0]&&!cnt[1]&&cnt[2])
        {
            for(ll i=0;i<s.size();i++)
                if(cnt[f(s[i])]>1&&!flag)
                {
                    putchar('A');
                    flag=1;
                }
                else
                    putchar(s[i]);  
        }
        else if(cnt[0]&&cnt[1]&&!cnt[2])
        {
            for(ll i=0;i<s.size();i++)
                if(cnt[f(s[i])]>1&&!flag)
                {
                    putchar('a');
                    flag=1;
                }
                else
                    putchar(s[i]);      
        }
        else if(!cnt[0]&&!cnt[1]&&cnt[2])
        {
            putchar('0');
            putchar('A');
            for(ll i=2;i<s.size();i++)
                putchar(s[i]);  
        }
        else if(!cnt[0]&&cnt[1]&&!cnt[2])
        {
            putchar('0');
            putchar('a');
            for(ll i=2;i<s.size();i++)
                putchar(s[i]);  
        }
        else if(cnt[0]&&!cnt[1]&&!cnt[2])
        {
            putchar('A');
            putchar('a');
            for(ll i=2;i<s.size();i++)
                putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}