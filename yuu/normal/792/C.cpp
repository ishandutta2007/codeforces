#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "C"
string s;
int n;
vector <int> pos[3];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>s;
    n=s.size();
    DFOR(i, n-1, 0)
        pos[s[i]%3].push_back(i);
    int nmod=(pos[2].size()*2+pos[1].size())%3;
    if(s.size()==1){
        if(s[0]%3)
            cout<<-1;
        else cout<<s[0];
        return 0;
    }
    if(s.size()==2){
        if(nmod==0)
            cout<<s;
        else{
            if(s[0]%3==0)
                cout<<s[0];
            else if(s[1]%3==0)
                cout<<s[1];
            else cout<<"-1";
        }
        return 0;
    }
    if(nmod==0)
        cout<<s;
    else if(nmod==1){
        if(!pos[1].empty()){
            string ss=s;
            ss.erase(ss.begin()+pos[1][0]);
            int i=0;
            while(i<ss.size()&&ss[i]=='0')
                i++;
            if(i==ss.size())
                cout<<"0";
            else{
                string sss=ss.substr(i);
                if(sss.size()>=s.size()-2)
                    cout<<sss;
                else{
                    if(pos[2].size()>=2){
                        ss=s;
                        ss.erase(ss.begin()+pos[2][0]);
                        ss.erase(ss.begin()+pos[2][1]);
                        int i=0;
                        while(i<ss.size()&&ss[i]=='0')
                            i++;
                        if(i==ss.size())
                            s="0";
                        else
                            s=ss.substr(i);
                        if(s.size()>sss.size())
                            cout<<s;
                        else cout<<sss;
                    }
                    else cout<<sss;
                }
            }
        }
        else if(pos[2].size()>=2){
            string ss=s;
            ss.erase(ss.begin()+pos[2][0]);
            ss.erase(ss.begin()+pos[2][1]);
            int i=0;
            while(i<ss.size()&&ss[i]=='0')
                i++;
            if(i==ss.size())
                s="0";
            else
                s=ss.substr(i);
            cout<<s;
        }
        else cout<<-1;
    }
    else{
        if(!pos[2].empty()){
            string ss=s;
            ss.erase(ss.begin()+pos[2][0]);
            int i=0;
            while(i<ss.size()&&ss[i]=='0')
                i++;
            if(i==ss.size())
                cout<<"0";
            else{
                string sss=ss.substr(i);
                if(sss.size()>=s.size()-2)
                    cout<<sss;
                else{
                    if(pos[1].size()>=2){
                        ss=s;
                        ss.erase(ss.begin()+pos[1][0]);
                        ss.erase(ss.begin()+pos[1][1]);
                        int i=0;
                        while(i<ss.size()&&ss[i]=='0')
                            i++;
                        if(i==ss.size())
                            s="0";
                        else
                            s=ss.substr(i);
                        if(s.size()>sss.size())
                            cout<<s;
                        else cout<<sss;
                    }
                    else cout<<sss;
                }
            }
        }
        else if(pos[1].size()>=2){
            string ss=s;
            ss.erase(ss.begin()+pos[1][0]);
            ss.erase(ss.begin()+pos[1][1]);
            int i=0;
            while(i<ss.size()&&ss[i]=='0')
                i++;
            if(i==ss.size())
                s="0";
            else
                s=ss.substr(i);
            cout<<s;
        }
        else cout<<-1;
    }
}