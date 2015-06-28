/*
 * Triangle.h
 *
 *  Created on: 2015��6��28��
 *      Author: zpff
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_


class Triangle {
private:
	GLfloat vertices[9];
public:
	Triangle(GLfloat[]);
	void draw();
	virtual ~Triangle();
};


#endif /* TRIANGLE_H_ */
