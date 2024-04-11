#include <bits/stdc++.h>
using namespace std;

map< int, map<int, int> > a1;
map< int, map<int, int> > a2;

int n, m, k;
int idx[200010], storage[200100], chk[210000];

int main()
{
    int i, j;
    scanf("%d%d%d", &n, &m, &k);
    for(i=0; i<m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a1[a][idx[a]]=b;
        a2[a][idx[a]]=c;
        a1[b][idx[b]]=a;
        a2[b][idx[b]]=c;
        idx[a]++;
        idx[b]++;
    }

    for(i=0; i<k; i++)
    {
        scanf("%d", &storage[i]);
        chk[storage[i]]=1;
    }
    int ans=-1; int cost=1000000001;
    for(i=0; i<k; i++)
    {
        for(j=0; j<idx[storage[i]]; j++)
        {
            if(a2[storage[i]][j]<cost&&chk[a1[storage[i]][j]]!=1)
            {
                ans=0;
                cost=a2[storage[i]][j];
            }
        }
    }
    printf("%d", ans!=-1?cost:ans);
}