#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Interval {
    long long start, end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

/**
 * @brief Checks if it's possible to place N cows with a minimum distance of D.
 * 
 * @param D The minimum distance to check.
 * @param N The number of cows.
 * @param M The number of intervals.
 * @param intervals The vector of grass intervals.
 * @return true if placement is possible, false otherwise.
 */
bool can_place(long long D, int N, int M, const vector<Interval>& intervals) {
    int cows_placed = 1;
    long long last_pos = intervals[0].start;

    for (int i = 0; i < M; ++i) {
        // Find the next possible position in the current interval
        long long next_pos = max(intervals[i].start, last_pos + D);

        while (next_pos <= intervals[i].end) {
            cows_placed++;
            if (cows_placed >= N) return true;
            last_pos = next_pos;
            next_pos = last_pos + D;
        }
    }
    return cows_placed >= N;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Interval> intervals(M);
    for (int i = 0; i < M; ++i) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    long long low = 0, high = 1e18, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_place(mid, N, M, intervals)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}

