/*
  Discrete Mathematics and Its Applications
  by Dr. Kenneth H. Rosen
  Chapter 8.3 Divide and Conquer Algorithms and Recurrence Relations
  Solution 4
  Rakesh Kumar, cpp.rakesh@gmail.com
  09/06/2018
 */

#include <bits/stdc++.h>

int fast_multiply(int a, int b) {
    int a1 = a >> 16;
    int a0 = ((1 << 16) - 1) & a;

    const int b1 = b >> 16;
    const int b0 = ((1 << 16) - 1) & b;

    int x1 = a1 - a0;
    int x2 = b0 - b1;
    int x3 = a1 * b1;
    int x4 = x1 * x2;
    int x5 = a0 * b0;

    int y1 = x3 << 4;
    int y2 = x3 << 2;
    int y3 = x4 << 2;
    int y4 = x5 << 2;
    int y5 = x5;

    return y1 + y2 + y3 + y4 + y5;
}

int normal_multiplay(int a, int b) {
    return a * b;
}

int random(int s, int e) {
    return s + rand() % (e - s + 1);
}

int unit_test() {
    printf("-----------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 30; ++i) {
        const int a = random(1, 10000);
        const int b = random(1, 10000);

        const int x = fast_multiply(a, b);
        const int y = normal_multiplay(a, b);

        printf("[%8d] * [%8d] == [%16d] || [%16d] || result == %s\n",
               a, b, x, y, x == y ? "PASS" : "FAIL");
    }
    printf("-----------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------------\n");
}

int main() {
    unit_test();

    return 0;
}