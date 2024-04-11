#include <iostream>
using namespace std;
int cc[26], dc=0, qmc=0, ok=0;
int main(){
    string s;
    cin>>s;
    int ml=s.length()-26+1;
    if(s.length()<26)
        cout<<-1;
    else{
        for(int i=0; i<26; i++){
            if(s[i]!='?'){
                cc[s[i]-65]++;
                if(cc[s[i]-65]==1) dc++;
            }
            else qmc++;
        }
        if(qmc+dc>25){
            int x=0, y=0;
            while(y<26){
                if(s[y]=='?'){
                    while(cc[x]) x++;
                    s[y]=char(x+65);
                    if(x<25)
                        x++;
                }
                y++;
            }
             for(int j=0; j<s.length(); j++)
                        if(s[j]=='?')
                            s[j]='A';
            ok=1;
        }
        else{
            for(int i=1; i<ml; i++){
                if(s[i-1]!='?'){
                    cc[s[i-1]-65]--;
                    if(cc[s[i-1]-65]==0)
                        dc--;
                }
                else qmc--;
                if(s[i+25]!='?'){
                    cc[s[i+25]-65]++;
                    if(cc[s[i+25]-65]==1)
                        dc++;
                }
                else qmc++;
                if(qmc+dc>25){
                    int x=0, y=i;
                    while(y<i+26){
                        while(cc[x]) x++;
                        if(s[y]=='?'){
                            s[y]=char(x+65);
                            x++;
                        }
                        y++;
                    }
                    for(int j=0; j<s.length(); j++)
                        if(s[j]=='?')
                            s[j]='A';
                    ok=1;
                    break;
                }
            }
        }
        if(ok) cout<<s;
        else cout<<-1;
    }
}