#include <iostream>

using namespace std;

#include "stack.h"
#include "queue.h"

int main()
{
    Stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);

    cout << "Stack: " << endl;
    while(!S.isEmpty())
        cout << S.pop() << " ";

    Queue<double> Q;
    Q.insert(1.2);
    Q.insert(2.3);
    Q.insert(3.4);
    cout << "\n\nQueue: " << "\n";
    while(!Q.isEmpty())
        cout << Q.pop() << " ";

    cout << '\n';

    return 0;
}