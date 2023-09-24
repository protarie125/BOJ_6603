#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vi pool;
vi selected;

void solve(int b) {
	if (6 == selected.size()) {
		for (const auto& x : selected) {
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}

	for (auto i = b; i < n; ++i) {
		selected.push_back(pool[i]);
		solve(i + 1);
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (cin >> n) {
		if (0 == n) {
			break;
		}

		pool = vi(n);
		for (auto i = 0; i < n; ++i) {
			cin >> pool[i];
		}

		selected = vi{};
		selected.reserve(n);

		solve(0);
		cout << '\n';
	}

	return 0;
}