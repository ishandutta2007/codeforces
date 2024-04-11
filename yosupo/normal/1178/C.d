/+ dub.sdl:
    name "C"
    dependency "dunkelheit" version="1.0.1"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner, dkh.modint;

alias Mint = ModInt!(998244353);

int main() {
    Scanner sc = new Scanner(stdin);
    scope(exit) assert(!sc.hasNext);

    int w, h;
    sc.read(w, h);

    writeln(Mint(2) ^^ (w + h));
    return 0;
}
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/modint.d */
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
     
    auto opBinary(string op:"^^", T)(T r) const {return pow(this, r, ModInt(1));}
    auto opOpAssign(string op)(ModInt r) {return mixin ("this=this"~op~"r");}
     
    static ModInt inv(ModInt x) {return x^^(MD-2);};
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
        is(T : ModInt!MD, uint MD) || is(T : DModInt!S, string S);
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

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/container/stackpayload.d */
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

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/numeric/primitive.d */
// module dkh.numeric.primitive;

import std.traits, std.bigint;

 
T lcm(T)(in T a, in T b) {
    import std.numeric : gcd;
    return a / gcd(a,b) * b;
}

 
 

 
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
    Unqual!U m = n;
    while (m) {
        if (m & 1) r = (r*x)%md;
        x = (x*x)%md;
        m >>= 1;
    }
    return r % md;
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

 
 

 
T invMod(T)(T x, T md) {
    auto r = extGcd!T(x, md);
    assert(r[2] == 1);
    auto z = r[0];
    return (z % md + md) % md;
}

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/foundation.d */
 
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
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/scanner.d */
// module dkh.scanner;

// import dkh.container.stackpayload;

 
class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    private File f;
     
    this(File f) {
        this.f = f;
    }
    private char[512] lineBuf;
    private char[] line;
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
                    assert(succW());
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
     
    void read(Args...)(auto ref Args args) {
        import std.exception : enforce;
        static if (args.length != 0) {
            enforce(readSingle(args[0]));
            read(args[1..$]);
        }
    }
     
    bool hasNext() {
        return succ();
    }
}


 
 

 

/*
This source code generated by dunkelheit and include dunkelheit's source code.
dunkelheit's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dunkelheit)
dunkelheit's License: MIT License(https://github.com/yosupo06/dunkelheit/blob/master/LICENSE.txt)
*/