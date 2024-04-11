#include <bits/stdc++.h>
using namespace std;

constexpr uint64_t unit=1;
uint64_t QueenAllowed[64];
constexpr int Dx[]={-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int Dy[]={-1, 0, 1, -1, 1, -1, 0, 1};
const string MoveName[]={"Up-Left", "Up", "Up-Right", "Left", "Right", "Down-Left", "Down", "Down-Right"};
map <string, int> MoveId;
uint64_t MoveAllowed[8];
vector <int> g[64];
uint64_t GetAllowed(int move, uint64_t Allowed){
    int shift=0;
    if(Dy[move]==-1){
        shift+=1;
    }
    else if(Dy[move]==1){
        shift-=1;
    }
    if(Dx[move]==-1){
        shift+=8;
    }
    else if(Dx[move]==1){
        shift-=8;
    }
    if(shift>0) Allowed>>=shift;
    else Allowed<<=-shift;
    return Allowed&MoveAllowed[move];
}
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve(){
    int Queen=rng()%64;
    uint64_t KingAllowed=0b1111111111111111111111111111111111111111111111111111111111111111;
    cerr<<Queen<<'\n';
    cerr<<"King Set: "<<bitset<64>(KingAllowed)<<'\n';
    cerr<<"King Set: "<<KingAllowed<<'\n';
    cout<<Queen/8+1<<' '<<Queen%8+1<<'\n';
    cout.flush();
    string s;
    bool follow=false;
    while(true){
        cin>>s;
        if(s=="Done"){
            return;
        }
        int id = MoveId[s];
        KingAllowed=GetAllowed(id, KingAllowed)&QueenAllowed[Queen];
        cerr<<id<<'\n';
        cerr<<"King Set: "<<bitset<64>(KingAllowed)<<'\n';
        cerr<<"Move Set: "<<bitset<64>(MoveAllowed[id])<<'\n';
        int cnt=__builtin_popcountll(KingAllowed);
        assert(cnt>0);
        //Reduce the number of position as much as possible
        if(cnt>1){
            int min_allowed=64;
            int min_method_count;
            int BestNewQueen=-1;
            for(int NewQueen: g[Queen]){
                int best_allowed=0;
                int best_method_count=0;
                for(int move=0; move<8; move++){
                    uint64_t NewKingAllowed=GetAllowed(move, KingAllowed)&QueenAllowed[NewQueen];
                    int count=__builtin_popcountll(NewKingAllowed);
                    if(count>best_allowed){
                        best_allowed=count;
                        best_method_count=1;
                    }
                    else if(count==best_allowed) best_method_count++;
                }
                if(best_allowed<min_allowed){
                    min_allowed=best_allowed;
                    min_method_count=best_method_count;
                    BestNewQueen=NewQueen;
                }
                else if((best_allowed==min_allowed)&&(best_method_count<min_method_count)){
                    min_method_count=best_method_count;
                    BestNewQueen=NewQueen;
                }
                else if ((best_allowed==min_allowed)&&(best_method_count==min_method_count)){
                    if(rng()%2) BestNewQueen=NewQueen;
                }
            }
            assert(BestNewQueen!=-1);
            Queen=BestNewQueen;
            int x=Queen/8;
            int y=Queen%8;
            cout<<x+1<<' '<<y+1<<'\n';
            cout.flush();
        }
        else{
            int pos=__builtin_ctzll(KingAllowed);
            int kx=pos/8;
            int ky=pos%8;
            int qx=Queen/8;
            int qy=Queen%8;
            cerr<<kx<<' '<<ky<<' '<<qx<<' '<<qy<<'\n';
            assert((kx!=qx)&&(ky!=qy));
            if(follow){
                qx+=Dx[id];
                qy+=Dy[id];
            }
            else if(abs(kx-qx)==1){
                qy=ky;
                follow=1;
            }
            else{
                qx=kx;
                if(abs(ky-qy)==1) follow=1;
            }
            cout<<qx+1<<' '<<qy+1<<'\n';
            cout.flush();
            Queen=qx*8+qy;
        }
    }
}
int main(){
    for (int i=0; i<64; i++){
        QueenAllowed[i]=0;
        int x=i/8;
        int y=i%8;
        for(int xx=0; xx<8; xx++){
            for(int yy=0; yy<8; yy++){
                if(xx==x||yy==y) continue;
                if(abs(xx-x)==abs(yy-y)) continue;
                int id=xx*8+yy;
                QueenAllowed[i]|=unit<<id;
            }
        }
    }
    for (int i=0; i<64; i++){
        int x=i/8;
        int y=i%8;
        for(int xx=0; xx<8; xx++){
            for(int yy=0; yy<8; yy++){
                if(xx==x||yy==y) goto line0;
                if(abs(x-xx)==abs(yy-y)) goto line0;
                continue;
                line0:;
                if(xx==x&&yy==y) continue;
                g[i].push_back(xx*8+yy);
            }
        }
    }
    for(int move=0; move<8; move++){
        MoveAllowed[move]=0;
        for(int i=0; i<64; i++){
            int x=i/8;
            int y=i%8;
            int xx=x-Dx[move];
            int yy=y-Dy[move];
            if(xx<0||xx>=8) continue;
            if(yy<0||yy>=8) continue;
            MoveAllowed[move]|=unit<<i;
        }
    }
    for(int i=0; i<8; i++) MoveId[MoveName[i]]=i;
    int t;
    cin>>t;
    while(t--) solve();
}