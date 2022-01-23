'''
Jackson Warren
Apple Assigment
9/3/21
'''

import timeit

def rule_cross(C1, R1, O1, S1, S2):
    return bool(C1 != R1 and C1 != O1 and C1 != S1 and C1 != S2 and R1 != O1 and R1 != S1 and R1 != S2 and O1 != S1 and O1 != S2 and S1 == S2)

def rule_roads(R21, O21, A21, D21, S21):
    return bool(R21 != O21 and R21 != A21 and R21 != D21 and R21 != S21 and O21 != A21 and O21 != D21 and O21 != S21 and A21 != D21 and A21 != S21 and D21 != S21)

def rule_danger(D31, A31, N31, G31, E31, R31):
    return bool(D31 != A31 and D31 != N31 and D31 != G31 and D31 != E31 and D31 != R31 and A31 != N31 and A31 != G31 and A31 != E31 and A31 != R31 and N31 != G31 and N31 != E31 and N31 != R31 and G31 != E31 and G31 != R31 and E31 != R31)

def con_cross_roads(R1, R21, O1, O21, S1, S21):
    return bool(R1 == R21 and O1 == O21 and S1 == S21)

def con_cross_roads_danger(A21, A31, R1, R31, D21, D31, C1, E31, O21, G31, S1, N31):
    return bool(A21 == A31 and R1 == R31 and D21 == D31 and C1 != E31 and O21 != E31 and O21 != G31 and S1 != N31 and C1 != N31)


def main():
    cross = 10000
    while cross < 100000:
        rem = cross
        C1 = int(rem/10000)
        rem = int(rem%10000)
        R1 = int(rem/1000)
        rem = int(rem%1000)
        O1 = int(rem/100)
        rem = int(rem%100)
        S1 = int(rem/10)
        S2 = int(rem%10)
        if rule_cross(C1, R1, O1, S1, S2):
            roads = 10000
            while roads < 100000:
                rem = roads
                R21 = int(rem/10000)
                rem = int(rem%10000)
                O21 = int(rem/1000)
                rem = int(rem%1000)
                A21 = int(rem/100)
                rem = int(rem%100)
                D21 = int(rem/10)
                S21 = int(rem%10)
                if rule_roads(R21, O21, A21, D21, S21):
                    if con_cross_roads(R1, R21, O1, O21, S1, S21):
                        danger = cross + roads
                        if danger > 99999 and danger < 1000000:
                            rem = danger
                            D31 = int(rem/100000)
                            rem = int(rem%100000)
                            A31 = int(rem/10000)
                            rem = int(rem%10000)
                            N31 = int(rem/1000)
                            rem = int(rem%1000)
                            G31 = int(rem/100)
                            rem = int(rem%100)
                            E31 = int(rem/10)
                            R31 = int(rem%10)
                            if rule_danger(D31, A31, N31, G31, E31, R31):
                                if con_cross_roads_danger(A21, A31, R1, R31, D21, D31, C1, E31, O21, G31, S1, N31):
                                    print(cross, " + ", roads, " = ", danger)
                roads += 1
        cross += 1


start = timeit.default_timer()
main()
stop = timeit.default_timer()
print('Time: ', stop - start, " seconds.")  