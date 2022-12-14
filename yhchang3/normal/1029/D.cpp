#include<bits/stdc++.h>

using namespace std;
vector<int> v[11];
int a[200010];
int dig[200010];
int main(){
    int n,k,digans,x;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long int ex[11],rem,ans = 0;
    ex[0]=1;
    for(int i=1;i<=10;i++)
        ex[i]=ex[i-1]*10%k;
    for(int i=1;i<=n;i++){
        digans=0;
        x=a[i];
        while(x){
            digans++;
            x/=10;
        }
        dig[i]=digans;
        v[digans].push_back(a[i]%k);
    }
    for(int i=1;i<=10;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            rem=(k-((long long int) a[i]*ex[j])%k)%k;
            ans+=int(upper_bound(v[j].begin(),v[j].end(),rem)-lower_bound(v[j].begin(),v[j].end(),rem));
        }
        if(!(((long long int)a[i]*ex[dig[i]]+a[i])%k))  ans--;
    }
    
    cout<<ans<<endl;
    
}