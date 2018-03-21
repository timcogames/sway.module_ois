#ifndef SWAY_OIS_MOUSELISTENER_H
#define SWAY_OIS_MOUSELISTENER_H

#include <sway/ois/inputevents.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class MouseListener {
public:
	virtual void onMouseButtonDown(const MouseEventArgs & event) {
		// Empty
	}

	virtual void onMouseButtonUp(const MouseEventArgs & event) {
		// Empty
	}

	virtual void onMouseMove(const MouseEventArgs & event) {
		// Empty
	}
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_MOUSELISTENER_H
