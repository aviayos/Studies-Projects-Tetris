#include "Square.h"


//c-tor
Square::Square()
{
	for (int i = 0; i < NUM_SQUARES; i++) {
		m_shape[i].setPosition(SHAPE_SIZE * 10, -SHAPE_SIZE);
	}
	m_shape[0].setOrigin(0, SHAPE_SIZE);
	m_shape[1].setOrigin(SHAPE_SIZE, SHAPE_SIZE);
	m_shape[2].setOrigin(SHAPE_SIZE, 0);
	
}

//d-tor
Square::~Square()
{
}
