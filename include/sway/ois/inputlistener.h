#ifndef SWAY_OIS_INPUTLISTENER_H
#define SWAY_OIS_INPUTLISTENER_H

#include <sway/ois/inputevents.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputListener {
public:
	#pragma region Keyboard

	virtual void onKeyPressed(const KeyboardEventArgs & event) {
		// Empty
	}

	virtual void onKeyReleased(const KeyboardEventArgs & event) {
		// Empty
	}

	#pragma endregion

	#pragma region Mouse

	virtual void onMouseButtonDown(const MouseEventArgs & event) {
		// Empty
	}

	virtual void onMouseButtonUp(const MouseEventArgs & event) {
		// Empty
	}

	virtual void onMouseMove(const MouseEventArgs & event) {
		// Empty
	}

	#pragma endregion
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_INPUTLISTENER_H
