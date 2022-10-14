//package ru.spbau.mit

import java.io.InputStream
import java.io.OutputStream
import java.io.PrintWriter
import java.util.*

/**
 * That class defines a semigroup structure on a type T.
 * The following property should hold (associativity):
 * for any three values `a`, `b`, and `c` we have
 * `reduce(reduce(a, b), c)) == reduce(a, reduce(b, c))`.
 *
 * Examples: addition of two numbers, matrix multiplication.
 *
 * @param T the underlying data type on which the semigroup is defined
 */
interface SemigroupPolicy<T> {
    fun reduce(left: T, right: T): T
}

/**
 * A data structure which allows generic range aggregation queries on a array.
 * Given a fixed list `data` of type `T` (`a_0`, `a_1`, ...) and an associative operation
 * `policy` which can reduce two instances of type `T` into a single one, this
 * structure can efficiently reduce all values from an arbitrary subsegment of `data`.
 *
 * E.g. if `T` is `Int` and `policy` specifies addition of numbers, then this data
 * structure will efficiently solve Range Sum Query problem.
 *
 * Performance assuming `n` is equal to `data.length`:
 * * Memory consumption:
 * ** Requires between ~2n instances of type `T` plus O(n) objects.
 * * Performance:
 * ** O(n) calls to `policy.reduce` and O(n) object creations during construction
 * ** O(log n) calls to `policy.reduce` per request plus O(log n) stack frames
 *
 * @param T type of the data in the list and the return value of aggregation operation
 * @param data the list on which range queries will be performed, should be non-empty
 * @param policy an object which defines how to reduce the values in a range
 * @constructor Constructs and initializes a range query solver, calculates all necessary data
 */
class RangeQuerySolver<out T>(data: List<T>, private val policy: SemigroupPolicy<T>) {
    init {
        if (data.isEmpty()) {
            throw IllegalArgumentException("data should be non-empty")
        }
    }

    private val root = createNode(data, policy)
    val size = data.size

    /**
     * Given `left` and `right`, folds all elements of `data` with numbers
     * `left`, `left+1`, ..., `right-1`, `right` (in order) using `policy` and
     * return the result.
     *
     * The segment requested should be non-empty and fully lie inside initial `data`
     * for which the data structure is constructed.
     *
     * @param left left border of the segment requested (incl.)
     * @param right right border of the segment requested (incl.)
     * @return result of reducing all elements from `left` to `right` (incl.) with `policy`, in order
     */
    fun getRangeValue(left: Int, right: Int): T {
        if (!(left in 0..right && right < size)) {
            throw IndexOutOfBoundsException("Illegal range query: [$left; $right] when size is $size")
        }
        return root.getRangeValue(left, right, policy)
    }

    /**
     * Represents a single node of the segment tree which is responsible for answering
     * range requests for some non-empty subsegment of the initial `data`.
     * The subsegment is always indexed from zero up to node's size minus one,
     * even if that does not correspond to initial positions in `data`.
     *
     * It does not store `policy` to lower memory footprint,
     * `policy` should be passed to all methods manually.
     */
    private interface Node<T> {
        val size: Int

        /**
         * Given a non-empty subsegment of the node, returns result of reducing
         * all values in that subsegment.
         *
         * @param left left border of the subsegment (incl.)
         * @param left right border of the subsegment (incl.)
         * @param policy the reducing policy used when creating the node
         */
        fun getRangeValue(left: Int, right: Int, policy: SemigroupPolicy<T>): T
    }

    companion object NodesFactory {
        private fun <T> createNode(data: List<T>, policy: SemigroupPolicy<T>): Node<T> {
            assert(data.isNotEmpty())
            return if (data.size == 1) Leaf(data[0]) else InnerNode(data, policy)
        }
    }

    /**
     * Represents a leaf node which contains only a single value.
     */
    private class Leaf<T>(val v: T) : Node<T> {
        override val size = 1

        override fun getRangeValue(left: Int, right: Int, policy: SemigroupPolicy<T>): T {
            assert(left == 0 && right == 0)
            return v
        }
    }

    /**
     * Represents an inner node which contains more than one value.
     * @param data the data list for which the node is responsible
     * @param policy the reducing policy for the data, will be used for all child nodes
     * @constructor create all necessary child nodes for answering range queries
     */
    private class InnerNode<T>(data: List<T>, policy: SemigroupPolicy<T>) : Node<T> {
        init {
            assert(data.size >= 2)
        }

        override val size = data.size
        private val leftNode = createNode(data.subList(0, size / 2), policy)
        private val rightNode = createNode(data.subList(size / 2, size), policy)
        private val total = policy.reduce(
                leftNode.getRangeValue(0, leftNode.size - 1, policy),
                rightNode.getRangeValue(0, rightNode.size - 1, policy)
        )

        override fun getRangeValue(left: Int, right: Int, policy: SemigroupPolicy<T>): T {
            assert(left in 0..right && right < size)
            if (left == 0 && right == size - 1) {
                return total
            }
            // Three cases: either the requested segment fully lies inside one of children, or
            // it intersects the border between them.
            val rightNodeShift = leftNode.size
            return when {
                right < leftNode.size -> leftNode.getRangeValue(left, right, policy)
                leftNode.size <= left -> rightNode.getRangeValue(left - rightNodeShift, right - rightNodeShift, policy)
                else -> policy.reduce(
                        leftNode.getRangeValue(left, leftNode.size - 1, policy),
                        rightNode.getRangeValue(0, right - rightNodeShift, policy)
                )
            }
        }
    }
}

/**
 * Data structure which keeps `size` elements which are partitioned into disjoint
 * subsets. Initially each element is in its own subset, and later one can `merge` two
 * sets together. Each set has a 'root' element at any point of time, which can be used
 * as set's ID.
 *
 * Performance:
 * * Memory consumption: a single IntArray of size `size`
 */
class DisjointSetForest(val size: Int) {
    private val parent = IntArray(size, { i -> i })

    /**
     * @param a an arbitrary element (should be between 0 and `size-1` incl.)
     * @return a number of the root element of the set where element `a` is located
     */
    operator fun get(a: Int): Int {
        if (parent[a] != a) {
            parent[a] = get(parent[a])
        }
        return parent[a]
    }

    /**
     * Merges two sets together.
     * @param a an arbitrary element of the first set to merge (should be between 0 and `size-1` incl.)
     * @param b an arbitrary element of the second set to merge (should be between 0 and `size-1` incl.)
     * @return `true` if `a` and `b` were in different sets which are now merged, `false` if they were in the same set.
     */
    fun merge(a: Int, b: Int): Boolean {
        val compA = get(a)
        val compB = get(b)
        parent[compA] = compB
        return compA != compB
    }
}

/**
 * Given a sequence of integers (ids of connectivity components)
 * renumbers components such that all ids are between 0 and number of components,
 * and the resulting sequence is lexicographically minimal.
 *
 * E.g. it will transform `3, 2, 2, 1, 2, 10` into `0, 1, 1, 2, 1, 3`.
 */
fun canonizeComponentsList(components: IntArray): IntArray {
    val occuredIds = IntArray(components.max()!! + 1, { -1 })
    var componentsCount = 0
    return IntArray(components.size) { position ->
        val id = components[position]
        if (occuredIds[id] == -1) {
            occuredIds[id] = componentsCount
            componentsCount++
        } else {
            occuredIds[id]
        }
    }
}

/**
 * Represents a segment of the flag.
 * Knows total number of components in the segment, as well as which cells on both sides of
 * the segment lie in the same component. This is denoted by `leftComponents` and `rightComponents`
 * properties which contain IDs of components to which cells on the corresponding side belong.
 *
 * E.g. for the following segment:
 *     1221
 *     1111
 *     2443
 * The following FlagSegment will be constructed:
 *     FlagSegment(leftColor=[1, 1, 2], rightColor=[1, 1, 3], totalComponents=5, leftComponents=[0, 0, 1], rightComponents=[0, 0, 2])
 * Explanation: there are five different components, one appears on both ends (component 0), two
 * are not visible on the sides, and two appear on different sides each (components 1 and 2).
 */
class FlagSegment(leftComponents: IntArray, rightComponents: IntArray, val leftColors: IntArray, val rightColors: IntArray, val totalComponents: Int) {
    val leftComponents: IntArray
    val rightComponents: IntArray

    init {
        if (leftComponents.size != rightComponents.size) {
            throw IllegalArgumentException("leftComponents and rightComponents should have the same size")
        }
        if (leftComponents.size != leftColors.size) {
            throw IllegalArgumentException("leftComponents and leftColors should have the same size")
        }
        if (rightComponents.size != rightColors.size) {
            throw IllegalArgumentException("rightComponents and rightColors should have the same size")
        }
        val repainted = canonizeComponentsList(leftComponents + rightComponents)
        this.leftComponents = repainted.sliceArray(0 until leftComponents.size)
        this.rightComponents = repainted.sliceArray(leftComponents.size until repainted.size)
    }

    val height
        get() = leftComponents.size

    companion object {
        fun fromSingleColumn(columnColors: IntArray): FlagSegment {
            var previousFlagColor = -1
            var componentsCount = 0
            val components = IntArray(columnColors.size) { row ->
                val color = columnColors[row]
                if (previousFlagColor != color) {
                    previousFlagColor = color
                    componentsCount++
                }
                componentsCount - 1
            }
            return FlagSegment(components, components, columnColors, columnColors, componentsCount)
        }
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as FlagSegment

        if (!Arrays.equals(leftColors, other.leftColors)) return false
        if (!Arrays.equals(rightColors, other.rightColors)) return false
        if (totalComponents != other.totalComponents) return false
        if (!Arrays.equals(leftComponents, other.leftComponents)) return false
        if (!Arrays.equals(rightComponents, other.rightComponents)) return false

        return true
    }

    override fun hashCode(): Int {
        var result = Arrays.hashCode(leftColors)
        result = 31 * result + Arrays.hashCode(rightColors)
        result = 31 * result + totalComponents
        result = 31 * result + Arrays.hashCode(leftComponents)
        result = 31 * result + Arrays.hashCode(rightComponents)
        return result
    }

    override fun toString(): String {
        return "FlagSegment(leftColors=${Arrays.toString(leftColors)}, rightColors=${Arrays.toString(rightColors)}, totalComponents=$totalComponents, leftComponents=${Arrays.toString(leftComponents)}, rightComponents=${Arrays.toString(rightComponents)})"
    }
}

class FlagSegmentConcatenator : SemigroupPolicy<FlagSegment> {
    override fun reduce(left: FlagSegment, right: FlagSegment): FlagSegment {
        val height = left.height
        assert(height == right.height)
        val rightComponentIdOffset = height * 2
        val components = DisjointSetForest(height * 4)
        var totalComponents = left.totalComponents + right.totalComponents
        (0 until height)
                .filter { left.rightColors[it] == right.leftColors[it] }
                .forEach {
                    if (components.merge(left.rightComponents[it], rightComponentIdOffset + right.leftComponents[it])) {
                        totalComponents--
                    }
                }
        return FlagSegment(
                IntArray(height) { components[left.leftComponents[it]] },
                IntArray(height) { components[rightComponentIdOffset + right.rightComponents[it]] },
                left.leftColors,
                right.rightColors,
                totalComponents
        )
    }
}

fun solve(input: InputStream, output: OutputStream) {
    input.bufferedReader().use { reader ->
        PrintWriter(output).use { writer ->
            val tokenizer = StringTokenizer(reader.readText())
            while (tokenizer.hasMoreTokens()) {
                val height = tokenizer.nextToken().toInt()
                val width = tokenizer.nextToken().toInt()
                val queries = tokenizer.nextToken().toInt()
                val flag = Array(height, { _ -> IntArray(width, { _ -> tokenizer.nextToken().toInt() }) })
                val flagColumns =
                        (0 until width)
                                .map { col -> IntArray(height) { row -> flag[row][col] } }
                                .map(FlagSegment.Companion::fromSingleColumn)
                val solver = RangeQuerySolver(flagColumns, FlagSegmentConcatenator())

                (0 until queries).forEach {
                    val l = tokenizer.nextToken().toInt() - 1
                    val r = tokenizer.nextToken().toInt() - 1
                    val result = solver.getRangeValue(l, r)
                    writer.println(result.totalComponents)
                }
            }
        }
    }
}

fun main(args: Array<String>) {
    solve(System.`in`, System.out)
}