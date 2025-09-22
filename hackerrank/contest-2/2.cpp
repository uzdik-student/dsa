/**
 * In an old college, there are N students, each with a unique student ID, conveniently numbered 1...N. The students are all gathered in a row for a special event. Each student has one of three majors: Computer Science (major 1), Robotics (major 2), and Electrical Engineering (major 3). The head of the college is seeking your assistance in counting the number of students from each major within specific intervals along the row.
 * 
 * Input format:
 * The first line of input contains N and Q, where N is the number of students and Q is the number of queries.
 * The next N lines contain an integer that is either 1, 2, or 3, giving the major number of a single student in the ordering.
 * The next Q lines describe a query in the form of two integers a, b.
 * 
 * Output format:
 * For each of the Q queries (a, b), print a line containing three numbers: the number of students numbered a...b that are Computer Science (major 1), Robotics (major 2), and Electrical Engineering (major 3) majors.
 * 
 * Constrains:
 * 1 <= N <= 100000
 * 1 <= Q <= 100000
 * a <= b
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> prefix_1(N + 1, 0), prefix_2(N + 1, 0), prefix_3(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int major;
        cin >> major;
        prefix_1[i] = prefix_1[i - 1] + (major == 1);
        prefix_2[i] = prefix_2[i - 1] + (major == 2);
        prefix_3[i] = prefix_3[i - 1] + (major == 3);
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        int count_1 = prefix_1[b] - prefix_1[a - 1];
        int count_2 = prefix_2[b] - prefix_2[a - 1];
        int count_3 = prefix_3[b] - prefix_3[a - 1];
        cout << count_1 << " " << count_2 << " " << count_3 << endl;
    }
}
