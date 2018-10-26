from math import sqrt

def first_100_prime_numbers():
    prime_list = []
    x = 2

    while (len(prime_list) < 100):
        if 1 < x <= 3:
            prime_list.append(x)
            x += 1
            
        elif x % 2 == 0 or x % 3 == 0:
            x += 1
            
        elif [y for y in range(5, (int(sqrt(x))) + 1) if x % y == 0 and x != y] == []:
            prime_list.append(x)
            x += 1
        
        else:
            x += 1

    return prime_list

def test():
    primes = set([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541])

    if set(first_100_prime_numbers()) == primes:
        print("Answer is correct. Paste URL to your solution into application.")
    else:
        print("Answer is wrong. Keep trying!")

test()