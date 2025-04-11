#include <cassert>
#include <string>
#include <vector>
#include <iostream>

// Repeat 클래스 정의
template<typename T, unsigned N>
struct Repeat {
  typedef T ValueType;

  T operator()(const T& value) const {
    T result = value;
    for(unsigned i = 1; i < N; ++i) {
      result = result + value;
    }
    return result;
  }
};

// Mapper 클래스 정의
template <class Funct>
struct Mapper {
  typedef typename Funct::ValueType ValueType;

  std::vector<ValueType>& operator()(std::vector<ValueType>& vec) const {
    Funct funct;
    for(size_t i = 0; i < vec.size(); ++i) {
      vec[i] = funct(vec[i]);
    }
    return vec;
  }
};

int main() {
  Mapper< Repeat<int, 3> > map_int;
  Mapper< Repeat<std::string, 2> > map_str;

  std::vector<int> vec_int;
  for(int i = 1; i <= 5; ++i) {
    vec_int.push_back(i);
  }

  map_int(vec_int);

  // int 테스트
  {
    static const int res[] = {3,6,9,12,15};
    std::vector<int> test(res, res + 5);
    assert(test == vec_int);
  }

  std::vector<std::string> vec_str;
  vec_str.push_back("foo"); 
  vec_str.push_back("bar");

  map_str(vec_str);

  // 문자열 테스트
  {
    static const char* res[] = {"foofoo", "barbar"};
    std::vector<std::string> test(res, res + 2);
    assert(test == vec_str);
  }

  std::cout << "All tests passed!\n";
  return 0;
}