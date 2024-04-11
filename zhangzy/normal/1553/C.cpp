#include<bits/stdc++.h>
using namespace std;


int T;
char s[22];

int main(){
    for (cin>>T;T--;){
        cin>>s;
        int ans=233;
        for (int S=0;S<(1<<10);++S){
            int ok=1;
            for (int i=0;i<10;++i){
                int c=S>>i&1;
                if (s[i]=='1'&&c==0) ok=0;
                if (s[i]=='0'&&c==1) ok=0;
            }
            if (ok==0) continue;
            int a=0, b=0, res=10;
            for (int i=0;i<10;++i){
                int c=S>>i&1;
                if (i%2==0){
                    a+=c;
                    int lasb=5-(i+1)/2, lasa=4-i/2;
                    if (b+lasb<a||a+lasa<b){
                        res=i+1; break;
                    }
                }else{
                    b+=c;
                    int lasb=5-(i+1)/2, lasa=4-i/2;
                    if (b+lasb<a||a+lasa<b){
                        res=i+1; break;
                    }
                } 
            }
            ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
}