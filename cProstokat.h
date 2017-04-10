#ifndef _CPROSTOKAT_H
#define _CPROSTOKAT_H

#include "scena.h"
#include "fizyka.h"
#include "cFigura.h"

class cProstokat : public cFigura {
protected:
	float h, w;
public:
	cProstokat();
	cProstokat(float _h, float _w);
	void rysuj();
};

#endif