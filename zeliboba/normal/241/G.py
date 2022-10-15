print 302
print "0 500000"
x = 300000
r = 400
print "%d %d" % (x, r)
for i in range (2, 301):
    x += 2 * r
    r -= 1
    print "%d %d" % (x, r)
print "1000000 500005"