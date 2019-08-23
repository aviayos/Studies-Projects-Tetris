
#include "Controller.h"

#ifdef _DEBUG 
#pragma comment ( lib , "sfml-main-d.lib" ) 
#elif defined (NDEBUG) 
#pragma comment ( lib , "sfml-main.lib" ) 
#else #error "Unrecognized configuration!" 
#endif

int main() {
	Controller con;
	con.run();

}