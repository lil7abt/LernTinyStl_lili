#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void max_li( T t1,  T t2)
{
    if (t1>=t2)
    {
        cout<<t1;
    }
    else
    {
        cout<<t2<<endl;
    }      
}

template <typename T>
void max_li( vector<T> &vec)
{   T max_t = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (max_t<vec[i])
        {
            max_t=vec[i];
        }        
    }
    cout<<max_t<<endl;
}

template <typename T>
void max_li( T arr[],  int arr_size)
{
    T max_t = arr[0];
    for (int i = 1; i < arr_size; i++)
    {
        if (max_t<arr[i])
        {
            max_t=arr[i];
        }        
    }
    cout<<max_t<<endl;
}

int main()
{
    int            a    = 0,       b = 1;
    float          c    = 0.0,     d = 1.2;
    string         e    = "hello", f = "ni hao";
    vector<int>    g    = {1,2,3,4};
    vector<float>  h    = {1.0, 1.1, 1.2, 1.3};
    vector<string> i    = {"nihao", "hello", "guten tag"};
    int            j[4] = {1,2,3,4};
    float          k[4] = {1.0, 1.1, 1.2, 1.3};
    string         l[3] = {"guten tag", "hello", "nihao"};

    max_li(a,b);
    max_li(c,d);
    max_li(e,f);
    max_li(g);
    max_li(h);
    max_li(i);
    max_li(j,4);
    max_li(k,4);
    max_li(l,3);
    return 0;
}