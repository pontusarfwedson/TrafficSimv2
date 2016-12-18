//InvalidLength
#ifndef INVALIDLENGTH_H_
#define INVALIDLENGTH_H_

#include<exception>
using namespace std;

class InvalidLength : public exception {
public:
  InvalidLength();

  const char * what () const throw () {
        return "Invalid Length. Length is lesss than 0";
     }
  };

InvalidLength::InvalidLength() {
}


#endif /* INVALIDLENGTH_H_ */
