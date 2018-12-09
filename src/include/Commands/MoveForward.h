#ifndef MoveForwardWhileHeld_H
#define MoveForwardWhileHeld_H

#include "../CommandBase.h"

class MoveForwardWhileHeld : public CommandBase {
public:
	MoveForwardWhileHeld();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveForwardWhileHeld_H
