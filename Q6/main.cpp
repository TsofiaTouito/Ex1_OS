#include <iostream>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t signal_count = 0;  // I use this instead of int for safe read and write inside handler
int i = 0;

void signal_handler(int sig) {
    signal_count++;
    std::cout << "Signal received: " << sig << " (signal_count: " << signal_count << ")" << std::endl;

    if (signal_count == 4) {
        std::cout << "Processed 4 signals, performing additional operation..." << std::endl;
        i++;
        std::cout << "Value of i after increment: " << i << std::endl;

        exit(0);
    }

    sleep(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_NODEFER;  // Allow signals of the same type to interrupt the handler
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, nullptr) == -1) {
        std::cerr << "Error registering signal handler." << std::endl;
        return 1;
    }

    std::cout << "Process ID: " << getpid() << std::endl;
    std::cout << "Waiting for SIGUSR1 signals..." << std::endl;

    while (true) {} // To keep the program running

    return 0;
}
