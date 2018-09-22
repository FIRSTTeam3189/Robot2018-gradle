#ifndef ClawOuttake_H
#define ClawOuttake_H

#include "../CommandBase.h"
#include "Constants.h"

class ClawOuttake : public CommandBase {
public:
	ClawOuttake(double speed = CLAW_OUTAKE_POWER);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double speed = CLAW_OUTAKE_POWER;
};

#endif  // ClawOuttake_H
