#include<bits/stdc++.h>
using namespace std;

int T;

string s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        bool ok=1;
        while(s.size())
        {
            int x=s.back(),c=1;
            s.pop_back();
            while(s.size()&&s.back()==x)
                s.pop_back(),c++;
            if(c==1)
                ok=0;
        }
        puts(ok?"YES":"NO");
    }
}