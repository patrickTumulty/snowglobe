
#ifndef SYSTEMS_RUNNER_HPP
#define SYSTEMS_RUNNER_HPP

#include "system.hpp"
#include <memory>
#include <thread>
#include <vector>

class SystemsRunner
{
  public:
    SystemsRunner();
    ~SystemsRunner();

    void start();

    void stop();

    void addSystem(std::unique_ptr<System> system);

    void setFrequencyHz(double frequencyHz);

    double getFrequencyHz();

  private:

    void runSystemsLoop();

    std::vector<std::unique_ptr<System>> systems;

    double frequencyHz;

    bool isRunning;

    std::thread systemsLoopThread;
};

#endif
