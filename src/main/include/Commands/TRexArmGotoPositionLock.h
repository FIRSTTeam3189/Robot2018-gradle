#ifndef TRexArmGotoPositionLock_H
#define TRexArmGotoPositionLock_H

#include "../CommandBase.h"

class TRexArmGotoPositionLock : public CommandBase {
public:
	TRexArmGotoPositionLock(double goal);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double goal;
};

#endif  // TRexArmGotoPosition_H
