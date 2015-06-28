/*
 * Square.h
 *
 *  Created on: 2015��6��28��
 *      Author: zpff
 */

#ifndef SQUARE_H_
#define SQUARE_H_

class Square {
private:
	GLfloat vertices[12];
	GLfloat colors[16];
	GLbyte indices[6];
public:
	Square(GLfloat[], GLfloat[], GLbyte[]);
	void draw();
	virtual ~Square();
};



#endif /* SQUARE_H_ */
