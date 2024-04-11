#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int a[N];
int cnt[N];
bool used[N];

int main ()
{
    int n;
    scanf("%d",&n);
    int _=0;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        if (cnt[ a[i] ]) _++;
        cnt[ a[i] ]++;
    }
    set<int> st;
    for (int i=1;n>=i;i++)
    {
        if (cnt[i] == 0) st.insert(i);
    }
    printf("%d\n",_);
    vector<int> ans;
    for (int i=1;n>=i;i++)
    {
        if(cnt[ a[i] ] == 1)
        {
            ans.push_back(a[i]);
        }
        else if (used[ a[i] ])
        {
            ans.push_back(*st.begin());
            st.erase(st.begin());
        }
        else
        {
            if ((*st.begin()) > a[i])
            {
                used[ a[i] ] = 1;
                ans.push_back(a[i]);
            }
            else
            {
                cnt[ a[i] ]--;
                ans.push_back(*st.begin());
                st.erase(st.begin());
            }
        }
    }
    for (int i=0;ans.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}