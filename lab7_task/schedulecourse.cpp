#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	static bool compile(vector<int>& a, vector<int>& b) {
		return a[1] < b[1];
	}

	int scheduleCourse(vector<vector<int>>& courses) {
		int n = courses.size();

		sort(courses.begin(), courses.end(), compile);
		priority_queue<int> coursesQueue;

		int sum = 0;

		for (vector<int>& course : courses) {
			int duration = course[0];
			int deadline = course[1];

			if (sum + duration <= deadline) {
				sum += duration;
				coursesQueue.push(duration);
			}

			else if (coursesQueue.size() && coursesQueue.top() > duration) {
				sum += duration - coursesQueue.top();
				coursesQueue.pop();
				coursesQueue.push(duration);
			}
		}
		cout << coursesQueue.size();
		return coursesQueue.size();
	}
};

int main() {
	vector<vector<int>> courses = { {100, 200}, {200, 1300}, {1000, 1250} };
	Solution solution;
	solution.scheduleCourse(courses);
}