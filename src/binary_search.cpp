#include <iostream>
#include <vector>

using namespace std;

int binary_search_fst(vector<int>& nums, int l, int r, int tgt) {
	while (l < r) {
		int mid = (l + r) / 2;
		if (tgt <= nums[mid]) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int binary_search_lst(vector<int>& nums, int l, int r , int tgt) {
	while (l < r) {
		int mid = (l + r) / 2;
		if (tgt < nums[mid]) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	while (q--) {
		int x;
		cin >> x;
		int first = binary_search_fst(nums, 0, n - 1, x);
		int last = -1;
		if (first < 0 || first > n - 1 || nums[first] != x) {
			first = -1;
		} else {
			last = binary_search_lst(nums, 0, n - 1, x);
			if (nums[last] != x) {
				--last;
			}
		}
		cout << first << " " << last << "\n";
	}

	return 0;
}