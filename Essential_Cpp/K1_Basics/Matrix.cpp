#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
    friend Matrix<T> operator+(const Matrix<T> &, const Matrix<T> &);
    friend Matrix<T> operator*(const Matrix<T> &, const Matrix<T> &);
protected:
    int _rows;
    int _cols;
    T *_matrix;
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix &);
    ~Matrix();

    int rows() const {return _rows;}
    int cols() const {return _cols;}

    Matrix& operator=(const Matrix &);
    void operator+=(const Matrix &);
    T& operator()(int row, int column) {return _matrix[row*cols() + column];}
    const T& operator()(int row, int column) const {return _matrix[row*cols() + column];}

    bool same_size(const Matrix &m) const {return rows() == m.rows() && cols()==m.cols();}
    bool comfortable(const Matrix &m) const {return (cols()==m.rows());}

    ostream& print(ostream&) const;
}