#pragma once

#include "AlarmEvent.hpp"
#include "AlarmState.hpp"


class AlarmController{
public:

	bool handleEvent(AlarmEvent event);

	AlarmState getState() const;



private:

	AlarmState state_ = AlarmState::Inactive;

};
