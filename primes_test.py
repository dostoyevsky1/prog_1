def isPrime(x_lower, x_upper):

    num_list = range(x_lower,x_upper+1)

    primes_list = []
    for num in num_list:
        check_list = []
        check_lim = int(num**0.5)
        for i in range(2,check_lim+1):
            check_list.append(num % i == 0)
        if any(check_list):
            continue
        elif num != 1:
            primes_list.append(num)
    return primes_list

print(isPrime(1,1000))
