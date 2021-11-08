def mystery(n):
    r = 0
    for i in range(n - 1):
        for j in range (i + 1, n):
            for _ in range(1, j):
                r += 1
    return r

print(mystery(100))
