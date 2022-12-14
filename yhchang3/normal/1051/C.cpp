#include<bits/stdc++.h>
using namespace std;
int s[101];
int a[101];
int ty[101];
int ta,tb;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        a[s[i]]++;
    }
    for(int i=1;i<=100;i++){
        if(a[i]==1){
            ta++;
            ty[i]=1;
        }else if(a[i]==2){
            ty[i]=-1;
        }
        else if(a[i]>0){
            tb++;
            ty[i]=2;
        }
    }
    if(tb>0){
        cout<<"YES"<<endl;
        if(ta%2){
            for(int i=1,j=ta/2;j>0;i++){
                if(ty[i]!=1)    continue;
                ty[i]=3;
                j--;
            }
            for(int k=1;k<=100;k++){
                if(ty[k]==2){
                    ty[k]=4;
                    break;
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(ty[s[i]]==1||ty[s[i]]==2)
                    cout<<'A';
                else if(ty[s[i]]==3)
                    cout<<'B';
                else if(cnt==0&&ty[s[i]]==4){
                    cout<<'B';
                    cnt++;
                }
                else cout<<'A';
            }
        }
        else{
            for(int i=1,j=ta/2;j>0;i++){
                if(ty[i]!=1)    continue;
                ty[i]=3;
                j--;
            }
            for(int i=1;i<=n;i++){
                if(ty[s[i]]==3)
                    cout<<'B';
                else
                    cout<<'A';
            }
        }
    }
    else{
        if(ta%2)
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=1,j=ta/2;j>0;i++){
                if(ty[i]!=1)    continue;
                ty[i]=3;
                j--;
            }
            for(int i=1;i<=n;i++){
                if(ty[s[i]]==3)
                    cout<<'B';
                else
                    cout<<'A';
            }
        }
    }
}