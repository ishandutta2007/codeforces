#include <bits/stdc++.h>
using namespace std;

int a[56];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    set<int> st;
    vector<int> ans;
    for (int i=n;i>=1;i--)
    {
        if (st.find(a[i]) == st.end())
        {
            ans.push_back(a[i]);
        }
        st.insert(a[i]);
    }
    reverse(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for (int i=0;ans.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}