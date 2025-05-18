# include <stdlib.h>
# include "class.h"

Stack::Stack(){
  elems = new int[max_size];
  _size = 0;
}

Stack::Stack(size_t size){
  elems = new int[size];
  _size = 0;
}



int Stack::pop_kth(size_t size) {
    if (size == 1) return pop();
    for (size_t i=0; i<size-1; i++){
        this->pop();
    }
    return pop();
  }