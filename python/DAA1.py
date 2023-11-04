n = 10


def fibonacci_iterative(n):
    if n <= 1:
        return n
    else:
        a, b = 0, 1
        print(a)
        print(b)
        for _ in range(2, n):
            a, b = b, a + b
            print(b)


def fibonacci_recursive(n):
    if n <= 1:
        return n
    else:
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)


print(f"Fibonacci Iterative({n}): ")
fibonacci_iterative(n)

print(f"Fibonacci Recursive({n}): ")
for i in range(n):
    print(fibonacci_recursive(i))
