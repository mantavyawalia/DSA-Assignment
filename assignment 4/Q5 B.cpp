#include <iostream>
#include <queue>
using namespace std;

class StackOneQ {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        while (size--) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) { cout << "Empty\n"; return; }
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
};

int main() {
    StackOneQ s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
}
