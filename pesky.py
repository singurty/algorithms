def pesky(n):
    r = 0
    for i in range(1, n):
        for j in range(1, i):
            for _ in range(j, i+j):
                r += 1
    return r
print(pesky(100))
