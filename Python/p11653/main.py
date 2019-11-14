num = int(input())

for i in range(2,num):
    while not (num % i):
        num /= i
        print(i)