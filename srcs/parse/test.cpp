#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

int main() {
    std::ifstream infile("default.conf");
    
    if (!infile.is_open()) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return 1;
    }
    
    // 파일 내용을 한 번에 읽기
    std::string file_contents((std::istreambuf_iterator<char>(infile)),
                              std::istreambuf_iterator<char>());

    // 파일 내용 출력
    std::cout << file_contents;

    // 파일 닫기
    infile.close();

    return 0;
}
