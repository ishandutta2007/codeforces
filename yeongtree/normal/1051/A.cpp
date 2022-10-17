#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int T; cin>>T;
    while(T--)
    {
        string s; cin>>s;
        int n=s.size();
        int fx=n,fy=n,fz=n; int nx=0,ny=0,nz=0;
        for(int i=0;i<n;i++)
        {
            if(65<=s[i]&&s[i]<=90) {fx=min(fx,i); nx++;}
            else if(97<=s[i]&&s[i]<=122) {fy=min(fy,i); ny++;}
            else if(48<=s[i]&&s[i]<=57) {fz=min(fz,i); nz++;}
        }
        if(nx==0&&ny==0) {s[0]='A'; s[1]='a';}
        else if(ny==0&&nz==0) {s[0]='a'; s[1]='0';}
        else if(nz==0&&nx==0) {s[0]='0'; s[1]='A';}
        else if(nx==0)
        {
            if(ny==1) s[fz]='A';
            else s[fy]='A';
        }
        else if(ny==0)
        {
            if(nz==1) s[fx]='a';
            else s[fz]='a';
        }
        else if(nz==0)
        {
            if(nx==1) s[fy]='0';
            else s[fx]='0';
        }
        cout<<s<<endl;
    }
    return 0;
}