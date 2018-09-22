#ifndef TankDriveWithJoystick_H
#define TankDriveWithJoystick_H

#include <CommandBase.h>

class TankDriveWithJoystick: public CommandBase {
public:
	TankDriveWithJoystick();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	bool r = false;
	bool flag;
};

#endif  // TankDriveWithJoystick_H
