#include <iostream>
#include <list>
#include <forward_list>
#include <vector>
using namespace std;

int main() // 4 steps
{
  cout << "hello, world!" << endl;

  list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);

  vector<int> v;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) // n * 3
  {
    cout << i << " ";
    cout << i << " ";
    cout << i << " ";
  }

  for (int i = 0; i < n; i++) // n * n
  {
    for (int j = 0; j < n; j++)
    {
      cout << i << " ";
      cout << i << " ";
      cout << i << " ";
    }
  }

  int x; // 4 steps due to calculating worst case path
  cin >> x;
  if (x == 4)
    cout << "ahmed\n";
}
// Data structures - Algorithms
// space - time

// linked list (x)
// vector
// stack
// queue
// trees
// graphs
// set
// map

// crud (create, read, update, delete)

// array

// pros
// fast access time

// cons
// fixed size
// hard to manipulate

// linked list
// pros
// dynamic size
// easy to manipulate

// cons
// searching is extremely bad
