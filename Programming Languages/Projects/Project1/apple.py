'''
Jackson Warren
Apple Assigment
9/3/21
'''


'''
NOTES

All logic passed over from c++ code, 

I tried to keep the exact same logic for all 3 programs (ie. not changing the code to be lists/tuples) and
then highlighted the major differences I found I needed to make to each program to run the exact same program 
in a different language. 

Couldn't pass values by reference, so no longer can do digi functions unless it is converted to a tuple/list

All values had to be clarified as an int, as the type would change otherwise. 
'''

import timeit

def rule_eat(E1, A1, T1):
    return bool(E1 != A1 and E1 != T1 and A1 != T1)

def rule_that(T2, H2, A2, T21):
    return bool(T2 == T21 and T2 != H2 and T2 != A2 and H2 != A2 and H2 != T21 and A2 != T21)

def rule_apple(A3, P3, P32, L3, E3):
    return bool(A3 != P3 and A3 != P32 and A3 != L3 and A3 != E3 and P3 == P32 and P3 != L3 and P3 != E3 and L3 != E3)

def con_eat_that(T1, T2, T21, A1, A2):
    return bool(T1 == T2 and A1 == A2 and T1 == T21)

def con_eat_that_apple(apple, A1, A2, A3, E1, E3):
    return bool(A1 == A3 and A2 == A3 and E1 == E3)


def main():
    eat = 100
    while eat < 1000:
        rem = eat
        E1 = int(rem/100)   
        rem = int(rem%100)
        A1 = int(rem/10)
        T1 = int(rem%10)
        if rule_eat(E1, A1, T1):
            that = 1000
            while that < 10000:
                rem = that
                T2 = int(rem/1000)
                rem = int(rem%1000)
                H2 = int(rem/100)
                rem = int(rem%100)
                A2 = int(rem/10)
                T21 = int(rem%10)
                if rule_that(T2, H2, A2, T21):
                    if con_eat_that(T1, T2, T21, A1, A2):
                        apple = eat + that
                        if apple > 9999 and apple < 100000:
                            rem = apple
                            A3 = int(rem/10000)
                            rem = int(rem%10000)
                            P3 = int(rem/1000)
                            rem = int(rem%1000)
                            P32 = int(rem/100)
                            rem = int(rem%100)
                            L3 = int(rem/10)
                            E3 = int(rem%10)
                            if rule_apple(A3, P3, P32, L3, E3):
                                if con_eat_that_apple(apple, A1, A2, A3, E1, E3):
                                    print(eat, " + ", that, " = ", apple)
                that += 1
        eat += 1


start = timeit.default_timer()
main()
stop = timeit.default_timer()
print('Time: ', stop - start, " seconds.")  

# Results:
# 819  +  9219  =  10038
# Time:  4.662068983  seconds.