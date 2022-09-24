// Span.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>
#include <span>
#include <vector>

void printVec(const std::vector<int>& nums)
{
    for (auto num : nums)
    {
        std::cout << num;
    }
    std::cout << std::endl;
}

void printVec(const std::array<int,4>& nums)
{
    for (auto num : nums)
    {
        std::cout << num;
    }
    std::cout << std::endl;
}
//그런데 이렇게 일일이 만들 필요가 없다. 추상화된 컨테이터 span을 이용한다. 

void printSpan(std::span<int> nums)
{
   /* for (auto num : nums)
    {
        std::cout << num;
    }
    std::cout << std::endl;*/

    //find 와 같은 std를 span에 적용 가능하다.

    auto ret = std::ranges::find(nums, 3);
    if (ret != nums.end())
    {
        std::cout << "found 3" << std::endl;
    }
}


int main()
{
    //우리는 이것에 대해 프린트하는 함수를 만들때 각각의 자료형의 인터페이스를 맞춰 함수를 만들어야한다.
    std::vector<int> vecNums{ 1,2,3 };
    std::array<int, 4> arryNums{ 4,5,6,7 };
    int cNums[6] = { 1,2,3,4,5,6 };

    std::span<int> sp{ vecNums };
    //이렇게 span을 만들고 벡터를 넘겨주면 내부에 시작점과 사이즈가 할당
    printSpan(vecNums);
    printSpan(arryNums);
    

    return EXIT_SUCCESS;
}

