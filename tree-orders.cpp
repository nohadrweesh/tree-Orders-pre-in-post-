#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
private:
	int n;
	vector <int> key;
	vector <int> left;
	vector <int> right;
	vector<int>* inOrderTraversal(int treeIndex){
		static vector<int>result;
		if (treeIndex == -1)
			return NULL;
		inOrderTraversal(left[treeIndex]);
		result.push_back(key[treeIndex]);
		inOrderTraversal(right[treeIndex]);
		return &result;

	}
	vector<int>* preOrderTraversal(int treeIndex){//nde left right
		static vector<int>result;
		if (treeIndex == -1)
			return NULL;
		result.push_back(key[treeIndex]);
		preOrderTraversal(left[treeIndex]);
		preOrderTraversal(right[treeIndex]);
		return &result;

	}
	vector<int>* postOrderTraversal(int treeIndex){//nde left right
		static vector<int>result;
		if (treeIndex == -1)
			return NULL;

		postOrderTraversal(left[treeIndex]);
		postOrderTraversal(right[treeIndex]);
		result.push_back(key[treeIndex]);
		return &result;

	}



public:

	void read() {
		cin >> n;
		key.resize(n);
		left.resize(n);
		right.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> key[i] >> left[i] >> right[i];
		}
	}


	vector <int> in_order() {//LEFT NDE RIGHT
		vector<int> *result;
		
		result = inOrderTraversal(0);

		return *result;
	}

	vector <int> pre_order() {
		vector<int> *result;
		
		result = preOrderTraversal(0);
		return *result;
	}

	vector <int> post_order() {
		vector<int>* result;
		
		result = postOrderTraversal(0);

		return *result;
	}
};

void print(vector <int> a) {
	for (size_t i = 0; i < a.size(); i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << a[i];
	}
	cout << '\n';
}

int main_with_large_stack_space() {
	ios_base::sync_with_stdio(0);
	TreeOrders t;
	t.read();
	print(t.in_order());
	print(t.pre_order());
	print(t.post_order());
	//system("pause");
	return 0;
}

int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
	// Allow larger stack space
	const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}
#endif

	return main_with_large_stack_space();
}

