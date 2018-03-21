#ifndef SWAY_OIS_KEYBOARDLISTENER_H
#define SWAY_OIS_KEYBOARDLISTENER_H

#include <sway/ois/inputevents.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class KeyboardListener {
public:
	virtual void onKeyPressed(const KeyboardEventArgs & event) {
		// Empty
	}

	virtual void onKeyReleased(const KeyboardEventArgs & event) {
		// Empty
	}
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_KEYBOARDLISTENER_H
