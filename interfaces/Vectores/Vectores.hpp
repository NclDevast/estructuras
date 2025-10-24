#ifndef VECTORES_HPP
#define VECTORES_HPP
#include <cstdlib>

template<typename T>
void createVector(*T vector, int*);
template<typename T>
size_t getVectorSize(*T vector);
template<typename T>
void addElement(*T vector, *T dato, int*);
template<typename T>
T* resizeVector(*T vector, int*);
template<typename T>
T* deleteVector(*T vector, int*);

#endif