#ifndef AutoForwardTime_H
#define AutoForwardTime_H

#include "../CommandBase.h"

class AutoForwardTime : public CommandBase {
public:
	AutoForwardTime(double seconds, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double seconds;
	double speed_;
};

#endif  // AutoForwardTime_H
