#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL ans[31];

void build()
{
    for (int n=1;30>=n;n++)
    {
        set<LL> st;
        for (int i=0;n>=i;i++)
        {
            for (int j=0;n>=j;j++)
            {
                for (int k=0;n>=k;k++)
                {
                    int l=n-i-j-k;
                    if (l < 0) continue;
                    st.insert(i+5*j+10*k+50*l);
                }
            }
        }
        ans[n] = st.size();
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    build();
    if (n <= 30) printf("%lld\n",ans[n]);
    else printf("%lld\n",ans[30] + (n-30)*(ans[30] - ans[29]) );
}