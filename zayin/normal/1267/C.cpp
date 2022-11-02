#include<bits/stdc++.h>
#define maxn 2050
using namespace std;

int n,d[maxn];
vector<pair<int,int> > E;

void join(int u,int v)  {
    cerr<<"join:"<<u<<" "<<v<<endl;

    --d[u],--d[v];
    E.emplace_back(u,v);
}

int main()  {
    // freopen("c.in","r",stdin);

    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",d+i);

    while (1)   {
        vector<int> vert;
        for (int i=1;i<=n;++i)
            if (d[i])
                vert.push_back(i);
        if (!vert.size()) break;
        if (vert.size()==1) return puts("-1"),0;

        cerr<<"size:"<<vert.size()<<endl;

        sort(vert.begin(),vert.end(),[&](int i,int j) {
            return d[i]>d[j];
        });

        int u=vert.back();
        if (d[u]==1)    {
            cerr<<"type 1"<<endl;

            int v=vert.front();
            for (int i=0;i<vert.size();++i) 
                if (d[vert[i]]%2&&d[vert[i]]>1)
                    v=vert[i];
            if (d[v]==1&&vert.size()>2) return puts("-1"),0;
            join(u,v);
        } else  
        if (d[u]==2)    {
            if (vert.size()<3) return puts("-1"),0;
            if (d[vert.front()]==2) {
                cerr<<"type 2"<<endl;
                for (int i=0;i<vert.size();++i)
                    join(vert[i],vert[(i+1)%vert.size()]);
            } else  {
                cerr<<"type 3"<<endl;
                if (d[vert[vert.size()-2]]!=2)
                    return puts("-1"),0;
                vert.pop_back();
                int v=vert.back();
                join(vert.front(),v);
                join(vert.front(),u);
                join(u,v);
            }

        } else return puts("-1"),0;
    }

    printf("%d\n",E.size());
    for (pair<int,int> e:E)
        printf("2 %d %d\n",e.first,e.second);
    return 0;
}