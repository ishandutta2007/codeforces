#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <stdio.h>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
using namespace std;
#define taskname "E"
string s;
vector <string> v;
map <string, int> M;
struct operation{
    bool motngoi;
    int varleft;
    int var1, var2;
    string svar1, svar2;
    int oper;
} op[5001];
int value[5001];
int msize=0;
int n, m;
int f[5001][2];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    cin.ignore();
    FOR(i, 1, n){
        getline(cin, s);
        stringstream ss(s);
        v.clear();
        while(ss>>s)
            v.push_back(s);
        M[v[0]]=++msize;
        op[i].varleft=msize;
        if(v.size()==3){
            op[i].motngoi=1;
            if(isdigit(v[2][0])){
                op[i].var1=-1;
                op[i].svar1=v[2];
            }
            else if(isalpha(v[2][0]))
                op[i].var1=M[v[2]];
        }
        else{
            op[i].motngoi=0;
            if(isdigit(v[2][0])){
                op[i].var1=-1;
                op[i].svar1=v[2];
            }
            else if(isalpha(v[2][0]))
                op[i].var1=M[v[2]];
            if(isdigit(v[4][0])){
                op[i].var2=-1;
                op[i].svar2=v[4];
            }
            else if(isalpha(v[4][0]))
                op[i].var2=M[v[4]];
            if(v[3][0]=='A')
                op[i].oper=1;
            else if(v[3][0]=='O')
                op[i].oper=2;
            else
                op[i].oper=3;
        }
    }
    FOR(i, 1, m){
        FOR(bit, 0, 1){
            FOR(j, 1, n){
                if(op[j].motngoi){
                    if(op[j].var1==-1)
                        value[op[j].varleft]=op[j].svar1[i-1]-48;
                    else if(op[j].var1==0)
                        value[op[j].varleft]=bit;
                    else
                        value[op[j].varleft]=value[op[j].var1];
                }
                else{
                    if(op[j].var1==-1)
                        value[op[j].varleft]=op[j].svar1[i-1]-48;
                    else if(op[j].var1==0)
                        value[op[j].varleft]=bit;
                    else
                        value[op[j].varleft]=value[op[j].var1];
                    if(op[j].oper==1){//AND
                        if(op[j].var2==-1)
                            value[op[j].varleft]&=op[j].svar2[i-1]-48;
                        else if(op[j].var2==0)
                            value[op[j].varleft]&=bit;
                        else
                            value[op[j].varleft]&=value[op[j].var2];
                    }
                    else if(op[j].oper==2){//OR
                        if(op[j].var2==-1)
                            value[op[j].varleft]|=op[j].svar2[i-1]-48;
                        else if(op[j].var2==0)
                            value[op[j].varleft]|=bit;
                        else
                            value[op[j].varleft]|=value[op[j].var2];
                    }
                    else{//XOR
                        if(op[j].var2==-1)
                            value[op[j].varleft]^=op[j].svar2[i-1]-48;
                        else if(op[j].var2==0)
                            value[op[j].varleft]^=bit;
                        else
                            value[op[j].varleft]^=value[op[j].var2];
                    }
                }
                f[i][bit]+=value[op[j].varleft];
            }
        }
    }
    FOR(i, 1, m){
        if(f[i][0]<=f[i][1])
            cout<<0;
        else cout<<1;
    }
    cout<<'\n';
    FOR(i, 1, m){
        if(f[i][0]>=f[i][1])
            cout<<0;
        else cout<<1;
    }
}