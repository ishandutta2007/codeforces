#include<bits/stdc++.h>

using namespace std;
int a[27];
int main(){
    int n,k,ans=0;
    string s;
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++)
        if(!a[s[i]-'a'+1])
            a[s[i]-'a'+1]++;
    int kk=1;
    for(int i=1;i<=26&&kk<=k;i++){
        if(!a[i])   continue;
        ans+=i++;
        kk++;
    }
    if(kk==k+1)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}