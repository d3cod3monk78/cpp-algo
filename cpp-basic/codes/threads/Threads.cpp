#include <chrono>
#include <iostream>
#include <queue>
#include <thread>

void run(int count) {
    while (count-- > 0) {
        std::cout << count << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main(int argc, char const *argv[]) {
    std::thread t1(run, 10);
    std::cout << "main thread" << std::endl;
    t1.join();
    return 0;
}
