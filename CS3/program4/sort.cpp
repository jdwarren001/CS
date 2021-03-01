/*************************
 * 
 * Jackson Warren
 * Sorts (BS, QS, Shell, Radix, Merge)
 * 11/10/20
 * 
 ************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <math.h>

using namespace std;

int N = 10000;
int c = 0;
clock_t begintime, endtime;

void readf(int nums[]) {
    ifstream inf("input.txt");

    for(int i = 0; i < N; i++) {
        inf >> nums[i];
    }
}

void init(int a[]) {
    for(int i = 0; i < N; i++) {
        a[i] = 0;
    }
}

void swapem(int &a, int &b) {
    int temp = 0;

    temp = a;
    a = b;
    b = temp;
    c += 3;
}

void bs(int nums[]) {
    for(int i = 0; i < N - 1; i ++) {
        for(int j = 0; j < N - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                swapem(nums[j], nums[j + 1]);
            }
        }
    }
}

void qs(int nums[], int left, int right) {
    int j = 0, k = 0;

    if(left < right) {
        j = left;
        k = right + 1;

        do {
            do {
                j++;
            } while(nums[j] < nums[left] && j <= k);
            do {
                k = k - 1;
            } while(nums[k] > nums[left] && k >= 0);

            if(j < k)
                swapem(nums[j], nums[k]);
        } while(j <= k);

        swapem(nums[left], nums[k]);

        qs(nums, left, k - 1);
        qs(nums, k + 1, right);
    }
}

void merge(int nums[], int z[], int L, int m, int n) {
    int i = 0, j = 0, k = 0, t = 0;
    i = L;
    k = L;
    j = m + 1;

    while(i <= m && j <= n) {
        if(nums[i] <= nums[j]) {
            z[k++] = nums[i++];
            c++;
        }
        else {
            z[k++] = nums[j++];
            c++;
        }
    }
    if(i > m) {
        for(t = j; t <= n; t++) {
            z[k + t - j] = nums[t];
            c++;
        }
    }
    else {
        for(t = i; t <= m; t++) {
            z[k + t - i] = nums[t];
            c++;
        }
    }
}

void mergePass(int nums[], int z[], int &L, int n) {
    int i, t;
    i = 0;

    while(i <= (n - (2 * L) + 1)) {
        merge(nums, z, i, i + L - 1, i + 2 * L - 1);
        i = i + 2 * L;
    }
    if((i + L - 1) < n)
        merge(nums, z, i, i + L - 1, n);
    else {
        for(t = i; t <= n; t++) {
            z[t] = nums[t];
            c++;
        }
    }
    
}

void mergeSort(int nums[], int z[], int n) {
    int L = 1;

    while(L < n) {
        mergePass(nums, z, L, n);
        L = 2 * L;
        mergePass(z, nums, L, n);
        L = 2 * L;
    }
}

void shell(int nums[], int l, int r) {
    int i, j, x;
    int h[8];

    h[0] = 1;

    for(int i = 1; i < 8; i++) 
        h[i] = pow(4, i) + 3 * pow(2, i - 1);

    for(int k = 7; k >= 0; k--) {
        for(i = l + h[k]; i <= r; i++) {
            j = i;
            x = nums[i];
            c++;
            while(j >= h[k] && x < nums[j - h[k]]) {
                nums[j] = nums[j - h[k]];
                c++;
                j -= h[k];
            }
            nums[j] = x;
            c++;
        }
    }
}

void radix(int nums[], int b[], int k, int r) {
    int rtok = 1;
    int j;
    int count[r];

    for(int i = 0; i < k; i++, rtok *= r) {
        for(j = 0; j < r; j++)
            count[j] = 0;

        for(j = 0; j < N; j++)
            count[nums[j] / rtok % r]++;

        for(j = 1; j < r; j++)
            count[j] = count[j - 1] + count[j];
        
        for(j = N - 1; j >= 0; j--)
            b[--count[nums[j] / rtok % r]] = nums[j];

        for(j = 0; j < N; j++)
            nums[j] = b[j];

        c += 2 * N;
    }
}

void print(ofstream &ofs, string sortName, int nums[], double diftime, int count){
    int incr = N / 10;
    int j = 1;

    ofs << sortName << ":" << endl;
    ofs << "----------------------------------------------------" << endl;
    for(int i = 0; i < N; i += incr) {
        ofs << setw(10) << nums[i];
        j++;
        if(j >= 6) {
            ofs << endl;
            j = 1;
        }
    }
    ofs << "----------------------------------------------------" << endl;
    ofs << "Moves: " << c << endl;
    ofs << "Time for sort: " << diftime << endl;
    ofs << endl << endl;
}

int main() {
    int numsorts = 6;
    int nums[N];
    int z[N];
    string sortName = "";
    ofstream ofs("output.txt");

    init(nums);

    for(int i = 0; i < numsorts; i++) {
        c = 0;
        readf(nums);
        begintime = clock();
        switch(i) {
            case 0: 
                sortName = "Unsorted";
                break;
            case 1:
                bs(nums);
                sortName = "Bubble Sort";
                break;
            case 2:
                init(z);
                radix(nums, z, 6, 10);
                sortName = "Radix Sort";
                break;
            case 3:
                init(z);
                mergeSort(nums, z, N - 1);
                sortName = "Merge Sort";
                break;
            case 4:
                shell(nums, 0, N - 1);
                sortName = "Shell Sort";
                break;
            case 5:
                qs(nums, 0, N - 1);
                sortName = "Quick Sort";
                break;
        }
        endtime = clock();
        double diftime = ((1.0 * endtime - begintime) / CLOCKS_PER_SEC);
        print(ofs, sortName, nums, diftime, c);
    }

    return 0;
}