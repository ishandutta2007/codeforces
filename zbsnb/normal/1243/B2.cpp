#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define ll long long 

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        char s1[1010],s2[1010];
        cin>>s1+1>>s2+1;
        int num[1000]={};
        for(int i=1;i<=n;i++){
            num[s1[i]]++,num[s2[i]]++;
        }
        int flg=0;
        for(int i='a';i<='z';i++){
            if(num[i]%2){
                flg=1;
                break;
            }
        }
        if(flg)cout<<"No"<<endl;
        else{
            int cnt=0;
            int p1[1000],p2[1000];
            for(int i=1;i<=n;i++){
                if(s1[i]==s2[i])continue;
                else{
                    int flg=0;
                    for(int j=i+1;j<=n;j++){
                        if(s1[j]==s1[i]){
                            swap(s1[j],s2[i]);
                            p1[++cnt]=j,p2[cnt]=i;
                            flg=1;
                            break;
                        }
                    }
                    if(!flg){
                        for(int j=i+1;j<=n;j++){
                            if(s2[j]==s1[i]){
                                swap(s1[j],s2[j]);
                                p1[++cnt]=j,p2[cnt]=j;
                                swap(s1[j],s2[i]);
                                p1[++cnt]=j,p2[cnt]=i;
                                break;
                            }
                        }
                    }
                }
            }
            cout<<"Yes"<<endl;
            cout<<cnt<<endl;
            for(int i=1;i<=cnt;i++){
                cout<<p1[i]<<" "<<p2[i]<<endl;
            }
        }
    }
}