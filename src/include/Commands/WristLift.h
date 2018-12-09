#ifndef WristLift_H
#define WristLift_H

#include "../CommandBase.h"

class WristLift : public CommandBase {
public:
	WristLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WristLift_H
