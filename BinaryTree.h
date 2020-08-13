#include <iostream>
using namespace std;
template <typename valType>
class BTNode;

template <typename valType>
class BinaryTree;


/************ BTNode class ***************/
template <typename valType>
class BTNode
{
    friend class BinaryTree<valType>;
private:
    valType _val;
    int _cnt;//节点值重复次数
    BTNode *_lchild;
    BTNode *_rchild;
public:    
    BTNode();
    BTNode(const valType &);
    //set-method
    void insert_value(const valType &);
    void lchild_leaf(BTNode *leaf, BTNode *subtree);//把leaf结点放到subtree结点到最左下方
    void remove_value(const valType &val, BTNode *&prev);
        //traver algorithm
    void preorder(BTNode *pt, ostream &os) const;
    void inorder(BTNode *pt, ostream &os) const;
    void postorder(BTNode *pt, ostream &os) const;
};


template <typename valType> //constructor
inline BTNode<valType>::BTNode(const valType &val):_val(val)//constructor
{
    _cnt    = 1;
    _lchild = 0;
    _rchild = 0;
}

template <typename valType>//插入节点的函数
void BTNode<valType>::insert_value(const valType & val)
{
    if (_val == val)
    {
        _cnt++;//记录同值的node插入次数
    }
    else if (val < _val)//如果新插入的小于被插入的node值，则被放到左边
    {
        if (!_lchild)
        {
            _lchild = new BTNode(val);
        }
        else
        {
            _lchild->insert_value(val);
        }  
    } 
    else//case val>_val，如果新插入的大于被插入的node的值，则放到右边
    {
        if (!_rchild)
        {
            _rchild=new BTNode(val);
        }
        else
        {
            _rchild->insert_value(val);
        }   
    }
}

//把leaf结点放到subtree结点到最左下方
template <typename valType>
void BTNode<valType>::lchild_leaf(BTNode *leaf, BTNode *subtree)
{
    while (subtree->_lchild)//不断地去寻找lchild，直到某个结点的lchild为空
    {
        subtree = subtree->_lchild;
    }
    subtree->_lchild = leaf;//然后把这个结点的lchild设为参数传进来的leaf结点
}
//1)将被删除的值，2）一个指针指向目前关注的结点的父结点
//parameter传reference to pointer，我们能够改的 指针本身，和pointer所指的对象
template <typename valType>
void BTNode<valType>::remove_value(const valType &val, BTNode *& prev)
{//先找此结点下面找是否有这个值
    if(val<_val)
    {
        if (!_lchild)
            return;//Not found
        else
            _lchild->remove_value(val, _lchild);//继续找
    }
    else if(val>_val)
    {
        if(!_rchild)
            return;//Not found
        else
            _rchild->remove_value(val, _rchild);//继续找
    }
    else//found!
    {
        if (_rchild)
        {
            prev=_rchild;
            if (_lchild)
            {
                if (!prev->lchild)
                {
                    prev->_lchild = _lchild;
                }
                else
                {
                    BTNode<valType>::lchild_leaf(_lchild, prev->_lchild);
                }                
            }
        }
        else
        {
            prev = _lchild;
        }
        delete this;
    }
}
template <typename valType>
void BTNode<valType>::preorder(BTNode *pt, ostream &os) const
{
    if(pt)
    {
        display_val(pt,os);
        if(pt->_lchild) preorder(pt->_lchild, os);
        if(pt->_rchild) preorder(pt->_rchild, os);
    }
}
template <typename valType>
void BTNode<valType>::inorder(BTNode *pt, ostream &os) const
{
    if(pt)
    {
        if(pt->_lchild) preorder(pt->_lchild, os);
        display_val(pt,os);
        if(pt->_rchild) preorder(pt->_rchild, os);
    }
}
template <typename valType>
void BTNode<valType>::postorder(BTNode *pt, ostream &os) const
{
    if(pt)
    {
        if(pt->_lchild) preorder(pt->_lchild, os);
        if(pt->_rchild) preorder(pt->_rchild, os);
        display_val(pt,os);
    }
}
/************** BinaryTree Class ******************/
template <typename valType>
class BinaryTree
{
private:
    BTNode<valType> *_root;

    void copy(BTNode<valType> *tar, BTNode<valType> *src);//copy src subtree to the tar subtree
    void clear(BTNode<valType> *);
public:
    BinaryTree();//default constructor
    BinaryTree(const BinaryTree&);//Copy constructor
    ~BinaryTree();//option + , Destructor
    BinaryTree& operator=(const BinaryTree&);

    bool empty();
    bool clear() {if(_root){clear(_root); _root=0;}}

    void insert(const valType &);
    void remove(const valType &);
    void remove_root();


};

template <typename valType>
inline BinaryTree<valType>::BinaryTree(const BinaryTree &rhs) //copy constructor
{
    copy(_root, rhs._root);
}
template <typename valType>
inline BinaryTree<valType>::~BinaryTree()//destructor
{
    clear();
}
template <typename valType>
inline BinaryTree<valType>& BinaryTree<valType>::operator=(const BinaryTree &rhs)//assignment
{
    if (this!=&rhs)
    {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}

template <typename valType>
inline void BinaryTree<valType>::insert(const valType &elem)
{
    if (!_root)
    {
        _root = new BTNode<valType>(elem);
    }
    else
    {
        _root->insert_value(elem);
    }    
}

template <typename valType>
inline void BinaryTree<valType>::remove(const valType &elem)
{
    if (_root)
    {   //1)要被删除的结点是root
        if (_root->_val==elem)//因为_root是个指针，所以用->
        {
            remove_root();
        }
        else//2）要被删除的结点不是root
        {
            _root->remove_value(elem, _root);
        }
    }
}

template <typename valType>
void BinaryTree<valType>::remove_root()
{
    if (!_root)
    {
        //do nothing
    }
    else
    {
        BTNode<valType> *temp = _root;
        if (_root->_rchild)//如果有rchild，1）rchild替代自己2）然后把原lchild放到新root的最左leaf
        {
            _root = temp->_rchild;
            if (temp->_lchild)
            {
                BTNode<valType> *lc    = temp->lchild;
                BTNode<valType> *newlc = _root->_lchild;
                if (!newlc)
                {
                    _root->_lchild = lc;                    
                }
                else
                {
                    BTNode<valType>::lchild_leaf(lc,newlc);
                }               
                lchild_leaf(temp->_lchild, temp->_rchild);
            }
        }
        else//如果没有rchild，用lchild直接替代原root结点
        {
            _root = temp->_lchild;
        }
        delete temp;
    }
}

template <typename valType>
void BinaryTree<valType>::clear(BTNode<valType> *pt)
{
    if (pt)
    {
        clear(pt->_lchild);//递归
        clear(pt->_rchild);
        delete pt;
    }
}