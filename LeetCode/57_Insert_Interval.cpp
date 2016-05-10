#include "stdafx.h"

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
namespace InsertInterval {
	 struct Interval {
	     int start;
	     int end;
	     Interval() : start(0), end(0) {}
	     Interval(int s, int e) : start(s), end(e) {}
	 };
	class Solution {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> ans;
			int i; bool inserted = false;
			for (i = 0; i < (int)intervals.size(); ++i) {
				if (newInterval.end < intervals[i].start) {
					ans.push_back(newInterval);
					inserted = true;
					break;
				}
				if (intervals[i].end >= newInterval.start) {
					intervals[i].start = min(intervals[i].start, newInterval.start);
					intervals[i].end = max(intervals[i].end, newInterval.end);
					inserted = true;
					while (i < (int)intervals.size() - 1) {
						if (intervals[i].end >= intervals[i + 1].start) {
							intervals[i + 1].start = min(intervals[i].start, intervals[i + 1].start);
							intervals[i + 1].end = max(intervals[i].end, intervals[i + 1].end);
						}
						else
							ans.push_back(intervals[i]);
						i++;
					}
					break;
				}
				ans.push_back(intervals[i]);
			}
			while (i < intervals.size()) {
				ans.push_back(intervals[i++]);
			}
			if (!inserted)
				ans.push_back(newInterval);

			return ans;
		}
	};

	TEST_CLASS(insert) {
	public:
		TEST_METHOD(InsertInterval) {
			test({ { 1, 3 },{ 6, 9 } }, { 2, 5 }, { { 1, 5 }, {6, 9}});
			test({ { 1, 2 },{ 3, 5 }, {6, 7}, {8, 10},{12, 16} }, { 4, 9 }, { { 1, 2 }, {3 ,10}, {12, 16} });
			test({}, { 1, 2 }, { {1, 2} });
			test({ {3, 4} }, { 1, 2 }, { {1, 2},{3, 4} });
			test({ {1, 2} }, { 3, 4 }, { {1, 2},{3, 4} });
		}
	private:
		void test(vector<Interval>intervals, Interval newInterval, vector<Interval> expected) {
			Solution sln;
			auto& ans = sln.insert(intervals, newInterval);
			Assert::AreEqual(expected.size(), ans.size());
			for (int i = 0; i < expected.size(); ++i) {
				Assert::AreEqual(expected[i].start, ans[i].start);
				Assert::AreEqual(expected[i].end, ans[i].end);
			}
		}
	};
}