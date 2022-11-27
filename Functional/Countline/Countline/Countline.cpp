// Countline.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <string>

#include <range/v3/view/transform.hpp>
#include <range/v3/range/conversion.hpp>

auto count_lines(std::ifstream& filestream) -> int;
auto open_file(std::string& filename)->std::ifstream;


int count_lines(std::ifstream& filestream) 
{
    return std::count(
        std::istream_iterator<char>(filestream >> std::noskipws),
        std::istream_iterator<char>(),
        '\n');
}


std::ifstream open_file(std::string& filename) 
{
    std::ifstream in(filename);
    return in;
}

std::vector<int>count_lines_in_files(std::vector<std::string>& files)
{
    /*std::vector<int> results(files.size());

    std::transform(files.cbegin(), files.cend(),
        results.begin(),
        count_lines);

    return results;*/

    auto fileList = files | ranges::views::transform(open_file);


    return std::vector<int>();
    
  
}

int main()
{
    std::vector<std::string> vec = { "countline.cpp" };
    auto results = count_lines_in_files(vec);

    for (const auto& result : results) {
        std::cout << result << " line(s)\n";
    }

    return 0;
}


