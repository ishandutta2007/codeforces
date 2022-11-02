#include <bits/stdc++.h>
using namespace std; 

struct node{
    int var,arr,sub;
    bool operator < (const node& cmp){
        return var < cmp.var;
    }
    void set(int v,int a,int s){
        var = v;
        arr = a;
        sub = s;
    }
};

node num[200005];
int pri[200005];

int main(){
    int k,tot = 0;
    cin>>k;
    for (int i=1;i<=k;i++){
        int n;
        cin>>n;
        int sum = 0;
        for (int j=1;j<=n;j++){
            int read;
            cin>>read;
            sum += read;
            pri[j] = read;
        }
        for (int j=1;j<=n;j++){
            num[++tot].set(sum - pri[j],i,j);
        }
    }
    sort(num + 1,num + tot + 1);
    for (int i=1;i<tot;i++){
        if (num[i].var == num[i+1].var){
            if (num[i].arr != num[i+1].arr){
                puts("YES");
                cout<<num[i  ].arr<<' '<<num[i  ].sub<<endl;
                cout<<num[i+1].arr<<' '<<num[i+1].sub<<endl;
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}