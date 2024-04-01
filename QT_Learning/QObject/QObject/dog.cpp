#include "dog.h"

Dog::Dog (QObject* parent) : QObject{ parent } {
}

void Dog::chase()
{
    // prevent call this slot directly
    if (!sender()) {
        qInfo() << "No sender to the slot, RETURN!!!";
        return;
    }

    // sender():  Returns a pointer to the object that sent the signal,
    // if called in a slot activated by a signal;
    qInfo() << "Chasing" << sender();
}
