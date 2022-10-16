
 #include <bits/stdc++.h>
using namespace std;
int a[3];
const int f[]={0, 1, 2, 0, 2, 1, 0};
int main(){
    cin>>a[0]>>a[1]>>a[2];
    int ans=0;
    for(int start=0; start<7; start++){
        int res=0;
        int b[3];
        for(int i=0; i<3; i++) b[i]=a[i];
        for(int i=start; i; i=(i+1)%7){
            if(b[f[i]]){
                res++;
                b[f[i]]--;
            }
            else goto line0;
        }
        {
            int week_count=min(b[0]/3, min(b[1]/2, b[2]/2));
            res+=week_count*7;
            b[0]-=week_count*3;
            b[1]-=week_count*2;
            b[2]-=week_count*2;
        }
        for(int i=0; i<7; i++){
            if(b[f[i]]){
                res++;
                b[f[i]]--;
            }
            else goto line0;
        }
        line0:;
        ans=max(ans, res);
    }
    cout<<ans<<'\n';
}