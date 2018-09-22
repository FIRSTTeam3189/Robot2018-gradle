
#ifndef AutoMove_H
#define AutoMove_H

#include "../CommandBase.h"
enum class TurnDirection {
	Right, Left, Forward, Backward
};
class AutoMove: public CommandBase {
public:
	AutoMove(TurnDirection direction, double seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	TurnDirection direction;
	double seconds;
};

#endif  // AutoMove_H
