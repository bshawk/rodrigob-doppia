/* 
  Cuda Templates.

  Copyright (C) 2008 Institute for Computer Graphics and Vision,
                     Graz University of Technology
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CUDA_VECTOR_VECTOR3_H
#define CUDA_VECTOR_VECTOR3_H


// #include <cudatemplates/vector.hpp>


namespace Cuda {

/**
   Specialization of size template for 1D case.
*/
template <class Type>
class Vector<Type, 3>: public VectorBase<Type, 3>
{
public:
  /**
     Default constructor.
  */
  Vector() {}

  /**
     Copy constructor with type conversion.
     @param v vector to be copied
  */
  template <class T>
  Vector(const VectorBase<T, 3> &v)
  {
    for(unsigned i = 3; i--;)
      (*this)[i] = v[i];
  }

  /**
     Constructor.
     @param x0, x1, x2 vector component(s)
  */
  Vector(Type x0, Type x1, Type x2) { (*this)[0] = x0; (*this)[1] = x1; (*this)[2] = x2; }

  // CUDA_VECTOR_OPS(Vector<1>, size_t);
};

}  // namespace Cuda


#endif
