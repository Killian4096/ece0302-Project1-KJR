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
    bitStringSize = size;
    if(size<0){
        valid = false;
        bitString = new element_t[0];
    }
    else
    {
        bitString = new element_t[size];
        for(intmax_t i=0;i<size;i++){
            reset(i);
        }
    }
}

Bitset::Bitset(const std::string &value){
    valid = true;
    intmax_t m_length = value.size();
    bitString = new element_t[m_length];
    bitStringSize = m_length;
    for(intmax_t i=0;i<m_length;i++){
        if(value[size()-1-i] == '1'){
            set(i);
        }
        else if(value[size()-1-i] == '0'){
            reset(i);
        }
        else{
            valid = false;
        }
    }
}

Bitset::~Bitset(){
    delete[] bitString;
}

intmax_t Bitset::size() const{
    return bitStringSize;
}

bool Bitset::good() const{
    return valid;
}

void Bitset::set(intmax_t index){
    valid = checkValid(index);
    *(bitString+index) = 1;
}

void Bitset::reset(intmax_t index){
    valid = checkValid(index);
    *(bitString+index) = 0;
}

void Bitset::toggle(intmax_t index){
    valid = checkValid(index);
    *(bitString+index) = not(*(bitString+index));
}

bool Bitset::test(intmax_t index){
    valid = checkValid(index);
    return get(index) && checkValid(index);
}

std::string Bitset::asString() const{
    char buffer[size()];
    for(intmax_t i=0;i<size();i--){
        buffer[size()-1-i] = get(i);
    }
    std::string returnBuffer = buffer;
    return returnBuffer;
}

bool Bitset::checkValid(intmax_t index) const{
    if(index>0 && index<size()){
        return true;
    }
    return false;
}

bool Bitset::get(intmax_t index) const{
    return (*(bitString+index));
}
