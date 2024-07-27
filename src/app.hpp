

#ifndef APP_HPP
#define APP_HPP

#include "system.hpp"
#include "systems_runner.hpp"
#include <memory>

class AppBuilder;

class App
{
public:
    static AppBuilder builder();

private:
    SystemsRunner systemManager;

    App();

public:
    class AppBuilder
    {
    public:
        AppBuilder();

        AppBuilder addSystem(std::unique_ptr<System> system);

        App build();

    private:
    };
};

#endif
