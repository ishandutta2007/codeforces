/+ dub.sdl:
    name "D"
    dependency "dunkelheit" version="1.0.1"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner, dkh.numeric.prime;

int main() {
    Scanner sc = new Scanner(stdin);
    scope(exit) assert(!sc.hasNext);


    debug {
        foreach (n; 3..1001) {
            bool ok = false;
            foreach (m; n..(n + n / 4 * 2) + 1) {
                if (isPrime(m)) {
                    ok = true;
                    writefln("find %d : %d", n, m);
                    stdout.flush;
                    break;
                }
            }
            if (!ok) {
                writeln("ERROR ", n);
                return 0;
            }
        }
    }

    int n;
    sc.read(n);        
    foreach (m; n..(n + n / 4 * 2) + 1) {
        if (isPrime(m)) {

            int[2][] edges;
            foreach (i; 0..n) {
                edges ~= [i, (i + 1) % n];
            }
            foreach (i; 0..n) {
                if (i % 4 >= 2) continue;
                if (edges.length.to!int >= m) break;
                edges ~= [i, (i + 2) % n];
            }

            writeln(m);
            foreach (d; edges) {
                writeln(d[0] + 1, " ", d[1] + 1);
            }
            return 0;
        }
    }


    return 0;
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


 
 

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/numeric/prime.d */
// module dkh.numeric.prime;

import std.traits;
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

 
T[] divisorList(T)(T x) {
    import std.algorithm : sort;
    T[] res;
    for (T i = 1; i*i <= x; i++) {
        if (x%i == 0) {
            res ~= i;
            if (i*i != x) res ~= x/i;
        }
    }
    sort(res);
    return res;
}

 
 

 
T[] factorList(T)(T x) {
    T[] res;
    for (T i = 2; i*i <= x; i++) {
        while (x % i == 0) {
            res ~= i;
            x /= i;
        }
    }
    if (x > 1) res ~= x;
     
    return res;
}

 
 

// import dkh.numeric.primitive;

 
bool isPrime(ulong n) {
//     import dkh.int128;
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    ulong d = n-1;
    while (d % 2 == 0) d /= 2;
    ulong[] alist = [2,3,5,7,11,13,17,19,23,29,31,37];
    foreach (a; alist) {
        if (n <= a) break;
        ulong y = ulongPowMod(a, d, n);
        ulong t = d;
        while (t != n-1 && y != 1 && y != n-1) {
            y = mul128(y, y).mod128(n);
            t <<= 1;
        }
        if (y != n-1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
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
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/ldc/inline.d */
// module dkh.ldc.inline;

version(LDC) {
    pragma(LDC_inline_ir) R inlineIR(string s, R, P...)(P);
}
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/int128.d */
 

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