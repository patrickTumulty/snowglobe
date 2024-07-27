
#include "systems_runner.hpp"
#include <chrono>
#include <ratio>
#include <thread>

SystemsRunner::SystemsRunner(double frequencyHz) : frequencyHz(frequencyHz), isRunning(false)
{
}

SystemsRunner::~SystemsRunner()
{
    stop();
}

void SystemsRunner::start()
{
    systemsLoopThread = std::thread([this]() { this->runSystemsLoop(); });
}

void SystemsRunner::runSystemsLoop()
{
    isRunning = true;
    double period = 1.0 / frequencyHz;
    while (isRunning)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto sys : systems)
        {
            sys->update();
        }
        auto end = std::chrono::high_resolution_clock::now();

        // std::chrono::milliseconds elapsed = end - start;
        // std::this_thread::sleep_for(std::chrono::microseconds(period - elapsed.count()));
    }
}

void SystemsRunner::stop()
{
    isRunning = false;

    if (systemsLoopThread.joinable())
    {
        systemsLoopThread.join();
    }
}

void SystemsRunner::addSystem(std::shared_ptr<System> system)
{
    systems.push_back(system);
}

void SystemsRunner::setFrequencyHz(double frequencyHz)
{
    this->frequencyHz = frequencyHz;
}

double SystemsRunner::getFrequencyHz()
{
    return frequencyHz;
}
