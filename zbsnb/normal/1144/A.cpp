#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100010];
char b[1010];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        cin>>b;
        int len=strlen(b);
        sort(b,b+len);
        char oldl=b[0];
        int flg=1;
        for(int i=1;i<len;i++)
        {
            oldl++;
            if(b[i]!=oldl)
            {
                cout<<"No"<<endl;
                flg=0;
                break;
            }
        }
        if(flg)
        {
            cout<<"Yes"<<endl;
        }
    }
}