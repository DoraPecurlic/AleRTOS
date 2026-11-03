#include "AlarmController.hpp"
#include "AlarmEvent.hpp"
#include "AlarmState.hpp"

AlarmController alarm;

bool AlarmController::handleEvent(AlarmEvent event){
	switch(event)
	{
	    case AlarmEvent::ButtonPressed:
	    	if(state_ == AlarmState::Inactive)
	    	{
	    		state_ = AlarmState::Active;
	    	}else
	    	{
	    		state_ = AlarmState::Inactive;
	    	}
	    	return true;

		case AlarmEvent::ObjectDetected:
			if(state_ == AlarmState::Active)
		    {
				state_ = AlarmState::Alert;
				return true;
			}
			break;

		case AlarmEvent::ObjectCleared:
			if(state_ == AlarmState::Alert)
			{
				state_ = AlarmState::Active;
				return true;
			}
			break;
	}

	return false;
}


AlarmState AlarmController::getState() const{

	return state_;
}

