#ifndef WinchEngage_H
#define WinchEngage_H

#include "../CommandBase.h"

class WinchEngage : public CommandBase {
public:
	WinchEngage();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WinchEngage_H
