/*
 * Cube.h
 *
 *  Created on: 2015��6��29��
 *      Author: zpff
 */

#ifndef CUBE_H_
#define CUBE_H_

#include <GLES/gl.h>

class Cube{
private:
	GLfloat vertices[24];
	GLfloat colors[32];
	GLbyte  indices[36];
public:
	Cube(GLfloat[] , GLfloat[], GLbyte[]);
	void draw();
	void lighting();
	virtual ~Cube();
};

#endif /* CUBE_H_ */
