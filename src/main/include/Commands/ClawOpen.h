#ifndef ClawOpen_H
#define ClawOpen_H

#include "../CommandBase.h"

class ClawOpen : public CommandBase {
public:
	ClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawOpen_H
