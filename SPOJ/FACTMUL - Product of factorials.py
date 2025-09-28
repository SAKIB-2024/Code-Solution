mod = 109546051211

N = 10000000
fact_list = [1] * (N + 1)
for i in range(1, N + 1):
    fact_list[i] = (fact_list[i-1] * i) % mod

a = int(input())
ans = 1
for i in range(1, a + 1):
    ans = (ans * fact_list[i]) % mod

print(ans)
