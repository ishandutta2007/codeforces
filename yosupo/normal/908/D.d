/+ dub.sdl:
    name "D"
    dependency "dunkelheit" version=">=0.9.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner;

// import dkh.functional;

// import dkh.modint;
alias Mint = ModInt!(10^^9 + 7);

int K;
Mint pa, pb;

Mint calcBase(int l, int k) {
    if (l+k >= K) {
        return Mint(l+k) + (Mint(1) - pb) / pb;
    }
    Mint ans = Mint(0);
    ans += pa * calc(l+1, k);
    ans += pb * calc(l, l+k);
    return ans;
}
memoCont!calcBase calc;

int main() {
    Scanner sc = new Scanner(stdin);
    scope(exit) sc.read!true;

    int _pa, _pb;
    sc.read(K, _pa, _pb);

    calc.init([[1, K], [0, K]]);

    pa = Mint(_pa) / Mint(_pa + _pb);
    pb = Mint(_pb) / Mint(_pa + _pb);
    writeln(calc(1, 0));
/*
    Mint[] a = new Mint[k+1];
    Mint[] b = new Mint[k+1];

    b[0] = Mint(0);
    foreach (i; 1..k+1) {
        a[i] = (Mint(1) + pb * b[i-1]) / (Mint(1) - pa);
        b[i] = (Mint(1) + pa * a[i]) / (Mint(1) - pb);
    }

    writeln(a[k], " ", b[k]);*/
    return 0;
}
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/container/stackpayload.d */
// module dkh.container.stackpayload;

 
struct StackPayload(T, size_t MINCAP = 4) if (MINCAP >= 1) {
    import core.exception : RangeError;

    private T* _data;
    private uint len, cap;

    @property bool empty() const { return len == 0; }
    @property size_t length() const { return len; }
    alias opDollar = length;

     
    inout(T)[] data() inout { return (_data) ? _data[0..len] : null; }
    
    ref inout(T) opIndex(size_t i) inout {
        version(assert) if (len <= i) throw new RangeError();
        return _data[i];
    }  
    ref inout(T) front() inout { return this[0]; }  
    ref inout(T) back() inout { return this[$-1]; }  

    void reserve(size_t newCap) {
        import core.memory : GC;
        import core.stdc.string : memcpy;
        import std.conv : to;
        if (newCap <= cap) return;
        void* newData = GC.malloc(newCap * T.sizeof);
        cap = newCap.to!uint;
        if (len) memcpy(newData, _data, len * T.sizeof);
        _data = cast(T*)(newData);
    }  
    void free() {
        import core.memory : GC;
        GC.free(_data);
    }  
     
    void clear() {
        len = 0;
    }

    void insertBack(T item) {
        import std.algorithm : max;
        if (len == cap) reserve(max(cap * 2, MINCAP));
        _data[len++] = item;
    }  
    alias opOpAssign(string op : "~") = insertBack;  
    void removeBack() {
        assert(!empty, "StackPayload.removeBack: Stack is empty");
        len--;
    }  
}

 
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/ldc/inline.d */
// module dkh.ldc.inline;

version(LDC) {
    pragma(LDC_inline_ir) R inlineIR(string s, R, P...)(P);
}
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/functional.d */
// module dkh.functional;

 
struct memoCont(alias pred) {
    import std.traits : ReturnType, ParameterTypeTuple, isIntegral;
    import std.meta : allSatisfy;
    alias R = ReturnType!pred;
    alias Args = ParameterTypeTuple!pred;
    static assert (allSatisfy!(isIntegral, Args));
    static immutable N = Args.length;
    
    private int[2][N] rng;
    int[N] len;
    R[] dp;
    bool[] used;
    void init(in int[2][N] rng) {
        import std.algorithm : reduce, map;
        import std.range : array;
        this.rng = rng;
        len = rng[].map!(a => a[1]-a[0]+1).array;
        auto sz = reduce!"a*b"(1, len);
        dp = new R[sz];
        used = new bool[sz];
    }
    R opCall(Args args) {
        import core.exception : RangeError;
        size_t idx, base = 1;
        foreach (i, v; args) {
            version(assert) {
                if (v < rng[i][0] || rng[i][1] < v) {
                    throw new RangeError;
                }
            }
            assert(rng[i][0] <= v && v <= rng[i][1]);
            idx += base*(v - rng[i][0]);
            base *= len[i];
        }
        if (used[idx]) return dp[idx];
        used[idx] = true;
        auto r = pred(args);
        dp[idx] = r;
        return r;
    }
}

 
 
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/foundation.d */
 
// module dkh.foundation;

 
static if (__VERSION__ <= 2070) {
    /*
    Copied by https://github.com/dlang/phobos/blob/master/std/algorithm/iteration.d
    Copyright: Andrei Alexandrescu 2008-.
    License: $(HTTP boost.org/LICENSE_1_0.txt, Boost License 1.0).
    */
    template fold(fun...) if (fun.length >= 1) {
        auto fold(R, S...)(R r, S seed) {
            import std.algorithm : reduce;
            static if (S.length < 2) {
                return reduce!fun(seed, r);
            } else {
                import std.typecons : tuple;
                return reduce!fun(tuple(seed), r);
            }
        }
    }
     
}
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/modint.d */
// module dkh.modint;

// import dkh.numeric.primitive;

 
struct ModInt(uint MD) if (MD < int.max) {
    import std.conv : to;
    uint v;
    this(int v) {this(long(v));}
    this(long v) {this.v = (v%MD+MD)%MD;}
    static auto normS(uint x) {return (x<MD)?x:x-MD;}
    static auto make(uint x) {ModInt m; m.v = x; return m;}
     
    auto opBinary(string op:"+")(ModInt r) const {return make(normS(v+r.v));}
     
    auto opBinary(string op:"-")(ModInt r) const {return make(normS(v+MD-r.v));}
     
    auto opBinary(string op:"*")(ModInt r) const {return make((ulong(v)*r.v%MD).to!uint);}
     
    auto opBinary(string op:"/")(ModInt r) const {return this*inv(r);}
    auto opOpAssign(string op)(ModInt r) {return mixin ("this=this"~op~"r");}
     
    static ModInt inv(ModInt x) {return ModInt(extGcd!int(x.v, MD)[0]);}
    string toString() const {return v.to!string;}
}

 
 

 

 
struct DModInt(string name) {
    import std.conv : to;
    static uint MD;
    uint v;
    this(int v) {this(long(v));}
    this(long v) {this.v = ((v%MD+MD)%MD).to!uint;}
    static auto normS(uint x) {return (x<MD)?x:x-MD;}
    static auto make(uint x) {DModInt m; m.MD = MD; m.v = x; return m;}
     
    auto opBinary(string op:"+")(DModInt r) const {return make(normS(v+r.v));}
     
    auto opBinary(string op:"-")(DModInt r) const {return make(normS(v+MD-r.v));}
     
    auto opBinary(string op:"*")(DModInt r) const {return make((ulong(v)*r.v%MD).to!uint);}
     
    auto opBinary(string op:"/")(DModInt r) const {return this*inv(r);}
    auto opOpAssign(string op)(DModInt r) {return mixin ("this=this"~op~"r");}
     
    static DModInt inv(DModInt x) {
        return DModInt(extGcd!int(x.v, MD)[0]);
    }
    string toString() {return v.to!string;}
}

 
 

 

template isModInt(T) {
    const isModInt =
        is(T : ModInt!MD, uint MD) || is(S : DModInt!S, string s);
}


T[] factTable(T)(size_t length) if (isModInt!T) {
    import std.range : take, recurrence;
    import std.array : array;
    return T(1).recurrence!((a, n) => a[n-1]*T(n)).take(length).array;
}

T[] invFactTable(T)(size_t length) if (isModInt!T) {
    import std.algorithm : map, reduce;
    import std.range : take, recurrence, iota;
    import std.array : array;
    auto res = new T[length];
    res[$-1] = T(1) / iota(1, length).map!T.reduce!"a*b";
    foreach_reverse (i, v; res[0..$-1]) {
        res[i] = res[i+1] * T(i+1);
    }
    return res;
}

T[] invTable(T)(size_t length) if (isModInt!T) {
    auto f = factTable!T(length);
    auto invf = invFactTable!T(length);
    auto res = new T[length];
    foreach (i; 1..length) {
        res[i] = invf[i] * f[i-1];
    }
    return res;
}

 
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/scanner.d */
// module dkh.scanner;

// import dkh.container.stackpayload;

 
class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    File f;
    this(File f) {
        this.f = f;
    }
    char[512] lineBuf;
    char[] line;
    private bool succW() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (!line.empty && line.front.isWhite) {
            line.popFront;
        }
        return !line.empty;
    }
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            line = lineBuf[];
            f.readln(line);
            if (!line.length) return false;
        }
        return true;
    }

    private bool readSingle(T)(ref T x) {
        import std.algorithm : findSplitBefore;
        import std.string : strip;
        import std.conv : parse;
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                 
                 
                auto r = line.findSplitBefore(" ");
                x = r[0].strip.dup;
                line = r[1];
            } else static if (isStaticArray!T) {
                foreach (i; 0..T.length) {
                    bool f = succW();
                    assert(f);
                    x[i] = line.parse!E;
                }
            } else {
                StackPayload!E buf;
                while (succW()) {
                    buf ~= line.parse!E;
                }
                x = buf.data;
            }
        } else {
            x = line.parse!T;
        }
        return true;
    }

    int unsafeRead(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
    void read(bool enforceEOF = false, T, Args...)(ref T x, auto ref Args args) {
        import std.exception;
        enforce(readSingle(x));
        static if (args.length == 0) {
            enforce(enforceEOF == false || !succ());
        } else {
            read!enforceEOF(args);
        }
    }
    void read(bool enforceEOF = false, Args...)(auto ref Args args) {
        import std.exception;
        static if (args.length == 0) {
            enforce(enforceEOF == false || !succ());
        } else {
            enforce(readSingle(args[0]));
            read!enforceEOF(args);
        }
    }
}


 
 

 
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/numeric/primitive.d */
// module dkh.numeric.primitive;

import std.traits;
import std.bigint;

 
Unqual!T pow(T, U)(T x, U n)
if (!isFloatingPoint!T && (isIntegral!U || is(U == BigInt))) {
    return pow(x, n, T(1));
}

 
Unqual!T pow(T, U, V)(T x, U n, V e)
if ((isIntegral!U || is(U == BigInt)) && is(Unqual!T == Unqual!V)) {
    Unqual!T b = x, v = e;
    Unqual!U m = n;
    while (m) {
        if (m & 1) v *= b;
        b *= b;
        m /= 2;
    }
    return v;
}

 

 
T powMod(T, U, V)(T x, U n, V md)
if (isIntegral!U || is(U == BigInt)) {
    T r = T(1);
    while (n) {
        if (n & 1) r = (r*x)%md;
        x = (x*x)%md;
        n >>= 1;
    }
    return r % md;
}

// import dkh.int128;

 
ulong ulongPowMod(U)(ulong x, U n, ulong md)
if (isIntegral!U || is(U == BigInt)) {
    x %= md;
    ulong r = 1;
    while (n) {
        if (n & 1) {
            r = mul128(r, x).mod128(md);
        }
        x = mul128(x, x).mod128(md);
        n >>= 1;
    }
    return r % md;
}

 
T lcm(T)(in T a, in T b) {
    import std.numeric : gcd;
    return a / gcd(a,b) * b;
}

 
 

 
 
T[3] extGcd(T)(in T a, in T b) 
if (!isIntegral!T || isSigned!T)  
{
    if (b==0) {
        return [T(1), T(0), a];
    } else {
        auto e = extGcd(b, a%b);
        return [e[1], e[0]-a/b*e[1], e[2]];
    }
}

 
 
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/int128.d */
 

// module dkh.int128;

version(LDC) {
//     import dkh.ldc.inline;
}

version(LDC) version(X86_64) {
    version = LDC_IR;
}

 
ulong[2] mul128(ulong a, ulong b) {
    ulong[2] res;
    version(LDC_IR) {
        ulong upper, lower;
        inlineIR!(`
            %r0 = zext i64 %0 to i128 
            %r1 = zext i64 %1 to i128
            %r2 = mul i128 %r1, %r0
            %r3 = trunc i128 %r2 to i64
            %r4 = lshr i128 %r2, 64
            %r5 = trunc i128 %r4 to i64
            store i64 %r3, i64* %2
            store i64 %r5, i64* %3`, void)(a, b, &lower, &upper);
        return [lower, upper];
    } else version(D_InlineAsm_X86_64) {
        ulong upper, lower;
        asm {
            mov RAX, a;
            mul b;
            mov lower, RAX;
            mov upper, RDX;
        }
        return [lower, upper];
    } else {
        ulong B = 2UL^^32;
        ulong[2] a2 = [a % B, a / B];
        ulong[2] b2 = [b % B, b / B];
        ulong[4] c;
        foreach (i; 0..2) {
            foreach (j; 0..2) {
                c[i+j] += a2[i] * b2[j] % B;
                c[i+j+1] += a2[i] * b2[j] / B;
            }
        }
        foreach (i; 0..3) {
            c[i+1] += c[i] / B;
            c[i] %= B;
        }
        return [c[0] + c[1] * B, c[2] + c[3] * B];
    }
}

 

 
ulong div128(ulong[2] a, ulong b) {
    version(LDC_IR) {
        return inlineIR!(`
            %r0 = zext i64 %0 to i128
            %r1 = zext i64 %1 to i128
            %r2 = shl i128 %r1, 64
            %r3 = add i128 %r0, %r2
            %r4 = zext i64 %2 to i128
            %r5 = udiv i128 %r3, %r4
            %r6 = trunc i128 %r5 to i64
            ret i64 %r6`,ulong)(a[0], a[1], b);
    } else version(D_InlineAsm_X86_64) {
        ulong upper = a[1], lower = a[0];
        ulong res;
        asm {
            mov RDX, upper;
            mov RAX, lower;
            div b;
            mov res, RAX;
        }
        return res;
    } else {
        if (b == 1) return a[0];
        while (!(b & (1UL << 63))) {
            a[1] <<= 1;
            if (a[0] & (1UL << 63)) a[1] |= 1;
            a[0] <<= 1;
            b <<= 1;
        }
        ulong ans = 0;
        foreach (i; 0..64) {
            bool up = (a[1] & (1UL << 63)) != 0;
            a[1] <<= 1;
            if (a[0] & (1UL << 63)) a[1] |= 1;
            a[0] <<= 1;

            ans <<= 1;
            if (up || b <= a[1]) {
                a[1] -= b;
                ans++;
            }
        }
        return ans;
    }
}


 
ulong mod128(ulong[2] a, ulong b) {
    version(D_InlineAsm_X86_64) {
        ulong upper = a[1], lower = a[0];
        ulong res;
        asm {
            mov RDX, upper;
            mov RAX, lower;
            div b;
            mov res, RDX;
        }
        return res;
    } else {
        return a[0] - div128(a, b) * b;
    }
}

 

/*
This source code generated by dunkelheit and include dunkelheit's source code.
dunkelheit's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dunkelheit)
dunkelheit's License: MIT License(https://github.com/yosupo06/dunkelheit/blob/master/LICENSE.txt)
*/