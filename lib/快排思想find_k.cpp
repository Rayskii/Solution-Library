#include <iostream>
#include <vector>

using namespace std;

void find_k(vector<int>& nums, int l, int r, int k, int& res) {
	if (l >= r) {
		res = nums[k];
		return;
	}
	int i = l - 1, j = r + 1;
	int x = nums[(l + r) / 2];
	while (i < j) {
		do {
			++i;
		} while (nums[i] < x);
		do {
			--j;
		} while (nums[j] > x);
		if (i < j) {
			swap(nums[i], nums[j]);
		}
	}
	if (k <= j) {
		find_k(nums, l, j, k, res);
	} else {
		find_k(nums, j + 1, r, k, res);
	}
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	int res = 0;
	find_k(nums, 0, n - 1, k - 1, res);
	cout << res << "\n";
	return 0;
}