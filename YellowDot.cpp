#include "YellowDot.hh"

YellowDot::YellowDot(int width, int height){
	moveBehavior = new MoveWithArrows(width, height);
}

