#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

typedef bool element_t;
typedef intmax_t bitSetSize_t;

class Bitset{
public:

  //Default Constructor to create 8 size but
  Bitset();

  //Constructor for string of size
  Bitset(intmax_t size);

  //Construcor for creating BitSet from string
  Bitset(const std::string & value);

  //Destructor for Bitset
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  //Return size of Bitset
  intmax_t size() const;

  //Check if Bitset is Valid
  bool good() const;

  //Set index to 1
  void set(intmax_t index);

  //Set index to 0
  void reset(intmax_t index);

  //NOT index
  void toggle(intmax_t index);

  //Check value of index
  bool test(intmax_t index);

  //Return Bitset as String
  std::string asString() const;

private:

  //Function to determine if function is valid given N
  bool checkValid(intmax_t n) const;

  //Function to update valid given index
  void updateValid(intmax_t index);

  //Function to get index valud
  bool get(intmax_t index) const;

  element_t *bitString;
  bitSetSize_t bitStringSize;
  bool valid;

};

#endif
