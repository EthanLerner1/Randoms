#include "Ptrace.hpp"
#include <sys/ptrace.h>
#include <stdexcept>
#include <assert.h>


Ptrace::Ptrace(pid_t target_pid) :
    _target_pid(target_pid)
{
    const int ptrace_attach_result = ptrace(PTRACE_ATTACH, _target_pid, nullptr, nullptr);
    static constexpr int PTRACE_ERROR = -1;
    if (ptrace_attach_result == PTRACE_ERROR)
    {
        throw std::runtime_error("failed attaching to process");
    }
}

Ptrace::~Ptrace()
{
    try
    {
	static constexpr int PTRACE_ERROR = -1;
	if(ptrace(PTRACE_DETACH, _target_pid, nullptr, nullptr) == PTRACE_ERROR)
        {
            assert(false);
        }
    }
    catch (...)
    {
        assert(false);
    }
}
