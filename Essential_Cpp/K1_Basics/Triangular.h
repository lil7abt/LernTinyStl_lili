class Triangular
{
private:
    int _length;
    int _beg_pos;
    int _next;
public:
    Triangular();
    Triangular(int len);
    Triangular(int len, int beg_pos);


    // ~Triangular();//destructor
    //               //主要用来释放在constructor中或对象生命周期中配置的资源
    //               //例如:constructor从heap用new开辟的一块内存
    //               //那么destructor的body就要通过delete来删除这块内存
    //               //不能被overloaded
};

Triangular::Triangular(/* args */)
{
    _length  = 1;
    _beg_pos = 1;
    _next    = 0;
}

