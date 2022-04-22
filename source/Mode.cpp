#include "Mode.h"

std::string modeToString(const Mode& mode)
{
	switch (mode)
	{
	case EASY:
		return "Easy";
	case NORMAL:
		return "Normal";
	case HARD:
		return "Hard";
	default:
		break;
	}
}