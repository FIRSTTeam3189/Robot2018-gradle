#ifndef DriveTimed_H
#define DriveTimed_H

#include "../CommandBase.h"

class DriveTimed : public CommandBase {
public:
	DriveTimed(double _time, enum DriveDirection _dir, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double power;
	enum DriveDirection dir;
	double length;
};

#endif  // DriveTimed_H
