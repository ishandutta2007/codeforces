#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    string res;
    int l=1, r=n;
    int last=-1e9;
    while(l<=r){
        if(max(a[l], a[r])<=last) break;
        if(a[l]==a[r]){
            int i=l;
            while((i<r)&&(a[i+1]>a[i])) i++;
            int j=r;
            while((j>l)&&(a[j-1]>a[j])) j--;
            if(i-l+1>r-j+1) for(int x=l; x<=i; x++) res+='L';
            else for(int x=r; x>=j; x--) res+='R';
            break;
        }
        else{
            if(min(a[l], a[r])>last){
                if(a[l]<a[r]){
                    last=a[l];
                    l++;
                    res+='L';
                }
                else{
                    last=a[r];
                    r--;
                    res+='R';
                }
            }
            else{
                if(a[l]<a[r]){
                    last=a[r];
                    r--;
                    res+='R';
                }
                else{
                    last=a[l];
                    l++;
                    res+='L';
                }
            }
        }
    }
    cout<<res.size()<<'\n';
    cout<<res;
}