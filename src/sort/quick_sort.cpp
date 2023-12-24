#include <iostream>

#pragma warning(disable:4996)

using namespace std;

const int N = 1e6 + 10;

int nums[N];

void quick_sort(int nums[], int l, int r) {
  if (l >= r) {
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
  quick_sort(nums, l, j);
  quick_sort(nums, j + 1, r);
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
  quick_sort(nums, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    cout << nums[i] << " ";
  }
  cout << "\n";
  return 0;
}