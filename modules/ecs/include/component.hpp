
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdint>

class Component
{
  public:
    virtual ~Component() = default;

    virtual void setEntityIndex(uint32_t entityUid);

    uint32_t getEntityIndex();

  private:
    uint32_t entityIndex;
};

#endif
