#ifndef GoForwardWithEncoders_H
#define GoForwardWithEncoders_H

#include "../CommandBase.h"
#include "Constants.h"

class GoForwardWithEncoders : public CommandBase {
public:
	GoForwardWithEncoders(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int distance;
};

#endif  // GoForwardWithEncoders_H
