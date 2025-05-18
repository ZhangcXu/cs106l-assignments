#define max_size 200
# include <stdlib.h>

class Stack{
private:
  size_t _size;
  int* elems;

public:
  Stack();

  Stack(size_t size);

  ~Stack(){
    delete []elems;
  }

  bool is_empty() const {
    return _size == 0;
  }

  const size_t& size() const {
    return this->_size;
  }

  void push(const int& elem){
    elems[_size++] = elem;
  }

  int pop(){
    return elems[--_size];
  }

  const int& get() const {
    return elems[_size];
  }

  int pop_kth(size_t size);

};
