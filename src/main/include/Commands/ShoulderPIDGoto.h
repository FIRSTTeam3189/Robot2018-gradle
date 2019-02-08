#ifndef ShoulderPIDGoto_H
#define ShoulderPIDGoto_H

#include "../CommandBase.h"

class ShoulderPIDGoto : public CommandBase {
public:
	ShoulderPIDGoto(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double amount;
};

#endif  // ShoulderPIDGoto_H
