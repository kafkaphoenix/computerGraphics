/*
 * Matrix44.h
 *
 *  Created on: 10 jun. 2017
 *      Author: sorak
 */

#ifndef MATRIX44_H_
#define MATRIX44_H_

template <typename T>
class Matrix44
{
	Matrix44() {}

	const T* operator [] (uint8_t i) const
	{
		return m[i];
	}
	T* operator [] (uint8_t i)
	{
		return m[i];
	}

	T m[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
};

#endif /* MATRIX44_H_ */
