
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdint>

class Component
{
  public:
    virtual ~Component() = default;
    virtual void setEntityUid(uint32_t entityUid);

    uint32_t getEntityUid();

  private:
    uint32_t entityUid;
};

#endif
