#include <iostream>
#include <vector>
using namespace std;

// 修改 get_fibon_seq 返回引用，这样就能直接在 fibon_elem 中操作
vector<int>* fibon_seq(int size) {
    const int max_size = 1024;
    static vector<int> elems;  // 静态变量

    if (size <= 0 || size > max_size) {
        cerr << "get_fibon_seq(): invalid size: " << size << ", can't fulfill request.\n";
        static vector<int> empty_vec;  // 如果请求不合法，返回一个空的 vector
        return &empty_vec;
    }

    // 填充 Fibonacci 数列
    for (size_t ix = elems.size(); ix < size; ix++) {
        if (ix == 0 || ix == 1) {
            elems.push_back(1);
        }
        else {
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
        }
    }

    return &elems;
}

// 获取特定位置的 Fibonacci 数字，并且打印当前 Fibonacci 数列
bool seq_elem(int pos, int& elem) {
    if (pos <= 0 || pos > 1024) {
        elem = 0;
        return false;
    }

    // 获取 Fibonacci 数列的指针
    vector<int>* vec = fibon_seq(pos);

    // 打印当前 Fibonacci 数列
    cout << "Current Fibonacci sequence up to position " << pos << ":\n";
    for (int i = 0; i < vec->size(); ++i) {
        cout << vec->at(i) << " ";
    }
    cout << endl;

    // 获取目标位置的元素
    elem = vec->at(pos - 1);
    return true;
}

int main() {
    int elem = 0;
    int pos = 0;
    while (pos != -1) {
        cout << "Please enter the index of the number you want to get, or enter -1 to leave." << endl;
        cin >> pos;

        if (seq_elem(pos, elem)) {
            cout << "The " << pos << "th number in Fibonacci sequence is " << elem << endl;
        }
        else {
            cout << "Please enter a valid index number.\n" << endl;
        }
    }

    return 0;
}
