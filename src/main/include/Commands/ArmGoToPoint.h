#ifndef ArmGoToPoint_H
#define ArmGoToPoint_H

#include "../CommandBase.h"
#include "Constants.h"
#include "Utils/Point.h"

class ArmGoToPoint : public CommandBase {
public:
	ArmGoToPoint(double x, double y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double x, y;
	Point last_position;
};


#endif  // ArmGoToPoint_H
