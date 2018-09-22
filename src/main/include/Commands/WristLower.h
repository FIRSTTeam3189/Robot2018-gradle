#ifndef WristLower_H
#define WristLower_H

#include "../CommandBase.h"

class WristLower : public CommandBase {
public:
	WristLower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WristLower_H
