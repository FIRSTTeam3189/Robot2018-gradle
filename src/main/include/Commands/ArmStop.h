#ifndef ArmStop_H
#define ArmStop_H

#include "../CommandBase.h"

class ArmStop : public CommandBase {
public:
	ArmStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmStop_H
