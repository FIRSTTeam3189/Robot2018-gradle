#ifndef HaltIfOnWrongSide_H
#define HaltIfOnWrongSide_H

#include "../CommandBase.h"

class HaltIfOnWrongSide : public CommandBase {
public:
	HaltIfOnWrongSide(char side_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	char side;
	bool willFinish;
};

#endif  // HaltIfOnWrongSide_H
