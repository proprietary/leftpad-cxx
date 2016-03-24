#include <iostream>
#include <algorithm>
#include <string>

template <class T,class charT,class Size>
T leftpad(T cont,charT c,Size n) {
  std::generate_n(std::inserter(cont,std::begin(cont)),n,[c](){return c;});
  return cont;
}

template <class T,class charT,class Size>
T rightpad(T cont,charT c,Size n) {
  std::generate_n(std::inserter(cont,std::end(cont)),n,[c](){return c;});
  return cont;
}
int main(int argc, char *argv[])
{
  std::cout << "|"<<leftpad(std::string{"Bernie 2016"},' ',3)<<"|" << "\n";
  std::cout << "|"<<rightpad(std::string{"Bernie 2016"},' ',3)<<"|" << "\n";
  return 0;
}
