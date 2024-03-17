// stl queue
#include <iostream>
#include <queue>
 
using namespace std;
 
// Print the queue
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
 
int main()
{
    queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
 
    cout << "The queue queue is : ";
    showq(queue);
 
    cout << "\nqueue.size() : " << queue.size();
    cout << "\nqueue.front() : " << queue.front();
    cout << "\nqueue.back() : " << queue.back();
 
    cout << "\nqueue.pop() : ";
    queue.pop();
    showq(queue);
 
    return 0;
}