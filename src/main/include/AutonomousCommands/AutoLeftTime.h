#ifndef AutoLeftTime_H
#define AutoLeftTime_H

#include "../CommandBase.h"

class AutoLeftTime : public CommandBase {
public:
	AutoLeftTime(double seconds, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double seconds;
	double speed_;
};

#endif  // AutoLeftTime_H
