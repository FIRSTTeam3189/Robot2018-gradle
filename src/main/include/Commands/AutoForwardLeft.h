#ifndef AutoForwardLeft_H
#define AutoForwardLeft_H

#include "../CommandBase.h"

class AutoForwardLeft : public CommandBase {
public:
	AutoForwardLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoForwardLeft_H
