/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval& a, const Interval& b) {
  return a.start < b.start;
}

class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
      sort(intervals.begin(), intervals.end());

      vector<Interval> res;
      if (intervals.size() == 0) return res;
      Interval x = intervals[0];
      for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start <= x.end) {
          x.end = max(x.end, intervals[i].end);
        } else {
          Interval a;
          a.start = x.start;
          a.end = x.end;
          res.push_back(a);
          if (i < intervals.size() - 1) x = intervals[i+1];
        }
      }
      return res;
    }
};
