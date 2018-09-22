#ifndef AutoEncoderTurn_H
#define AutoEncoderTurn_H

#include "../CommandBase.h"

class AutoEncoderTurn : public CommandBase {
public:
	AutoEncoderTurn(double distance_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double distance;
};

#endif  // AutoEncoderTurn_H
