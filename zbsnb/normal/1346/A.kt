private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
    var t = readInt()
    while(t-- > 0 ){
        var (a,b)=readInts()
        var tmp=a/(1+b+b*b+b*b*b)
        var q=tmp*b
        var w =tmp*b*b
        var e =tmp*b*b*b
        println("${tmp} ${q} ${w} $e")
    }
}