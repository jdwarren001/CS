/*******************
 * 
 * Jackson Warren
 * Apple Assigment
 * 9/3/21
 * 
 *******************/

/*
NOTES

All logic passed over from c++ code, I tried to keep the exact same logic for all 3 programs (ie. not changing the code to be lists/tuples) 
and then highlighted the major differences I found I needed to make to each program to run the exact same program in a different language. 

Once again, passing by reference isn't possible, so I got rid of the functions since they could not edit my variables the same as c++

Only difference was the syntax, passing by reference, and the class/structure of the entire program

*/

public class apple {

    static boolean rule_eat(int E1, int A1, int T1) {
        return E1 != A1 && E1 != T1 && A1 != T1;
    }
    
    static boolean rule_that(int T2, int H2, int A2, int T21) {
        return T2 == T21 && T2 != H2 && T2 != A2 && H2 != A2 && H2 != T21 && A2 != T21;
    }
    
    static boolean rule_apple(int A3, int P3, int P32, int L3, int E3) {
        return A3 != P3 && A3 != P32 && A3 != L3 && A3 != E3 && P3 == P32 && P3 != L3 && P3 != E3 && L3 != E3;
    }
    
    static boolean con_eat_that(int T1, int T2, int T21, int A1, int A2) {
        return T1 == T2 && A1 == A2 && T1 == T21;
    }
    
    static boolean con_eat_that_apple(int apple, int A1, int A2, int A3, int E1, int E3) {
        return A1 == A3 && A2 == A3 && E1 == E3;
    }

    public static void main(String args[]) {
        long start = System.nanoTime();

        int eat, that, apple;
        int E1, A1, T1;
        int T2, H2, A2, T21;
        int A3, P3, P32, L3, E3;

        for(eat = 100; eat < 1000; eat++) {
            int rem = eat;
            E1 = rem/100;
            rem = rem%100;
            A1 = rem/10;
            T1 = rem%10;
            if(rule_eat(E1, A1, T1)) {
                for(that = 1000; that < 10000; that++) {
                    rem = that;
                    T2 = rem/1000;
                    rem = rem%1000;
                    H2 = rem/100;
                    rem = rem%100;
                    A2 = rem/10;
                    T21 = rem%10;
                    if(rule_that(T2, H2, A2, T21)) {
                        if(con_eat_that(T1, T2, T21, A1, A2)) {
                            apple = eat + that;
                            if(apple > 9999 && apple < 100000) {
                                rem = apple;
                                A3 = rem/10000;
                                rem = rem%10000;
                                P3 = rem/1000;
                                rem = rem%1000;
                                P32 = rem/100;
                                rem = rem%100;
                                L3 = rem/10;
                                E3 = rem%10;
                                if(rule_apple(A3, P3, P32, L3, E3)) {
                                    if(con_eat_that_apple(apple, A1, A2, A3, E1, E3)) {
                                        System.out.println(eat + " + " + that + " = " + apple);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        long end = System.nanoTime();
        double finalTime = 1.0 * (end - start) / 1000000000;

        System.out.println("Time: " + finalTime + " seconds.");
    }
}


// Results: 
// 819 + 9219 = 10038
// Time: 0.054803618 seconds.