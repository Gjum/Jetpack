#include "Jetpack.h"

Jetpack::Jetpack()
{

}

Jetpack::~Jetpack()
{
}

static Jetpack* Jetpack::Get()
{
   return JetpackPointer;
}

