#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n,a[maxn];

int cnt[maxn],mex;

void add(int x) {
    ++cnt[x];
    while (cnt[mex]) ++mex;
}

void del(int x) {
    --cnt[x];
    if (x<mex)
        mex=x;
}

int calc() {
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<n;++i)
        ++cnt[a[i]];
    for (int i=0;;++i)
        if (!cnt[i])
            return i;
}

int main()  {

    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=0;i<n;++i)
            scanf("%d",a+i),add(a[i]);
        
        vector<int> ans;

        auto deal=[&]() {
            while (1)   {
                int mex=calc();
                if (mex==n) break;
                ans.push_back(mex);
                a[mex]=mex;
            };
        };
        deal();

        for (int i=0,j;i<n;++i)   {
            if (a[i]==i) continue;
            int mex=calc();
            assert(mex==n);

            for (j=0;j<n;++j)
                if (a[j]==i)
                    break;
            ans.push_back(j),a[j]=n;
            deal();
        }

        assert(ans.size()<=2*n);

        printf("%d\n",ans.size());
        for (int x:ans) printf("%d ",x+1);
        puts("");
    }
    return 0;
}