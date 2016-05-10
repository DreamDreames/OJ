//#include "shared.h"
#include "stdafx.h"
#include <stdio.h>

/*
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
*/

namespace MergeIntervals{
    struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
    };

	struct comparor {
		inline bool operator()(const Interval& left, const Interval& right) {
			return left.start < right.start;
		}
	};
    class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> ans;
			sort(intervals.begin(), intervals.end(), comparor());
			int i;
			for (i = 0; i < (int)intervals.size() - 1; ++i) {
				if (intervals[i].end >= intervals[i + 1].start) {
					intervals[i + 1].start = min(intervals[i].start, intervals[i].start);
					intervals[i + 1].end = max(intervals[i].end, intervals[i + 1].end);
				}
				else
					ans.push_back(intervals[i]);
			}
			if(i < intervals.size())
				ans.push_back(intervals[i]);
            return ans;
        }
    };
	TEST_CLASS(merge) {
	public:
		TEST_METHOD(MergeIntervals) {
			//test({ {1, 3}, {2, 6}, {8, 10},{15, 18} }, { {1, 6}, {8, 10}, {15, 18} });
			//test({ {1, 3}, {0, 4}}, { {0, 4} });
			//test({ {0, 4}}, { {0, 4} });
			test({ }, { });
		}
	private:
		void test(vector<Interval>intervals, vector<Interval> expected) {
			Solution sln;
			auto& ans = sln.merge(intervals);
			Assert::AreEqual(expected.size(), ans.size());
			for (int i = 0; i < expected.size(); ++i) {
				Assert::AreEqual(expected[i].start, ans[i].start);
				Assert::AreEqual(expected[i].end, ans[i].end);
			}
		}
	};
}
