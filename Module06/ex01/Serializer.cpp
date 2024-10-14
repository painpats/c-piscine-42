#include "Serializer.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Serializer::Serializer() {
}
Serializer::Serializer(const Serializer& copy) {
    (void)copy;
}
////////// DESTRUCTOR ///////////////////////////////////////////////
Serializer::~Serializer() {
}

////////// OPERATOR /////////////////////////////////////////////////
Serializer& Serializer::operator=(const Serializer& copy) {
    (void)copy;
    return *this;
}

////////// FUNCTIONS ////////////////////////////////////////////////
uintptr_t    Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
Data*    Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
