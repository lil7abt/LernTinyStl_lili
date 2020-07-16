#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* void display(const vector<int> &vec)
{
    for(int ix=0; ix<vec.size(); ix++)
    {
        cout<<vec[ix]<<' ';
    }
    cout<<endl;
} */

template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec)
{
    cout<<msg;
    for(int ix=0;ix<vec.size();ix++)
    {
        elemType t = vec[ix];
        cout<<t<<' ';
    }
    cout<<"\n";
}

void swap(int &val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}
//the memory  associated with a static local object persists across function invocations. elems is no longer destroyed and re-created with each invocation of fibon_seq()
//this is why we can return elems's address safetly
const vector<int>* fibon_seq(int size)
{
    const int max_size=1024;
    static vector<int> elems;
    if(size<=0 || size>1024)
    {
        cerr<<"Warning: fibo_seq(): "
            <<size<<"not seupported -- resetting to 8\n";
        size=8;
        return 0;
    }
    
    for (int ix = 0; ix < size; ix++)
    {
        if (ix==0||ix==1)
        {
            elems[ix]=1;
        }
        else
        {
            elems[ix]=elems[ix-1]+elems[ix-2];
        }     
    }
    return &elems;
}
void bubble_sort(vector<int> &vec)
{
    for (int ix = 0; ix < vec.size(); ix++)
    {
        for (int jx = ix+1; jx < vec.size(); jx++)
        {
            if(vec[ix]>vec[jx])
            {
                swap(vec[ix], vec[jx]);
            }
        }        
    }    
}

int main() {
    int ia[8]={8,34,3,13,1,21,5,2};
    vector<int> vec(ia,ia+8);

    cout<<"vector before sort: ";
    // display(vec);
    display_message("this vector is ", vec);

    bubble_sort(vec);
    cout<<"vector after sort: ";
    // display(vec);
    display_message("this vector is ", vec);
    return 0;
}