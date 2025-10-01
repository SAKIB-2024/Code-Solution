import math

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    x = k * math.log10(n)
    frac = x - int(x)
    leading = int(pow(10, frac) * 100)  # 3 digits

    trailing = pow(n, k, 1000)

    print(f"{leading}...{trailing:03d}")
