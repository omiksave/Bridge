#pragma once
#include "InsoleWrapper.h"

float* InsoleWrapper::SetupInsole()
{
	tx->connect(true);
	return p;
}

void InsoleWrapper::UpdateInsole()
{
	tx->scan();
	pprivate = tx->matrix();
	memcpy(p, pprivate, 128 * 4);
}

