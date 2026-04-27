#include <iostream>
#include <string>
#include <stdexcept>

void check_server_ping(int ping_speed_ms) {
    std::cout << "[PING SENSOR ACTIVE]: Testing Huawei Packet  Router at " << ping_speed_ms << "ms latency.\n";

    if (ping_speed_ms < 0) {
        throw std::invalid_argument("ERROR: Latency cannot be physically negative. Logic Breach!");
    } else if (ping_speed_ms > 2000) {
        throw std::runtime_error("FATAL ERROR: Over 2 seconds of lag detected. Link fully unstable. Rejecting Packet!");
    }

    std::cout << "[PACKET SECURED]: The connection held successfully! Status is GREEN.\n";
}

int main() {
    std::cout << "=== HUAWEI AFRICAN NETWORK (HQ: Yaounde Breach) DEPLOYED ===\n\n";

    try {
        std::cout << "-- Checking Submarine Cable --\n";
        check_server_ping(120);

        std::cout << "-- Incoming satellite Request --\n";
        check_server_ping(9999);

        std::cout << "\n-- THIS SHOULD NEVER BE READ BY HUMAN EYES --\n";
    }

    catch (const std::exception& e) {
        std::cout << "\n[[SYSTEM AUTO-SHUTOFF TRIGGERED]]\n"
                  << "[Hardware Log from Shenzhen Terminal]: " << e.what() << '\n'
                  << "Status Maintained! Core C++ program survived despite castrophic crash.\n";
    }

    std::cout << "\nEnd of Main... Code executes smoothly regardless of exceptions.\n";

    return 0;
}