#include <iostream>

int main() {
    std::cout << "[BYD AUTO] Booting LiDAR OS Framework...\n\n";
    
    int target_speed {120};

    int* p_speed {&target_speed};

    std::cout << "--- RADAR SENSOR REPORT ---\n"
              << "Target Speed Data: " << target_speed << " km/h\n"

              << "Hardware Memory Address: " << p_speed << "\n\n"
              << "!!! ALERT: OBSTACLE DETECTED IN NOA (Navigate on Autopilot)!!!\n"
              << "Engaging direct memory overwrite...\n\n";

    *p_speed = 0;

    std::cout << "[SYSTEM STATUS]\n"
              << "Target Speed memory changed remotely using a Pointer!\n"

              << "New Target Speed: " << target_speed << " km/h -> CRISIS AVERTED.\n";

    return 0;
}