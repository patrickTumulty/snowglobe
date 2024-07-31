
#ifndef TEST_COMPONENTS_HPP
#define TEST_COMPONENTS_HPP

#include "component.hpp"

struct ComponentA : public Component
{
    int a;
    int b;
    int c;
};

struct ComponentB : public Component
{
    int d;
    int e;
    int f;
};

struct ComponentC : public Component
{
    int g;
    int h;
    int i;
};

#endif
