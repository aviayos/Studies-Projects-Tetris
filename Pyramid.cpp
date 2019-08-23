#include "Pyramid.h"


//c-tor
Pyramid::Pyramid()
{
	for (int i = 0; i < NUM_SQUARES; i++) {
		m_shape[i].setPosition(100 + (SHAPE_SIZE * 10 / 2) - SHAPE_SIZE / 2, -SHAPE_SIZE * 1.5);
	}
	m_shape[0].setOrigin(SHAPE_SIZE/2,-SHAPE_SIZE/2);
	m_shape[1].setOrigin(SHAPE_SIZE/2,SHAPE_SIZE/2);
	m_shape[2].setOrigin(-SHAPE_SIZE/2, SHAPE_SIZE/2);
	m_shape[3].setOrigin((SHAPE_SIZE / 2)+SHAPE_SIZE, SHAPE_SIZE / 2);
	
}


//d-tor
Pyramid::~Pyramid()
{
}
