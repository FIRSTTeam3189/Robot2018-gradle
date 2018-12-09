#ifndef DriveEncoders_H
#define DriveEncoders_H

#include "../CommandBase.h"

class DriveEncoders : public CommandBase {
public:
	DriveEncoders(double _power,enum DriveDirection _dir, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double power;
	enum DriveDirection dir;
	double distance;
};

#endif  // DriveEncoders_H
