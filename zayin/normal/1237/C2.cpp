#include<bits/stdc++.h>
#define maxn 50050
using namespace std;

int n;
struct node {
    int x,y,z;
    bool operator < (const node& N) const   {
        if (x!=N.x) return x<N.x;
        if (y!=N.y) return y<N.y;
        if (z!=N.z) return z<N.z;
        return 0;
    }
    bool cmp1(const node& N) const  {
        return x==N.x&&y==N.y;
    }
    bool cmp2(const node& N) const  {
        return x==N.x;
    }
} P[maxn];
int pos[maxn];

vector<int> cand1,cand2;

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  {
        scanf("%d%d%d",&P[i].x,&P[i].y,&P[i].z);
        cand1.push_back(i);
    }
    sort(cand1.begin(),cand1.end(),[&](const int& i,const int& j)   {
        return P[i]<P[j];
    });
    // for (int i=0;i<cand1.size();++i)  
    //     cout<<cand1[i]<<" ";
    // cout<<endl;

    for (int i=0;i<cand1.size();++i)  {
        if (cand2.size()&&P[cand1[i]].cmp1(P[cand2.back()])) {
            cout<<cand2.back()<<" "<<cand1[i]<<endl;
            cand2.pop_back();
        } else cand2.push_back(cand1[i]);
    }
    cand1.clear();
    // cout<<"2:";
    // for (int i=0;i<cand2.size();++i)  
    //     cout<<cand2[i]<<" ";
    // cout<<endl;
    for (int i=0;i<cand2.size();++i)    {
        if (cand1.size()&&P[cand2[i]].cmp2(P[cand1.back()]))   {
            cout<<cand1.back()<<" "<<cand2[i]<<endl;
            cand1.pop_back();
        } else cand1.push_back(cand2[i]);
    }
    assert(~cand1.size()&1);
    // cout<<"1:";
    // for (int i=0;i<cand1.size();++i)  
    //     cout<<cand1[i]<<" ";
    // cout<<endl;
    for (int i=0;i<cand1.size();i+=2)
        cout<<cand1[i]<<" "<<cand1[i+1]<<endl;
    return 0;
}