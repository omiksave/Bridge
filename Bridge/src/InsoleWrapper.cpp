#pragma once
#include "InsoleWrapper.h"

void InsoleWrapper::SetupInsole()
{
	tx->connect(true);
}

float* InsoleWrapper::UpdateInsole()
{
	tx->scan();
	pprivate = tx->matrix();
	memcpy(p, pprivate, 128 * 4);
	return p;
}
