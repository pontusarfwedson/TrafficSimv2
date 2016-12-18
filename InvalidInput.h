//InvalidInput
#ifndef INVALIDINPUT_H_
#define INVALIDINPUT_H_


#include<exception>
using namespace std;

template <class T>
class InvalidInput : public exception {
  T input;
public:
  InvalidInput();
  InvalidInput(T& input);

  const char * what () const throw () {
        return "Invalid Input. Value is lesss than 0";
     }
  };

  template <class T>
  InvalidInput<T>::InvalidInput() {
  }

  template <class T>
  InvalidInput<T>::InvalidInput(T& input) {
    this->input = input;
  }


#endif /* INVALIDINPUT_H_ */
