

#ifndef APP_HPP
#define APP_HPP

#include "system.hpp"
#include "systems_runner.hpp"
#include <memory>

class AppBuilder;

class App
{
public:
    App();

    static AppBuilder builder();

    SystemsRunner& getSystemsRunner();



private:
    SystemsRunner systemRunner;

};

class AppBuilder
{
public:
    AppBuilder();

    AppBuilder &addSystem(std::unique_ptr<System> system);

    std::unique_ptr<App> build();

private:
    std::unique_ptr<App> app;
};
#endif
