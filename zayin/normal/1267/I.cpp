#include<bits/stdc++.h>
#define maxn 150
using namespace std;

int winner[maxn];
vector<int> loser,a;

int pri[maxn],le[maxn][maxn];

int ask(int i,int j)   {
    cout<<"? "<<i<<" "<<j<<endl;
    // return le[i][j];
    string s;
    cin>>s;
    return s=="<";
}

int main()  {
    int T,n;
    cin>>T;
    while (T--) {
        cin>>n;
        // for (int i=0;i<2*n;++i)   scanf("%d",pri+i);
        // for (int i=0;i<2*n;++i)
        //     for (int j=i+1;j<2*n;++j)
        //         le[pri[i]][pri[j]]=1;

        a.clear();
        loser.clear();
        for (int i=1;i<=2*n;i+=2)   {
            // cout<<"i i+1:"<<i<<" "<<ask(i,i+1)<<endl;
            if (ask(i,i+1))
                winner[i]=i+1,loser.push_back(i);
            else
                winner[i+1]=i,loser.push_back(i+1);
        }

        sort(loser.begin(),loser.end(),[&](int i,int j){
            return ask(i,j);
        });

        // cout<<"------"<<endl;
        
        for (int i=0;i<n-1;++i)
            a.push_back(loser[i]),a.push_back(winner[loser[i]]);
        
        sort(a.begin(),a.end(),[&](int i,int j){
            return ask(i,j);
        });

        // cout<<a[n-2]<<endl;
        // cout<<"a:"; for (int i:a) cout<<i<<" "; cout<<endl;

        // cout<<loser[n-1]<<" "<<a[n-2]<<endl;
        if (a[n-2]==loser[n-2])
            ask(loser[n-1],a[n-1]);

        cout<<"!"<<endl;
    }
    return 0;
}