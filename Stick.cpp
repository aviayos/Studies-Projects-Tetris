#include "Stick.h"


//c-tor
Stick::Stick()
{
	//הכנסת מיקום לכל ריבוע נקודת התחלה של כל הריבועים באותו מקום
	for (unsigned int i = 0; i < NUM_SQUARES; i++) {
		m_shape[i].setPosition(LEFTLIMIT+(SHAPE_SIZE*WIDTH/2), -2*SHAPE_SIZE);
	}//הכנסת נקודת מרכז לכל נקודה וככה זה משנה את המיקום
	
	m_shape[0].setOrigin(0,-SHAPE_SIZE);
	m_shape[1].setOrigin(0, 0);
	m_shape[2].setOrigin(0, SHAPE_SIZE);
	m_shape[3].setOrigin(0,2*SHAPE_SIZE );
	
}

//d-tor
Stick::~Stick()
{
}



