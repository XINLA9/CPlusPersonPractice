#include <iostream>
#include <vector>
using namespace std;

// �޸� get_fibon_seq �������ã���������ֱ���� fibon_elem �в���
vector<int>* fibon_seq(int size) {
    const int max_size = 1024;
    static vector<int> elems;  // ��̬����

    if (size <= 0 || size > max_size) {
        cerr << "get_fibon_seq(): invalid size: " << size << ", can't fulfill request.\n";
        static vector<int> empty_vec;  // ������󲻺Ϸ�������һ���յ� vector
        return &empty_vec;
    }

    // ��� Fibonacci ����
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

// ��ȡ�ض�λ�õ� Fibonacci ���֣����Ҵ�ӡ��ǰ Fibonacci ����
bool seq_elem(int pos, int& elem) {
    if (pos <= 0 || pos > 1024) {
        elem = 0;
        return false;
    }

    // ��ȡ Fibonacci ���е�ָ��
    vector<int>* vec = fibon_seq(pos);

    // ��ӡ��ǰ Fibonacci ����
    cout << "Current Fibonacci sequence up to position " << pos << ":\n";
    for (int i = 0; i < vec->size(); ++i) {
        cout << vec->at(i) << " ";
    }
    cout << endl;

    // ��ȡĿ��λ�õ�Ԫ��
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
