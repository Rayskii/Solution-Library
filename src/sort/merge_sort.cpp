#include <iostream>

#pragma warning(disable:4996)

using namespace std;

const int N = 1e6 + 10;

int nums[N], temp_arr[N];

void merge_sort(int nums[], int l, int r) {
  if (l >= r) {
    return;
  }
  int mid = (l + r) / 2;
  merge_sort(nums, l, mid);
  merge_sort(nums, mid + 1, r);
  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r) {
    if (nums[i] < nums[j]) {
      temp_arr[k++] = nums[i++];
    } else {
      temp_arr[k++] = nums[j++];
    }
  }
  while (i <= mid) {
    temp_arr[k++] = nums[i++];
  }
  while (j <= r) {
    temp_arr[k++] = nums[j++];
  }
  for (i = l, j = 0; i <= r; ++i, ++j) {
    nums[i] = temp_arr[j];
  }
}

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  merge_sort(nums, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    cout << nums[i] << " ";
  }
  cout << "\n";
  return 0;
}