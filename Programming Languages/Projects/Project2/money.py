'''
Jackson Warren
Apple Assigment
9/3/21
'''

import timeit

def rule_send(S1, E1, N1, D1):
    return bool(S1 != E1 and S1 != N1 and S1 != D1 and E1 != N1 and E1 != D1 and N1 != D1)

def rule_more(M21, O21, R21, E21):
    return bool(M21 != O21 and M21 != R21 and M21 != E21 and O21 != R21 and O21 != E21 and R21 != E21)

def rule_money(M31, O31, N31, E31, Y31):
    return bool(M31 != O31 and M31 != N31 and M31 != E31 and M31 != Y31 and O31 != N31 and O31 != E31 and O31 != Y31 and N31 != E31 and N31 != Y31 and E31 != Y31)

def con_send_more(E1, E21):
    return bool(E1 == E21)

def con_send_more_money(E1, E31, M21, M31, O21, O31, N1, N31, R21, Y31, D1, S1):
    return bool(E1 == E31 and M21 == M31 and O21 == O31 and N1 == N31 and R21 != N31 and R21 != Y31 and D1 != R21 and S1 != R21)


def main():
    send = 1000
    while send < 10000:
        rem = send
        S1 = int(rem/1000)
        rem = int(rem%1000)
        E1 = int(rem/100)
        rem = int(rem%100)
        N1 = int(rem/10)
        D1 = int(rem%10)
        if rule_send(S1, E1, N1, D1):
            more = 1000
            while more < 10000:
                rem = more
                M21 = int(rem/1000)
                rem = int(rem%1000)
                O21 = int(rem/100)
                rem = int(rem%100)
                R21 = int(rem/10)
                E21 = int(rem%10)
                if rule_more(M21, O21, R21, E21):
                    if con_send_more(E1, E21):
                        money = send + more
                        if money > 9999 and money < 100000:
                            rem = money
                            M31 = int(rem/10000)
                            rem = int(rem%10000)
                            O31 = int(rem/1000)
                            rem = int(rem%1000)
                            N31 = int(rem/100)
                            rem = int(rem%100)
                            E31 = int(rem/10)
                            Y31 = int(rem%10)
                            if rule_money(M31, O31, N31, E31, Y31):
                                if con_send_more_money(E1, E31, M21, M31, O21, O31, N1, N31, R21, Y31, D1, S1):
                                    print(send, " + ", more, " = ", money)
                more += 1
        send += 1


start = timeit.default_timer()
main()
stop = timeit.default_timer()
print('Time: ', stop - start, " seconds.")  