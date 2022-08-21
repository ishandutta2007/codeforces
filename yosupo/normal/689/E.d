import std.stdio, std.conv;
import std.algorithm, std.range, std.random;
import std.string, std.array, std.container, std.bigint;
import std.exception;



int main() {
    immutable MN = 200200;
    Mint[] fact = new Mint[](MN), iFac = new Mint[](MN);
    fact[0] = Mint(1);
    foreach (i; 1..MN) {
        fact[i] = fact[i-1] * Mint(i);
    }
    foreach (i; 0..MN) {
        iFac[i] = Mint.inv(fact[i]);
    }
    Mint C(int n, int k) {
        return fact[n]*iFac[k]*iFac[n-k];
    }
    int n, k;
    readf("%d %d\n", &n, &k);
    alias P = int[2];
    int[2][] ev;
    foreach (i; 0..n) {
        int l, r;
        readf("%d %d\n", &l, &r);
        ev ~= [l, 0];
        ev ~= [r+1, 1];
    }
    ev.sort;
    int co = 0;
    Mint ans = 0;
    foreach (i, e; ev) {
        if (e[1] == 0) co++;
        else co--;

        if (i < ev.length-1 && ev[i+1][0] != ev[i][0]) {
            Mint di = Mint(ev[i+1][0]-ev[i][0]);
            if (k <= co) {
                ans += di * C(co, k);
            }
        }
    }
    writeln(ans);
	return 0;
}

T pow(T)(T x, ulong n) {
    T r = 1;
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}


struct ModInt(uint MD) {
    import std.conv : to;
    uint v;
    this(long v) {this.v = (v%MD+MD)%MD;}
    auto normS(uint x) {return (x<MD)?x:x-MD;};
    auto opBinary(string op:"+")(ModInt r) {return ModInt(normS(v+r.v));};
    auto opBinary(string op:"-")(ModInt r) {return this+ModInt(MD-r.v);};
    auto opBinary(string op:"*")(ModInt r) {return ModInt(cast(ulong)v*r.v%MD);};
    auto opOpAssign(string op)(ModInt r) {return mixin ("this=this"~op~"r");}
    static ModInt inv(Mint x) { return pow(x, MD-2); }
    string toString() {return v.to!string;}
}
//alias Mint = ModInt!(10^^9+7);
alias ModInt!(10^^9+7) Mint;
string readToken() {
    import std.stdio : readln;
    import std.string : split;
    static size_t pos;
    static string[] tokens;
    while (!(pos < tokens.length)) {
        pos = 0;
        tokens = readln.split;
    }
    return tokens[pos++];
}
T read(T)() {
    import std.conv : to;
    return readToken.to!T;
}