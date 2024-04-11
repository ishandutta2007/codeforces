#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
string str[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        static char buff[5];
        scanf("%s",buff);
        str[i]=buff;
    }
    for(int i=1;i<=n;i++)
    {
        string tmp=str[i];
        reverse(tmp.begin(),tmp.end());
        if(tmp==str[i])return 0*printf("YES\n");
    }
    set<string> st,st_2;
    for(int i=1;i<=n;i++)
    {
        string tmp=str[i];
        reverse(tmp.begin(),tmp.end());
        if(st.find(tmp)!=st.end()) // 2+2, 3+3
            return 0*printf("YES\n");
        if(str[i].size()==2u)
        {
            if(st_2.find(tmp)!=st_2.end()) // 3+2
                return 0*printf("YES\n");
        }
        if(str[i].size()==3u)
        {
            if(st.find(tmp.substr(0,2))!=st.end()) // 2+3
                return 0*printf("YES\n");
            st_2.insert(str[i].substr(0,2));
        }
        st.insert(str[i]);
    }
    return 0*printf("NO\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}