
#include "component.hpp"

void Component::setEntityUid(uint32_t entityUid)
{
    this->entityUid = entityUid;
}

uint32_t Component::getEntityUid()
{
    return entityUid;
}
