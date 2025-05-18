/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Stack st;
  int a[3] = {2,3,1};
  for (const auto& elem: a){
    st.push(elem);
  }
  st.pop_kth(2);
}
