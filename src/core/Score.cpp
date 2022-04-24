#include "Score.h"

Score::Score() : score(0) {}

const int Score::getScore() const { return score; }

void Score::setScore() { score++; }