#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ULL = unsigned long long;

vector<int> biginteger_add(const vector<int>& A, const vector<int>& B) {
	if (A.size() < B.size()) {
		return biginteger_add(B, A);
	}
	vector<int> res;
	int t = 0;
	for (int i = 0; i < A.size(); ++i) {
		t += A[i];
		if (i < B.size()) {
			t += B[i];
		}
		res.push_back(t % 10);
		t /= 10;
	}
	if (t) {
		res.push_back(t);
	}
	return res;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; --i) {
		A.push_back(a[i] - '0');
	}
	for (int i = b.size() - 1; i >= 0; --i) {
		B.push_back(b[i] - '0');
	}
	vector<int> res = biginteger_add(A, B);
	for (int i = res.size() - 1; i >= 0; --i) {
		cout << res[i];
	}
	cout << endl;
	return 0;
}