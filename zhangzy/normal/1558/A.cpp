#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int T, a, b;
    for (cin>>T;T--;){
        cin>>a>>b;
        set<int>S;
        if (1){
            int n=a+b;
            int aa=(n+1)/2, bb=n-aa;
            for (int i=0;i<=aa;++i){
                if (aa-i>=0&&a-i>=0&&b-aa+i>=0){
                    int ans=aa-i+a-i;
                    S.insert(ans);
                }
            }
        }
        swap(a,b);
        if (1){
            int n=a+b;
            int aa=(n+1)/2, bb=n-aa;
            for (int i=0;i<=aa;++i){
                if (aa-i>=0&&a-i>=0&&b-aa+i>=0){
                    int ans=aa-i+a-i;
                    S.insert(ans);
                }
            }
        }
        cout<<S.size()<<endl;
        for (auto o:S) printf("%d ",o);
        puts("");
    }
}