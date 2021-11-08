def pestiferous(n):
    r = 0
    for i in range(n):
        for j in range(i):
            for k in range (j, i+j):
                for l in range (1, i+j-k):
                    r += 1
    return r
print(pestiferous(100))
