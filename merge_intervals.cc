/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <algorithm>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool cmp(const Interval &a, const Interval &b) {
  return a.start < b.start;
}

class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
      sort(intervals.begin(), intervals.end(), cmp);

      vector<Interval> res;
      if (intervals.size() == 0) return res;
      Interval x = intervals[0];
      for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start <= x.end) {
          x.end = max(x.end, intervals[i].end);
        } else {
          res.push_back(x);
          x = intervals[i];
        }
      }
      res.push_back(x);
      
      return res;
    }
};
