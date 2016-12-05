#include "stdafx.h"
#include "Constants.h"

const std::string Constants::TITLE = "Pong";
bool Constants::closeWindow = false;

void Constants::close()
{
	Constants::closeWindow = true;
}
