#include<bits/stdc++.h>
using namespace std;

string s;
int a[100];
int cap,low,dig;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        cap=dig=low=0;
        for(int j=0;j<s.size();j++){
            if(s[j]>='A'&&s[j]<='Z'){
                a[j]=1;
                cap++;
            }
            else if(s[j]>='a'&&s[j]<='z'){
                a[j]=2;
                low++;
            }
            else{
                a[j]=3;
                dig++;
            }
        }
        if(cap){
            if(low){
                if(dig){
                    cout<<s<<endl;
                }
                else{
                    if(cap==1){
                        int z=0;
                        while(a[z]!=2)
                            z++;
                        s[z]='1';
                        cout<<s<<endl;
                    }
                    else{
                        int z=0;
                        while(a[z]!=1)
                            z++;
                        s[z]='1';
                        cout<<s<<endl;
                    }
                }
            }
            else{
                if(dig){
                    if(cap==1){
                        int z=0;
                        while(a[z]!=3)
                            z++;
                        s[z]='a';
                        cout<<s<<endl;
                    }
                    else{
                        int z=0;
                        while(a[z]!=1)
                            z++;
                        s[z]='a';
                        cout<<s<<endl;
                    }
                }
                else{
                    s[0]='1';
                    s[1]='a';
                    cout<<s<<endl;
                }
            }
        }
        else{
            if(low){
                if(dig){
                    if(low==1){
                        int z=0;
                        while(a[z]!=3)
                            z++;
                        s[z]='A';
                        cout<<s<<endl;
                    }
                    else{
                        int z=0;
                        while(a[z]!=2)
                            z++;
                        s[z]='A';
                        cout<<s<<endl;
                    }
                }
                else{
                    s[0]='1';
                    s[1]='A';
                    cout<<s<<endl;
                }
            }
            else{
                s[0]='A';
                s[1]='a';
                cout<<s<<endl;
            }
        }
    }
}