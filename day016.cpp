#include <iostream>
#include <thread> // WAKING UP THE INTEL CORES!
#include <chrono> // Time management library
#include <string>

// --- THREAD 1 ALGORITHM ---
// This represents the Core downloading the heavy video data.
void download_video_data(std::string video_name) {
    std::cout << "[Core 1]: Background Engine Started! Downloading " << video_name << "...\n";
    
    // We physically force this thread to SLEEP for 3 seconds to simulate heavy network load
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
    
    std::cout << "[Core 1]: 🟢 VIDEO DOWNLOAD COMPLETE (" << video_name << ")!\n";
}

// --- THREAD 2 ALGORITHM ---
// This represents the UI thread allowing the user to read comments immediately!
void load_ui_comments() {
    std::cout << "[Core 2]: UI Render Started! Loading comment section...\n";
    
    for (int i {1}; i <= 3; i++) {
        // Sleep for 1 second each loop
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
        std::cout << "[Core 2 - UI]: User Comment " << i << " rendered on screen instantly!\n";
    }
}

int main() {
    std::cout << "=== BYTEDANCE (DOUYIN) ASYNC ENGINE STARTUP ===\n\n";

    std::cout << "-> Waking up Multi-Core processor on ThinkPad...\n\n";

    // 1. WE SPIN UP THE THREADS!
    // Instead of calling functions normally, we give them to 'std::thread'. 
    // They start executing AT THE EXACT SAME TIME. The matrix is splitting!
    std::thread background_task(download_video_data, "Yaounde_Vlog.mp4");
    std::thread user_interface_task(load_ui_comments);

    std::cout << "\n[Main Thread]: Both secondary cores are now running independently!\n";
    std::cout << "[Main Thread]: Waiting for them to finish...\n\n";

    // 2. SYNCHRONIZING THE CORES (Joining)
    // The main program cannot just close itself while the other threads are still working.
    // 'join()' tells the main thread to WAIT until the side-tasks are fully done.
    background_task.join();
    user_interface_task.join();

    std::cout << "\nStatus: ASYNC EXECUTION COMPLETE. MULTI-CORE HARDWARE UNLOCKED!\n";

    return 0;
}
