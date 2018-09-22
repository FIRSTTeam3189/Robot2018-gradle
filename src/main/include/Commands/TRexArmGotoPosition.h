#ifndef TRexArmGotoPosition_H
#define TRexArmGotoPosition_H

#include "../CommandBase.h"

class TRexArmGotoPosition : public CommandBase {
public:
	TRexArmGotoPosition(double goal);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double goal;
};

#endif  // TRexArmGotoPosition_H
