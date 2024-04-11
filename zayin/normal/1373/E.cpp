#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string min(string a,string b)   {
    return a.size()<b.size()||(a.size()==b.size()&&a<b)?a:b;
}

string make(int sum,int x)  {
    string t;
    for (int i=0;sum>=9;++i)   {
        if (!i&&x)
            t+="8",sum-=8;
        else
            t+="9",sum-=9;
    }
    if (sum) t+=(char)('0'+sum);
    reverse(t.begin(),t.end());
    return t;
}

int main()  {
    int T;
    cin>>T;
    while (T--) {
        int n,k;
        cin>>n>>k;++k;
        string ans(200,'1');

        for (int x=0;x<=150;++x) {
            if (n<k*x*9) continue;
            for (int y=0;y<=9;++y)  {
                int sum=0,f=0;
                for (int i=0;i<k;++i)   {
                    if (i+y<10)
                        sum+=x*9+i+y;
                    else
                        f=1,sum+=1+i+y-10;
                }

                if (n<sum||(n-sum)%k) continue;
                string t=make((n-sum)/k,f);
                // cout<<x<<" "<<y<<":"<<t<<endl;
                for (int i=0;i<x;++i) t+="9";
                t+=(char)(y+'0');
                ans=min(ans,t);
            }
        }

        if (ans.size()==200)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }   
    return 0;
}