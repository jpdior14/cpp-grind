#include <iostream>
#include <string>

struct TiMi_GameCharacter {
    std::string player_name;
    int health_points;
    int damage_power;

    void take_damage(int hit_points) {
        health_points -= hit_points;
        std::cout << "[SYSTEM ALERT]: " << player_name << " took " << hit_points << " damage!\n";
        
        if (health_points <= 0) {
            std::cout << "--> Status: OFFLINE. Proceed to respawn base.\n";
        } else {
            std::cout << "--> Status: SURVIVING. HP Remaining: " << health_points << "\n";
        }
    }
};

int main() {
    std::cout << "=== TENCENT CLOUD: HONOR OF KINGS SERVER START ===\n\n";

    TiMi_GameCharacter my_hero {"Godzilla", 1500, 300};

    std::cout << "Player Login: " << my_hero.player_name << '\n'
              << "Initial Core HP: " << my_hero.health_points << '\n'
              << "Attack Damage: " << my_hero.damage_power << "\n\n"

              << "!! ENEMY GANK INCOMING !!\n";
    my_hero.take_damage(600);
    my_hero.take_damage(900);

    return 0;
}