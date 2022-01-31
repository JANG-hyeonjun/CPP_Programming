//2차원 배열 접근에 대한 오버로딩 연산자 난이도 상 

#include <iostream>

class BoundCheckIntArray
{
private:
    int* arr;
    int arrlen;

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            std::cout << "Array index out of bound exception" << std::endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const 
    {
        return arrlen;
    }
    ~BoundCheckIntArray()
    {
        delete[]arr;
    }
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray
{
private:
    BoundCheckIntArray ** arr;
    int arrlen;
    BoundCheck2DIntArray(const BoundCheck2DIntArray& arr){ }
    BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) { }

public:
    BoundCheck2DIntArray(int col, int row) : arrlen(col)
    {
        arr = new BoundCheckIntArrayPtr[col]; //new BoundCheckArray* [col]
        for (int i = 0; i < col; i++)
        {
            arr[i] = new BoundCheckIntArray(row);
        }
    }

    BoundCheckIntArray& operator[](int idx)
    {
        if (idx < 0 || idx > arrlen)
        {
            std::cout << "Array index out of bound exception" << std::endl;
            exit(1);
        }
        return *(arr[idx]);
    }

    ~BoundCheck2DIntArray()
    {
        for (int i = 0; i < arrlen; i++)
        {
            delete arr[i];
        }
        delete arr;
    }

};


int main()
{
	
    BoundCheck2DIntArray arr2d(3, 4);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr2d[i][j] = i + j;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << arr2d[i][j] << ' ';
        }
        std::cout << std::endl;
    }
	return EXIT_SUCCESS;
}

