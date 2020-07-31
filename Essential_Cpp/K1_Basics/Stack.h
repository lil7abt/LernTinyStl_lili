#include <string>
#include <vector>

using namespace std;

class Stack
{
public:
    //Exercise 4.1
    bool push(const string&);
    bool pop (string &elem);
    bool peek(string &elem);
    bool empty() const {return _stack.empty();}
    bool full()  const {return _stack.size()==_stack.max_size();}
    int  size()        {return _stack.size();}


    //Exercise 4.2
    bool find (const string &elem) const;  //return if the value is found
    int  count(const string &elem) const;  //return the number of the occurrences
private:
    vector<string> _stack;
};



