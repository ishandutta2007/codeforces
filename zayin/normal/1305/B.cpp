#include<bits/stdc++.h>
#define maxn 10050
using namespace std;

int n;
char s[maxn];

vector<int> L,R;

int main()  {
    scanf("%s",s+1),n=strlen(s+1);
    for (int i=1;i<=n;++i)
        if (s[i]=='(')
            L.push_back(i);
    for (int i=n;i;--i)
        if (s[i]==')')
            R.push_back(i);
    
    // cout<<L[0]<<" "<<R.back()<<endl;
    if (!L.size()||!R.size()||L[0]>R[0])
        puts("0");
    else    {
        puts("1");
        vector<int> pos;
        for (int i=0;i<L.size()&&i<R.size();++i)
            if (L[i]<R[i])
                pos.push_back(L[i]),pos.push_back(R[i]);
        sort(pos.begin(),pos.end());
        printf("%d\n",pos.size());
        for (int i:pos)
            printf("%d ",i);
    }
    return 0;
}