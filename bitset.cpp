#include "bitset.hpp"

Bitset::Bitset(){
    unsigned char d_length = 8;
    valid = true;
    bitString = new element_t[d_length];
    bitStringSize = d_length;
    for(unsigned char i=0;i<d_length;i++)
    {
        reset(i);
    }

}

Bitset::Bitset(intmax_t size){
    valid = true;
    if(size<0){
        valid = false;
    }
    bitString = new element_t[size]
    bitStringSize = size;
    for(intmax_t i=0;i<size;i++){
        reset(i);
    }
}

Bitset::Bitset(const std::string & value){
    valid = true;
    intmax_t m_length = size(value);
    bitString = new element_t[m_length];
    bitStringSize = m_length;
    for(intmax_t i=0;i<m_length;i++){
        if(*(value+i) == 1){
            set(i);
        }
        else if(*(value+i) == 0){
            reset(i);
        }
        else{
            valid = false;
        }
    }
}

~Bitset::Bitset(){
    delete[] bitString;
}

Bitset::Bitset(const Bitset & ) = delete;
Bitset & operator=(const Bitset &) = delete;

intmax_t Bitset::size() const{
    return bitStringSize;
}

bool Bitset::good() const{
    return valid;
}

void Bitset::set(intmax_t index){
    *(bitString+index) = 1;
}

void Bitset::reset(intmax_t index){
    *(bitString+index) = 0;
}

void Bitset::toggle(intmax_t index){
    *(bitString+index) = not(*(bitString+index));
}

bool Bitset::test(intmax_t index){
    return *(bitString+index);
}

std::string Bitset::asString() const{
    
}
