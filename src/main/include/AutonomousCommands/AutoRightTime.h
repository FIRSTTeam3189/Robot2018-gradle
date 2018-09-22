#ifndef AutoRightTime_H
#define AutoRightTime_H

#include "../CommandBase.h"

class AutoRightTime : public CommandBase {
public:
	AutoRightTime(double seconds, double speed_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double seconds;
	double speed_;
};

#endif  // AutoRightTime_H
