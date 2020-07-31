#include "Stack.h"
#include <algorithm>

bool Stack::pop(string &elem)
{
    if(empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string & elem)
{
    if(empty())
        return false;
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem)
{
    if (full()) 
        return false;
    _stack.push_back(elem);
    return true;
}

bool Stack::find(const string &elem) const
{
    // if (_stack.empty())
    // {
    //     return false;
    // }
    // else
    // {
    //     for (int i = 0; i < _stack.size(); i++)
    //     {
    //         if (_stack[i]==elem)
    //         {
    //             return true;
    //         }            
    //     }
    //     return false;  
    // }
    vector<string>::const_iterator end_it = _stack.end();//返回一个最后element之后的位置
    return ::find(_stack.begin(), end_it, elem)!=end_it;//检查 find返回的指向,是否为最后个element之后的 位置, 不是的话,就相当于找到了,是的话,相当于搜索了一遍都没有找到
                                                        //Find the first occurrence of a value in a sequence.
                                                        //使用全局函数or变量
}

int Stack::count(const string &elem) const
{
    // int cnt=0;
    // if (_stack.empty())
    // {
    //     return 0;
    // }
    // else
    // {
    //     for (int i = 0; i < _stack.size(); i++)
    //     {
    //         if (_stack[i]==elem)
    //         {
    //             cnt++;
    //         }            
    //     }
    //     return cnt;  
    // }
    return ::count(_stack.begin(), _stack.end(), elem);
}