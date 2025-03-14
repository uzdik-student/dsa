/**
 * https://contest.yandex.ru/contest/69109/problems/B/
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

struct Group {
    int m;
    int median;
    int i;
};

int getMedian(int temp[], int m) {
    if (m % 2 == 0) {
        return (temp[m/2 - 1] + temp[m/2]) / 2;
    }

    return temp[m/2];
}

bool group_sorter(Group const& a, Group const& b) {
    return a.median < b.median;
}

int main() {
    int n, t;
    cin >> n;

    vector<Group> groups(n);
    for (int i=0; i<n; i++) {
        int m;
        cin >> m;

        int temp[m];
        for (int j=0; j<m; j++) {
            cin >> temp[j];
        }

        sort(temp, temp+m);
        groups[i].median = getMedian(temp, m);
        groups[i].m = m;
        groups[i].i = i;
    }

    cin >> t;

    sort(groups.begin(), groups.end(), &group_sorter);

    vector<int> answer(n, 0);

    for (int i = 0; i < n && t > 0; ++i) {
        int remainder = min(groups[i].m, t);
        answer[groups[i].i] = remainder;
        t -= remainder;
    }

    for (int jars: answer) {
        cout << jars << endl;
    }
}

