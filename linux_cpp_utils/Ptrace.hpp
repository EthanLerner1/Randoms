#pragma once

#include <unistd.h>

class Ptrace final
{
public:
    explicit Ptrace(pid_t target_pid);
    ~Ptrace();

private:
    pid_t _target_pid;
};