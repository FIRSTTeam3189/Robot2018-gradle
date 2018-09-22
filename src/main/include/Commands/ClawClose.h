#ifndef ClawClose_H
#define ClawClose_H

#include "../CommandBase.h"

class ClawClose : public CommandBase {
public:
	ClawClose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawClose_H
