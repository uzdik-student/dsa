/**
 * A massive data processing task was underway, involving N sequential
 * modules (numbered 1 to N, in execution order). Each module i had a specific processing time, d(i), representing how long it would take to complete its work.
 * The sustem administrators were trina to determine the optimal level of parallelization, K, for these modules. If K was too small, the overall
 * processino time woula exceea te allowea limit. Imax
 * Initially, modules 1 to K would start processing simultaneously. As soon as a module finished, the next in line (module K+1, then K+2, and so on)
 * would begin its work, ensuring K modules were always running. The entire task ended when the last module finished, at time T.
 * The system had a maximum allowed processing time of Tmax. The administrators needed to find the smallest value of K that would keep the
 * task within this time constraint.
 * The Challenge:
 * Given the number of modules N, their processing umes at, and the maximum allowed processing time Tmax, determine the smallest level o parallelization K that satisfies the time constraint.
 * INPUT FORMATI
 * The first line of input contains N and Tmax, where Tmax is integer
 * The next N lines give the integer durations d(1)...d(N) of the modules from 1 to N, respectively.
 * I is cuaranteed mnal it Ken. le Snow will Tinish in time
 * OUTPUT FORMAT
 * Print out the smallest possible value of K such that the execution of the entire
 * task will take no more than Timax units of time
 */
#include <bits/stdc++.h>
using namespace std;

int N, Tmax;
int d[10000];

bool ok(int K) {
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // Start first K tasks
  for (int i = 0; i < K; ++i) {
      minHeap.push(d[i]);
  }

  // Assign the rest as others finish
  for (int i = K; i < N; ++i) {
      int earliest = minHeap.top();
      minHeap.pop();
      minHeap.push(earliest + d[i]);
  }

  // Get the maximum finish time
  int maxTime = 0;
  while (!minHeap.empty()) {
      maxTime = max(maxTime, minHeap.top());
      minHeap.pop();
  }

  return maxTime <= Tmax;
}

int main() {
  cin >> N >> Tmax;
  for (int i=0; i<N; i++) {
    cin >> d[i];
  }

  int left = 1, right = N;
  int answer = N;

  while (left <= right) {
      int mid = (left + right) / 2;
      if (ok(mid)) {
          answer = mid;
          right = mid - 1;
      } else {
          left = mid + 1;
      }
  }

  cout << answer << endl;
}